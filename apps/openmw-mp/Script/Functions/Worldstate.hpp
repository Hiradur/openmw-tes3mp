#ifndef OPENMW_WORLDSTATEAPI_HPP
#define OPENMW_WORLDSTATEAPI_HPP

#include <components/openmw-mp/Base/BaseWorldstate.hpp>
#include "../Types.hpp"

#include <Script/Platform.hpp>

#define WORLDSTATEAPI \
    {"ReadReceivedWorldstate",            WorldstateFunctions::ReadReceivedWorldstate},\
    \
    {"CopyReceivedWorldstateToStore",     WorldstateFunctions::CopyReceivedWorldstateToStore},\
    \
    {"ClearMapChanges",                   WorldstateFunctions::ClearMapChanges},\
    \
    {"GetMapChangesSize",                 WorldstateFunctions::GetMapChangesSize},\
    \
    {"GetWeatherRegion",                  WorldstateFunctions::GetWeatherRegion},\
    {"GetWeatherCurrent",                 WorldstateFunctions::GetWeatherCurrent},\
    {"GetWeatherNext",                    WorldstateFunctions::GetWeatherNext},\
    {"GetWeatherQueued",                  WorldstateFunctions::GetWeatherQueued},\
    {"GetWeatherTransitionFactor",        WorldstateFunctions::GetWeatherTransitionFactor},\
    \
    {"GetMapTileCellX",                   WorldstateFunctions::GetMapTileCellX},\
    {"GetMapTileCellY",                   WorldstateFunctions::GetMapTileCellY},\
    \
    {"SetAuthorityRegion",                WorldstateFunctions::SetAuthorityRegion},\
    \
    {"SetWeatherRegion",                  WorldstateFunctions::SetWeatherRegion},\
    {"SetWeatherForceState",              WorldstateFunctions::SetWeatherForceState},\
    {"SetWeatherCurrent",                 WorldstateFunctions::SetWeatherCurrent},\
    {"SetWeatherNext",                    WorldstateFunctions::SetWeatherNext},\
    {"SetWeatherQueued",                  WorldstateFunctions::SetWeatherQueued},\
    {"SetWeatherTransitionFactor",        WorldstateFunctions::SetWeatherTransitionFactor},\
    \
    {"SetHour",                           WorldstateFunctions::SetHour},\
    {"SetDay",                            WorldstateFunctions::SetDay},\
    {"SetMonth",                          WorldstateFunctions::SetMonth},\
    {"SetYear",                           WorldstateFunctions::SetYear},\
    {"SetDaysPassed",                     WorldstateFunctions::SetDaysPassed},\
    {"SetTimeScale",                      WorldstateFunctions::SetTimeScale},\
    \
    {"SetPlayerCollisionState",           WorldstateFunctions::SetPlayerCollisionState},\
    {"SetActorCollisionState",            WorldstateFunctions::SetActorCollisionState},\
    {"SetPlacedObjectCollisionState",     WorldstateFunctions::SetPlacedObjectCollisionState},\
    {"UseActorCollisionForPlacedObjects", WorldstateFunctions::UseActorCollisionForPlacedObjects},\
    \
    {"AddEnforcedCollisionRefId",         WorldstateFunctions::AddEnforcedCollisionRefId},\
    {"ClearEnforcedCollisionRefIds",      WorldstateFunctions::ClearEnforcedCollisionRefIds},\
    \
    {"SaveMapTileImageFile",              WorldstateFunctions::SaveMapTileImageFile},\
    {"LoadMapTileImageFile",              WorldstateFunctions::LoadMapTileImageFile},\
    \
    {"SendWorldMap",                      WorldstateFunctions::SendWorldMap},\
    {"SendWorldTime",                     WorldstateFunctions::SendWorldTime},\
    {"SendWorldWeather",                  WorldstateFunctions::SendWorldWeather},\
    {"SendWorldCollisionOverride",        WorldstateFunctions::SendWorldCollisionOverride},\
    {"SendWorldRegionAuthority",          WorldstateFunctions::SendWorldRegionAuthority},\
    \
    {"ReadLastWorldstate",                WorldstateFunctions::ReadLastWorldstate},\
    {"CopyLastWorldstateToStore",         WorldstateFunctions::CopyLastWorldstateToStore}

