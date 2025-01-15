#include "sappch.h"
#include "Application.h"

#include "Sapling/Core/Input.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Sapling/Core/DeltaTime.h"

#include <GLFW/glfw3.h>

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
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (_running)
		{
			float time = static_cast<float>(glfwGetTime()); // TODO: Platform::GetTime()
			DeltaTime dt = time - _lastFrameTime;
			_lastFrameTime = time;

			for (Layer* layer : _layerStack)
			{
				layer->OnUpdate(dt);
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
