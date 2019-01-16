#ifndef OPENMW_PROCESSORRECORDDYNAMIC_HPP
#define OPENMW_PROCESSORRECORDDYNAMIC_HPP

#include "../WorldstateProcessor.hpp"

namespace mwmp
{
    class ProcessorRecordDynamic : public WorldstateProcessor
    {
    public:
        ProcessorRecordDynamic()
        {
            BPP_INIT(ID_RECORD_DYNAMIC)
        }

        void Do(WorldstatePacket &packet, Player &player, BaseWorldstate &worldstate) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Plugin::Call<CallbackIndex("OnRecordDynamic")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORRECORDDYNAMIC_HPP
