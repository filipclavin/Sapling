#include <Sapling.h>

#include <imgui.h>

class ExampleLayer : public Sapling::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		_vertexArray = Sapling::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0, 0.0, 1.0, 1.0,
			 0.5f, -0.5f, 0.0f, 0.0, 0.0, 1.0, 1.0,
			 0.0f,  0.5f, 0.0f, 1.0, 1.0, 0.0, 1.0
		};
		auto vertexBuffer = Sapling::VertexBuffer::Create(vertices, sizeof(vertices));
		vertexBuffer->SetLayout({
			{Sapling::ShaderDataType::Float3, "a_Position"},
			{Sapling::ShaderDataType::Float4, "a_Color"},
		});
		_vertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		auto indexBuffer = Sapling::IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int));
		_vertexArray->SetIndexBuffer(indexBuffer);

		_squareVA = Sapling::VertexArray::Create();
		
		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		auto squareVB = Sapling::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		squareVB->SetLayout({
			{Sapling::ShaderDataType::Float3, "a_Position"}
		});
		_squareVA->AddVertexBuffer(squareVB);

		unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		auto squareIB = Sapling::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(unsigned int));
		_squareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec3 position;
			out vec4 color;

			void main()
			{
				position = a_Position;
				color = a_Color;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string blueVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			out vec3 position;
			out vec4 color;

			void main()
			{
				position = a_Position;
				color = vec4(0.0, 0.0, 1.0, 1.0);
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 o_color;

			in vec3 position;
			in vec4 color;

			void main()
			{
				o_color = color;
			}
		)";

		_shader = Sapling::Shader::Create(vertexSrc, fragmentSrc);
		_squareShader = Sapling::Shader::Create(blueVertexSrc, fragmentSrc);
	}

	void OnUpdate() override
	{
		Sapling::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Sapling::RenderCommand::Clear();

		Sapling::Renderer::BeginScene();

		_squareShader->Bind();
		Sapling::Renderer::Submit(_squareVA);

		_shader->Bind();
		Sapling::Renderer::Submit(_vertexArray);

		Sapling::Renderer::EndScene();
	}

	void OnEvent(Sapling::Event& event) override
	{
		if (event.GetEventType() == Sapling::EventType::CharTyped)
		{
			Sapling::CharTypedEvent& e = (Sapling::CharTypedEvent&)event;
			
			std::cout << e << std::endl;
		}
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

private:
	std::shared_ptr<Sapling::Shader> _shader;
	std::shared_ptr<Sapling::VertexArray> _vertexArray;

	std::shared_ptr<Sapling::Shader> _squareShader;
	std::shared_ptr<Sapling::VertexArray> _squareVA;
};

class Sandbox : public Sapling::Application
{
public:
	Sandbox()
	{
		std::cout << "Sandbox created" << std::endl;
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
		
	}

};

Sapling::Application* Sapling::CreateApplication()
{
	return new Sandbox();
}