#ifndef OPENMW_MECHANICSAPI_HPP
#define OPENMW_MECHANICSAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(MechanicsFunctions)
    /**
    * \brief Get the type of a PlayerMiscellaneous packet.
    *
    * \param pid The player ID.
    * \return The type.
    */
    API_FUNCTION unsigned char CDECL GetMiscellaneousChangeType(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the cell description of a player's Mark cell.
    *
    * \param pid The player ID.
    * \return The cell description.
    */
    API_FUNCTION const char *CDECL GetMarkCell(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the X position of a player's Mark.
    *
    * \param pid The player ID.
    * \return The X position.
    */
    API_FUNCTION double CDECL GetMarkPosX(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Y position of a player's Mark.
    *
    * \param pid The player ID.
    * \return The Y position.
    */
    API_FUNCTION double CDECL GetMarkPosY(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Z position of a player's Mark.
    *
    * \param pid The player ID.
    * \return The Z position.
    */
    API_FUNCTION double CDECL GetMarkPosZ(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the X rotation of a player's Mark.
    *
    * \param pid The player ID.
    * \return The X rotation.
    */
    API_FUNCTION double CDECL GetMarkRotX(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Z rotation of a player's Mark.
    *
    * \param pid The player ID.
    * \return The X rotation.
    */
    API_FUNCTION double CDECL GetMarkRotZ(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the ID of a player's selected spell.
    *
    * \param pid The player ID.
    * \return The spell ID.
    */
    API_FUNCTION const char *CDECL GetSelectedSpellId(PlayerId pid) NOEXCEPT;

    /**
    * \brief Check whether the killer of a certain player is also a player.
    *
    * \param pid The player ID of the killed player.
    * \return Whether the player was killed by another player.
    */
    API_FUNCTION bool CDECL DoesPlayerHavePlayerKiller(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the player ID of the killer of a certain player.
    *
    * \param pid The player ID of the killed player.
    * \return The player ID of the killer.
    */
    API_FUNCTION int CDECL GetPlayerKillerPid(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the refId of the actor killer of a certain player.
    *
    * \param pid The player ID of the killed player.
    * \return The refId of the killer.
    */
    API_FUNCTION const char *CDECL GetPlayerKillerRefId(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the refNum of the actor killer of a certain player.
    *
    * \param pid The player ID of the killed player.
    * \return The refNum of the killer.
    */
    API_FUNCTION unsigned int CDECL GetPlayerKillerRefNum(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the mpNum of the actor killer of a certain player.
    *
    * \param pid The player ID of the killed player.
    * \return The mpNum of the killer.
    */
    API_FUNCTION unsigned int CDECL GetPlayerKillerMpNum(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the name of the actor killer of a certain player.
    *
    * \param pid The player ID of the killed player.
    * \return The name of the killer.
    */
    API_FUNCTION const char *CDECL GetPlayerKillerName(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the draw state of a player (0 for nothing, 1 for drawn weapon,
    *        2 for drawn spell).
    *
    * \param pid The player ID.
    * \return The draw state.
    */
    API_FUNCTION unsigned int CDECL GetDrawState(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the sneak state of a player.
    *
    * \param pid The player ID.
    * \return Whether the player is sneaking.
    */
    API_FUNCTION bool CDECL GetSneakState(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the Mark cell of a player.
    *
    * This changes the Mark cell recorded for that player in the server memory, but does not by itself
    * send a packet.
    *
    * The cell is determined to be an exterior cell if it fits the pattern of a number followed
    * by a comma followed by another number.
    *
    * \param pid The player ID.
    * \param cellDescription The cell description.
    * \return void
    */
    API_FUNCTION void CDECL SetMarkCell(PlayerId pid, const char *cellDescription) NOEXCEPT;

    /**
    * \brief Set the Mark position of a player.
    *
    * This changes the Mark positional coordinates recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param x The X position.
    * \param y The Y position.
    * \param z The Z position.
    * \return void
    */
    API_FUNCTION void CDECL SetMarkPos(PlayerId pid, double x, double y, double z) NOEXCEPT;

    /**
    * \brief Set the Mark rotation of a player.
    *
    * This changes the Mark positional coordinates recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param x The X rotation.
    * \param z The Z rotation.
    * \return void
    */
    API_FUNCTION void CDECL SetMarkRot(PlayerId pid, double x, double z) NOEXCEPT;

    /**
    * \brief Set the ID of a player's selected spell.
    *
    * This changes the spell ID recorded for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param spellId The spell ID.
    * \return void
    */
    API_FUNCTION void CDECL SetSelectedSpellId(PlayerId pid, const char *spellId) NOEXCEPT;

    /**
    * \brief Send a PlayerMiscellaneous packet with a Mark location to a player.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendMarkLocation(PlayerId pid);

    /**
    * \brief Send a PlayerMiscellaneous packet with a selected spell ID to a player.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendSelectedSpell(PlayerId pid);

    /**
    * \brief Send a PlayerJail packet about a player.
    *
    * This is similar to the player being jailed by a guard, but provides extra parameters for
    * increased flexibility.
    *
    * It is only sent to the player being jailed, as the other players will be informed of the
    * jailing's actual consequences via other packets sent by the affected client.
    *
    * \param pid The player ID.
    * \param jailDays The number of days to spend jailed, where each day affects one skill point.
    * \param ignoreJailTeleportation Whether the player being teleported to the nearest jail
    *                                marker should be overridden.
    * \param ignoreJailSkillIncrease Whether the player's Sneak and Security skills should be
    *                                prevented from increasing as a result of the jailing,
    *                                overriding default behavior.
    * \param jailProgressText The text that should be displayed while jailed.
    * \param jailEndText The text that should be displayed once the jailing period is over.
    * \return void
    */
    API_FUNCTION void CDECL Jail(PlayerId pid, int jailDays, bool ignoreJailTeleportation, bool ignoreJailSkillIncreases,
                     const char* jailProgressText, const char* jailEndText) NOEXCEPT;

    /**
    * \brief Send a PlayerResurrect packet about a player.
    *
    * This sends the packet to all players connected to the server.
    *
    * \param pid The player ID.
    * \param type The type of resurrection (0 for REGULAR, 1 for IMPERIAL_SHRINE,
    *             2 for TRIBUNAL_TEMPLE).
    * \return void
    */
    API_FUNCTION void CDECL Resurrect(PlayerId pid, unsigned int type) NOEXCEPT;

    // All methods below are deprecated versions of methods from above

    API_FUNCTION const char *CDECL GetDeathReason(PlayerId pid) NOEXCEPT;
    API_FUNCTION unsigned int CDECL GetPlayerKillerRefNumIndex(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_MECHANICSAPI_HPP
