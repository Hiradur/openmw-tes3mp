#ifndef OPENMW_SETTINGSAPI_HPP
#define OPENMW_SETTINGSAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(SettingFunctions)
    /**
    * \brief Set the difficulty for a player.
    *
    * This changes the difficulty for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param difficulty The difficulty.
    * \return void
    */
    API_FUNCTION void CDECL SetDifficulty(PlayerId pid, int difficulty);

    /**
    * \brief Set the client log level enforced for a player.
    *
    * This changes the enforced log level for that player in the server memory, but does not by itself
    * send a packet.
    *
    * Enforcing a certain log level is necessary to prevent players from learning information from
    * their console window that they are otherwise unable to obtain, such as the locations of
    * other players.
    *
    * If you do not wish to enforce a log level, simply set enforcedLogLevel to -1
    *
    * \param pid The player ID.
    * \param enforcedLogLevel The enforced log level.
    * \return void
    */
    API_FUNCTION void CDECL SetEnforcedLogLevel(PlayerId pid, int enforcedLogLevel);

    /**
    * \brief Set the physics framerate for a player.
    *
    * This changes the physics framerate for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param physicsFramerate The physics framerate.
    * \return void
    */
    API_FUNCTION void CDECL SetPhysicsFramerate(PlayerId pid, double physicsFramerate);

    /**
    * \brief Set whether the console is allowed for a player.
    *
    * This changes the console permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param state The console permission state.
    * \return void
    */
    API_FUNCTION void CDECL SetConsoleAllowed(PlayerId pid, bool state);

    /**
    * \brief Set whether resting in beds is allowed for a player.
    *
    * This changes the resting permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param state The resting permission state.
    * \return void
    */
    API_FUNCTION void CDECL SetBedRestAllowed(PlayerId pid, bool state);

    /**
    * \brief Set whether resting in the wilderness is allowed for a player.
    *
    * This changes the resting permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param state The resting permission state.
    * \return void
    */
    API_FUNCTION void CDECL SetWildernessRestAllowed(PlayerId pid, bool state);

    /**
    * \brief Set whether waiting is allowed for a player.
    *
    * This changes the waiting permission for that player in the server memory, but does not
    * by itself send a packet.
    *
    * \param pid The player ID.
    * \param state The waiting permission state.
    * \return void
    */
    API_FUNCTION void CDECL SetWaitAllowed(PlayerId pid, bool state);

    /**
    * \brief Send a PlayerSettings packet to the player affected by it.
    *
    * \param pid The player ID to send it to.
    * \return void
    */
    API_FUNCTION void CDECL SendSettings(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_SETTINGSAPI_HPP
