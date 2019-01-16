//
// Created by koncord on 15.03.16.
//

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>
#include <Player.hpp>
#include <Networking.hpp>
#include <Script/API/TimerAPI.hpp>

#include "Timer.h"

using namespace std;
using namespace mwmp;

extern "C" int TimerFunctions::CreateTimer(ScriptFunc callback, int msec) noexcept
{
    va_list list;
    return mwmp::TimerAPI::CreateTimer(callback, msec, "", list);
}

extern "C" int TimerFunctions::CreateTimerEx(ScriptFunc callback, int msec, const char *types, ...) noexcept
{
    try
    {
        va_list args;
        va_start(args, types);
        int tid = mwmp::TimerAPI::CreateTimer(callback, msec, types, args);
        va_end(args);
        return tid;
    }
    catch (...)
    {
        return -1;
    }
}

extern "C" void TimerFunctions::StartTimer(int timerId) noexcept
{
    TimerAPI::StartTimer(timerId);
}

extern "C" void TimerFunctions::StopTimer(int timerId) noexcept
{
    TimerAPI::StopTimer(timerId);
}

extern "C" void TimerFunctions::RestartTimer(int timerId, int msec) noexcept
{
    TimerAPI::ResetTimer(timerId, msec);
}

extern "C" void TimerFunctions::FreeTimer(int timerId) noexcept
{
    TimerAPI::FreeTimer(timerId);
}

extern "C" bool TimerFunctions::IsTimerElapsed(int timerId) noexcept
{
    return TimerAPI::IsEndTimer(timerId);
}

extern "C" int TimerFunctions::GetTimerId() noexcept
{
    return TimerAPI::GetTimerId();
}

const char *TimerFunctions::GetTimerDefinition(int timerId)
{
    return TimerAPI::GetDefinition(timerId);
}
