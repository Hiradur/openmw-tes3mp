#ifndef OPENMW_PROCESSOROBJECTDELETE_HPP
#define OPENMW_PROCESSOROBJECTDELETE_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorObjectDelete : public ObjectProcessor
    {
    public:
        ProcessorObjectDelete()
        {
            BPP_INIT(ID_OBJECT_DELETE)
        }

        void Do(ObjectPacket &packet, Player &player, BaseObjectList &objectList) override
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received %s from %s", strPacketID.c_str(), player.npc.mName.c_str());

            Plugin::Call<CallbackIndex("OnObjectDelete")>(player.getId(), objectList.cell.getDescription().c_str());
        }
    };
}

#endif //OPENMW_PROCESSOROBJECTDELETE_HPP
