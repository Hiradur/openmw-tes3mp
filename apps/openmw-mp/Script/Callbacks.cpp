#include "Callbacks.hpp"
#include "API/PublicFnAPI.hpp"
#include <cstdarg>
#include <iostream>
#include <apps/openmw-mp/Player.hpp>
#include <apps/openmw-mp/Networking.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

template<typename... Types>
constexpr char TypeString<Types...>::value[];
constexpr ScriptCallbackData Callbacks::callbacks[];

using namespace std;
