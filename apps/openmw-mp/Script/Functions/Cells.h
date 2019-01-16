#ifndef OPENMW_CELLAPI_HPP
#define OPENMW_CELLAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(CellFunctions)
    /**
    * \brief Get the number of indexes in a player's latest cell state changes.
    *
    * \param pid The player ID whose cell state changes should be used.
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetCellStateChangesSize(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the cell state type at a certain index in a player's latest cell state changes.
    *
    * \param pid The player ID whose cell state changes should be used.
    * \param index The index of the cell state.
    * \return The cell state type (0 for LOAD, 1 for UNLOAD).
    */
    API_FUNCTION unsigned int CDECL GetCellStateType(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the cell description at a certain index in a player's latest cell state changes.
    *
    * \param pid The player ID whose cell state changes should be used.
    * \param index The index of the cell state.
    * \return The cell description.
    */
    API_FUNCTION const char *CDECL GetCellStateDescription(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the cell description of a player's cell.
    *
    * \param pid The player ID.
    * \return The cell description.
    */
    API_FUNCTION const char *CDECL GetCell(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the X coordinate of the player's exterior cell.
    *
    * \param pid The player ID.
    * \return The X coordinate of the cell.
    */
    API_FUNCTION int CDECL GetExteriorX(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Y coordinate of the player's exterior cell.
    *
    * \param pid The player ID.
    * \return The Y coordinate of the cell.
    */
    API_FUNCTION int CDECL GetExteriorY(PlayerId pid) NOEXCEPT;

    /**
    * \brief Check whether the player is in an exterior cell or not.
    *
    * \param pid The player ID.
    * \return Whether the player is in an exterior cell.
    */
    API_FUNCTION bool CDECL IsInExterior(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the region of the player's exterior cell.
    *
    * A blank value will be returned if the player is in an interior.
    *
    * \param pid The player ID.
    * \return The region.
    */
    API_FUNCTION const char *CDECL GetRegion(PlayerId pid) NOEXCEPT;

    /**
    * \brief Check whether the player's last cell change has involved a region change.
    *
    * \param pid The player ID.
    * \return Whether the player has changed their region.
    */
    API_FUNCTION bool CDECL IsChangingRegion(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the cell of a player.
    *
    * This changes the cell recorded for that player in the server memory, but does not by itself
    * send a packet.
    *
    * The cell is determined to be an exterior cell if it fits the pattern of a number followed
    * by a comma followed by another number.
    *
    * \param pid The player ID.
    * \param cellDescription The cell description.
    * \return void
    */
    API_FUNCTION void CDECL SetCell(PlayerId pid, const char *cellDescription) NOEXCEPT;

    /**
    * \brief Set the cell of a player to an exterior cell.
    *
    * This changes the cell recorded for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param x The X coordinate of the cell.
    * \param y The Y coordinate of the cell.
    * \return void
    */
    API_FUNCTION void CDECL SetExteriorCell(PlayerId pid, int x, int y) NOEXCEPT;

    /**
    * \brief Send a PlayerCellChange packet about a player.
    *
    * It is only sent to the affected player.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendCell(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_CELLAPI_HPP
