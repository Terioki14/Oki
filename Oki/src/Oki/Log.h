#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Oki 
{

	class OKI_API Log
	{
	public:
		static void init();
		
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define OKI_CORE_TRACE(...)   Oki::Log::getCoreLogger()->trace(__VA_ARGS__)
#define OKI_CORE_INFO(...)    Oki::Log::getCoreLogger()->info(__VA_ARGS__)
#define OKI_CORE_WARN(...)    Oki::Log::getCoreLogger()->warn(__VA_ARGS__)
#define OKI_CORE_ERROR(...)   Oki::Log::getCoreLogger()->error(__VA_ARGS__)
#define OKI_CORE_FATAL(...)   Oki::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define OKI_TRACE(...)        Oki::Log::getClientLogger()->trace(__VA_ARGS__)
#define OKI_INFO(...)         Oki::Log::getClientLogger()->info(__VA_ARGS__)
#define OKI_WARN(...)         Oki::Log::getClientLogger()->warn(__VA_ARGS__)
#define OKI_ERROR(...)        Oki::Log::getClientLogger()->error(__VA_ARGS__)
#define OKI_FATAL(...)        Oki::Log::getClientLogger()->fatal(__VA_ARGS__)