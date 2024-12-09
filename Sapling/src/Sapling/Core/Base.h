#pragma once

#ifdef SAP_PLATFORM_WINDOWS
	#ifdef SAP_BUILD_DLL
		#define SAPLING_API __declspec(dllexport)
	#else
		#define SAPLING_API __declspec(dllimport)
	#endif
#else
	#error Sapling only supports Windows!
#endif

#include <cstdint>

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
