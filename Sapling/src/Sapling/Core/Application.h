#pragma once

#include "Sapling/Core/Base.h"

#include "Sapling/Core/Window.h"
#include "Sapling/Core/LayerStack.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> _window;
		LayerStack _layerStack;
		bool _running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

