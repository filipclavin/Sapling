#pragma once


namespace Sapling
{
	enum class MOUSE_BTN;

	int GetGlfwMouseButtonBySaplingMouseButton(MOUSE_BTN button);
	MOUSE_BTN GetSaplingMouseButtonByGlfwMouseButton(int button);
}