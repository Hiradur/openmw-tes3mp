#include "Factions.h"

#include <components/misc/stringops.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <apps/openmw-mp/Networking.hpp>

using namespace mwmp;

Faction tempFaction;
const Faction emptyFaction = {};

extern "C" void FactionFunctions::ClearFactionChanges(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->factionChanges.factions.clear();
}

extern "C" unsigned int FactionFunctions::GetFactionChangesSize(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->factionChanges.count;
}

extern "C" unsigned char FactionFunctions::GetFactionChangesAction(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->factionChanges.action;
}

extern "C" const char *FactionFunctions::GetFactionId(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->factionChanges.count)
        return "invalid";

    return player->factionChanges.factions.at(index).factionId.c_str();
}

extern "C" int FactionFunctions::GetFactionRank(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->factionChanges.factions.at(index).rank;
}

extern "C" bool FactionFunctions::GetFactionExpulsionState(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, false);

    return player->factionChanges.factions.at(index).isExpelled;
}

extern "C" int FactionFunctions::GetFactionReputation(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->factionChanges.factions.at(index).reputation;
}

extern "C" void FactionFunctions::SetFactionChangesAction(PlayerId pid, unsigned char action) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->factionChanges.action = action;
}

extern "C" void FactionFunctions::SetFactionId(const char* factionId) noexcept
{
    tempFaction.factionId = factionId;
}

extern "C" void FactionFunctions::SetFactionRank(unsigned int rank) noexcept
{
    tempFaction.rank = rank;
}

extern "C" void FactionFunctions::SetFactionExpulsionState(bool expulsionState) noexcept
{
    tempFaction.isExpelled = expulsionState;
}

extern "C" void FactionFunctions::SetFactionReputation(int reputation) noexcept
{
    tempFaction.reputation = reputation;
}

extern "C" void FactionFunctions::AddFaction(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->factionChanges.factions.push_back(tempFaction);

    tempFaction = emptyFaction;
}

extern "C" void FactionFunctions::SendFactionChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_FACTION);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

extern "C" // All methods below are deprecated versions of methods from above

void FactionFunctions::InitializeFactionChanges(PlayerId pid) noexcept
{
    ClearFactionChanges(pid);
}
