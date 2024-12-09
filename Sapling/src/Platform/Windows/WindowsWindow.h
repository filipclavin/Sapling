#pragma once

#include "Sapling/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Sapling
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return _data.Width; }
		unsigned int GetHeight() const override { return _data.Height; }
		
		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { _data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return _window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* _window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData _data;
	};
}