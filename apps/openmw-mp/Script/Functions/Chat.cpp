#include "Chat.h"

#include <components/openmw-mp/NetworkMessages.hpp>
#include <components/openmw-mp/Log.hpp>

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <apps/openmw-mp/Networking.hpp>

extern "C" void ChatFunctions::SendMessage(PlayerId pid, const char *message, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->chatMessage = message;

    LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "System: %s", message);

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_CHAT_MESSAGE);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

extern "C" void ChatFunctions::CleanChatForPid(PlayerId pid)
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->chatMessage.clear();

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_CHAT_MESSAGE);
    packet->setPlayer(player);

    packet->Send(false);
}

extern "C" void ChatFunctions::CleanChat()
{
    for (auto player : *Players::getPlayers())
    {
        player.second->chatMessage.clear();

        mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_CHAT_MESSAGE);
        packet->setPlayer(player.second);

        packet->Send(false);
    }
}
