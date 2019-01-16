//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERINVENTORY_HPP
#define OPENMW_PROCESSORPLAYERINVENTORY_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerInventory : public PlayerProcessor
    {
    public:
        ProcessorPlayerInventory()
        {
            BPP_INIT(ID_PLAYER_INVENTORY)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Plugin::Call<CallbackIndex("OnPlayerInventory")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERINVENTORY_HPP
