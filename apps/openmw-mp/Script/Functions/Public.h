//
// Created by koncord on 09.12.18.
//

#ifndef OPENMW_PUBLIC_HPP
#define OPENMW_PUBLIC_HPP

#include <apps/openmw-mp/Script/ScriptFunction.hpp>
#include "../api.h"

NAMESPACE_BEGIN(PublicFunctions)
    API_FUNCTION void CDECL MakePublic(ScriptFunc _public, const char *name, char ret_type, const char *def) noexcept;
    API_FUNCTION boost::any CDECL CallPublic(const char *name, va_list args) noexcept;
NAMESPACE_END()

#endif
