//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERSPELLBOOK_HPP
#define OPENMW_PROCESSORPLAYERSPELLBOOK_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerSpellbook : public PlayerProcessor
    {
    public:
        ProcessorPlayerSpellbook()
        {
            BPP_INIT(ID_PLAYER_SPELLBOOK)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Plugin::Call<CallbackIndex("OnPlayerSpellbook")>(player.getId());
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERSPELLBOOK_HPP
