//
// Created by koncord on 21.04.17.
//

#ifndef NEWMASTERPROTO_MASTERDATA_HPP
#define NEWMASTERPROTO_MASTERDATA_HPP

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <list>
#include <MessageIdentifiers.h>

enum MASTER_PACKETS
{
    ID_MASTER_QUERY = ID_USER_PACKET_ENUM,
    ID_MASTER_UPDATE,
    ID_MASTER_ANNOUNCE
};

struct ServerRule
{
    enum Type : char
    {
        string = 's',
        number = 'v'
    } type;

    std::string str;
    double val;
};

struct _Plugin
{
    std::string name;
    unsigned hash;
    _Plugin(std::string name = "", unsigned hash = 0): name(std::move(name)), hash(hash) {};
};

struct QueryData
{
    QueryData()
    {
        rules["name"].type = ServerRule::Type::string;
        rules["name"].str.clear();
        rules["version"].type = ServerRule::Type::string;
        rules["version"].str.clear();
        rules["players"].type = ServerRule::Type::number;
        rules["players"].val = 0;
        rules["maxPlayers"].type = ServerRule::Type::number;
        rules["maxPlayers"].val = 0;
        rules["gamemode"].type = ServerRule::Type::string;
        rules["gamemode"].str.clear();
        rules["passw"].type = ServerRule::Type::number;
        rules["passw"].val = 0;
    }
    const char *GetName() const { return rules.at("name").str.c_str(); }
    void SetName(const char *name) { rules["name"].str = name; }

    const char *GetVersion() const { return rules.at("version").str.c_str(); }
    void SetVersion(const char *version) { rules["version"].str = version; }

    int GetPlayers() const { return rules.at("players").val; }
    void SetPlayers(int players) { rules["players"].val = players; }

    int GetMaxPlayers() const { return rules.at("maxPlayers").val; }
    void SetMaxPlayers(int players) { rules["maxPlayers"].val = players; }

    const char *GetGameMode() const { return rules.at("gamemode").str.c_str(); }
    void SetGameMode(const char *str) { rules["gamemode"].str = str; }

    void SetPassword(int value) { rules["passw"].val = value; };
    int GetPassword() const { return rules.at("passw").val; }


    std::vector<std::string> players;
    std::map<std::string, ServerRule> rules;
    std::vector<_Plugin> plugins;
    const static int predefinedRules = 6;
    const static int maxRules = 128;
    const static int maxUserRules = maxRules - predefinedRules;
    const static int maxPlayers = 100; // will shown only maxPlayers players
    const static int maxPlugins = 256;
    const static int maxStringLength = 256;
};

#endif //NEWMASTERPROTO_MASTERDATA_HPP
