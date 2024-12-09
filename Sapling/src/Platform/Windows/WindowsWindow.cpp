#include "sappch.h"
#include "WindowsWindow.h"

#include <Sapling/Events/ApplicationEvent.h>
#include <Sapling/Events/MouseEvent.h>
#include <Sapling/Events/KeyboardEvent.h>

#include <glad/gl.h>

namespace Sapling
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		_data.Title = props.Title;
		_data.Width = props.Width;
		_data.Height = props.Height;
		
		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			if (!glfwInit())
			{
				std::cout << "Could not initialize GLFW!" << std::endl;
				return;
			}

			glfwSetErrorCallback([](int error, const char* description)
			{
				std::cout << "GLFW Error (" << error << "): " << description << std::endl;
			});

			s_GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)props.Width, (int)props.Height, _data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);

		int glVersion = gladLoadGL(glfwGetProcAddress);

		if (glVersion == 0)
		{
			std::cout << "Could not initialize GLAD!" << std::endl;
			return;
		}

		// Used for event callbacks (pushes the window data to the callback)
		glfwSetWindowUserPointer(_window, &_data);

		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(_window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, scancode);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key, scancode);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
				KeyRepeatedEvent event(key, scancode);
				data.EventCallback(event);
				break;
			}
		});

		glfwSetCharCallback(_window, [](GLFWwindow* window, unsigned int codepoint)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			CharTypedEvent event(codepoint);
			data.EventCallback(event);
		});

		glfwSetCharModsCallback(_window, [](GLFWwindow* window, unsigned int codepoint, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			CharTypedWithModsEvent event(codepoint, mods);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(_window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		_data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return _data.VSync;
	}

}