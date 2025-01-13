#include "sappch.h"
#include "WindowsWindow.h"

#include <Sapling/Events/ApplicationEvent.h>
#include <Sapling/Events/MouseEvent.h>
#include <Sapling/Events/KeyboardEvent.h>

#include <Platform/GLFW/GLFWKeyCodes.h>
#include <Platform/GLFW/GLFWMouseButtonCodes.h>
#include <Platform/OpenGL/OpenGLContext.h>

#include <GLFW/glfw3.h>
#include <Sapling/Renderer/RendererAPI.h>

namespace Sapling
{
	static bool s_glfwInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		_data.Title = props.Title;
		_data.Width = props.Width;
		_data.Height = props.Height;

		if (!s_glfwInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			if (!glfwInit())
			{
				throw std::runtime_error("Could not initialize GLFW!");
			}

			glfwSetErrorCallback([](int error, const char* description)
			{
				throw std::runtime_error(std::format("GLFW Error {}: {}", error, description));
			});

			s_glfwInitialized = true;
		}

		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:
				throw std::runtime_error("RendererAPI::None is not supported!");

			case RendererAPI::API::OpenGL:
				_context = new OpenGLContext((int)props.Width,
					(int)props.Height,
					_data.Title.c_str(),
					nullptr,
					nullptr,
					_nativeWindow);
				break;

			default:
				throw std::runtime_error("Unknown RendererAPI!");
		}

		_context->Init();

		// Used for event callbacks (pushes the window data to the callback)
		glfwSetWindowUserPointer(_nativeWindow, &_data);

		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(_nativeWindow, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(_nativeWindow, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(_nativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(GetSaplingKeyByGlfwKey(key));
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyRepeatedEvent event(GetSaplingKeyByGlfwKey(key));
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(GetSaplingKeyByGlfwKey(key));
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetCharCallback(_nativeWindow, [](GLFWwindow* window, unsigned int codepoint)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			CharTypedEvent event(codepoint);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(_nativeWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event({xPos, yPos});
			data.EventCallback(event);
			SetPrevMousePos({ xPos, yPos });
		});

		glfwSetMouseButtonCallback(_nativeWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(GetSaplingMouseButtonByGlfwMouseButton(button));
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(GetSaplingMouseButtonByGlfwMouseButton(button));
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(_nativeWindow, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event({xOffset, yOffset});
			data.EventCallback(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(_nativeWindow);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		_context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		_context->SetVSync(enabled);
		_data.VSync = enabled;
	}

}