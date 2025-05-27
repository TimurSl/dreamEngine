#pragma once

#include <memory>
#include <mutex>
#include "core/logger/Logger.h"

/// @brief Logging macros for trace level.
#define DE_LOG_TRACE(msg) LogManager::Instance().Log(LogLevel::Trace, msg)
/// @brief Logging macros for debug level.
#define DE_LOG_DEBUG(msg) LogManager::Instance().Log(LogLevel::Debug, msg)
/// @brief Logging macros for info level.
#define DE_LOG_INFO(msg) LogManager::Instance().Log(LogLevel::Info, msg)
/// @brief Logging macros for warning level.
#define DE_LOG_WARNING(msg) LogManager::Instance().Log(LogLevel::Warning, msg)
/// @brief Logging macros for error level.
#define DE_LOG_ERROR(msg) LogManager::Instance().Log(LogLevel::Error, msg)
/// @brief Logging macros for fatal level.
#define DE_LOG_FATAL(msg) LogManager::Instance().Log(LogLevel::Fatal, msg)

enum class LogLevel;

class LogManager
{
public:
    /// @brief Returns the singleton instance of LogManager.
    /// @return Reference to the LogManager instance.
    static LogManager& Instance();

    /// @brief Sets the logger to be used by the LogManager.
    void SetLogger(std::shared_ptr<Logger> logger);
    /// @brief Sets the current log level for the LogManager.
    void SetLevel(LogLevel level);
    /// @brief Logs a message with the specified log level.
    void Log(LogLevel level, const std::string& msg);

private:
    LogManager();
    std::shared_ptr<Logger> m_Logger;
    LogLevel m_CurrentLevel;
    std::mutex m_Mutex;
};
