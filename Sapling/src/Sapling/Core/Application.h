#pragma once

#include "Sapling/Core/Base.h"
#include "Sapling/Core/Window.h"
#include "Sapling/Events/Event.h"
#include "Sapling/Events/ApplicationEvent.h"

namespace Sapling
{
	class SAPLING_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

