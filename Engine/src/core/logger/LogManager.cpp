#include "core/logger/LogManager.h"
#include <iostream>
#include <memory>

#include "core/logger/ConsoleLogger.h"
#include "core/logger/LogLevel.h"

LogManager::LogManager() : m_Logger(std::make_shared<ConsoleLogger>()), m_CurrentLevel(LogLevel::Info) {}

LogManager& LogManager::Instance()
{
    static LogManager instance;
    return instance;
}

void LogManager::SetLogger(std::shared_ptr<Logger> logger)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Logger = logger;
}

void LogManager::SetLevel(LogLevel level)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_CurrentLevel = level;
}

void LogManager::Log(LogLevel level, const std::string& msg)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if (level < m_CurrentLevel)
        return;

    if (m_Logger)
        m_Logger->Log(level, msg);
}
