//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERCHARGEN_HPP
#define OPENMW_PROCESSORPLAYERCHARGEN_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerCharGen : public PlayerProcessor
    {
    public:
        ProcessorPlayerCharGen()
        {
            BPP_INIT(ID_PLAYER_CHARGEN)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            if (player.charGenState.currentStage == player.charGenState.endStage)
                Plugin::Call<CallbackIndex("OnPlayerEndCharGen")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERCHARGEN_HPP
