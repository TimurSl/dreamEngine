#pragma once

#include <string>

enum class LogLevel;

class Logger
{
public:
    virtual ~Logger() = default;

    virtual void Log(LogLevel level, const std::string& msg) = 0;
};
