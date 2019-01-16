//
// Created by koncord on 29.08.16.
//

#include "CharClass.h"

#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Networking.hpp>
#include <apps/openmw-mp/Script/Callbacks.hpp>

using namespace std;
using namespace ESM;

extern "C" const char *CharClassFunctions::GetDefaultClass(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    return player->charClass.mId.c_str();
}

extern "C" const char *CharClassFunctions::GetClassName(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    return player->charClass.mName.c_str();
}

extern "C" const char *CharClassFunctions::GetClassDesc(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    return player->charClass.mDescription.c_str();
}

extern "C" int CharClassFunctions::GetClassMajorAttribute(PlayerId pid, unsigned char slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (slot > 1)
        throw invalid_argument("Incorrect attribute slot id");

    return player->charClass.mData.mAttribute[slot];
}

extern "C" int CharClassFunctions::GetClassSpecialization(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->charClass.mData.mSpecialization;
}

extern "C" int CharClassFunctions::GetClassMajorSkill(PlayerId pid, unsigned char slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (slot > 4)
        throw invalid_argument("Incorrect skill slot id");

    return player->charClass.mData.mSkills[slot][1];
}

extern "C" int CharClassFunctions::GetClassMinorSkill(PlayerId pid, unsigned char slot) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    if (slot > 4)
        throw invalid_argument("Incorrect skill slot id");

    return player->charClass.mData.mSkills[slot][0];
}

extern "C" int CharClassFunctions::IsClassDefault(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return !player->charClass.mId.empty(); // true if default
}

extern "C" void CharClassFunctions::SetDefaultClass(PlayerId pid, const char *id) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->charClass.mId = id;
}

extern "C" void CharClassFunctions::SetClassName(PlayerId pid, const char *name) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->charClass.mName = name;
    player->charClass.mId.clear();
}

extern "C" void CharClassFunctions::SetClassDesc(PlayerId pid, const char *desc) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->charClass.mDescription = desc;
}

extern "C" void CharClassFunctions::SetClassMajorAttribute(PlayerId pid, unsigned char slot, int attrId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    if (slot > 1)
        throw invalid_argument("Incorrect attribute slot id");

    player->charClass.mData.mAttribute[slot] = attrId;

}

extern "C" void CharClassFunctions::SetClassSpecialization(PlayerId pid, int spec) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->charClass.mData.mSpecialization = spec;
}

extern "C" void CharClassFunctions::SetClassMajorSkill(PlayerId pid, unsigned char slot, int skillId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    if (slot > 4)
        throw invalid_argument("Incorrect skill slot id");

    player->charClass.mData.mSkills[slot][1] = skillId;
}

extern "C" void CharClassFunctions::SetClassMinorSkill(PlayerId pid, unsigned char slot, int skillId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    if (slot > 4)
        throw invalid_argument("Incorrect skill slot id");

    player->charClass.mData.mSkills[slot][0] = skillId;
}

extern "C" void CharClassFunctions::SendClass(PlayerId pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_CHARCLASS);
    packet->setPlayer(player);

    packet->Send(false);
}
