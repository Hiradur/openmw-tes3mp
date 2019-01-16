#ifndef SCRIPTFUNCTIONS_HPP
#define SCRIPTFUNCTIONS_HPP

#include <Script/Functions/Actors.h>
#include <Script/Functions/Books.h>
#include <Script/Functions/Cells.h>
#include <Script/Functions/CharClass.h>
#include <Script/Functions/Chat.h>
#include <Script/Functions/Dialogue.h>
#include <Script/Functions/Factions.h>
#include <Script/Functions/GUI.h>
#include <Script/Functions/Items.h>
#include <Script/Functions/Mechanics.h>
#include <Script/Functions/Miscellaneous.h>
#include <Script/Functions/Objects.h>
#include <Script/Functions/Positions.h>
#include <Script/Functions/Public.h>
#include <Script/Functions/Quests.h>
#include <Script/Functions/RecordsDynamic.h>
#include <Script/Functions/Shapeshift.h>
#include <Script/Functions/Server.h>
#include <Script/Functions/Settings.h>
#include <Script/Functions/Spells.h>
#include <Script/Functions/Stats.h>
#include <Script/Functions/Timer.h>
#include <Script/Functions/Worldstate.h>
#include "Callback.hpp"

#include <components/openmw-mp/Log.hpp>

#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCTION__
#endif

#define GET_PLAYER(pid, pl, retvalue) \
     pl = Players::getPlayer(pid); \
     if (player == 0) {\
        LOG_MESSAGE_SIMPLE(Log::LOG_ERROR, "%s: Player with pid \'%d\' not found\n", __PRETTY_FUNCTION__, pid);\
        /*ScriptFunctions::StopServer(1);*/ \
        return retvalue;\
}

struct Callbacks
{
    static constexpr ScriptCallbackData callbacks[]{
            {"OnServerInit",             Callback<>()},
            {"OnServerPostInit",         Callback<>()},
            {"OnServerExit",             Callback<bool>()},
            {"OnPlayerConnect",          Callback<PlayerId>()},
            {"OnPlayerDisconnect",       Callback<PlayerId>()},
            {"OnPlayerDeath",            Callback<PlayerId>()},
            {"OnPlayerResurrect",        Callback<PlayerId>()},
            {"OnPlayerCellChange",       Callback<PlayerId>()},
            {"OnPlayerAttribute",        Callback<PlayerId>()},
            {"OnPlayerSkill",            Callback<PlayerId>()},
            {"OnPlayerLevel",            Callback<PlayerId>()},
            {"OnPlayerBounty",           Callback<PlayerId>()},
            {"OnPlayerReputation",       Callback<PlayerId>()},
            {"OnPlayerEquipment",        Callback<PlayerId>()},
            {"OnPlayerInventory",        Callback<PlayerId>()},
            {"OnPlayerJournal",          Callback<PlayerId>()},
            {"OnPlayerFaction",          Callback<PlayerId>()},
            {"OnPlayerShapeshift",       Callback<PlayerId>()},
            {"OnPlayerSpellbook",        Callback<PlayerId>()},
            {"OnPlayerQuickKeys",        Callback<PlayerId>()},
            {"OnPlayerTopic",            Callback<PlayerId>()},
            {"OnPlayerDisposition",      Callback<PlayerId>()},
            {"OnPlayerBook",             Callback<PlayerId>()},
            {"OnPlayerItemUse",          Callback<PlayerId>()},
            {"OnPlayerMiscellaneous",    Callback<PlayerId>()},
            {"OnPlayerInput",            Callback<PlayerId>()},
            {"OnPlayerRest",             Callback<PlayerId>()},
            {"OnRecordDynamic",          Callback<PlayerId>()},
            {"OnCellLoad",               Callback<PlayerId, const char*>()},
            {"OnCellUnload",             Callback<PlayerId, const char*>()},
            {"OnCellDeletion",           Callback<const char*>()},
            {"OnContainer",              Callback<PlayerId, const char*>()},
            {"OnDoorState",              Callback<PlayerId, const char*>()},
            {"OnObjectActivate",         Callback<PlayerId, const char*>()},
            {"OnObjectPlace",            Callback<PlayerId, const char*>()},
            {"OnObjectState",            Callback<PlayerId, const char*>()},
            {"OnObjectSpawn",            Callback<PlayerId, const char*>()},
            {"OnObjectDelete",           Callback<PlayerId, const char*>()},
            {"OnObjectLock",             Callback<PlayerId, const char*>()},
            {"OnObjectScale",            Callback<PlayerId, const char*>()},
            {"OnObjectTrap",             Callback<PlayerId, const char*>()},
            {"OnVideoPlay",              Callback<PlayerId, const char*>()},
            {"OnActorList",              Callback<PlayerId, const char*>()},
            {"OnActorEquipment",         Callback<PlayerId, const char*>()},
            {"OnActorAI",                Callback<PlayerId, const char*>()},
            {"OnActorDeath",             Callback<PlayerId, const char*>()},
            {"OnActorCellChange",        Callback<PlayerId, const char*>()},
            {"OnActorTest",              Callback<PlayerId, const char*>()},
            {"OnPlayerSendMessage",      Callback<PlayerId, const char*>()},
            {"OnPlayerEndCharGen",       Callback<PlayerId>()},
            {"OnGUIAction",              Callback<PlayerId, int, const char*>()},
            {"OnWorldKillCount",         Callback<PlayerId>()},
            {"OnWorldMap",               Callback<PlayerId>()},
            {"OnWorldWeather",           Callback<PlayerId>() },
            {"OnMpNumIncrement",         Callback<int>()},
            {"OnRequestPluginList",      Callback<>()}
    };
};

#endif //SCRIPTFUNCTIONS_HPP
