#pragma once

#include "Sapling/Core/Window.h"

struct GLFWwindow;

namespace Sapling
{
	class RenderingContext;

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual unsigned int GetWidth() const override { return _data.Width; }
		virtual unsigned int GetHeight() const override { return _data.Height; }
		
		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) override { _data.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override { return _data.VSync; };

		inline virtual void* GetNativeWindow() const override { return _nativeWindow; }

	private:
		virtual void Shutdown();
		RenderingContext* _context;

	private:
		GLFWwindow* _nativeWindow = nullptr;

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