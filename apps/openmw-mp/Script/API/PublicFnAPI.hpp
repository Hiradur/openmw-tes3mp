//
// Created by koncord on 14.05.16.
//

#ifndef PLUGINSYSTEM3_PUBLICFNAPI_HPP
#define PLUGINSYSTEM3_PUBLICFNAPI_HPP

#include <unordered_map>
#include <Script/FFI.hpp>


class Public : public FFI
{
private:
    ~Public();

    static std::unordered_map<std::string, Public *> publics;

    Public(ScriptFunc _public, const std::string &name, char ret_type, const std::string &def);

    std::string def;
    char retType;
public:
    template<typename... Args>
    static void MakePublic(Args &&... args) { new Public(std::forward<Args>(args)...); }

    static ffi_arg Call(const std::string &name, va_list args);

    static const std::string &GetName();

    static const std::string &GetDefinition(const std::string &name);
    static char GetReturnType(const std::string &name);

    static void DeleteAll();
};

#endif //PLUGINSYSTEM3_PUBLICFNAPI_HPP
