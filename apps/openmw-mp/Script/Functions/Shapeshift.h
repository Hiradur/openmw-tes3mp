#ifndef OPENMW_SHAPESHIFTAPI_HPP
#define OPENMW_SHAPESHIFTAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(ShapeshiftFunctions)
    /**
    * \brief Get the scale of a player.
    *
    * \param pid The player ID.
    * \return The scale.
    */
    API_FUNCTION double CDECL GetScale(PlayerId pid) NOEXCEPT;

    /**
    * \brief Check whether a player is a werewolf.
    *
    * This is based on the last PlayerShapeshift packet received or sent for that player.
    *
    * \param pid The player ID.
    * \return The werewolf state.
    */
    API_FUNCTION bool CDECL IsWerewolf(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the refId of the creature the player is disguised as.
    *
    * \param pid The player ID.
    * \return The creature refId.
    */
    API_FUNCTION const char *CDECL GetCreatureRefId(PlayerId pid) NOEXCEPT;

    /**
    * \brief Check whether a player's name is replaced by that of the creature they are
    *        disguised as when other players hover over them.
    *
    * This is based on the last PlayerShapeshift packet received or sent for that player.
    *
    * \param pid The player ID.
    * \return The creature name display state.
    */
    API_FUNCTION bool CDECL GetCreatureNameDisplayState(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the scale of a player.
    *
    * This changes the scale recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param scale The new scale.
    * \return void
    */
    API_FUNCTION void CDECL SetScale(PlayerId pid, double scale) NOEXCEPT;

    /**
    * \brief Set the werewolf state of a player.
    *
    * This changes the werewolf state recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param isWerewolf The new werewolf state.
    * \return void
    */
    API_FUNCTION void CDECL SetWerewolfState(PlayerId pid, bool isWerewolf) NOEXCEPT;

    /**
    * \brief Set the refId of the creature a player is disguised as.
    *
    * This changes the creature refId recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param refId The creature refId.
    * \param displaysCreatureName Whether the player's name appears as that of the creature
    *                             when hovered over by others.
    * \return void
    */
    API_FUNCTION void CDECL SetCreatureRefId(PlayerId pid, const char *refId) NOEXCEPT;

    /**
    * \brief Set whether a player's name is replaced by that of the creature they are
    *        disguised as when other players hover over them.
    *
    * \param pid The player ID.
    * \param displayState The creature name display state.
    * \return void
    */
    API_FUNCTION void CDECL SetCreatureNameDisplayState(PlayerId pid, bool displayState) NOEXCEPT;

    /**
    * \brief Send a PlayerShapeshift packet about a player.
    *
    * This sends the packet to all players connected to the server. It is currently used
    * only to communicate werewolf states.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendShapeshift(PlayerId pid);
NAMESPACE_END()

#endif //OPENMW_SHAPESHIFTAPI_HPP