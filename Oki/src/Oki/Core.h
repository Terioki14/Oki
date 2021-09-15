#pragma once

#ifdef OKI_PLATFORM_WINDOWS
	#ifdef OKI_BUILD_DLL
		#define OKI_API __declspec(dllexport)
	#else
		#define OKI_API __declspec(dllimport)
	#endif
#else 
	#error Oki only supports Windows!
#endif