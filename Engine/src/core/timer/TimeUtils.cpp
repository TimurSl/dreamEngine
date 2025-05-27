#include "core/timer/TimeUtils.h"

float TimeUtils::GetCurrentTime()
{
    using namespace std::chrono;
    static auto start = steady_clock::now();
    auto now = steady_clock::now();
    duration<float> elapsed = now - start;
    return elapsed.count();
}
