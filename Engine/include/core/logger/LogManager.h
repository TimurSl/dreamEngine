#pragma once

#include "core/logger/Logger.h"
#include <memory>
#include <mutex>

#define DE_LOG_TRACE(msg)   ::DreamEngine::Core::Logger::LogManager::Instance().Log(::DreamEngine::Core::Logger::LogLevel::Trace,   msg)
#define DE_LOG_DEBUG(msg)   ::DreamEngine::Core::Logger::LogManager::Instance().Log(::DreamEngine::Core::Logger::LogLevel::Debug,   msg)
#define DE_LOG_INFO(msg)    ::DreamEngine::Core::Logger::LogManager::Instance().Log(::DreamEngine::Core::Logger::LogLevel::Info,    msg)
#define DE_LOG_WARNING(msg) ::DreamEngine::Core::Logger::LogManager::Instance().Log(::DreamEngine::Core::Logger::LogLevel::Warning, msg)
#define DE_LOG_ERROR(msg)   ::DreamEngine::Core::Logger::LogManager::Instance().Log(::DreamEngine::Core::Logger::LogLevel::Error,   msg)
#define DE_LOG_FATAL(msg)   ::DreamEngine::Core::Logger::LogManager::Instance().Log(::DreamEngine::Core::Logger::LogLevel::Fatal,   msg)

namespace DreamEngine::Core::Logger {enum class LogLevel;

    class LogManager {
    public:
        static LogManager& Instance();

        void SetLogger(std::shared_ptr<Logger> logger);
        void SetLevel(LogLevel level);
        void Log(LogLevel level, const std::string& msg);

    private:
        LogManager();
        std::shared_ptr<Logger> m_Logger;
        LogLevel m_CurrentLevel;
        std::mutex m_Mutex;
    };

} // namespace DreamEngine::Core::Logger
