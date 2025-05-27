#pragma once

#include <functional>

class Timer
{
public:
    Timer(float interval, std::function<void()> callback, bool loop = false, bool runOnFirstTick = true);

    void Update(float deltaTime);
    void Start();
    void Stop();
    void Pause();
    void Resume();
    void Reset();

    bool IsPaused() const;
    bool IsRunning() const;
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
