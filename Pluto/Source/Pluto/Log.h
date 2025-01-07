#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pluto
{
	class PLUTO_API Log
	{
	public:
		/**
		 * @brief Instantiate the log.
		 * 
		 * Instantiates both the Core and the Client logger.
		 */
		static void Init();

		/**
		 * @brief Get the Core logger.
		 * 
		 * The Core logger is only meant for usage within Pluto Engine itself.
		 * For logging through client applications, r efer to the Client logger.
		 * 
		 * @see GetClientLogger
		 * @return A reference to the Core logger.
		 */
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };

		/**
		 * @brief Get the Client logger.
		 * 
		 * The Client logger is meant for usage from client application using the Pluto Engine.
		 * 
		 * @return A reference to the Client logger.
		 */
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		/** @brief The Core logger instance. */
		static std::shared_ptr<spdlog::logger> s_CoreLogger;

		/** @brief The Client logger instance. */
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// We're using macros for logging so we don't have to type Pluto::Log::GetCoreLogger, etc.
// Furthermore, we're able to remove the logging macros from dest builds simply by doing:
// #define PLUTO_ERROR

// Core log macros
#define PLUTO_CORE_TRACE(...)     ::Pluto::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define PLUTO_CORE_INFO(...)      ::Pluto::Log::GetCoreLogger()->info(__VA_ARGS__);
#define PLUTO_CORE_WARN(...)      ::Pluto::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define PLUTO_CORE_ERROR(...)     ::Pluto::Log::GetCoreLogger()->error(__VA_ARGS__);
#define PLUTO_CORE_CRIT(...)      ::Pluto::Log::GetCoreLogger()->critical(__VA_ARGS__);
							      
// Client log macros		      
#define PLUTO_TRACE(...)          ::Pluto::Log::GetClientLogger()->trace(__VA_ARGS__);
#define PLUTO_INFO(...)           ::Pluto::Log::GetClientLogger()->info(__VA_ARGS__);
#define PLUTO_WARN(...)           ::Pluto::Log::GetClientLogger()->warn(__VA_ARGS__);
#define PLUTO_ERROR(...)          ::Pluto::Log::GetClientLogger()->error(__VA_ARGS__);
#define PLUTO_CRIT(...)           ::Pluto::Log::GetClientLogger()->critical(__VA_ARGS__);