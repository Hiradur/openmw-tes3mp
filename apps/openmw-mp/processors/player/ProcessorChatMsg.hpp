//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERCHATMSG_HPP
#define OPENMW_PROCESSORPLAYERCHATMSG_HPP

#include "../PlayerProcessor.hpp"
#include <Script/Plugin.hpp>

namespace mwmp
{
    class ProcessorChatMsg : public PlayerProcessor
    {
    public:
        ProcessorChatMsg()
        {
            BPP_INIT(ID_CHAT_MESSAGE)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Plugin::Call<CallbackIndex("OnPlayerSendMessage")>(player.getId(), player.chatMessage.c_str());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERCHATMSG_HPP
