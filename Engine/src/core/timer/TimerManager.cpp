#include "core/timer/TimerManager.h"

#include "core/logger/LogLevel.h"
#include "core/logger/LogManager.h"

TimerManager::TimerManager() {}

Timer* TimerManager::AddTimer(float interval, std::function<void()> callback, bool loop, bool runOnFirstTick,
                              bool startImmediately)
{
    if (interval <= 0.0f)
    {
        throw std::invalid_argument("Interval must be greater than zero.");
    }
    if (!callback)
    {
        throw std::invalid_argument("Callback function cannot be null.");
    }

    auto timer = std::make_unique<Timer>(interval, std::move(callback), loop, runOnFirstTick);
    Timer* timerPtr = timer.get();
    m_timers.push_back(std::move(timer));

    if (startImmediately)
    {
        timerPtr->Start();
    }
    else
    {
        timerPtr->Reset();
    }

    return timerPtr;
}

void TimerManager::RemoveTimer(Timer* timer)
{
    auto it = std::remove_if(m_timers.begin(), m_timers.end(),
                             [timer](const std::unique_ptr<Timer>& t) { return t.get() == timer; });

    if (it != m_timers.end())
    {
        m_timers.erase(it, m_timers.end());
    }
    else
    {
        throw std::runtime_error("Timer not found in TimerManager.");
    }
}

void TimerManager::ClearTimers() { m_timers.clear(); }

void TimerManager::Update(float deltaTime)
{
    DE_LOG_TRACE("TimerManager::Update, timers count: " + std::to_string(m_timers.size()) +
                 ", deltaTime: " + std::to_string(deltaTime));
    for (auto it = m_timers.begin(); it != m_timers.end();)
    {
        (*it)->Update(deltaTime);
        if ((*it)->IsFinished())
        {
            it = m_timers.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
