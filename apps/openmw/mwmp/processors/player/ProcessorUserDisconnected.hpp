//
// Created by koncord on 16.04.17.
//

#ifndef OPENMW_PROCESSORUSERDISCONNECTED_HPP
#define OPENMW_PROCESSORUSERDISCONNECTED_HPP


#include "../PlayerProcessor.hpp"
#include <apps/openmw/mwbase/environment.hpp>
#include "apps/openmw/mwstate/statemanagerimp.hpp"

namespace mwmp
{
    class ProcessorUserDisconnected : public PlayerProcessor
    {
    public:
        ProcessorUserDisconnected()
        {
            BPP_INIT(ID_USER_DISCONNECTED)
            avoidReading = true; // -V519 (PVS Studio false-positive warning)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            if (isLocal())
                MWBase::Environment::get().getStateManager()->requestQuit();
            else if (player != 0)
                PlayerList::deletePlayer(guid);
        }
    };
}

#endif //OPENMW_PROCESSORUSERDISCONNECTED_HPP
