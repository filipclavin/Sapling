#pragma once

#ifdef WIN32
#else
	#error Sapling only supports Windows!
#endif

#include <cstdint>

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
