#include "sappch.h"
#include "MouseButtonCodes.h"

namespace Sapling
{
	std::unordered_map<MOUSE_BTN, std::string> s_MouseButtonNames = {
		{ MOUSE_BTN::MOUSE_1, "MOUSE_1" },
		{ MOUSE_BTN::MOUSE_2, "MOUSE_2" },
		{ MOUSE_BTN::MOUSE_3, "MOUSE_3" },
		{ MOUSE_BTN::MOUSE_4, "MOUSE_4" },
		{ MOUSE_BTN::MOUSE_5, "MOUSE_5" },
		{ MOUSE_BTN::MOUSE_6, "MOUSE_6" },
		{ MOUSE_BTN::MOUSE_7, "MOUSE_7" },
		{ MOUSE_BTN::MOUSE_8, "MOUSE_8" },
		{ MOUSE_BTN::MOUSE_LAST, "MOUSE_LAST" },
		{ MOUSE_BTN::MOUSE_LEFT, "MOUSE_LEFT" },
		{ MOUSE_BTN::MOUSE_RIGHT, "MOUSE_RIGHT" },
		{ MOUSE_BTN::MOUSE_MIDDLE, "MOUSE_MIDDLE" }
	};

	std::string GetMouseButtonName(MOUSE_BTN button)
	{
		return s_MouseButtonNames[button];
	}
}