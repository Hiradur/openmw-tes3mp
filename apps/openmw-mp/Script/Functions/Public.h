//
// Created by koncord on 09.12.18.
//

#ifndef OPENMW_PUBLIC_HPP
#define OPENMW_PUBLIC_HPP


#include "../api.h"
#include <stdarg.h>

NAMESPACE_BEGIN(PublicFunctions)
    API_FUNCTION void CDECL MakePublic(ScriptFunc _public, const char *name, char ret_type, const char *def) NOEXCEPT;
    API_FUNCTION RetType CDECL CallPublic(const char *name, ...) NOEXCEPT;
    API_FUNCTION const char *CDECL GetPublicName() NOEXCEPT;
    API_FUNCTION const char *GetPublicDefinition(const char *_public);
    API_FUNCTION char GetPublicReturnType(const char *_public);
NAMESPACE_END()

#endif
