#ifndef OPENMW_FACTIONAPI_HPP
#define OPENMW_FACTIONAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(FactionFunctions)
    /**
    * \brief Clear the last recorded faction changes for a player.
    *
    * This is used to initialize the sending of new PlayerFaction packets.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL ClearFactionChanges(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the number of indexes in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetFactionChangesSize(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the action type used in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return The action type (0 for RANK, 1 for EXPULSION, 2 for REPUTATION).
    */
    API_FUNCTION unsigned char CDECL GetFactionChangesAction(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the factionId at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The factionId.
    */
    API_FUNCTION const char *CDECL GetFactionId(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the rank at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The rank.
    */
    API_FUNCTION int CDECL GetFactionRank(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the expulsion state at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The expulsion state.
    */
    API_FUNCTION bool CDECL GetFactionExpulsionState(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the reputation at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The reputation.
    */
    API_FUNCTION int CDECL GetFactionReputation(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Set the action type in a player's faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param action The action (0 for RANK, 1 for EXPULSION, 2 for REPUTATION).
    * \return void
    */
    API_FUNCTION void CDECL SetFactionChangesAction(PlayerId pid, unsigned char action) NOEXCEPT;

    /**
    * \brief Set the factionId of the temporary faction stored on the server.
    *
    * \param factionId The factionId.
    * \return void
    */
    API_FUNCTION void CDECL SetFactionId(const char* factionId) NOEXCEPT;

    /**
    * \brief Set the rank of the temporary faction stored on the server.
    *
    * \param rank The rank.
    * \return void
    */
    API_FUNCTION void CDECL SetFactionRank(unsigned int rank) NOEXCEPT;

    /**
    * \brief Set the expulsion state of the temporary faction stored on the server.
    *
    * \param expulsionState The expulsion state.
    * \return void
    */
    API_FUNCTION void CDECL SetFactionExpulsionState(bool expulsionState) NOEXCEPT;

    /**
    * \brief Set the reputation of the temporary faction stored on the server.
    *
    * \param reputation The reputation.
    * \return void
    */
    API_FUNCTION void CDECL SetFactionReputation(int reputation) NOEXCEPT;

    /**
    * \brief Add the server's temporary faction to the faction changes for a player.
    *
    * In the process, the server's temporary faction will automatically be cleared so a new one
    * can be set up.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL AddFaction(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerFaction packet with a player's recorded faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendFactionChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    // All methods below are deprecated versions of methods from above

    API_FUNCTION void CDECL InitializeFactionChanges(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_FACTIONAPI_HPP
