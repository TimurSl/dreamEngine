#pragma once


class TimerManager;

class Engine
{
public:
    /// @brief Constructor for the Engine class.
    Engine();
    /// @brief Destructor for the Engine class.
    ~Engine();

    /// @brief Initializes the engine, setting up necessary components.
    void Initialize();
    /// @brief Starts the engine and enters the main loop.
    void Run();
    /// @brief Shuts down the engine, cleaning up resources.
    void Shutdown();

    /// @brief Gets the TimerManager instance.
    /// @returns A reference to the TimerManager instance.
    TimerManager& GetTimerManager();

private:
    void InitializeComponents();
    bool m_IsRunning;
    bool m_IsInitialized = false;
    TimerManager* m_TimerManager;

};