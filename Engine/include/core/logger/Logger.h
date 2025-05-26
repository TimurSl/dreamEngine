#pragma once

#include <string>

namespace DreamEngine::Core::Logger {
    enum class LogLevel;

    class Logger {
    public:
        virtual ~Logger() = default;

        /// @brief Logs a message with the specified log level.
        /// @param level The log level of the message.
        /// @paran msg The message to log.
        virtual void Log(LogLevel level, const std::string& msg) = 0;
    };

} // namespace DreamEngine::Core::Logger
