#include "Cells.h"

#include <components/openmw-mp/Log.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Networking.hpp>

#include <iostream>
using namespace std;

static std::string tempCellDescription;

extern "C" unsigned int CellFunctions::GetCellStateChangesSize(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->cellStateChanges.count;
}

extern "C" unsigned int CellFunctions::GetCellStateType(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->cellStateChanges.cellStates.at(index).type;
}

extern "C" const char *CellFunctions::GetCellStateDescription(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->cellStateChanges.count)
        return "invalid";

    tempCellDescription = player->cellStateChanges.cellStates.at(index).cell.getDescription();
    return tempCellDescription.c_str();
}

extern "C" const char *CellFunctions::GetCell(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    tempCellDescription = player->cell.getDescription();
    return tempCellDescription.c_str();
}

extern "C" int CellFunctions::GetExteriorX(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);
    return player->cell.mData.mX;
}

extern "C" int CellFunctions::GetExteriorY(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);
    return player->cell.mData.mY;
}

extern "C" bool CellFunctions::IsInExterior(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, false);

    return player->cell.isExterior();
}

extern "C" const char *CellFunctions::GetRegion(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->cell.mRegion.c_str();
}

extern "C" bool CellFunctions::IsChangingRegion(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, false);

    return player->isChangingRegion;
}

extern "C" void CellFunctions::SetCell(PlayerId pid, const char *cellDescription) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Script is moving %s from %s to %s", player->npc.mName.c_str(),
                       player->cell.getDescription().c_str(), cellDescription);

    player->cell = Utils::getCellFromDescription(cellDescription);
}

extern "C" void CellFunctions::SetExteriorCell(PlayerId pid, int x, int y) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Script is moving %s from %s to %i,%i", player->npc.mName.c_str(),
                       player->cell.getDescription().c_str(), x, y);

    // If the player is currently in an interior, turn off the interior flag
    // from the cell
    if (!player->cell.isExterior())
        player->cell.mData.mFlags &= ~ESM::Cell::Interior;

    player->cell.mData.mX = x;
    player->cell.mData.mY = y;
}

extern "C" void CellFunctions::SendCell(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_CELL_CHANGE);
    packet->setPlayer(player);

    packet->Send(false);
}
