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

#ifdef OKI_DEBUG
	#define OKI_ENABLE_ASSERTS
#endif

#ifdef OKI_ENABLE_ASSERTS
	#define OKI_ASSERT(x, ...) {if(!(x)) {OKI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define OKI_CORE_ASSERT(x, ...) {if(!(x)) {OKI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define OKI_ASSERT(x, ...)
	#define OKI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define OKI_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)