#pragma once

#include "Sapling/Core/Base.h"

#include "Sapling/Core/Window.h"
#include "Sapling/Core/LayerStack.h"
#include "Sapling/Events/Event.h"
#include "Sapling/Events/ApplicationEvent.h"

#include "Sapling/ImGui/ImGuiLayer.h"

namespace Sapling
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		static Application& Get() { return *s_instance; }
		Window& GetWindow() { return *_window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> _window;
		ImGuiLayer* _imguiLayer;
		LayerStack _layerStack;

		bool _running = true;

		static Application* s_instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

