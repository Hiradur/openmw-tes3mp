//
// Created by koncord on 18.04.17.
//

#include "ActorProcessor.hpp"
#include "../Networking.hpp"
#include "../Main.hpp"

using namespace mwmp;

template<class T>
typename BasePacketProcessor<T>::processors_t BasePacketProcessor<T>::processors;

bool ActorProcessor::Process(RakNet::Packet &packet, ActorList &actorList)
{
    RakNet::BitStream bsIn(&packet.data[1], packet.length, false);
    bsIn.Read(guid);
    actorList.guid = guid;

    ActorPacket *myPacket = Main::get().getNetworking()->getActorPacket(packet.data[0]);

    myPacket->setActorList(&actorList);
    myPacket->SetReadStream(&bsIn);

    for (auto &processor : processors)
    {
        if (processor.first == packet.data[0])
        {
            myGuid = Main::get().getLocalPlayer()->guid;
            request = packet.length == myPacket->headerSize();

            actorList.isValid = true;

            if (!request && !processor.second->avoidReading)
            {
                myPacket->Read();
            }

            if (actorList.isValid) // -V547 (PVS Studio false-positive warning)
                processor.second->Do(*myPacket, actorList);
            else
                LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "Received %s that failed integrity check and was ignored!", processor.second->strPacketID.c_str());

            return true;
        }
    }
    return false;
}