namespace WorldstateFunctions
{
    EXPORT_APIFUNCTION mwmp::BaseWorldstate CDECL *readWorldstate;
    EXPORT_APIFUNCTION mwmp::BaseWorldstate CDECL writeWorldstate;

    /**
    * \brief Use the last worldstate received by the server as the one being read.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ReadReceivedWorldstate() noexcept;

    /**
    * \brief Take the contents of the read-only worldstate last received by the
    *        server from a player and move its contents to the stored worldstate
    *        that can be sent by the server.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL CopyReceivedWorldstateToStore() noexcept;

    /**
    * \brief Clear the map changes for the write-only worldstate.
    *
    * This is used to initialize the sending of new WorldMap packets.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ClearMapChanges() noexcept;

    /**
    * \brief Get the number of indexes in the read worldstate's map changes.
    *
    * \return The number of indexes.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetMapChangesSize() noexcept;

    /**
    * \brief Get the weather region in the read worldstate.
    *
    * \return The weather region.
    */
    EXPORT_APIFUNCTION const char *CDECL GetWeatherRegion() noexcept;

    /**
    * \brief Get the current weather in the read worldstate.
    *
    * \return The current weather.
    */
    EXPORT_APIFUNCTION int CDECL GetWeatherCurrent() noexcept;

    /**
    * \brief Get the next weather in the read worldstate.
    *
    * \return The next weather.
    */
    EXPORT_APIFUNCTION int CDECL GetWeatherNext() noexcept;

    /**
    * \brief Get the queued weather in the read worldstate.
    *
    * \return The queued weather.
    */
    EXPORT_APIFUNCTION int CDECL GetWeatherQueued() noexcept;

    /**
    * \brief Get the transition factor of the weather in the read worldstate.
    *
    * \return The transition factor of the weather.
    */
    EXPORT_APIFUNCTION double CDECL GetWeatherTransitionFactor() noexcept;

    /**
    * \brief Get the X coordinate of the cell corresponding to the map tile at a certain index in
    *        the read worldstate's map tiles.
    *
    * \param index The index of the map tile.
    * \return The X coordinate of the cell.
    */
    EXPORT_APIFUNCTION int CDECL GetMapTileCellX(unsigned int index) noexcept;

    /**
    * \brief Get the Y coordinate of the cell corresponding to the map tile at a certain index in
    *        the read worldstate's map tiles.
    *
    * \param index The index of the map tile.
    * \return The Y coordinate of the cell.
    */
    EXPORT_APIFUNCTION int CDECL GetMapTileCellY(unsigned int index) noexcept;

