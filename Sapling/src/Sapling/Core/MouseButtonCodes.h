#pragma once

namespace Sapling
{
	// Based off of glfw3.h
	enum class MOUSE_BTN
	{
		MOUSE_1,
		MOUSE_2,
		MOUSE_3,
		MOUSE_4,
		MOUSE_5,
		MOUSE_6,
		MOUSE_7,
		MOUSE_8,
		MOUSE_LAST = MOUSE_8,
		MOUSE_LEFT = MOUSE_1,
		MOUSE_RIGHT = MOUSE_2,
		MOUSE_MIDDLE = MOUSE_3
	};

	std::string GetMouseButtonName(MOUSE_BTN button);
}