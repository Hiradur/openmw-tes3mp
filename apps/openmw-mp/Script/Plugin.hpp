//
// Created by koncord on 12.01.19.
//

#pragma once

#include "SystemInterface.hpp"
#include "Callbacks.hpp"

#include <unordered_map>
#include <memory>
#include <vector>

class Plugin: Callbacks
{
private:
    lib_t lib;
    void (*PluginFree)();
    int (*PluginInit)();

    typedef std::vector<std::unique_ptr<Plugin>> PluginList;
    std::unordered_map<unsigned int, FunctionEllipsis<void>> callbacks_;

    static PluginList plugins;

public:
    explicit Plugin(const std::string &pluginName);
    ~Plugin();
    Plugin(const Plugin&) = delete;
    Plugin& operator=(const Plugin&) = delete;

    static bool LoadPlugin(const std::string &plugin);
    static void LoadPlugins(const std::vector<std::string> &pluginsList);
    static void SetModDir(const std::string &moddir);
    static const char* GetModDir();
    static void SetPluginDir(const std::string &pluginDir);
    static const char* GetPluginDir();

    static constexpr ScriptCallbackData const& CallBackData(const unsigned int I, const unsigned int N = 0)
    {
        return callbacks[N].index == I ? callbacks[N] : CallBackData(I, N + 1);
    }

    template<unsigned int I, bool B = false, typename... Args>
    static unsigned int Call(Args&&... args)
    {
        constexpr ScriptCallbackData const& data = CallBackData(I);
        static_assert(data.callback.matches(TypeString<typename std::remove_reference<Args>::type...>::value),
                      "Wrong number or types of arguments");

        unsigned int count = 0;

        for (auto& plugin : plugins)
        {
            if (!plugin->callbacks_.count(I))
                plugin->callbacks_.emplace(I, SystemInterface<FunctionEllipsis<void>>(plugin->lib, data.name).result);

            auto callback = plugin->callbacks_[I];

            if (!callback)
                continue;

            (callback)(std::forward<Args>(args)...);
            ++count;
        }

        return count;
    }
};
