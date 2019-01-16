//
// Created by koncord on 12.01.19.
//

#pragma once

#include "Utils.hpp"
#include "Types.hpp"

template<typename... Types>
using Callback = void (*)(Types...);

template<typename R>
using FunctionEllipsis = R(*)(...);

template<size_t N>
static constexpr unsigned int CallbackIndex(const char(&str)[N])
{
    return Utils::hash(str);
}

struct CallbackIdentity
{
    const char* types;
    const unsigned int numargs;

    constexpr bool matches(const char* types, const unsigned int N = 0) const
    {
        return N < numargs ? this->types[N] == types[N] && matches(types, N + 1) : this->types[N] == types[N];
    }

    template<typename... Types>
    constexpr CallbackIdentity(Callback<Types...>) : types(TypeString<Types...>::value), numargs(sizeof(TypeString<Types...>::value) - 1) {}
};

struct ScriptCallbackData
{
    const char* name;
    const unsigned long long index;
    const CallbackIdentity callback;

    template<size_t N>
    constexpr ScriptCallbackData(const char(&name)[N], CallbackIdentity _callback) : name(name), index(CallbackIndex(name)), callback(_callback) {}
};