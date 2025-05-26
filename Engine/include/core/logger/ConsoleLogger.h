#pragma once

#include "core/logger/Logger.h"
#include <mutex>

namespace DreamEngine::Core::Logger {
enum class LogLevel;}namespace DreamEngine::Core::Logger
{
    class ConsoleLogger : public Logger
    {
    public:
        void Log(LogLevel level, const std::string& msg) override;

    private:
        std::mutex mutex;
    };
}