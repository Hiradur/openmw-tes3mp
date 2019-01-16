//
// Created by koncord on 19.03.16.
//

#pragma once

#ifdef _WIN32
#include <winsock2.h>
typedef HMODULE lib_t;
#else
#include <dlfcn.h>
typedef void *lib_t;
#endif

template<typename R = void *>
struct SystemInterface
{

    union
    {
        R result;
#ifdef _WIN32
        decltype(GetProcAddress(lib_t(), nullptr)) data;
#else
        decltype(dlsym(lib_t(), nullptr)) data;
#endif
    };

#ifndef _WIN32
    static_assert(sizeof(result) == sizeof(data), "R should have the same size");
#endif

    SystemInterface() : data(nullptr) {}
    explicit operator bool() { return data; }

#ifdef _WIN32
    SystemInterface(lib_t handle, const char* name) : data(GetProcAddress(handle, name)) {}
#else
    SystemInterface(lib_t handle, const char *name) : data(dlsym(handle, name)) {}
#endif
};

#ifdef _WIN32
#define OpenLibrary(pluginName) LoadLibrary(pluginName)
#define CloseLibrary(lib) FreeLibrary(lib)
#else
#define OpenLibrary(pluginName) dlopen(pluginName, RTLD_LAZY | RTLD_LOCAL)
#define CloseLibrary(lib) dlclose(lib)
#endif
