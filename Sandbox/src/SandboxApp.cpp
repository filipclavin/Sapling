#include <Sapling.h>

#include <imgui.h>

class ExampleLayer : public Sapling::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		_activeCamera = &_perspectiveCamera;
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

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Model;

			out vec4 color;

			void main()
			{
				color = a_Color;
				gl_Position = u_ViewProjection * u_Model * vec4(a_Position, 1.0);
			}
		)";

		std::string squareVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Model;

			out vec4 color;

			void main()
			{
				color = vec4(0.0, 0.0, 1.0, 1.0);
				gl_Position = u_ViewProjection * u_Model * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 o_color;

			in vec4 color;

			void main()
			{
				o_color = color;
			}
		)";

		_shader = Sapling::Shader::Create(vertexSrc, fragmentSrc);
		_shader->Bind();
		_shader->SetMat4("u_Model", glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, 0.1f)));

		_squareShader = Sapling::Shader::Create(squareVertexSrc, fragmentSrc);
		_squareShader->Bind();
		_squareShader->SetMat4("u_Model", glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, 0.0f)));
	}

	void OnUpdate() override
	{
		Sapling::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Sapling::RenderCommand::Clear();

		UpdateCamera();

		Sapling::Renderer::BeginScene(_activeCamera->GetViewProjectionMatrix());

		Sapling::Renderer::Submit(_squareVA, _squareShader);
		Sapling::Renderer::Submit(_vertexArray, _shader);

		Sapling::Renderer::EndScene();
	}

	void OnEvent(Sapling::Event& event) override
	{
		Sapling::EventDispatcher dispatcher(event);
		dispatcher.Dispatch<Sapling::MouseMovedEvent>(BIND_EVENT_FN(ExampleLayer::OnMouseMoved));
	}


	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Button("Toggle Camera Type");
		if (ImGui::IsItemClicked())
		{
			if (_cameraType == Sapling::CameraType::Perspective)
			{
				_cameraType = Sapling::CameraType::Orthographic;
				_orthographicCamera.CopySharedProperties(_perspectiveCamera);
				_activeCamera = &_orthographicCamera;
			}
			else
			{
				_cameraType = Sapling::CameraType::Perspective;
				_perspectiveCamera.CopySharedProperties(_orthographicCamera);
				_activeCamera = &_perspectiveCamera;
			}
		}
		ImGui::End();
	}

private:
	void UpdateCamera()
	{
		bool cameraMoved = false;

		glm::quat cameraRotation = _activeCamera->GetRotation();

		
		bool cameraRotated = false;

		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_LEFT))
		{
			cameraRotation = glm::normalize(glm::angleAxis(glm::radians(0.5f), glm::vec3(0.0f, 0.0f, 1.0f)) * cameraRotation);
			cameraRotated = true;
		}
		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_RIGHT))
		{
			cameraRotation = glm::normalize(glm::angleAxis(glm::radians(-0.5f), glm::vec3(0.0f, 0.0f, 1.0f)) * cameraRotation);
			cameraRotated = true;
		}

		if (cameraRotated)
		{
			_activeCamera->SetRotation(cameraRotation);
		}

		glm::vec3 cameraForward = cameraRotation * glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraRight = cameraRotation * glm::vec3(1.0f, 0.0f, 0.0f);
		glm::vec3 cameraUp = cameraRotation * glm::vec3(0.0f, 1.0f, 0.0f); 

		glm::vec3 cameraPosition = _activeCamera->GetPosition();
		
		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_W))
		{
			cameraPosition += cameraForward * 0.01f;
			cameraMoved = true;
		}
		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_A))
		{
			cameraPosition -= cameraRight * 0.01f;
			cameraMoved = true;
		}
		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_S))
		{
			cameraPosition -= cameraForward * 0.01f;
			cameraMoved = true;
		}
		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_D))
		{
			cameraPosition += cameraRight * 0.01f;
			cameraMoved = true;
		}
		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_Q))
		{
			cameraPosition -= cameraUp * 0.01f;
			cameraMoved = true;
		}
		if (Sapling::Input::IsKeyPressed(Sapling::KEY::KEY_E))
		{
			cameraPosition += cameraUp * 0.01f;
			cameraMoved = true;
		}

		if (cameraMoved)
		{
			_activeCamera->SetPosition(cameraPosition);
		}
	}

    bool OnMouseMoved(Sapling::MouseMovedEvent& event)
    {
        if (Sapling::Input::IsMouseButtonPressed(Sapling::MOUSE_BTN::MOUSE_LEFT))
        {
            glm::vec2 delta = event.GetDelta();
            glm::quat cameraRotation = _activeCamera->GetRotation();

            glm::quat pitch = glm::angleAxis(glm::radians(-delta.y * 0.1f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::quat yaw = glm::angleAxis(glm::radians(-delta.x * 0.1f), glm::vec3(0.0f, 1.0f, 0.0f));

            cameraRotation = glm::normalize(yaw * cameraRotation * pitch);

            _activeCamera->SetRotation(cameraRotation);
            return true;
        }

        return false;
    }

	bool OnScroll(Sapling::MouseScrolledEvent& event)
	{
		float yOffset = event.GetOffset().y;

		if (_cameraType == Sapling::CameraType::Perspective)
		{
			float fov = _perspectiveCamera.GetFOV();
			fov -= yOffset * 0.1f;
			fov = std::max(fov, 1.0f);
			fov = std::min(fov, 45.0f);
			_perspectiveCamera.SetFOV(fov);
		}
		else
		{
			float zoomLevel = _orthographicCamera.GetZoomLevel();
			zoomLevel -= yOffset * 0.1f;
			zoomLevel = std::max(zoomLevel, 0.25f);
			_orthographicCamera.SetZoomLevel(zoomLevel);
		}

		return true;
	}

	std::shared_ptr<Sapling::Shader> _shader;
	std::shared_ptr<Sapling::VertexArray> _vertexArray;

	std::shared_ptr<Sapling::Shader> _squareShader;
	std::shared_ptr<Sapling::VertexArray> _squareVA;

	Sapling::CameraType _cameraType = Sapling::CameraType::Perspective;

	Sapling::PerspectiveCamera _perspectiveCamera;
	Sapling::OrthographicCamera _orthographicCamera;

	Sapling::Camera* _activeCamera;
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