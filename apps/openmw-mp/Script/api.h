/**
 * @file api.h
 * @brief External API for plugins.
 * @authors koncord
 * @date 08.01.19
 */

#ifndef NEWNATIVE_API_H
#define NEWNATIVE_API_H


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include "Platform.h"
#endif

/** @addtogroup APIFunctions API Functions
 *  @brief API provided by the server.
 *  @{
 **/

NAMESPACE_BEGIN(Event)

/**
 * @param event
 * @param addr
 */
API_FUNCTION void CDECL RegisterEvent(const char *event, void *addr);

NAMESPACE_END()

/** @}*/
#if !(defined _HOST || defined _LUAJIT_PREPROCESS)

/** @addtogroup PluginFunctions Plugin Functions
 *  @brief Those functions must be implemented by plugin.
 * @{
 */

/*! @brief This function must be implemented by every plugin.
 *
 * Called by the server on initialization process, there is no possible to call any API functions in this function.
 * If this function returns 0, PluginFree() will be called
 *
 * @return 1 on success 0 on fail
 */
EXPORT_FUNCTION int CDECL PluginInit();

/*! @brief This function must be implemented by every plugin.
 *
 * Called by the server on qutitting or failing to initialize plugin by PluginInit()
 */
EXPORT_FUNCTION void CDECL PluginFree();
/** @}*/
#endif

#endif //NEWNATIVE_API_H
