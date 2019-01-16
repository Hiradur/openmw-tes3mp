#ifndef OPENMW_GUIAPI_HPP
#define OPENMW_GUIAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(GUIFunctions)
    /**
    * \brief Display a simple messagebox at the bottom of the screen that vanishes
    *        after a few seconds.
    *
    * Note for C++ programmers: do not rename into MessageBox so as to not conflict
    * with WINAPI's MessageBox.
    *
    * \param pid The player ID for whom the messagebox should appear.
    * \param id The numerical ID of the messagebox.
    * \param label The text in the messagebox.
    * \return void
    */
    API_FUNCTION void CDECL _MessageBox(PlayerId pid, int id, const char *label) NOEXCEPT;

    /**
    * \brief Display an interactive messagebox at the center of the screen that
    *        vanishes only when one of its buttons is clicked.
    *
    * \param pid The player ID for whom the messagebox should appear.
    * \param id The numerical ID of the messagebox.
    * \param label The text in the messagebox.
    * \parm buttons The captions of the buttons, separated by semicolons (e.g. "Yes;No;Maybe").
    * \return void
    */
    API_FUNCTION void CDECL CustomMessageBox(PlayerId pid, int id, const char *label, const char *buttons) NOEXCEPT;

    /**
    * \brief Display an input dialog at the center of the screen.
    *
    * \param pid The player ID for whom the input dialog should appear.
    * \param id The numerical ID of the input dialog.
    * \param label The text at the top of the input dialog.
    * \parm note The text at the bottom of the input dialog.
    * \return void
    */
    API_FUNCTION void CDECL InputDialog(PlayerId pid, int id, const char *label, const char *note) NOEXCEPT;

    /**
    * \brief Display a password dialog at the center of the screen.
    *
    * Although similar to an input dialog, the password dialog replaces all
    * input characters with asterisks.
    *
    * \param pid The player ID for whom the password dialog should appear.
    * \param id The numerical ID of the password dialog.
    * \param label The text at the top of the password dialog.
    * \parm note The text at the bottom of the password dialog.
    * \return void
    */
    API_FUNCTION void CDECL PasswordDialog(PlayerId pid, int id, const char *label, const char *note) NOEXCEPT;

    /**
    * \brief Display a listbox at the center of the screen where each item takes up
    *        a row and is selectable, with the listbox only vanishing once the Ok button
    *        is pressed.
    *
    * \param pid The player ID for whom the listbox should appear.
    * \param id The numerical ID of the listbox.
    * \param label The text at the top of the listbox.
    * \parm items The items in the listbox, separated by newlines (e.g. "Item 1\nItem 2").
    * \return void
    */
    API_FUNCTION void CDECL ListBox(PlayerId pid, int id, const char *label, const char *items);

    /**
    * \brief Clear the last recorded quick key changes for a player.
    *
    * This is used to initialize the sending of new PlayerQuickKeys packets.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL ClearQuickKeyChanges(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the number of indexes in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetQuickKeyChangesSize(PlayerId pid) NOEXCEPT;

    /**
    * \brief Add a new quick key to the quick key changes for a player.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param slot The slot to be used.
    * \param slot The type of the quick key (0 for ITEM, 1 for ITEM_MAGIC, 2 for MAGIC, 3 for UNASSIGNED).
    * \param itemId The itemId of the item.
    * \return void
    */
    API_FUNCTION void CDECL AddQuickKey(PlayerId pid, unsigned short slot, int type, const char* itemId = "") NOEXCEPT;

    /**
    * \brief Get the slot of the quick key at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param index The index of the quick key in the quick key changes vector.
    * \return The slot.
    */
    API_FUNCTION int CDECL GetQuickKeySlot(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the type of the quick key at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param index The index of the quick key in the quick key changes vector.
    * \return The quick key type.
    */
    API_FUNCTION int CDECL GetQuickKeyType(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the itemId at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param index The index of the quick key in the quick key changes vector.
    * \return The itemId.
    */
    API_FUNCTION const char *CDECL GetQuickKeyItemId(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Send a PlayerQuickKeys packet with a player's recorded quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL SendQuickKeyChanges(PlayerId pid) NOEXCEPT;

    //state 0 - disallow, 1 - allow

    /**
    * \brief Determine whether a player can see the map marker of another player.
    *
    * Note: This currently has no effect, and is just an unimplemented stub.
    *
    * \param targetPid The player ID whose map marker should be hidden or revealed.
    * \param affectedPid The player ID for whom the map marker will be hidden or revealed.
    * \param state The state of the map marker (false to hide, true to reveal).
    * \return void
    */
    API_FUNCTION void CDECL SetMapVisibility(unsigned short targetPid, unsigned short affectedPid, unsigned short state) NOEXCEPT;

    /**
    * \brief Determine whether a player's map marker can be seen by all other players.
    *
    * Note: This currently has no effect, and is just an unimplemented stub.
    *
    * \param targetPid The player ID whose map marker should be hidden or revealed.
    * \param state The state of the map marker (false to hide, true to reveal).
    * \return void
    */
    API_FUNCTION void CDECL SetMapVisibilityAll(unsigned short targetPid, unsigned short state) NOEXCEPT;

    // All methods below are deprecated versions of methods from above

    API_FUNCTION void CDECL InitializeQuickKeyChanges(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_GUIAPI_HPP
