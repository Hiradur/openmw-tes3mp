#ifndef OPENMW_PROCESSORCONTAINER_HPP
#define OPENMW_PROCESSORCONTAINER_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorContainer : public ObjectProcessor
    {
    public:
        ProcessorContainer()
        {
            BPP_INIT(ID_CONTAINER)
        }

        void Do(ObjectPacket &packet, Player &player, BaseObjectList &objectList) override
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received %s from %s", strPacketID.c_str(), player.npc.mName.c_str());
            LOG_APPEND(Log::LOG_INFO, "- action: %i", objectList.action);

            // Don't have any hardcoded sync, and instead expect Lua scripts to forward
            // container packets to ensure their integrity based on what exists in the
            // server data

            Plugin::Call<CallbackIndex("OnContainer")>(player.getId(), objectList.cell.getDescription().c_str());

            LOG_APPEND(Log::LOG_INFO, "- Finished processing ID_CONTAINER");
        }
    };
}

#endif //OPENMW_PROCESSORCONTAINER_HPP
