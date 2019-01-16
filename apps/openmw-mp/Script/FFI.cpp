//
// Created by koncord on 09.01.19.
//

#include <cstring>
#include <cstdarg>
#include "FFI.hpp"

FFI::FFI(ScriptFunc func, char retFormat, const char *argFormat, ...)
{
    std::va_list argList;
    va_start(argList, argFormat);

    fnPtr = func;

    setArguments(argFormat, argList);
    setRetType(retFormat);

    va_end(argList);
}

void FFI::setArguments(const std::string &format, va_list argList)
{
    cifInitialized = false;
    va_list vaList;
    va_copy(vaList, argList);

    resize(format.size());

    for (size_t i = 0; i < format.size(); ++i)
    {
        switch (format[i])
        {
            case 'v':
                break;
            case 's': // const char*
                setArgument(i, (const char*) va_arg(vaList, const char*));
                break;
            case 'c':
                setArgument(i, (int8_t) va_arg(vaList, int));
                break;
            case 'C':
                setArgument(i, (uint8_t) va_arg(vaList, int));
                break;
            case 'h':
                setArgument(i, (int16_t) va_arg(vaList, int));
                break;
            case 'H':
                setArgument(i, (uint16_t) va_arg(vaList, int));
                break;
            case 'i':
                setArgument(i, va_arg(vaList, int32_t));
                break;
            case 'I':
                setArgument(i, va_arg(vaList, uint32_t));
                break;
            case 'l':
                setArgument(i, va_arg(vaList, int64_t));
                break;
            case 'L':
                setArgument(i, va_arg(vaList, uint64_t));
                break;
            case 'd':
            case 'f':
                setArgument(i, va_arg(vaList, double));
                break;
            case 'p':
                setArgument(i, va_arg(vaList, void*));
                break;
            case 'b': // bool
                setArgument(i, (bool) (va_arg(vaList, int) == 1));
                break;

            default:
                break;
        }
    }
    va_end(vaList);
}

void FFI::setRetType(char type)
{
    cifInitialized = false;
    retType = formatToFFIType(type);
}

void FFI::setFunctionPtr(ScriptFunc func)
{
    cifInitialized = false;
    fnPtr = func;
}

#include "Types.hpp"

ffi_type *FFI::formatToFFIType(char type)
{
    switch (type)
    {
        case 'v':
            return CToFFIType<void>();
        case 's':
            return CToFFIType<const char *>();
        case 'c':
            return CToFFIType<int8_t>();
        case 'C':
            return CToFFIType<uint8_t>();
        case 'h':
            return CToFFIType<int16_t>();
        case 'H':
            return CToFFIType<uint16_t>();
        case 'i':
            return CToFFIType<int32_t>();
        case 'I':
            return CToFFIType<uint32_t>();
        case 'l':
            return CToFFIType<int64_t>();
        case 'L':
            return CToFFIType<uint64_t>();
        case 'f':
        case 'd':
            return CToFFIType<double>();
        case 'p':
            return CToFFIType<void *>();
        case 'b': // bool
            return CToFFIType<bool>();
        default:
            throw std::invalid_argument(std::string("unknown argument type \'") + type + '\'');
    }
}

void FFI::resize(size_t size)
{
    types.resize(size);
    ptrs.resize(size);
    argsStore.resize(size);
}

RetType FFI::call()
{
    if (!cifInitialized)
    {
        cifInitialized = true;
        if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, (unsigned int) types.size(), retType, types.data()) != FFI_OK)
            throw std::runtime_error("Whoops! Cannot prepare CIF!");
    }
    ffi_arg retVal;
    ffi_call(&cif, FFI_FN(fnPtr), &retVal, ptrs.data());
    return retVal;
}
