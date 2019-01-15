#ifndef OPENMW_FACTIONAPI_HPP
#define OPENMW_FACTIONAPI_HPP

#include <Script/Platform.hpp>

#define FACTIONAPI \
    {"ClearFactionChanges",      FactionFunctions::ClearFactionChanges},\
    \
    {"GetFactionChangesSize",    FactionFunctions::GetFactionChangesSize},\
    {"GetFactionChangesAction",  FactionFunctions::GetFactionChangesAction},\
    \
    {"GetFactionId",             FactionFunctions::GetFactionId},\
    {"GetFactionRank",           FactionFunctions::GetFactionRank},\
    {"GetFactionExpulsionState", FactionFunctions::GetFactionExpulsionState},\
    {"GetFactionReputation",     FactionFunctions::GetFactionReputation},\
    \
    {"SetFactionChangesAction",  FactionFunctions::SetFactionChangesAction},\
    {"SetFactionId",             FactionFunctions::SetFactionId},\
    {"SetFactionRank",           FactionFunctions::SetFactionRank},\
    {"SetFactionExpulsionState", FactionFunctions::SetFactionExpulsionState},\
    {"SetFactionReputation",     FactionFunctions::SetFactionReputation},\
    \
    {"AddFaction",               FactionFunctions::AddFaction},\
    \
    {"SendFactionChanges",       FactionFunctions::SendFactionChanges},\
    \
    {"InitializeFactionChanges", FactionFunctions::InitializeFactionChanges}

namespace FactionFunctions
{
    /**
    * \brief Clear the last recorded faction changes for a player.
    *
    * This is used to initialize the sending of new PlayerFaction packets.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ClearFactionChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return The number of indexes.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetFactionChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Get the action type used in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return The action type (0 for RANK, 1 for EXPULSION, 2 for REPUTATION).
    */
    EXPORT_APIFUNCTION unsigned char CDECL GetFactionChangesAction(unsigned short pid) noexcept;

    /**
    * \brief Get the factionId at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The factionId.
    */
    EXPORT_APIFUNCTION const char *CDECL GetFactionId(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the rank at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The rank.
    */
    EXPORT_APIFUNCTION int CDECL GetFactionRank(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the expulsion state at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The expulsion state.
    */
    EXPORT_APIFUNCTION bool CDECL GetFactionExpulsionState(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the reputation at a certain index in a player's latest faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param index The index of the faction.
    * \return The reputation.
    */
    EXPORT_APIFUNCTION int CDECL GetFactionReputation(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Set the action type in a player's faction changes.
    *
    * \param pid The player ID whose faction changes should be used.
    * \param action The action (0 for RANK, 1 for EXPULSION, 2 for REPUTATION).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetFactionChangesAction(unsigned short pid, unsigned char action) noexcept;

    /**
    * \brief Set the factionId of the temporary faction stored on the server.
    *
    * \param factionId The factionId.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetFactionId(const char* factionId) noexcept;

    /**
    * \brief Set the rank of the temporary faction stored on the server.
    *
    * \param rank The rank.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetFactionRank(unsigned int rank) noexcept;

    /**
    * \brief Set the expulsion state of the temporary faction stored on the server.
    *
    * \param expulsionState The expulsion state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetFactionExpulsionState(bool expulsionState) noexcept;

    /**
    * \brief Set the reputation of the temporary faction stored on the server.
    *
    * \param reputation The reputation.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetFactionReputation(int reputation) noexcept;

    /**
    * \brief Add the server's temporary faction to the faction changes for a player.
    *
    * In the process, the server's temporary faction will automatically be cleared so a new one
    * can be set up.
    *
    * \param pid The player ID whose faction changes should be used.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddFaction(unsigned short pid) noexcept;

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
    EXPORT_APIFUNCTION void CDECL SendFactionChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    // All methods below are deprecated versions of methods from above

    EXPORT_APIFUNCTION void CDECL InitializeFactionChanges(unsigned short pid) noexcept;
}

#endif //OPENMW_FACTIONAPI_HPP
