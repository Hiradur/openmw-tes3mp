#include "Shapeshift.h"

#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Log.hpp>

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <apps/openmw-mp/Networking.hpp>

#include <iostream>
using namespace std;

extern "C" double ShapeshiftFunctions::GetScale(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0.0f);

    return player->scale;
}

extern "C" bool ShapeshiftFunctions::IsWerewolf(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->isWerewolf;
}

extern "C" const char *ShapeshiftFunctions::GetCreatureRefId(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->creatureRefId.c_str();
}

extern "C" bool ShapeshiftFunctions::GetCreatureNameDisplayState(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->displayCreatureName;
}

extern "C" void ShapeshiftFunctions::SetScale(PlayerId pid, double scale) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->scale = scale;
}

extern "C" void ShapeshiftFunctions::SetWerewolfState(PlayerId pid, bool isWerewolf) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->isWerewolf = isWerewolf;
}

extern "C" void ShapeshiftFunctions::SetCreatureRefId(PlayerId pid, const char *refId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->creatureRefId = refId;
}

extern "C" void ShapeshiftFunctions::SetCreatureNameDisplayState(PlayerId pid, bool displayState) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->displayCreatureName = displayState;
}

extern "C" void ShapeshiftFunctions::SendShapeshift(PlayerId pid)
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_SHAPESHIFT);
    packet->setPlayer(player);

    packet->Send(false);
    packet->Send(true);
}
