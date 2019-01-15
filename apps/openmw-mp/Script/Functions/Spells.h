#ifndef OPENMW_SPELLAPI_HPP
#define OPENMW_SPELLAPI_HPP

#include "../api.h"

#define SPELLAPI \
    {"ClearSpellbookChanges",      SpellFunctions::ClearSpellbookChanges},\
    \
    {"GetSpellbookChangesSize",    SpellFunctions::GetSpellbookChangesSize},\
    {"GetSpellbookChangesAction",  SpellFunctions::GetSpellbookChangesAction},\
    \
    {"SetSpellbookChangesAction",  SpellFunctions::SetSpellbookChangesAction},\
    {"AddSpell",                   SpellFunctions::AddSpell},\
    \
    {"GetSpellId",                 SpellFunctions::GetSpellId},\
    \
    {"SendSpellbookChanges",       SpellFunctions::SendSpellbookChanges},\
    \
    {"InitializeSpellbookChanges", SpellFunctions::InitializeSpellbookChanges}

NAMESPACE_BEGIN(SpellFunctions)
    /**
    * \brief Clear the last recorded spellbook changes for a player.
    *
    * This is used to initialize the sending of new PlayerSpellbook packets.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL ClearSpellbookChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetSpellbookChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Get the action type used in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \return The action type (0 for SET, 1 for ADD, 2 for REMOVE).
    */
    API_FUNCTION unsigned int CDECL GetSpellbookChangesAction(unsigned short pid) noexcept;

    /**
    * \brief Set the action type in a player's spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param action The action (0 for SET, 1 for ADD, 2 for REMOVE).
    * \return void
    */
    API_FUNCTION void CDECL SetSpellbookChangesAction(unsigned short pid, unsigned char action) noexcept;

    /**
    * \brief Add a new spell to the spellbook changes for a player.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param spellId The spellId of the spell.
    * \return void
    */
    API_FUNCTION void CDECL AddSpell(unsigned short pid, const char* spellId) noexcept;

    /**
    * \brief Get the spellId at a certain index in a player's latest spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param index The index of the spell.
    * \return The spellId.
    */
    API_FUNCTION const char *CDECL GetSpellId(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Send a PlayerSpellbook packet with a player's recorded spellbook changes.
    *
    * \param pid The player ID whose spellbook changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendSpellbookChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    // All methods below are deprecated versions of methods from above

    API_FUNCTION void CDECL InitializeSpellbookChanges(unsigned short pid) noexcept;
NAMESPACE_END()

#endif //OPENMW_SPELLAPI_HPP
