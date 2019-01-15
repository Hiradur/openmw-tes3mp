//
// Created by koncord on 05.01.16.
//

#ifndef OPENMW_PLAYER_HPP
#define OPENMW_PLAYER_HPP

#include <map>
#include <string>
#include <chrono>
#include <RakNetTypes.h>

#include <components/esm/npcstats.hpp>
#include <components/esm/cellid.hpp>
#include <components/esm/loadnpc.hpp>
#include <components/esm/loadcell.hpp>

#include <components/openmw-mp/Log.hpp>
#include <components/openmw-mp/Base/BasePlayer.hpp>
#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>
#include "Cell.hpp"
#include "CellController.hpp"

struct Player;
typedef std::map<RakNet::RakNetGUID, Player*> TPlayers;
typedef std::map<unsigned short, Player*> TSlots;

class Players
{
public:
    static void newPlayer(const RakNet::RakNetGUID &guid);
    static void deletePlayer(const RakNet::RakNetGUID &guid);
    static Player *getPlayer(const RakNet::RakNetGUID &guid);
    static Player *getPlayer(unsigned short id);
    static TPlayers *getPlayers();
    static unsigned short getLastPlayerId();
    static bool doesPlayerExist(const RakNet::RakNetGUID &guid);

private:
    static TPlayers players;
    static TSlots slots;
};

class Player : public mwmp::BasePlayer
{
    friend class Cell;
public:
    const unsigned int InvalidID = (unsigned int) -1;
    enum
    {
        NOTLOADED=0,
        LOADED,
        POSTLOADED,
        KICKED
    };
    Player(const RakNet::RakNetGUID &guid);

    unsigned int getId();
    void setId(unsigned short id);

    bool isHandshaked();
    int getHandshakeAttempts();
    void incrementHandshakeAttempts();
    void setHandshake();

    void setLoadState(int state);
    int getLoadState();

    virtual ~Player();

    CellController::TContainer *getCells();
    void sendToLoaded(mwmp::PlayerPacket *myPacket);

    void forEachLoaded(std::function<void(Player *pl, Player *other)> func);

private:
    CellController::TContainer cells;
    int loadState;
    int handshakeCounter;
    unsigned int id;

};

#endif //OPENMW_PLAYER_HPP
