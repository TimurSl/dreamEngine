#pragma once

#include <vector>
#include <memory>

#include "Timer.h"

class TimerManager
{
public:
    TimerManager();

    Timer* AddTimer(float interval, std::function<void()> callback, bool loop = false, bool runOnFirstTick = false, bool startImmediately = true);
    void Update(float deltaTime);

    void RemoveTimer(Timer* timer);
    void ClearTimers();

private:
    std::vector<std::unique_ptr<Timer>> m_timers;
};