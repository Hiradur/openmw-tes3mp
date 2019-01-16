//
// Created by koncord on 09.01.19.
//

#pragma once

extern "C"
{
#include <ffi.h>
}
#include <stdexcept>
#include "ArgsStore.hpp"
#include <Script/CTypes.h>
class FFI
{
private:
    std::vector<ffi_type *> types;
    std::vector<void *> ptrs;
    TArgsStore argsStore;
    ffi_type *retType;
    bool cifInitialized;
    ffi_cif cif;
    ScriptFunc fnPtr;

    void resize(size_t size);

    template<typename T>
    constexpr ffi_type *CToFFIType()
    {
        if (std::is_same<T, bool>::value)
            return &ffi_type_sint8;
        if (std::is_same<T, void>::value)
            return &ffi_type_void;
        if (std::is_same<T, uint8_t>::value)
            return &ffi_type_uint8;
        if (std::is_same<T, int8_t>::value)
            return &ffi_type_sint8;
        if (std::is_same<T, uint16_t>::value)
            return &ffi_type_uint16;
        if (std::is_same<T, int16_t>::value)
            return &ffi_type_sint16;
        if (std::is_same<T, uint32_t>::value)
            return &ffi_type_uint32;
        if (std::is_same<T, int32_t>::value)
            return &ffi_type_sint32;
        if (std::is_same<T, uint64_t>::value)
            return &ffi_type_uint64;
        if (std::is_same<T, int64_t>::value)
            return &ffi_type_sint64;
        if (std::is_same<T, float>::value)
            return &ffi_type_float;
        if (std::is_same<T, double>::value)
            return &ffi_type_double;
        if (std::is_pointer<T>::value)
            return &ffi_type_pointer;
    }

    template<typename T>
    void setArgument(size_t index, const T &v)
    {
        types[index] = CToFFIType<T>();
        argsStore[index] = v;
        ptrs[index] = (void *) &std::get<T>(argsStore[index]);
    }
    ffi_type *formatToFFIType(char type);

protected:
    FFI() = default;
public:
    explicit FFI(ScriptFunc func, char retFormat, const char *argFormat, ...);

    void setArguments(const std::string &format, va_list argList);
    void setRetType(char type);
    void setFunctionPtr(ScriptFunc func);

    RetType call();
};
