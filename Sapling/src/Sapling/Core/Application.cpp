#include "sappch.h"
#include "Application.h"

namespace Sapling
{

	Application::Application()
	{
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (_running)
		{
			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		std::cout << e << std::endl;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		_running = false;
		return true;
	}
}
