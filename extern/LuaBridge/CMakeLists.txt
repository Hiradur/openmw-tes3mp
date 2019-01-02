set (LUABRIDGE_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/List.h
	${CMAKE_CURRENT_SOURCE_DIR}/LuaBridge.h
	${CMAKE_CURRENT_SOURCE_DIR}/Map.h
	${CMAKE_CURRENT_SOURCE_DIR}/RefCountedObject.h
	${CMAKE_CURRENT_SOURCE_DIR}/RefCountedPtr.h
	${CMAKE_CURRENT_SOURCE_DIR}/Vector.h
)
source_group ("LuaBridge" FILES ${LUABRIDGE_HEADERS})

set (LUABRIDGE_DETAIL_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/detail/CFunctions.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/ClassInfo.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/Constructor.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/dump.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/FuncTraits.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/Iterator.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/LuaException.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/LuaHelpers.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/LuaRef.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/Namespace.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/Stack.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/TypeList.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/TypeTraits.h
	${CMAKE_CURRENT_SOURCE_DIR}/detail/Userdata.h
)
source_group ("LuaBridge\\detail" FILES ${LUABRIDGE_DETAIL_HEADERS})

add_library (LuaBridge INTERFACE)
target_sources (LuaBridge INTERFACE
    ${LUABRIDGE_HEADERS}
    ${LUABRIDGE_DETAIL_HEADERS}
)
target_include_directories (LuaBridge INTERFACE .)

if (MSVC)
    add_custom_target (LuaBridgeLibrary SOURCES
		${LUABRIDGE_HEADERS}
		${LUABRIDGE_DETAIL_HEADERS}
	)
endif ()
