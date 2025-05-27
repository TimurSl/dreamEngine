#pragma once

#include <string>

namespace DreamEngine::Core::Logger
{
    enum class LogLevel;

    class Logger
    {
    public:
        virtual ~Logger() = default;

        virtual void Log(LogLevel level, const std::string& msg) = 0;
    };

} // namespace DreamEngine::Core::Logger
