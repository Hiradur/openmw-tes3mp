//
// Created by koncord on 09.12.18.
//

#include "Public.h"

#include <Script/Callbacks.hpp>
#include <Script/API/PublicFnAPI.hpp>

extern "C" void PublicFunctions::MakePublic(ScriptFunc _public, const char *name, char ret_type, const char *def) noexcept
{
    Public::MakePublic(_public, name, ret_type, def);
}

extern "C" RetType PublicFunctions::CallPublic(const char *name, ...) noexcept
{
    try
    {
        va_list args;
        va_start(args, name);
        RetType ret = Public::Call(name, args);
        va_end(args);
        return ret;
    }
    catch (...) {}

    return 0;
}

const char *PublicFunctions::GetPublicName() NOEXCEPT
{
    const std::string &str = Public::GetName();
    if(str.empty())
        return nullptr;
    else
        return str.c_str();
}

const char *PublicFunctions::GetPublicDefinition(const char *_public)
{
    return Public::GetDefinition(_public).c_str();
}

char PublicFunctions::GetPublicReturnType(const char *_public)
{
    return Public::GetReturnType(_public);
}
