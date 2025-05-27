#pragma once

#include <memory>
#include <vector>

#include "Timer.h"

class TimerManager
{
public:
    TimerManager();

    /// @brief Adds a new timer with the specified parameters.
    /// @param interval The time interval in seconds between ticks.
    /// @param callback The function to call when the timer ticks.
    /// @param loop If true, the timer will repeat every interval, if false, it will only run once.
    /// @param runOnFirstTick If true, the callback will be called immediately on the first tick.
    /// @param startImmediately If true, the timer will start immediately after being added.
    Timer* AddTimer(float interval, std::function<void()> callback, bool loop = false, bool runOnFirstTick = false,
                    bool startImmediately = true);

    /// @brief Updates all timers, should be called every frame with the elapsed time since the last call.
    /// @param deltaTime The time elapsed since the last update in seconds.
    void Update(float deltaTime);

    /// @brief Removes a timer from the manager.
    /// @param timer Pointer to the Timer object to be removed.
    void RemoveTimer(Timer* timer);

    /// @brief Clears all timers from the manager.
    void ClearTimers();

private:
    std::vector<std::unique_ptr<Timer>> m_timers;
};
