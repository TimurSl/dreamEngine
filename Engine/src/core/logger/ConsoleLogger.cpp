#include "core/logger/ConsoleLogger.h"
#include "core/logger/ConsoleLogger.h"
#include <iostream>
#include <mutex>
#include <time.h>

#include "core/logger/LogLevel.h"

namespace DreamEngine::Core::Logger {

    void ConsoleLogger::Log(LogLevel level, const std::string& msg) {
        std::lock_guard<std::mutex> lock(mutex);
        // Префиксы для уровней
        const char* levelStr = "";
        switch (level) {
        case LogLevel::Trace:   levelStr = "[Trace] ";   break;
        case LogLevel::Debug:   levelStr = "[Debug] ";   break;
        case LogLevel::Info:    levelStr = "[Info] ";    break;
        case LogLevel::Warning: levelStr = "[Warning] "; break;
        case LogLevel::Error:   levelStr = "[Error] ";   break;
        case LogLevel::Fatal:   levelStr = "[Fatal] ";   break;
        }

        // current time
        time_t now = time(nullptr);
        struct tm* timeinfo = localtime(&now);
        char timeBuffer[80];
        strftime(timeBuffer, sizeof(timeBuffer), "[%Y-%m-%d %H:%M:%S] ", timeinfo);

        std::cout << timeBuffer << levelStr << msg << std::endl;
    }

} // namespace DreamEngine::Core::Logger
