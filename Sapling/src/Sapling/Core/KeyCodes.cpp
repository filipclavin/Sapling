#include "sappch.h"

#include "KeyCodes.h"

namespace Sapling
{
	std::unordered_map<KEY, std::string> s_KeyNames = {
		{ KEY::KEY_UNKNOWN, "UNKNOWN" },

		// Printable keys
		{ KEY::KEY_SPACE, "SPACE" },
		{ KEY::KEY_APOSTROPHE, "APOSTROPHE" },
		{ KEY::KEY_COMMA, "COMMA" },
		{ KEY::KEY_MINUS, "MINUS" },
		{ KEY::KEY_PERIOD, "PERIOD" },
		{ KEY::KEY_SLASH, "SLASH" },
		{ KEY::KEY_0, "0" },
		{ KEY::KEY_1, "1" },
		{ KEY::KEY_2, "2" },
		{ KEY::KEY_3, "3" },
		{ KEY::KEY_4, "4" },
		{ KEY::KEY_5, "5" },
		{ KEY::KEY_6, "6" },
		{ KEY::KEY_7, "7" },
		{ KEY::KEY_8, "8" },
		{ KEY::KEY_9, "9" },
		{ KEY::KEY_SEMICOLON, "SEMICOLON" },
		{ KEY::KEY_EQUAL, "EQUAL" },
		{ KEY::KEY_A, "A" },
		{ KEY::KEY_B, "B" },
		{ KEY::KEY_C, "C" },
		{ KEY::KEY_D, "D" },
		{ KEY::KEY_E, "E" },
		{ KEY::KEY_F, "F" },
		{ KEY::KEY_G, "G" },
		{ KEY::KEY_H, "H" },
		{ KEY::KEY_I, "I" },
		{ KEY::KEY_J, "J" },
		{ KEY::KEY_K, "K" },
		{ KEY::KEY_L, "L" },
		{ KEY::KEY_M, "M" },
		{ KEY::KEY_N, "N" },
		{ KEY::KEY_O, "O" },
		{ KEY::KEY_P, "P" },
		{ KEY::KEY_Q, "Q" },
		{ KEY::KEY_R, "R" },
		{ KEY::KEY_S, "S" },
		{ KEY::KEY_T, "T" },
		{ KEY::KEY_U, "U" },
		{ KEY::KEY_0, "V" },
		{ KEY::KEY_W, "W" },
		{ KEY::KEY_X, "X" },
		{ KEY::KEY_Y, "Y" },
		{ KEY::KEY_Z, "Z" },
		{ KEY::KEY_LEFT_BRACKET, "LEFT_BRACKET" },
		{ KEY::KEY_BACKSLASH, "BACKSLASH" },
		{ KEY::KEY_RIGHT_BRACKET, "RIGHT_BRACKET" },
		{ KEY::KEY_GRAVE_ACCENT, "GRAVE_ACCENT" },
		{ KEY::KEY_WORLD_1, "WORLD_1" },
		{ KEY::KEY_WORLD_2, "WORLD_2" },

		// Function keys
		{ KEY::KEY_ESCAPE, "ESCAPE" },
		{ KEY::KEY_ENTER, "ENTER" },
		{ KEY::KEY_TAB, "TAB" },
		{ KEY::KEY_BACKSPACE, "BACKSPACE" },
		{ KEY::KEY_INSERT, "INSERT" },
		{ KEY::KEY_DELETE, "DELETE" },
		{ KEY::KEY_RIGHT, "RIGHT" },
		{ KEY::KEY_LEFT, "LEFT" },
		{ KEY::KEY_DOWN, "DOWN" },
		{ KEY::KEY_UP, "UP" },
		{ KEY::KEY_PAGE_UP, "PAGE_UP" },
		{ KEY::KEY_PAGE_DOWN, "PAGE_DOWN" },
		{ KEY::KEY_HOME, "HOME" },
		{ KEY::KEY_END, "END" },
		{ KEY::KEY_CAPS_LOCK, "CAPS_LOCK" },
		{ KEY::KEY_SCROLL_LOCK, "SCROLL_LOCK" },
		{ KEY::KEY_NUM_LOCK, "NUM_LOCK" },
		{ KEY::KEY_PRINT_SCREEN, "PRINT_SCREEN" },
		{ KEY::KEY_PAUSE, "PAUSE" },
		{ KEY::KEY_F1, "F1" },
		{ KEY::KEY_F2, "F2" },
		{ KEY::KEY_F3, "F3" },
		{ KEY::KEY_F4, "F4" },
		{ KEY::KEY_F5, "F5" },
		{ KEY::KEY_F6, "F6" },
		{ KEY::KEY_F7, "F7" },
		{ KEY::KEY_F8, "F8" },
		{ KEY::KEY_F9, "F9" },
		{ KEY::KEY_F10, "F10" },
		{ KEY::KEY_F11, "F11" },
		{ KEY::KEY_F12, "F12" },
		{ KEY::KEY_F13, "F13" },
		{ KEY::KEY_F14, "F14" },
		{ KEY::KEY_F15, "F15" },
		{ KEY::KEY_F16, "F16" },
		{ KEY::KEY_F17, "F17" },
		{ KEY::KEY_F18, "F18" },
		{ KEY::KEY_F19, "F19" },
		{ KEY::KEY_F20, "F20" },
		{ KEY::KEY_F21, "F21" },
		{ KEY::KEY_F22, "F22" },
		{ KEY::KEY_F23, "F23" },
		{ KEY::KEY_F24, "F24" },
		{ KEY::KEY_F25, "F25" },
		{ KEY::KEY_KP_0, "KP_0" },
		{ KEY::KEY_KP_1, "KP_1" },
		{ KEY::KEY_KP_2, "KP_2" },
		{ KEY::KEY_KP_3, "KP_3" },
		{ KEY::KEY_KP_4, "KP_4" },
		{ KEY::KEY_KP_5, "KP_5" },
		{ KEY::KEY_KP_6, "KP_6" },
		{ KEY::KEY_KP_7, "KP_7" },
		{ KEY::KEY_KP_8, "KP_8" },
		{ KEY::KEY_KP_9, "KP_9" },
		{ KEY::KEY_KP_DECIMAL, "KP_DECIMAL" },
		{ KEY::KEY_KP_DIVIDE, "KP_DIVIDE" },
		{ KEY::KEY_KP_MULTIPLY, "KP_MULTIPLY" },
		{ KEY::KEY_KP_SUBTRACT, "KP_SUBTRACT" },
		{ KEY::KEY_KP_ADD, "KP_ADD" },
		{ KEY::KEY_KP_ENTER, "KP_ENTER" },
		{ KEY::KEY_KP_EQUAL, "KP_EQUAL" },
		{ KEY::KEY_LEFT_SHIFT, "LEFT_SHIFT" },
		{ KEY::KEY_LEFT_CONTROL, "LEFT_CONTROL" },
		{ KEY::KEY_LEFT_ALT, "LEFT_ALT" },
		{ KEY::KEY_LEFT_SUPER, "LEFT_SUPER" },
		{ KEY::KEY_RIGHT_SHIFT, "RIGHT_SHIFT" },
		{ KEY::KEY_RIGHT_CONTROL, "RIGHT_CONTROL" },
		{ KEY::KEY_RIGHT_ALT, "RIGHT_ALT" },
		{ KEY::KEY_RIGHT_SUPER, "RIGHT_SUPER" },
		{ KEY::KEY_MENU, "MENU" }
	};

	std::string GetKeyName(KEY keyCode)
	{
		return s_KeyNames[keyCode];
	}
}
