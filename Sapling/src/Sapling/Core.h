#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SAPLING_API __declspec(dllexport)
	#else
		#define SAPLING_API __declspec(dllimport)
	#endif
#else
	#error Sapling only supports Windows!
#endif
