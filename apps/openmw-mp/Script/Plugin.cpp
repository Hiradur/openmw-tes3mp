//
// Created by koncord on 12.01.19.
//

#include "Plugin.hpp"

#include <cstdarg>
#include <algorithm>
#include <mutex>

Plugin::PluginList Plugin::plugins;
//constexpr ScriptCallbackData Plugin::callbacks[];

static Plugin* scriptTmpPtr; // hack for RegisterEvent

Plugin::Plugin(const std::string &pluginName)
{
    lib = OpenLibrary(pluginName.c_str());

    if (!lib)
        throw std::invalid_argument(std::string("Plugin ") + pluginName + " not found.");

    PluginInit = SystemInterface<decltype(PluginInit)>(lib, "PluginInit").result;
    if (!PluginInit)
        throw std::runtime_error("\"void PluginInit(int pluginId)\" not implemented by plugin");

    PluginFree = SystemInterface<decltype(PluginFree)>(lib, "PluginFree").result;
    if (!PluginFree)
        throw std::runtime_error("\"void PluginFree()\" not implemented");
}

Plugin::~Plugin()
{
    PluginFree();
    CloseLibrary(lib);
}

bool Plugin::LoadPlugin(const std::string &plugin)
{
    auto script = std::make_unique<Plugin>(plugin);
    scriptTmpPtr = script.get(); // needs for RegisterEvent

    bool result = script->PluginInit() == 1;

    scriptTmpPtr = nullptr; // reset value for safety

    if (result)
    {
        plugins.push_back(std::move(script));
        return true;
    }
    return false;
}

void Plugin::LoadPlugins(const std::vector<std::string> &pluginsList)
{
    for(const auto &plugin : pluginsList)
        LoadPlugin(plugin);
}

static std::string moddir;

void Plugin::SetModDir(const std::string &_moddir)
{
    if (moddir.empty()) // do not allow to change in runtime
        moddir = _moddir;
}

const char* Plugin::GetModDir()
{
    return moddir.c_str();
}

static std::string plugindir;

void Plugin::SetPluginDir(const std::string &pluginDir)
{
    if (plugindir.empty()) // do not allow to change in runtime
        plugindir = pluginDir;
}

const char *Plugin::GetPluginDir()
{
    return plugindir.c_str();
}
