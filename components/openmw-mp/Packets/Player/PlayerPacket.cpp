#include <components/openmw-mp/NetworkMessages.hpp>
#include <PacketPriority.h>
#include <RakPeer.h>
#include "PlayerPacket.hpp"

using namespace mwmp;

PlayerPacket::PlayerPacket(RakNet::RakPeerInterface *peer) : BasePacket(peer)
{
    player = nullptr;
    packetID = 0;
    priority = HIGH_PRIORITY;
    reliability = RELIABLE_ORDERED;
    orderChannel = CHANNEL_PLAYER;
    this->peer = peer;
}

PlayerPacket::~PlayerPacket()
{

}

void PlayerPacket::setPlayer(BasePlayer *player)
{
    this->player = player;
    guid = player->guid;
}

BasePlayer *PlayerPacket::getPlayer()
{
    return player;
}
