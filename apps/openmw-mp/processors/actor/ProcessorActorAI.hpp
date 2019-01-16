#ifndef OPENMW_PROCESSORACTORAI_HPP
#define OPENMW_PROCESSORACTORAI_HPP

#include "../ActorProcessor.hpp"

namespace mwmp
{
    class ProcessorActorAI : public ActorProcessor
    {
    public:
        ProcessorActorAI()
        {
            BPP_INIT(ID_ACTOR_AI)
        }

        void Do(ActorPacket &packet, Player &player, BaseActorList &actorList) override
        {
            Cell *serverCell = CellController::get()->getCell(&actorList.cell);

            if (serverCell != nullptr)
            {
                Plugin::Call<CallbackIndex("OnActorAI")>(player.getId(), actorList.cell.getDescription().c_str());
            }
        }
    };
}

#endif //OPENMW_PROCESSORACTORAI_HPP
