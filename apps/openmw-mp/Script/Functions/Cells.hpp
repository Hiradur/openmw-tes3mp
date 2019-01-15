#ifndef OPENMW_CELLAPI_HPP
#define OPENMW_CELLAPI_HPP

#include "../Types.hpp"

#include <Script/Platform.hpp>

#define CELLAPI \
    {"GetCellStateChangesSize", CellFunctions::GetCellStateChangesSize},\
    \
    {"GetCellStateType",        CellFunctions::GetCellStateType},\
    {"GetCellStateDescription", CellFunctions::GetCellStateDescription},\
    \
    {"GetCell",                 CellFunctions::GetCell},\
    {"GetExteriorX",            CellFunctions::GetExteriorX},\
    {"GetExteriorY",            CellFunctions::GetExteriorY},\
    {"IsInExterior",            CellFunctions::IsInExterior},\
    \
    {"GetRegion",               CellFunctions::GetRegion},\
    {"IsChangingRegion",        CellFunctions::IsChangingRegion},\
    \
    {"SetCell",                 CellFunctions::SetCell},\
    {"SetExteriorCell",         CellFunctions::SetExteriorCell},\
    \
    {"SendCell",                CellFunctions::SendCell}


namespace CellFunctions
{
    /**
    * \brief Get the number of indexes in a player's latest cell state changes.
    *
    * \param pid The player ID whose cell state changes should be used.
    * \return The number of indexes.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetCellStateChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Get the cell state type at a certain index in a player's latest cell state changes.
    *
    * \param pid The player ID whose cell state changes should be used.
    * \param index The index of the cell state.
    * \return The cell state type (0 for LOAD, 1 for UNLOAD).
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetCellStateType(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the cell description at a certain index in a player's latest cell state changes.
    *
    * \param pid The player ID whose cell state changes should be used.
    * \param index The index of the cell state.
    * \return The cell description.
    */
    EXPORT_APIFUNCTION const char *CDECL GetCellStateDescription(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the cell description of a player's cell.
    *
    * \param pid The player ID.
    * \return The cell description.
    */
    EXPORT_APIFUNCTION const char *CDECL GetCell(unsigned short pid) noexcept;

    /**
    * \brief Get the X coordinate of the player's exterior cell.
    *
    * \param pid The player ID.
    * \return The X coordinate of the cell.
    */
    EXPORT_APIFUNCTION int CDECL GetExteriorX(unsigned short pid) noexcept;

    /**
    * \brief Get the Y coordinate of the player's exterior cell.
    *
    * \param pid The player ID.
    * \return The Y coordinate of the cell.
    */
    EXPORT_APIFUNCTION int CDECL GetExteriorY(unsigned short pid) noexcept;

    /**
    * \brief Check whether the player is in an exterior cell or not.
    *
    * \param pid The player ID.
    * \return Whether the player is in an exterior cell.
    */
    EXPORT_APIFUNCTION bool CDECL IsInExterior(unsigned short pid) noexcept;

    /**
    * \brief Get the region of the player's exterior cell.
    *
    * A blank value will be returned if the player is in an interior.
    *
    * \param pid The player ID.
    * \return The region.
    */
    EXPORT_APIFUNCTION const char *CDECL GetRegion(unsigned short pid) noexcept;

    /**
    * \brief Check whether the player's last cell change has involved a region change.
    *
    * \param pid The player ID.
    * \return Whether the player has changed their region.
    */
    EXPORT_APIFUNCTION bool CDECL IsChangingRegion(unsigned short pid) noexcept;

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
    EXPORT_APIFUNCTION void CDECL SetCell(unsigned short pid, const char *cellDescription) noexcept;

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
    EXPORT_APIFUNCTION void CDECL SetExteriorCell(unsigned short pid, int x, int y) noexcept;

    /**
    * \brief Send a PlayerCellChange packet about a player.
    *
    * It is only sent to the affected player.
    *
    * \param pid The player ID.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendCell(unsigned short pid) noexcept;
}

#endif //OPENMW_CELLAPI_HPP
