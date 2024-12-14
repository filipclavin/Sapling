#include "sappch.h"

#include "Application.h"
#include "Sapling/Core/Input.h"

#include <Platform/Windows/WindowsWindow.h>
#include <Sapling/Renderer/Buffer.h>

#include <glad/gl.h>

namespace Sapling
{

	Application::Application()
	{
		if (s_instance)
		{
			throw std::runtime_error("Application already exists!");
		}
		s_instance = this;

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		_imguiLayer = new ImGuiLayer();
		PushOverlay(_imguiLayer);

		_vertexArray.reset(VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0, 0.0, 1.0, 1.0,
			 0.5f, -0.5f, 0.0f, 0.0, 0.0, 1.0, 1.0,
			 0.0f,  0.5f, 0.0f, 1.0, 1.0, 0.0, 1.0
		};

		_vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		_vertexBuffer->SetLayout({
			{ShaderDataType::Float3, "a_Position"},
			{ShaderDataType::Float4, "a_Color"},
		});
		_vertexArray->AddVertexBuffer(_vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };

		_indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int)));
		_vertexArray->SetIndexBuffer(_indexBuffer);

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

		_shader.reset(Shader::Create(vertexSrc, fragmentSrc));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (_running)
		{
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			_shader->Bind();
			glDrawElements(GL_TRIANGLES, _indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : _layerStack)
			{
				layer->OnUpdate();
			}

			_imguiLayer->Begin();
			for (Layer* layer : _layerStack)
			{
				layer->OnImGuiRender();
			}
			_imguiLayer->End();

			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		// std::cout << e << std::endl;

		for (auto it = _layerStack.end(); it != _layerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		_running = false;
		return true;
	}
}
