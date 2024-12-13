#include "sappch.h"
#include "Platform/GLFW/GLFWKeyCodes.h"

#include "Sapling/Core/KeyCodes.h"

#include <GLFW/glfw3.h>

namespace Sapling
{
	std::unordered_map<KEY, int> s_KeyMap =
	{
		{ KEY::KEY_UNKNOWN, GLFW_KEY_UNKNOWN },

		// Printable keys
		{ KEY::KEY_SPACE, GLFW_KEY_SPACE },
		{ KEY::KEY_APOSTROPHE, GLFW_KEY_APOSTROPHE },
		{ KEY::KEY_COMMA, GLFW_KEY_COMMA },
		{ KEY::KEY_MINUS, GLFW_KEY_MINUS },
		{ KEY::KEY_PERIOD, GLFW_KEY_PERIOD },
		{ KEY::KEY_SLASH, GLFW_KEY_SLASH },
		{ KEY::KEY_0, GLFW_KEY_0 },
		{ KEY::KEY_1, GLFW_KEY_1 },
		{ KEY::KEY_2, GLFW_KEY_2 },
		{ KEY::KEY_3, GLFW_KEY_3 },
		{ KEY::KEY_4, GLFW_KEY_4 },
		{ KEY::KEY_5, GLFW_KEY_5 },
		{ KEY::KEY_6, GLFW_KEY_6 },
		{ KEY::KEY_7, GLFW_KEY_7 },
		{ KEY::KEY_8, GLFW_KEY_8 },
		{ KEY::KEY_9, GLFW_KEY_9 },
		{ KEY::KEY_SEMICOLON, GLFW_KEY_SEMICOLON },
		{ KEY::KEY_EQUAL, GLFW_KEY_EQUAL },
		{ KEY::KEY_A, GLFW_KEY_A },
		{ KEY::KEY_B, GLFW_KEY_B },
		{ KEY::KEY_C, GLFW_KEY_C },
		{ KEY::KEY_D, GLFW_KEY_D },
		{ KEY::KEY_E, GLFW_KEY_E },
		{ KEY::KEY_F, GLFW_KEY_F },
		{ KEY::KEY_G, GLFW_KEY_G },
		{ KEY::KEY_H, GLFW_KEY_H },
		{ KEY::KEY_I, GLFW_KEY_I },
		{ KEY::KEY_J, GLFW_KEY_J },
		{ KEY::KEY_K, GLFW_KEY_K },
		{ KEY::KEY_L, GLFW_KEY_L },
		{ KEY::KEY_M, GLFW_KEY_M },
		{ KEY::KEY_N, GLFW_KEY_N },
		{ KEY::KEY_O, GLFW_KEY_O },
		{ KEY::KEY_P, GLFW_KEY_P },
		{ KEY::KEY_Q, GLFW_KEY_Q },
		{ KEY::KEY_R, GLFW_KEY_R },
		{ KEY::KEY_S, GLFW_KEY_S },
		{ KEY::KEY_T, GLFW_KEY_T },
		{ KEY::KEY_U, GLFW_KEY_U },
		{ KEY::KEY_V, GLFW_KEY_V },
		{ KEY::KEY_W, GLFW_KEY_W },
		{ KEY::KEY_X, GLFW_KEY_X },
		{ KEY::KEY_Y, GLFW_KEY_Y },
		{ KEY::KEY_Z, GLFW_KEY_Z },
		{ KEY::KEY_LEFT_BRACKET, GLFW_KEY_LEFT_BRACKET },
		{ KEY::KEY_BACKSLASH, GLFW_KEY_BACKSLASH },
		{ KEY::KEY_RIGHT_BRACKET, GLFW_KEY_RIGHT_BRACKET },
		{ KEY::KEY_GRAVE_ACCENT, GLFW_KEY_GRAVE_ACCENT },
		{ KEY::KEY_WORLD_1, GLFW_KEY_WORLD_1 },
		{ KEY::KEY_WORLD_2, GLFW_KEY_WORLD_2 },

		// Function keys
		{ KEY::KEY_ESCAPE, GLFW_KEY_ESCAPE },
		{ KEY::KEY_ENTER, GLFW_KEY_ENTER },
		{ KEY::KEY_TAB, GLFW_KEY_TAB },
		{ KEY::KEY_BACKSPACE, GLFW_KEY_BACKSPACE },
		{ KEY::KEY_INSERT, GLFW_KEY_INSERT },
		{ KEY::KEY_DELETE, GLFW_KEY_DELETE },
		{ KEY::KEY_RIGHT, GLFW_KEY_RIGHT },
		{ KEY::KEY_LEFT, GLFW_KEY_LEFT },
		{ KEY::KEY_DOWN, GLFW_KEY_DOWN },
		{ KEY::KEY_UP, GLFW_KEY_UP },
		{ KEY::KEY_PAGE_UP, GLFW_KEY_PAGE_UP },
		{ KEY::KEY_PAGE_DOWN, GLFW_KEY_PAGE_DOWN },
		{ KEY::KEY_HOME, GLFW_KEY_HOME },
		{ KEY::KEY_END, GLFW_KEY_END },
		{ KEY::KEY_CAPS_LOCK, GLFW_KEY_CAPS_LOCK },
		{ KEY::KEY_SCROLL_LOCK, GLFW_KEY_SCROLL_LOCK },
		{ KEY::KEY_NUM_LOCK, GLFW_KEY_NUM_LOCK },
		{ KEY::KEY_PRINT_SCREEN, GLFW_KEY_PRINT_SCREEN },
		{ KEY::KEY_PAUSE, GLFW_KEY_PAUSE },
		{ KEY::KEY_F1, GLFW_KEY_F1 },
		{ KEY::KEY_F2, GLFW_KEY_F2 },
		{ KEY::KEY_F3, GLFW_KEY_F3 },
		{ KEY::KEY_F4, GLFW_KEY_F4 },
		{ KEY::KEY_F5, GLFW_KEY_F5 },
		{ KEY::KEY_F6, GLFW_KEY_F6 },
		{ KEY::KEY_F7, GLFW_KEY_F7 },
		{ KEY::KEY_F8, GLFW_KEY_F8 },
		{ KEY::KEY_F9, GLFW_KEY_F9 },
		{ KEY::KEY_F10, GLFW_KEY_F10 },
		{ KEY::KEY_F11, GLFW_KEY_F11 },
		{ KEY::KEY_F12, GLFW_KEY_F12 },
		{ KEY::KEY_F13, GLFW_KEY_F13 },
		{ KEY::KEY_F14, GLFW_KEY_F14 },
		{ KEY::KEY_F15, GLFW_KEY_F15 },
		{ KEY::KEY_F16, GLFW_KEY_F16 },
		{ KEY::KEY_F17, GLFW_KEY_F17 },
		{ KEY::KEY_F18, GLFW_KEY_F18 },
		{ KEY::KEY_F19, GLFW_KEY_F19 },
		{ KEY::KEY_F20, GLFW_KEY_F20 },
		{ KEY::KEY_F21, GLFW_KEY_F21 },
		{ KEY::KEY_F22, GLFW_KEY_F22 },
		{ KEY::KEY_F23, GLFW_KEY_F23 },
		{ KEY::KEY_F24, GLFW_KEY_F24 },
		{ KEY::KEY_F25, GLFW_KEY_F25 },
		{ KEY::KEY_KP_0, GLFW_KEY_KP_0 },
		{ KEY::KEY_KP_1, GLFW_KEY_KP_1 },
		{ KEY::KEY_KP_2, GLFW_KEY_KP_2 },
		{ KEY::KEY_KP_3, GLFW_KEY_KP_3 },
		{ KEY::KEY_KP_4, GLFW_KEY_KP_4 },
		{ KEY::KEY_KP_5, GLFW_KEY_KP_5 },
		{ KEY::KEY_KP_6, GLFW_KEY_KP_6 },
		{ KEY::KEY_KP_7, GLFW_KEY_KP_7 },
		{ KEY::KEY_KP_8, GLFW_KEY_KP_8 },
		{ KEY::KEY_KP_9, GLFW_KEY_KP_9 },
		{ KEY::KEY_KP_DECIMAL, GLFW_KEY_KP_DECIMAL },
		{ KEY::KEY_KP_DIVIDE, GLFW_KEY_KP_DIVIDE },
		{ KEY::KEY_KP_MULTIPLY, GLFW_KEY_KP_MULTIPLY },
		{ KEY::KEY_KP_SUBTRACT, GLFW_KEY_KP_SUBTRACT },
		{ KEY::KEY_KP_ADD, GLFW_KEY_KP_ADD },
		{ KEY::KEY_KP_ENTER, GLFW_KEY_KP_ENTER },
		{ KEY::KEY_KP_EQUAL, GLFW_KEY_KP_EQUAL },
		{ KEY::KEY_LEFT_SHIFT, GLFW_KEY_LEFT_SHIFT },
		{ KEY::KEY_LEFT_CONTROL, GLFW_KEY_LEFT_CONTROL },
		{ KEY::KEY_LEFT_ALT, GLFW_KEY_LEFT_ALT },
		{ KEY::KEY_LEFT_SUPER, GLFW_KEY_LEFT_SUPER },
		{ KEY::KEY_RIGHT_SHIFT, GLFW_KEY_RIGHT_SHIFT },
		{ KEY::KEY_RIGHT_CONTROL, GLFW_KEY_RIGHT_CONTROL },
		{ KEY::KEY_RIGHT_ALT, GLFW_KEY_RIGHT_ALT },
		{ KEY::KEY_RIGHT_SUPER, GLFW_KEY_RIGHT_SUPER },
		{ KEY::KEY_MENU, GLFW_KEY_MENU },

		{ KEY::KEY_LAST, GLFW_KEY_LAST }
	};

