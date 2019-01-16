#include "Quests.h"

#include <components/misc/stringops.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <apps/openmw-mp/Networking.hpp>

using namespace mwmp;

extern "C" void QuestFunctions::ClearJournalChanges(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->journalChanges.journalItems.clear();
}

extern "C" void QuestFunctions::ClearKillChanges(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->killChanges.kills.clear();
}

extern "C" unsigned int QuestFunctions::GetJournalChangesSize(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.count;
}

extern "C" unsigned int QuestFunctions::GetKillChangesSize(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->killChanges.count;
}

extern "C" void QuestFunctions::AddJournalEntry(PlayerId pid, const char* quest, unsigned int index, const char* actorRefId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::JournalItem journalItem;
    journalItem.type = JournalItem::ENTRY;
    journalItem.quest = quest;
    journalItem.index = index;
    journalItem.actorRefId = actorRefId;
    journalItem.hasTimestamp = false;

    player->journalChanges.journalItems.push_back(journalItem);
}

extern "C" void QuestFunctions::AddJournalEntryWithTimestamp(PlayerId pid, const char* quest, unsigned int index, const char* actorRefId,
    unsigned int daysPassed, unsigned int month, unsigned int day) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::JournalItem journalItem;
    journalItem.type = JournalItem::ENTRY;
    journalItem.quest = quest;
    journalItem.index = index;
    journalItem.actorRefId = actorRefId;
    journalItem.hasTimestamp = true;

    journalItem.timestamp.daysPassed = daysPassed;
    journalItem.timestamp.month = month;
    journalItem.timestamp.day = day;

    player->journalChanges.journalItems.push_back(journalItem);
}

extern "C" void QuestFunctions::AddJournalIndex(PlayerId pid, const char* quest, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::JournalItem journalItem;
    journalItem.type = JournalItem::INDEX;
    journalItem.quest = quest;
    journalItem.index = index;

    player->journalChanges.journalItems.push_back(journalItem);
}

extern "C" void QuestFunctions::AddKill(PlayerId pid, const char* refId, int number) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::Kill kill;
    kill.refId = refId;
    kill.number = number;

    player->killChanges.kills.push_back(kill);
}

extern "C" void QuestFunctions::SetReputation(PlayerId pid, int value) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->npcStats.mReputation = value;
}

extern "C" const char *QuestFunctions::GetJournalItemQuest(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->journalChanges.count)
        return "invalid";

    return player->journalChanges.journalItems.at(index).quest.c_str();
}

extern "C" int QuestFunctions::GetJournalItemIndex(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.journalItems.at(index).index;
}

extern "C" int QuestFunctions::GetJournalItemType(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.journalItems.at(index).type;
}

extern "C" const char *QuestFunctions::GetJournalItemActorRefId(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->journalChanges.journalItems.at(index).actorRefId.c_str();
}

extern "C" const char *QuestFunctions::GetKillRefId(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->killChanges.count)
        return "invalid";

    return player->killChanges.kills.at(index).refId.c_str();
}

extern "C" int QuestFunctions::GetKillNumber(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->killChanges.kills.at(index).number;
}

extern "C" int QuestFunctions::GetReputation(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->npcStats.mReputation;
}

extern "C" void QuestFunctions::SendJournalChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_JOURNAL);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

extern "C" void QuestFunctions::SendKillChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_WORLD_KILL_COUNT);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

extern "C" void QuestFunctions::SendReputation(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_REPUTATION);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

extern "C" // All methods below are deprecated versions of methods from above

void QuestFunctions::InitializeJournalChanges(PlayerId pid) noexcept
{
    ClearJournalChanges(pid);
}

extern "C" void QuestFunctions::InitializeKillChanges(PlayerId pid) noexcept
{
    ClearKillChanges(pid);
}
