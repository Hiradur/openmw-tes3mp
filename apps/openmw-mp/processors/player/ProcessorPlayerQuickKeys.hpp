#ifndef OPENMW_PROCESSORPLAYERQUICKKEYS_HPP
#define OPENMW_PROCESSORPLAYERQUICKKEYS_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerQuickKeys : public PlayerProcessor
    {
    public:
        ProcessorPlayerQuickKeys()
        {
            BPP_INIT(ID_PLAYER_QUICKKEYS)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Plugin::Call<CallbackIndex("OnPlayerQuickKeys")>(player.getId());
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERQUICKKEYS_HPP
