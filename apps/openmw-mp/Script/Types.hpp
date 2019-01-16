//
// Created by koncord on 23.01.16.
//

#pragma once


#include <cstdint>
#include <cstddef>
#include <type_traits>

template<typename T> struct sizeof_void { enum { value = sizeof(T) }; };
template<> struct sizeof_void<void> { enum { value = 0 }; };

template<typename T, size_t t> struct TypeChar { static_assert(!t, "Unsupported type in variadic type list"); };
template<> struct TypeChar<bool, sizeof(bool)> { enum { value = 'b' }; };
template<typename T> struct TypeChar<T *, sizeof(void *)> { enum { value = 'p' }; };
template<typename T> struct TypeChar<T, sizeof(uint8_t)> { enum { value = std::is_signed<T>::value ? 'c' : 'C' }; };
template<typename T> struct TypeChar<T, sizeof(uint16_t)> { enum { value = std::is_signed<T>::value ? 'h' : 'H' }; };
template<typename T> struct TypeChar<T, sizeof(uint32_t)> { enum { value = std::is_signed<T>::value ? 'i' : 'I' }; };
template<typename T> struct TypeChar<T, sizeof(uint64_t)> { enum { value = std::is_signed<T>::value ? 'l' : 'L' }; };
template<> struct TypeChar<float, sizeof(float)> { enum { value = 'd' }; };
template<> struct TypeChar<double, sizeof(double)> { enum { value = 'd' }; };
template<> struct TypeChar<char *, sizeof(char *)> { enum { value = 's' }; };
template<> struct TypeChar<const char *, sizeof(const char *)> { enum { value = 's' }; };
template<> struct TypeChar<void, sizeof_void<void>::value> { enum { value = 'v' }; };

template<typename... Types>
struct TypeString
{
    static constexpr char value[sizeof...(Types) + 1] = {
            TypeChar<Types, sizeof(Types)>::value...
    };
};

template<char t> struct CharType { static_assert(!t, "Unsupported type in variadic type list"); };
template<> struct CharType<'b'> { typedef bool type; };
template<> struct CharType<'p'> { typedef void* type; };

template<> struct CharType<'c'> { typedef int8_t type; };
template<> struct CharType<'C'> { typedef uint8_t type; };

template<> struct CharType<'h'> { typedef int16_t type; };
template<> struct CharType<'H'> { typedef uint16_t type; };

template<> struct CharType<'i'> { typedef int32_t type; };
template<> struct CharType<'I'> { typedef uint32_t type; };

template<> struct CharType<'l'> { typedef int64_t type; };
template<> struct CharType<'L'> { typedef uint64_t type; };

template<> struct CharType<'f'> { typedef double type; };
template<> struct CharType<'d'> { typedef double type; };

template<> struct CharType<'s'> { typedef const char* type; };
template<> struct CharType<'v'> { typedef void type; };

