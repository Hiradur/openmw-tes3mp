#include "Settings.h"

#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Log.hpp>

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <apps/openmw-mp/Networking.hpp>

#include <iostream>
using namespace std;

extern "C" void SettingFunctions::SetDifficulty(PlayerId pid, int difficulty)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->difficulty = difficulty;
}

extern "C" void SettingFunctions::SetEnforcedLogLevel(PlayerId pid, int enforcedLogLevel)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->enforcedLogLevel = enforcedLogLevel;
}

extern "C" void SettingFunctions::SetPhysicsFramerate(PlayerId pid, double physicsFramerate)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->physicsFramerate = physicsFramerate;
}

extern "C" void SettingFunctions::SetConsoleAllowed(PlayerId pid, bool state)
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->consoleAllowed = state;
}

extern "C" void SettingFunctions::SetBedRestAllowed(PlayerId pid, bool state)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->bedRestAllowed = state;
}

extern "C" void SettingFunctions::SetWildernessRestAllowed(PlayerId pid, bool state)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->wildernessRestAllowed = state;
}

extern "C" void SettingFunctions::SetWaitAllowed(PlayerId pid, bool state)
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->waitAllowed = state;
}

extern "C" void SettingFunctions::SendSettings(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GAME_SETTINGS);
    packet->setPlayer(player);

    packet->Send(false);
}
