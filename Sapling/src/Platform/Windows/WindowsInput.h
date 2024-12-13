#pragma once

#include "Sapling/Core/Input.h"

enum class KEY;
enum class MOUSE_BTN;

namespace Sapling
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(KEY keycode) override;

		virtual bool IsMouseButtonPressedImpl(MOUSE_BTN button) override;
		virtual glm::vec2 GetMousePositionImpl() override;
	};
}