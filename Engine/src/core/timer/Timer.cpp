//
// Created by Tymur on 5/27/2025.
//

#include "core/timer/Timer.h"

#include "core/logger/LogLevel.h"
#include "core/logger/LogManager.h"

Timer::Timer(float interval, std::function<void()> callback, bool loop, bool runOnFirstTick) :
    m_Interval(interval), m_TimeLeft(interval), m_Loop(loop), m_Paused(false), m_Running(false),
    m_RunOnFirstTick(runOnFirstTick), m_FirstTick(true), m_Callback(std::move(callback))

{
}

void Timer::Start()
{
    m_TimeLeft = m_Interval;
    m_Paused = false;
    m_Running = true;
    m_FirstTick = true;
}

void Timer::Stop()
{
    m_Running = false;
    m_TimeLeft = m_Interval;
    m_Paused = false;
    m_FirstTick = true;
}

void Timer::Pause()
{
    if (!m_Running || m_Paused)
    {
        return;
    }
    m_Paused = true;
}

void Timer::Resume()
{
    if (!m_Running || !m_Paused)
    {
        return;
    }
    m_Paused = false;
}

void Timer::Reset() { Start(); }

bool Timer::IsPaused() const { return m_Paused; }

void Timer::Update(float deltaTime)
{
    DE_LOG_TRACE("Updating Timer");
    if (!m_Running || m_Paused)
    {
        return;
    }
    if (m_FirstTick && m_RunOnFirstTick)
    {
        m_FirstTick = false;
        if (m_Callback)
        {
            m_Callback();
        }

        if (!m_Loop)
        {
            m_TimeLeft = 0.0f; // Mark as finished
            return;
        }
    }

    m_TimeLeft -= deltaTime;

    if (m_TimeLeft <= 0.0f)
    {
        m_Callback();
        if (m_Loop)
        {
            m_TimeLeft += m_Interval;
        }
        else
        {
            m_TimeLeft = 0.0f; // Mark as finished
        }
    }
}

bool Timer::IsFinished() const { return !m_Running || !m_Loop; }
