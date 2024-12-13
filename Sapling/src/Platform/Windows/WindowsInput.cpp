#include "sappch.h"

#include "WindowsInput.h"
#include "Sapling/Core/Application.h"
#include <Platform/GLFW/GLFWKeyCodes.h>
#include <Platform/GLFW/GLFWMouseButtonCodes.h>

#include <GLFW/glfw3.h>

namespace Sapling
{
	Input* Input::s_instance = new WindowsInput();

	bool Sapling::WindowsInput::IsKeyPressedImpl(KEY keyCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetKey(window, GetGlfwKeyBySaplingKey(keyCode));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Sapling::WindowsInput::IsMouseButtonPressedImpl(MOUSE_BTN button)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, GetGlfwMouseButtonBySaplingMouseButton(button));
		return state == GLFW_PRESS;
	}

	glm::vec2 WindowsInput::GetMousePositionImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { xPos, yPos };
	}

}
