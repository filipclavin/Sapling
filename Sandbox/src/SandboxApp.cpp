#include <Sapling.h>

#include <imgui.h>

using namespace Sapling;

class ExampleLayer : public Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		_activeCamera = &_perspectiveCamera;

		std::string triangleVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec4 color;

			void main()
			{
				color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string squareVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec4 color;

			void main()
			{
				color = vec4(0.0, 0.0, 1.0, 1.0);
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
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

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0, 0.0, 1.0, 1.0,
			 0.5f, -0.5f, 0.0f, 0.0, 0.0, 1.0, 1.0,
			 0.0f,  0.5f, 0.0f, 1.0, 1.0, 0.0, 1.0
		};
		unsigned int indices[3] = { 0, 1, 2 };

		Transform triangleTransform = Transform({-1.0f, 0.0f, 1.0f});
		BufferLayout triangleLayout = {
			{ShaderDataType::Float3, "a_Position"},
			{ShaderDataType::Float4, "a_Color"},
		};
		Mesh triangleMesh(vertices, sizeof(vertices), indices, sizeof(indices) / sizeof(unsigned int), triangleLayout);
		auto triangleShader = Shader::Create(triangleVertexSrc, fragmentSrc);

		_triangle = GameObject("Triangle", std::make_shared<Transform>(triangleTransform), std::make_shared<Mesh>(triangleMesh), triangleShader);
		
		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};
		unsigned int squareIndices[2 * 3] = {
			0, 1, 2,
			2, 3, 0
		};

		Transform squareTransform = Transform();
		BufferLayout squareLayout = {
			{ShaderDataType::Float3, "a_Position"}
		};
		Mesh squareMesh(squareVertices, sizeof(squareVertices), squareIndices, sizeof(squareIndices) / sizeof(unsigned int), squareLayout);
		auto squareShader = Shader::Create(squareVertexSrc, fragmentSrc);

		_square = GameObject("Square", std::make_shared<Transform>(), std::make_shared<Mesh>(squareMesh), squareShader);
	}

	void OnUpdate(DeltaTime deltaTime) override
	{
		RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		RenderCommand::Clear();

		UpdateCamera(deltaTime);

		Renderer::BeginScene(_activeCamera->GetViewProjectionMatrix());
		
		Renderer::Submit(_triangle.Mesh->GetVertexArray(), _triangle.Shader, _triangle.Transform->GetMat4());
		Renderer::Submit(_square.Mesh->GetVertexArray(), _square.Shader, _square.Transform->GetMat4());

		Renderer::EndScene();
	}

	void OnEvent(Event& event) override
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(ExampleLayer::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ExampleLayer::OnScroll));
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Button("Toggle Camera Type");
		if (ImGui::IsItemClicked())
		{
			if (_cameraType == CameraType::Perspective)
			{
				_cameraType = CameraType::Orthographic;
				_orthographicCamera.CopySharedProperties(_perspectiveCamera);
				_activeCamera = &_orthographicCamera;
			}
			else
			{
				_cameraType = CameraType::Perspective;
				_perspectiveCamera.CopySharedProperties(_orthographicCamera);
				_activeCamera = &_perspectiveCamera;
			}
		}
		ImGui::End();
	}

private:
	void UpdateCamera(DeltaTime deltaTime)
	{
		glm::quat cameraRotation = _activeCamera->GetRotation();
		
		bool cameraRotated = false;
		float cameraRotationSpeed = 50.0f;

		if (Input::IsKeyPressed(KEY::KEY_LEFT))
		{
			cameraRotation = glm::normalize(glm::angleAxis(glm::radians(cameraRotationSpeed * deltaTime), glm::vec3(0.0f, 0.0f, 1.0f)) * cameraRotation);
			cameraRotated = true;
		}
		if (Input::IsKeyPressed(KEY::KEY_RIGHT))
		{
			cameraRotation = glm::normalize(glm::angleAxis(glm::radians(-cameraRotationSpeed * deltaTime), glm::vec3(0.0f, 0.0f, 1.0f)) * cameraRotation);
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
		float cameraMoveSpeed = 2.0f;
		
		bool cameraMoved = false;

		if (Input::IsKeyPressed(KEY::KEY_W))
		{
			cameraPosition += cameraMoveSpeed * deltaTime * cameraForward;
			cameraMoved = true;
		}
		if (Input::IsKeyPressed(KEY::KEY_A))
		{
			cameraPosition -= cameraMoveSpeed * deltaTime * cameraRight;
			cameraMoved = true;
		}
		if (Input::IsKeyPressed(KEY::KEY_S))
		{
			cameraPosition -= cameraMoveSpeed * deltaTime * cameraForward;
			cameraMoved = true;
		}
		if (Input::IsKeyPressed(KEY::KEY_D))
		{
			cameraPosition += cameraMoveSpeed * deltaTime * cameraRight;
			cameraMoved = true;
		}
		if (Input::IsKeyPressed(KEY::KEY_Q))
		{
			cameraPosition -= cameraMoveSpeed * deltaTime * cameraUp;
			cameraMoved = true;
		}
		if (Input::IsKeyPressed(KEY::KEY_E))
		{
			cameraPosition += cameraMoveSpeed * deltaTime * cameraUp;
			cameraMoved = true;
		}

		if (cameraMoved)
		{
			_activeCamera->SetPosition(cameraPosition);
		}
	}

    bool OnMouseMoved(MouseMovedEvent& event)
    {
        if (Input::IsMouseButtonPressed(MOUSE_BTN::MOUSE_RIGHT))
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

	bool OnScroll(MouseScrolledEvent& event)
	{
		float yOffset = event.GetOffset().y;

		if (_cameraType == CameraType::Perspective)
		{
			float fov = _perspectiveCamera.GetFOV();
			fov -= yOffset;
			fov = std::clamp(fov, 5.0f, 45.0f);
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

	GameObject _triangle;
	GameObject _square;

	CameraType			_cameraType = CameraType::Perspective;
	PerspectiveCamera	_perspectiveCamera;
	OrthographicCamera	_orthographicCamera;
	Camera*				_activeCamera;
};

class Sandbox : public Application
{
public:
	Sandbox()
	{
		std::cout << "Sandbox created" << std::endl;
		GetWindow().SetVSync(false);
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
		
	}

};

Application* Sapling::CreateApplication()
{
	return new Sandbox();
}