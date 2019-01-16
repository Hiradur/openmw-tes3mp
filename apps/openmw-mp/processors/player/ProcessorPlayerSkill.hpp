//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERSKILL_HPP
#define OPENMW_PROCESSORPLAYERSKILL_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerSkill : public PlayerProcessor
    {
    public:
        ProcessorPlayerSkill()
        {
            BPP_INIT(ID_PLAYER_SKILL)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            if (!player.creatureStats.mDead)
            {
                //myPacket->Send(player, true);
                player.sendToLoaded(&packet);

                Plugin::Call<CallbackIndex("OnPlayerSkill")>(player.getId());
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERSKILL_HPP
