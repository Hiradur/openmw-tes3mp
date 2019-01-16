//
// Created by koncord on 15.03.16.
//

#ifndef OPENMW_TIMERAPI_HPP
#define OPENMW_TIMERAPI_HPP

#include <string>

#include <Script/FFI.hpp>
#include <unordered_map>

namespace mwmp
{

    class TimerAPI;

    class Timer: public FFI
    {
        friend class TimerAPI;

    public:

        Timer(ScriptFunc callback, long msec, const std::string& def, va_list args);
        ~Timer();

        void Tick(int timerId);

        bool IsEnd();
        void Stop();
        void Start();
        void Restart(int msec);
        const char *GetDefinition();
    private:
        double startTime, targetMsec;
        //std::string publ, arg_types;
        //Script *scr;
        bool end;
        char *def;
    };

    class TimerAPI
    {
    public:
        static int CreateTimer(ScriptFunc callback, long msec, const std::string& def, va_list args);
        static void FreeTimer(int timerid);
        static void ResetTimer(int timerid, long msec);
        static void StartTimer(int timerid);
        static void StopTimer(int timerid);
        static bool IsEndTimer(int timerid);
        static int GetTimerId();
        static const char *GetDefinition(int timerid);

        static void Terminate();

        static void Tick();
    private:
        static std::unordered_map<int, Timer* > timers;
        static int pointer;
        static int lastTimerId;
    };
}

#endif //OPENMW_TIMERAPI_HPP
