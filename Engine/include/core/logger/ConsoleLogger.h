#pragma once

#include <mutex>
#include "core/logger/Logger.h"

enum class LogLevel;

class ConsoleLogger : public Logger
{
public:
    void Log(LogLevel level, const std::string& msg) override;

private:
    std::mutex mutex;
};
