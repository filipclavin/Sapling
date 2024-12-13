#pragma once

namespace Sapling
{
	enum class KEY;

	int GetGlfwKeyBySaplingKey(KEY key);
	KEY GetSaplingKeyByGlfwKey(int key);
}
