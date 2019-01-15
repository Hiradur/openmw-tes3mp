//
// Created by koncord on 09.12.18.
//

#ifndef OPENMW_TIMER_HPP
#define OPENMW_TIMER_HPP

#include <Script/ScriptFunction.hpp>
#include "../api.h"

NAMESPACE_BEGIN(TimerFunctions)
    /**
* \brief Create a timer that will run a script function after a certain interval.
*
* \param callback The Lua script function.
* \param msec The interval in miliseconds.
* \return The ID of the timer thus created.
*/
    API_FUNCTION int CDECL CreateTimer(ScriptFunc callback, int msec) noexcept;

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
    API_FUNCTION int CDECL CreateTimerEx(ScriptFunc callback, int msec, const char *types, va_list args) noexcept;

    /**
    * \brief Start the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    API_FUNCTION void CDECL StartTimer(int timerId) noexcept;

    /**
    * \brief Stop the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    API_FUNCTION void CDECL StopTimer(int timerId) noexcept;

    /**
    * \brief Restart the timer with a certain ID for a certain interval.
    *
    * \param timerId The timer ID.
    * \param msec The interval in miliseconds.
    * \return void
    */
    API_FUNCTION void CDECL RestartTimer(int timerId, int msec) noexcept;

    /**
    * \brief Free the timer with a certain ID.
    *
    * \param timerId The timer ID.
    * \return void
    */
    API_FUNCTION void CDECL FreeTimer(int timerId) noexcept;

    /**
    * \brief Check whether a timer is elapsed.
    *
    * \param timerId The timer ID.
    * \return Whether the timer is elapsed.
    */
    API_FUNCTION bool CDECL IsTimerElapsed(int timerId) noexcept;
NAMESPACE_END()

#endif //OPENMW_TIMER_HPP