	std::unordered_map<int, KEY> s_KeyMapReverse =
	{
		{ GLFW_KEY_UNKNOWN, KEY::KEY_UNKNOWN },

		// Printable keys
		{ GLFW_KEY_SPACE, KEY::KEY_SPACE },
		{ GLFW_KEY_APOSTROPHE, KEY::KEY_APOSTROPHE },
		{ GLFW_KEY_COMMA, KEY::KEY_COMMA },
		{ GLFW_KEY_MINUS, KEY::KEY_MINUS },
		{ GLFW_KEY_PERIOD, KEY::KEY_PERIOD },
		{ GLFW_KEY_SLASH, KEY::KEY_SLASH },
		{ GLFW_KEY_0, KEY::KEY_0 },
		{ GLFW_KEY_1, KEY::KEY_1 },
		{ GLFW_KEY_2, KEY::KEY_2 },
		{ GLFW_KEY_3, KEY::KEY_3 },
		{ GLFW_KEY_4, KEY::KEY_4 },
		{ GLFW_KEY_5, KEY::KEY_5 },
		{ GLFW_KEY_6, KEY::KEY_6 },
		{ GLFW_KEY_7, KEY::KEY_7 },
		{ GLFW_KEY_8, KEY::KEY_8 },
		{ GLFW_KEY_9, KEY::KEY_9 },
		{ GLFW_KEY_SEMICOLON, KEY::KEY_SEMICOLON },
		{ GLFW_KEY_EQUAL, KEY::KEY_EQUAL },
		{ GLFW_KEY_A, KEY::KEY_A },
		{ GLFW_KEY_B, KEY::KEY_B },
		{ GLFW_KEY_C, KEY::KEY_C },
		{ GLFW_KEY_D, KEY::KEY_D },
		{ GLFW_KEY_E, KEY::KEY_E },
		{ GLFW_KEY_F, KEY::KEY_F },
		{ GLFW_KEY_G, KEY::KEY_G },
		{ GLFW_KEY_H, KEY::KEY_H },
		{ GLFW_KEY_I, KEY::KEY_I },
		{ GLFW_KEY_J, KEY::KEY_J },
		{ GLFW_KEY_K, KEY::KEY_K },
		{ GLFW_KEY_L, KEY::KEY_L },
		{ GLFW_KEY_M, KEY::KEY_M },
		{ GLFW_KEY_N, KEY::KEY_N },
		{ GLFW_KEY_O, KEY::KEY_O },
		{ GLFW_KEY_P, KEY::KEY_P },
		{ GLFW_KEY_Q, KEY::KEY_Q },
		{ GLFW_KEY_R, KEY::KEY_R },
		{ GLFW_KEY_S, KEY::KEY_S },
		{ GLFW_KEY_T, KEY::KEY_T },
		{ GLFW_KEY_U, KEY::KEY_U },
		{ GLFW_KEY_V, KEY::KEY_V },
		{ GLFW_KEY_W, KEY::KEY_W },
		{ GLFW_KEY_X, KEY::KEY_X },
		{ GLFW_KEY_Y, KEY::KEY_Y },
		{ GLFW_KEY_Z, KEY::KEY_Z },
		{ GLFW_KEY_LEFT_BRACKET, KEY::KEY_LEFT_BRACKET },
		{ GLFW_KEY_BACKSLASH, KEY::KEY_BACKSLASH },
		{ GLFW_KEY_RIGHT_BRACKET, KEY::KEY_RIGHT_BRACKET },
		{ GLFW_KEY_GRAVE_ACCENT, KEY::KEY_GRAVE_ACCENT },
		{ GLFW_KEY_WORLD_1, KEY::KEY_WORLD_1 },
		{ GLFW_KEY_WORLD_2, KEY::KEY_WORLD_2 },

		// Function keys
		{ GLFW_KEY_ESCAPE, KEY::KEY_ESCAPE },
		{ GLFW_KEY_ENTER, KEY::KEY_ENTER },
		{ GLFW_KEY_TAB, KEY::KEY_TAB },
		{ GLFW_KEY_BACKSPACE, KEY::KEY_BACKSPACE },
		{ GLFW_KEY_INSERT, KEY::KEY_INSERT },
		{ GLFW_KEY_DELETE, KEY::KEY_DELETE },
		{ GLFW_KEY_RIGHT, KEY::KEY_RIGHT },
		{ GLFW_KEY_LEFT, KEY::KEY_LEFT },
		{ GLFW_KEY_DOWN, KEY::KEY_DOWN },
		{ GLFW_KEY_UP, KEY::KEY_UP },
		{ GLFW_KEY_PAGE_UP, KEY::KEY_PAGE_UP },
		{ GLFW_KEY_PAGE_DOWN, KEY::KEY_PAGE_DOWN },
		{ GLFW_KEY_HOME, KEY::KEY_HOME },
		{ GLFW_KEY_END, KEY::KEY_END },
		{ GLFW_KEY_CAPS_LOCK, KEY::KEY_CAPS_LOCK },
		{ GLFW_KEY_SCROLL_LOCK, KEY::KEY_SCROLL_LOCK },
		{ GLFW_KEY_NUM_LOCK, KEY::KEY_NUM_LOCK },
		{ GLFW_KEY_PRINT_SCREEN, KEY::KEY_PRINT_SCREEN },
		{ GLFW_KEY_PAUSE, KEY::KEY_PAUSE },
		{ GLFW_KEY_F1, KEY::KEY_F1 },
		{ GLFW_KEY_F2, KEY::KEY_F2 },
		{ GLFW_KEY_F3, KEY::KEY_F3 },
		{ GLFW_KEY_F4, KEY::KEY_F4 },
		{ GLFW_KEY_F5, KEY::KEY_F5 },
		{ GLFW_KEY_F6, KEY::KEY_F6 },
		{ GLFW_KEY_F7, KEY::KEY_F7 },
		{ GLFW_KEY_F8, KEY::KEY_F8 },
		{ GLFW_KEY_F9, KEY::KEY_F9 },
		{ GLFW_KEY_F10, KEY::KEY_F10 },
		{ GLFW_KEY_F11, KEY::KEY_F11 },
		{ GLFW_KEY_F12, KEY::KEY_F12 },
		{ GLFW_KEY_F13, KEY::KEY_F13 },
		{ GLFW_KEY_F14, KEY::KEY_F14 },
		{ GLFW_KEY_F15, KEY::KEY_F15 },
		{ GLFW_KEY_F16, KEY::KEY_F16 },
		{ GLFW_KEY_F17, KEY::KEY_F17 },
		{ GLFW_KEY_F18, KEY::KEY_F18 },
		{ GLFW_KEY_F19, KEY::KEY_F19 },
		{ GLFW_KEY_F20, KEY::KEY_F20 },
		{ GLFW_KEY_F21, KEY::KEY_F21 },
		{ GLFW_KEY_F22, KEY::KEY_F22 },
		{ GLFW_KEY_F23, KEY::KEY_F23 },
		{ GLFW_KEY_F24, KEY::KEY_F24 },
		{ GLFW_KEY_F25, KEY::KEY_F25 },
		{ GLFW_KEY_KP_0, KEY::KEY_KP_0 },
		{ GLFW_KEY_KP_1, KEY::KEY_KP_1 },
		{ GLFW_KEY_KP_2, KEY::KEY_KP_2 },
		{ GLFW_KEY_KP_3, KEY::KEY_KP_3 },
		{ GLFW_KEY_KP_4, KEY::KEY_KP_4 },
		{ GLFW_KEY_KP_5, KEY::KEY_KP_5 },
		{ GLFW_KEY_KP_6, KEY::KEY_KP_6 },
		{ GLFW_KEY_KP_7, KEY::KEY_KP_7 },
		{ GLFW_KEY_KP_8, KEY::KEY_KP_8 },
		{ GLFW_KEY_KP_9, KEY::KEY_KP_9 },
		{ GLFW_KEY_KP_DECIMAL, KEY::KEY_KP_DECIMAL },
		{ GLFW_KEY_KP_DIVIDE, KEY::KEY_KP_DIVIDE },
		{ GLFW_KEY_KP_MULTIPLY, KEY::KEY_KP_MULTIPLY },
		{ GLFW_KEY_KP_SUBTRACT, KEY::KEY_KP_SUBTRACT },
		{ GLFW_KEY_KP_ADD, KEY::KEY_KP_ADD },
		{ GLFW_KEY_KP_ENTER, KEY::KEY_KP_ENTER },
		{ GLFW_KEY_KP_EQUAL, KEY::KEY_KP_EQUAL },
		{ GLFW_KEY_LEFT_SHIFT, KEY::KEY_LEFT_SHIFT },
		{ GLFW_KEY_LEFT_CONTROL, KEY::KEY_LEFT_CONTROL },
		{ GLFW_KEY_LEFT_ALT, KEY::KEY_LEFT_ALT },
		{ GLFW_KEY_LEFT_SUPER, KEY::KEY_LEFT_SUPER },
		{ GLFW_KEY_RIGHT_SHIFT, KEY::KEY_RIGHT_SHIFT },
		{ GLFW_KEY_RIGHT_CONTROL, KEY::KEY_RIGHT_CONTROL },
		{ GLFW_KEY_RIGHT_ALT, KEY::KEY_RIGHT_ALT },
		{ GLFW_KEY_RIGHT_SUPER, KEY::KEY_RIGHT_SUPER },
		{ GLFW_KEY_MENU, KEY::KEY_MENU },
		{ GLFW_KEY_LAST, KEY::KEY_LAST }
	};

	int GetGlfwKeyBySaplingKey(KEY key)
	{
		return s_KeyMap[key];
	}

	KEY GetSaplingKeyByGlfwKey(int key)
	{
		return s_KeyMapReverse[key];
	}
}