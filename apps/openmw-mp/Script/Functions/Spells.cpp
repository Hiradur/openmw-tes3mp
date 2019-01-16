#include "Spells.h"

#include <components/misc/stringops.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/Callbacks.hpp>
#include <apps/openmw-mp/Networking.hpp>

using namespace mwmp;

extern "C" void SpellFunctions::ClearSpellbookChanges(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->spellbookChanges.spells.clear();
}

extern "C" unsigned int SpellFunctions::GetSpellbookChangesSize(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->spellbookChanges.count;
}

extern "C" unsigned int SpellFunctions::GetSpellbookChangesAction(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->spellbookChanges.action;
}

extern "C" void SpellFunctions::SetSpellbookChangesAction(PlayerId pid, unsigned char action) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->spellbookChanges.action = action;
}

extern "C" void SpellFunctions::AddSpell(PlayerId pid, const char* spellId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    ESM::Spell spell;
    spell.mId = spellId;

    player->spellbookChanges.spells.push_back(spell);
}

extern "C" const char *SpellFunctions::GetSpellId(PlayerId pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->spellbookChanges.count)
        return "invalid";

    return player->spellbookChanges.spells.at(index).mId.c_str();
}

extern "C" void SpellFunctions::SendSpellbookChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_SPELLBOOK);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

extern "C" // All methods below are deprecated versions of methods from above

void SpellFunctions::InitializeSpellbookChanges(PlayerId pid) noexcept
{
    ClearSpellbookChanges(pid);
}
