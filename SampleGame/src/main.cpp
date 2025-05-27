#include <core/logger/LogManager.h>
#include <core/logger/LogLevel.h>
#include <Engine.h>

#include "core/timer/TimerManager.h"

int main(int argc, char* argv[])
{
    LogManager::Instance().SetLevel(LogLevel::Debug);
    DE_LOG_INFO("Dream Engine sample game started");

    auto* engine = new Engine();
    engine->Initialize();

    TimerManager& timerManager = engine->GetTimerManager();
    timerManager.AddTimer(1.0f, []() {
        DE_LOG_INFO("Timer triggered every second");
    }, true, true, true);

    engine->Run();
}