    /**
    * \brief Set the region affected by the next WorldRegionAuthority packet sent.
    *
    * \param region The region.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetAuthorityRegion(const char* authorityRegion) noexcept;

    /**
    * \brief Set the weather region in the write-only worldstate stored on the server.
    *
    * \param region The region.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetWeatherRegion(const char* region) noexcept;

    /**
    * \brief Set the weather forcing state in the write-only worldstate stored on the server.
    *
    * Players who receive a packet with forced weather will switch to that weather immediately.
    *
    * \param forceState The weather forcing state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetWeatherForceState(bool forceState) noexcept;

    /**
    * \brief Set the current weather in the write-only worldstate stored on the server.
    *
    * \param currentWeather The current weather.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetWeatherCurrent(int currentWeather) noexcept;

    /**
    * \brief Set the next weather in the write-only worldstate stored on the server.
    *
    * \param nextWeather The next weather.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetWeatherNext(int nextWeather) noexcept;

    /**
    * \brief Set the queued weather in the write-only worldstate stored on the server.
    *
    * \param queuedWeather The queued weather.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetWeatherQueued(int queuedWeather) noexcept;

    /**
    * \brief Set the transition factor for the weather in the write-only worldstate stored on the server.
    *
    * \param transitionFactor The transition factor.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetWeatherTransitionFactor(double transitionFactor) noexcept;

    /**
    * \brief Set the world's hour in the write-only worldstate stored on the server.
    *
    * \param hour The hour.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetHour(double hour) noexcept;

    /**
    * \brief Set the world's day in the write-only worldstate stored on the server.
    *
    * \param day The day.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetDay(int day) noexcept;

    /**
    * \brief Set the world's month in the write-only worldstate stored on the server.
    *
    * \param month The month.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetMonth(int month) noexcept;

    /**
    * \brief Set the world's year in the write-only worldstate stored on the server.
    *
    * \param year The year.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetYear(int year) noexcept;

    /**
    * \brief Set the world's days passed in the write-only worldstate stored on the server.
    *
    * \param daysPassed The days passed.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetDaysPassed(int daysPassed) noexcept;

    /**
    * \brief Set the world's time scale in the write-only worldstate stored on the server.
    *
    * \param pid The player ID.
    * \param timeScale The time scale.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetTimeScale(double timeScale) noexcept;

    /**
    * \brief Set the collision state for other players in the write-only worldstate stored
    *        on the server.
    *
    * \param state The collision state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetPlayerCollisionState(bool state) noexcept;

    /**
    * \brief Set the collision state for actors in the write-only worldstate stored on the
    *        server.
    *
    * \param state The collision state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetActorCollisionState(bool state) noexcept;

    /**
    * \brief Set the collision state for placed objects in the write-only worldstate stored
    *        on the server.
    *
    * \param state The collision state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetPlacedObjectCollisionState(bool state) noexcept;

    /**
    * \brief Whether placed objects with collision turned on should use actor collision, i.e.
    *        whether they should be slippery and prevent players from standing on them.
    *
    * \param useActorCollision Whether to use actor collision.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL UseActorCollisionForPlacedObjects(bool useActorCollision) noexcept;

    /**
    * \brief Add a refId to the list of refIds for which collision should be enforced
    *        irrespective of other settings.
    *
    * \param refId The refId.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddEnforcedCollisionRefId(const char* refId) noexcept;

    /**
    * \brief Clear the list of refIdsd for which collision should be enforced irrespective
    *        of other settings.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ClearEnforcedCollisionRefIds() noexcept;

    /**
    * \brief Save the .png image data of the map tile at a certain index in the read worldstate's
    *        map changes.
    *
    * \param index The index of the map tile.
    * \param filePath The file path of the resulting file.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SaveMapTileImageFile(unsigned int index, const char *filePath) noexcept;

    /**
    * \brief Load a .png file as the image data for a map tile and add it to the write-only worldstate
    *        stored on the server.
    *
    * \param cellX The X coordinate of the cell corresponding to the map tile.
    * \param cellY The Y coordinate of the cell corresponding to the map tile.
    * \param filePath The file path of the loaded file.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL LoadMapTileImageFile(int cellX, int cellY, const char* filePath) noexcept;

    /**
    * \brief Send a WorldRegionAuthority packet establishing a certain player as the only one who
    *        should process certain region-specific events (such as weather changes).
    *
    * It is always sent to all players.
    *
    * \param pid The player ID attached to the packet.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendWorldRegionAuthority(unsigned short pid) noexcept;

    /**
    * \brief Send a WorldMap packet with the current set of map changes in the write-only
    *        worldstate.
    *
    * \param pid The player ID attached to the packet.
    * \param broadcast Whether this packet should be sent only to the attached player
    *                  or to all players on the server.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendWorldMap(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a WorldTime packet with the current time and time scale in the write-only
    *        worldstate.
    *
    * \param pid The player ID attached to the packet.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendWorldTime(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a WorldWeather packet with the current weather in the write-only worldstate.
    *
    * \param pid The player ID attached to the packet.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendWorldWeather(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a WorldCollisionOverride packet with the current collision overrides in
    *        the write-only worldstate.
    *
    * \param pid The player ID attached to the packet.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendWorldCollisionOverride(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;


    // All methods below are deprecated versions of methods from above

    EXPORT_APIFUNCTION void CDECL ReadLastWorldstate() noexcept;
    EXPORT_APIFUNCTION void CDECL CopyLastWorldstateToStore() noexcept;
}

#endif //OPENMW_WORLDSTATEAPI_HPP
