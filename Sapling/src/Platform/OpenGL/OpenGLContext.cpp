#include "sappch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/gl.h>

namespace Sapling
{
	OpenGLContext::OpenGLContext(int width, int height,
                                 const char* title,
                                 GLFWmonitor* monitor,
                                 GLFWwindow* share,
								 GLFWwindow*& outWindow)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		_nativeWindow = glfwCreateWindow(width, height, title, monitor, share);
		outWindow = _nativeWindow;
	}

	void OpenGLContext::Init()
	{
		if (!_nativeWindow)
		{
			throw std::runtime_error("Native window is null!");
		}

		glfwMakeContextCurrent(_nativeWindow);

		int glVersion = gladLoadGL(glfwGetProcAddress);

		if (glVersion == 0)
		{
			throw std::runtime_error("Could not initialize GLAD!");
		}

		glEnable(GL_DEPTH_TEST);

		std::cout << "OpenGL Info:\n";
		std::cout << "  Vendor: " << glGetString(GL_VENDOR) << "\n";
		std::cout << "  Renderer: " << glGetString(GL_RENDERER) << "\n";
		std::cout << "  Version: " << glGetString(GL_VERSION) << "\n";

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(_nativeWindow);
	}

	void OpenGLContext::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
	}
}