//
// Created by koncord on 09.12.18.
//

#ifndef OPENMW_TIMER_HPP
#define OPENMW_TIMER_HPP

#include "../api.h"
#include <stdarg.h>

NAMESPACE_BEGIN(TimerFunctions)
    /**
* \brief Create a timer that will run a script function after a certain interval.
*
* \param callback The Lua script function.
* \param msec The interval in miliseconds.
* \return The ID of the timer thus created.
*/
    API_FUNCTION int CDECL CreateTimer(ScriptFunc callback, int msec) NOEXCEPT;

    /**
    * \brief Create a timer that will run a script function after a certain interval and pass
    *        certain arguments to it.
    *
    * Example usage:
    * - tes3mp.CreateTimerEx("OnTimerTest1", 250, "i", 90)
    * - tes3mp.CreateTimerEx("OnTimerTest2", 500, "sif", "Test string", 60, 77.321)
    *
    * \param callback The Lua script function.
    * \param msec The interval in miliseconds.
    * \param types The argument types.
    * \param args The arguments.
    * \return The ID of the timer thus created.
    */
    API_FUNCTION int CDECL CreateTimerEx(ScriptFunc callback, int msec, const char *types, ...) NOEXCEPT;

    /**
    * \brief Start the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    API_FUNCTION void CDECL StartTimer(int timerId) NOEXCEPT;

    /**
    * \brief Stop the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    API_FUNCTION void CDECL StopTimer(int timerId) NOEXCEPT;

    /**
    * \brief Restart the timer with a certain ID for a certain interval.
    *
    * \param timerId The timer ID.
    * \param msec The interval in miliseconds.
    * \return void
    */
    API_FUNCTION void CDECL RestartTimer(int timerId, int msec) NOEXCEPT;

    /**
    * \brief Free the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    API_FUNCTION void CDECL FreeTimer(int timerId) NOEXCEPT;

    /**
    * \brief Check whether a timer is elapsed.
    *
    * \param timerId The timer ID.
    * \return Whether the timer is elapsed.
    */
    API_FUNCTION bool CDECL IsTimerElapsed(int timerId) NOEXCEPT;

    /**
    * \brief Return timer id if called from timer, otherwise -1
    *
    * \return TimerId
    */
    API_FUNCTION int CDECL GetTimerId() NOEXCEPT;

    /**
    * \brief Return timer id if called from timer, otherwise -1
    *
    * \param timerId The timer ID.
    * \return types of timer
    */
    API_FUNCTION const char *GetTimerDefinition(int timerId);
NAMESPACE_END()

#endif //OPENMW_TIMER_HPP
