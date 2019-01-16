#ifndef OPENMW_PROCESSOROBJECTSTATE_HPP
#define OPENMW_PROCESSOROBJECTSTATE_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorObjectState : public ObjectProcessor
    {
    public:
        ProcessorObjectState()
        {
            BPP_INIT(ID_OBJECT_STATE)
        }

        void Do(ObjectPacket &packet, Player &player, BaseObjectList &objectList) override
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received %s from %s", strPacketID.c_str(), player.npc.mName.c_str());
            
            Plugin::Call<CallbackIndex("OnObjectState")>(player.getId(), objectList.cell.getDescription().c_str());
        }
    };
}

#endif //OPENMW_PROCESSOROBJECTSTATE_HPP
