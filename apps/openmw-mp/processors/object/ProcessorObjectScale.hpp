#ifndef OPENMW_PROCESSOROBJECTSCALE_HPP
#define OPENMW_PROCESSOROBJECTSCALE_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorObjectScale : public ObjectProcessor
    {
    public:
        ProcessorObjectScale()
        {
            BPP_INIT(ID_OBJECT_SCALE)
        }

        void Do(ObjectPacket &packet, Player &player, BaseObjectList &objectList) override
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received %s from %s", strPacketID.c_str(), player.npc.mName.c_str());
            
            Plugin::Call<CallbackIndex("OnObjectScale")>(player.getId(), objectList.cell.getDescription().c_str());
        }
    };
}

#endif //OPENMW_PROCESSOROBJECTSCALE_HPP
