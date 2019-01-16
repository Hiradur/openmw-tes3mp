//
// Created by koncord on 14.05.16.
//

#include "PublicFnAPI.hpp"

#include <stack>
using namespace std;

unordered_map<string, Public *> Public::publics;

static std::stack<std::string> publicsStack;

Public::~Public()
{

}

Public::Public(ScriptFunc _public, const std::string &name, char ret_type, const std::string &def): def(def), retType(ret_type)
{
    setRetType(ret_type);
    setFunctionPtr(_public);
    publics.emplace(name, this);
}

ffi_arg Public::Call(const std::string &name, va_list args)
{
    auto it = publics.find(name);
    if (it == publics.end())
        throw runtime_error("Public with name \"" + name + "\" does not exist");

    Public *_pub = it->second;

    publicsStack.push(it->first);
    _pub->setArguments(_pub->def, args);

    ffi_arg res = _pub->call();

    publicsStack.pop();
    return res;
}

const std::string &Public::GetName()
{
    static std::string name;
    if (!publicsStack.empty())
        name = publicsStack.top();
    else
        name.clear();
    return name;
}


const std::string &Public::GetDefinition(const std::string &name)
{
    auto it = publics.find(name);

    if (it == publics.end())
        throw runtime_error("Public with name \"" + name + "\" does not exist");

    return it->second->def;
}

char Public::GetReturnType(const std::string &name)
{
    auto it = publics.find(name);

    if (it == publics.end())
        throw runtime_error("Public with name \"" + name + "\" does not exist");

    return it->second->retType;
}

void Public::DeleteAll()
{
    for (auto it = publics.begin(); it != publics.end(); ++it)
    {
        Public *_public = it->second;
        delete _public;
        publics.erase(it);
    }
}
