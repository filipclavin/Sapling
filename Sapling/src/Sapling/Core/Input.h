#pragma once

#include "KeyCodes.h"
#include "MouseButtonCodes.h"

#include <glm/vec2.hpp>

namespace Sapling
{
	class Input
	{
	public:
		static bool IsKeyPressed(KEY keycode) { return s_instance->IsKeyPressedImpl(keycode); }

		static bool IsMouseButtonPressed(MOUSE_BTN button) { return s_instance->IsMouseButtonPressedImpl(button); }
		inline static glm::vec2 GetMousePosition() { return s_instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_instance->GetMousePositionImpl().x; }
		inline static float GetMouseY() { return s_instance->GetMousePositionImpl().y; }

	protected:
		virtual bool IsKeyPressedImpl(KEY keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(MOUSE_BTN button) = 0;
		virtual glm::vec2 GetMousePositionImpl() = 0;

	private:
		static Input* s_instance;
	};
}