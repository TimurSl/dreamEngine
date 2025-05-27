#include "Engine.h"

#include "core/logger/LogLevel.h"
#include "core/logger/LogManager.h"
#include "core/timer/TimeUtils.h"
#include "core/timer/TimerManager.h"


Engine::Engine() : m_IsRunning(false) {}
Engine::~Engine() {}

void Engine::Initialize()
{
    if (m_IsInitialized)
    {
        DE_LOG_WARNING("Engine is already initialized. Skipping initialization.");
        return;
    }

    m_IsInitialized = true;
    DE_LOG_INFO("Engine is initializing...");

    // Initialize components
    InitializeComponents();

    DE_LOG_INFO("Engine initialized successfully.");
}

TimerManager& Engine::GetTimerManager()
{
    if (!m_TimerManager)
    {
        DE_LOG_ERROR("TimerManager is not initialized. Call Initialize() first.");
        throw std::runtime_error("TimerManager is not initialized.");
    }
    return *m_TimerManager;
}

void Engine::InitializeComponents()
{
    DE_LOG_INFO("Initializing components...");

    // Initialize TimerManager
    m_TimerManager = new TimerManager();
    if (!m_TimerManager)
    {
        DE_LOG_ERROR("Failed to create TimerManager instance.");
        throw std::runtime_error("Failed to create TimerManager instance.");
    }
    DE_LOG_INFO("TimerManager initialized successfully.");

    // Additional components can be initialized here

    DE_LOG_INFO("All components initialized successfully.");
}

void Engine::Run()
{
    if (!m_IsInitialized)
    {
        DE_LOG_ERROR("Engine is not initialized. Call Initialize() first.");
        Shutdown();
        throw std::runtime_error("Engine is not initialized.");
    }

    DE_LOG_INFO("Starting Engine...");
    m_IsRunning = true;
    DE_LOG_INFO("Engine started.");

    DE_LOG_INFO("Starting main loop...");
    float prevTime = TimeUtils::GetCurrentTime();
    while (m_IsRunning)
    {
        float now = TimeUtils::GetCurrentTime();
        float deltaTime = now - prevTime;
        prevTime = now;

        m_TimerManager->Update(deltaTime);
    }
    DE_LOG_INFO("Main loop ended.");
}
void Engine::Shutdown()
{
    DE_LOG_INFO("Shutting down Engine...");

    if (m_TimerManager)
    {
        delete m_TimerManager;
        m_TimerManager = nullptr;
        DE_LOG_INFO("TimerManager instance deleted.");
    }

    DE_LOG_INFO("Engine shutdown complete.");
    m_IsRunning = false;
}
