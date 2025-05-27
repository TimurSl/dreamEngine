#pragma once

#include <functional>

class Timer
{
public:
    /// @brief Constructs a Timer with the specified interval and callback function.
    /// @param interval The time interval in seconds between ticks.
    /// @param callback The function to call when the timer ticks.
    /// @param loop If true, the timer will repeat every interval, if false, it will only run once.
    /// @param runOnFirstTick If true, the callback will be called immediately on the first tick.
    /// @return A Timer object that can be used to manage the timer's state and behavior.
    Timer(float interval, std::function<void()> callback, bool loop = false, bool runOnFirstTick = true);

    /// @brief Updates the timer state, should be called every frame with the elapsed time since the last call.
    void Update(float deltaTime);
    /// @brief Starts the timer, resetting its state and beginning the countdown.
    void Start();
    /// @brief Stops the timer, resetting its state and stopping any further ticks.
    void Stop();
    /// @brief Pauses the timer, stopping it from ticking until resumed.
    void Pause();
    /// @brief Resumes the timer if it was paused, allowing it to continue ticking.
    void Resume();
    /// @brief Resets the timer to its initial state, starting the countdown again.
    void Reset();

    /// @brief Checks if the timer is currently paused.
    /// @returns True if the timer is paused, false otherwise.
    bool IsPaused() const;
    /// @brief Checks if the timer is currently running.
    /// @returns True if the timer is running, false otherwise.
    bool IsRunning() const;
    /// @brief Checks if the timer has finished its countdown.
    /// @returns True if the timer has finished, false otherwise.
    bool IsFinished() const;

private:
    float m_Interval;
    float m_TimeLeft;

    bool m_Loop;
    bool m_Paused;
    bool m_Running;
    bool m_RunOnFirstTick;
    bool m_FirstTick = true;

    std::function<void()> m_Callback;
};
