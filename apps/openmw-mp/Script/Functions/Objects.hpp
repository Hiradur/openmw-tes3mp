#ifndef OPENMW_OBJECTAPI_HPP
#define OPENMW_OBJECTAPI_HPP

#include <Script/Platform.hpp>

#define OBJECTAPI \
    {"ReadReceivedObjectList",                ObjectFunctions::ReadReceivedObjectList},\
    \
    {"ClearObjectList",                       ObjectFunctions::ClearObjectList},\
    {"SetObjectListPid",                      ObjectFunctions::SetObjectListPid},\
    \
    {"CopyReceivedObjectListToStore",         ObjectFunctions::CopyReceivedObjectListToStore},\
    \
    {"GetObjectListSize",                     ObjectFunctions::GetObjectListSize},\
    {"GetObjectListOrigin",                   ObjectFunctions::GetObjectListOrigin},\
    {"GetObjectListClientScript",             ObjectFunctions::GetObjectListClientScript},\
    {"GetObjectListAction",                   ObjectFunctions::GetObjectListAction},\
    {"GetObjectListContainerSubAction",       ObjectFunctions::GetObjectListContainerSubAction},\
    \
    {"IsObjectPlayer",                        ObjectFunctions::IsObjectPlayer},\
    {"GetObjectPid",                          ObjectFunctions::GetObjectPid},\
    {"GetObjectRefId",                        ObjectFunctions::GetObjectRefId},\
    {"GetObjectRefNum",                       ObjectFunctions::GetObjectRefNum},\
    {"GetObjectMpNum",                        ObjectFunctions::GetObjectMpNum},\
    {"GetObjectCount",                        ObjectFunctions::GetObjectCount},\
    {"GetObjectCharge",                       ObjectFunctions::GetObjectCharge},\
    {"GetObjectEnchantmentCharge",            ObjectFunctions::GetObjectEnchantmentCharge},\
    {"GetObjectSoul" ,                        ObjectFunctions::GetObjectSoul},\
    {"GetObjectGoldValue",                    ObjectFunctions::GetObjectGoldValue},\
    {"GetObjectScale",                        ObjectFunctions::GetObjectScale},\
    {"GetObjectState",                        ObjectFunctions::GetObjectState},\
    {"GetObjectDoorState",                    ObjectFunctions::GetObjectDoorState},\
    {"GetObjectLockLevel",                    ObjectFunctions::GetObjectLockLevel},\
    \
    {"DoesObjectHavePlayerActivating",        ObjectFunctions::DoesObjectHavePlayerActivating},\
    {"GetObjectActivatingPid",                ObjectFunctions::GetObjectActivatingPid},\
    {"GetObjectActivatingRefId",              ObjectFunctions::GetObjectActivatingRefId},\
    {"GetObjectActivatingRefNum",             ObjectFunctions::GetObjectActivatingRefNum},\
    {"GetObjectActivatingMpNum",              ObjectFunctions::GetObjectActivatingMpNum},\
    {"GetObjectActivatingName",               ObjectFunctions::GetObjectActivatingName},\
    \
    {"GetObjectSummonState",                  ObjectFunctions::GetObjectSummonState},\
    {"GetObjectSummonDuration",               ObjectFunctions::GetObjectSummonDuration},\
    {"DoesObjectHavePlayerSummoner",          ObjectFunctions::DoesObjectHavePlayerSummoner},\
    {"GetObjectSummonerPid",                  ObjectFunctions::GetObjectSummonerPid},\
    {"GetObjectSummonerRefId",                ObjectFunctions::GetObjectSummonerRefId},\
    {"GetObjectSummonerRefNum",               ObjectFunctions::GetObjectSummonerRefNum},\
    {"GetObjectSummonerMpNum",                ObjectFunctions::GetObjectSummonerMpNum},\
    \
    {"GetObjectPosX",                         ObjectFunctions::GetObjectPosX},\
    {"GetObjectPosY",                         ObjectFunctions::GetObjectPosY},\
    {"GetObjectPosZ",                         ObjectFunctions::GetObjectPosZ},\
    {"GetObjectRotX",                         ObjectFunctions::GetObjectRotX},\
    {"GetObjectRotY",                         ObjectFunctions::GetObjectRotY},\
    {"GetObjectRotZ",                         ObjectFunctions::GetObjectRotZ},\
    \
    {"GetVideoFilename",                      ObjectFunctions::GetVideoFilename},\
    \
    {"GetContainerChangesSize",               ObjectFunctions::GetContainerChangesSize},\
    {"GetContainerItemRefId",                 ObjectFunctions::GetContainerItemRefId},\
    {"GetContainerItemCount",                 ObjectFunctions::GetContainerItemCount},\
    {"GetContainerItemCharge",                ObjectFunctions::GetContainerItemCharge},\
    {"GetContainerItemEnchantmentCharge",     ObjectFunctions::GetContainerItemEnchantmentCharge},\
    {"GetContainerItemSoul",                  ObjectFunctions::GetContainerItemSoul},\
    {"GetContainerItemActionCount",           ObjectFunctions::GetContainerItemActionCount},\
    \
    {"DoesObjectHaveContainer",               ObjectFunctions::DoesObjectHaveContainer},\
    \
    {"SetObjectListCell",                     ObjectFunctions::SetObjectListCell},\
    {"SetObjectListAction",                   ObjectFunctions::SetObjectListAction},\
    {"SetObjectListConsoleCommand",           ObjectFunctions::SetObjectListConsoleCommand},\
    \
    {"SetObjectRefId",                        ObjectFunctions::SetObjectRefId},\
    {"SetObjectRefNum",                       ObjectFunctions::SetObjectRefNum},\
    {"SetObjectMpNum",                        ObjectFunctions::SetObjectMpNum},\
    {"SetObjectCount",                        ObjectFunctions::SetObjectCount},\
    {"SetObjectCharge",                       ObjectFunctions::SetObjectCharge},\
    {"SetObjectEnchantmentCharge",            ObjectFunctions::SetObjectEnchantmentCharge},\
    {"SetObjectSoul",                         ObjectFunctions::SetObjectSoul},\
    {"SetObjectGoldValue",                    ObjectFunctions::SetObjectGoldValue},\
    {"SetObjectScale",                        ObjectFunctions::SetObjectScale},\
    {"SetObjectState",                        ObjectFunctions::SetObjectState},\
    {"SetObjectLockLevel",                    ObjectFunctions::SetObjectLockLevel},\
    {"SetObjectDisarmState",                  ObjectFunctions::SetObjectDisarmState},\
    {"SetObjectSummonDuration",               ObjectFunctions::SetObjectSummonDuration},\
    {"SetObjectSummonState",                  ObjectFunctions::SetObjectSummonState},\
    {"SetObjectPosition",                     ObjectFunctions::SetObjectPosition},\
    {"SetObjectRotation",                     ObjectFunctions::SetObjectRotation},\
    \
    {"SetObjectActivatingPid",                ObjectFunctions::SetObjectActivatingPid},\
    \
    {"SetObjectDoorState",                    ObjectFunctions::SetObjectDoorState},\
    {"SetObjectDoorTeleportState",            ObjectFunctions::SetObjectDoorTeleportState},\
    {"SetObjectDoorDestinationCell",          ObjectFunctions::SetObjectDoorDestinationCell},\
    {"SetObjectDoorDestinationPosition",      ObjectFunctions::SetObjectDoorDestinationPosition},\
    {"SetObjectDoorDestinationRotation",      ObjectFunctions::SetObjectDoorDestinationRotation},\
    \
    {"SetPlayerAsObject",                     ObjectFunctions::SetPlayerAsObject},\
    \
    {"SetContainerItemRefId",                 ObjectFunctions::SetContainerItemRefId},\
    {"SetContainerItemCount",                 ObjectFunctions::SetContainerItemCount},\
    {"SetContainerItemCharge",                ObjectFunctions::SetContainerItemCharge},\
    {"SetContainerItemEnchantmentCharge",     ObjectFunctions::SetContainerItemEnchantmentCharge},\
    {"SetContainerItemSoul",                  ObjectFunctions::SetContainerItemSoul},\
    \
    {"SetContainerItemActionCountByIndex",    ObjectFunctions::SetContainerItemActionCountByIndex},\
    \
    {"AddObject",                             ObjectFunctions::AddObject},\
    {"AddContainerItem",                      ObjectFunctions::AddContainerItem},\
    \
    {"SendObjectActivate",                    ObjectFunctions::SendObjectActivate},\
    {"SendObjectPlace",                       ObjectFunctions::SendObjectPlace},\
    {"SendObjectSpawn",                       ObjectFunctions::SendObjectSpawn},\
    {"SendObjectDelete",                      ObjectFunctions::SendObjectDelete},\
    {"SendObjectLock",                        ObjectFunctions::SendObjectLock},\
    {"SendObjectTrap",                        ObjectFunctions::SendObjectTrap},\
    {"SendObjectScale",                       ObjectFunctions::SendObjectScale},\
    {"SendObjectState",                       ObjectFunctions::SendObjectState},\
    {"SendDoorState",                         ObjectFunctions::SendDoorState},\
    {"SendDoorDestination",                   ObjectFunctions::SendDoorDestination},\
    {"SendContainer",                         ObjectFunctions::SendContainer},\
    {"SendVideoPlay",                         ObjectFunctions::SendVideoPlay},\
    {"SendConsoleCommand",                    ObjectFunctions::SendConsoleCommand},\
    \
    {"ReadLastObjectList",                    ObjectFunctions::ReadLastObjectList},\
    {"ReadLastEvent",                         ObjectFunctions::ReadLastEvent},\
    {"InitializeObjectList",                  ObjectFunctions::InitializeObjectList},\
    {"InitializeEvent",                       ObjectFunctions::InitializeEvent},\
    {"CopyLastObjectListToStore",             ObjectFunctions::CopyLastObjectListToStore},\
    {"GetObjectChangesSize",                  ObjectFunctions::GetObjectChangesSize},\
    {"GetEventAction",                        ObjectFunctions::GetEventAction},\
    {"GetEventContainerSubAction",            ObjectFunctions::GetEventContainerSubAction},\
    {"GetObjectRefNumIndex",                  ObjectFunctions::GetObjectRefNumIndex},\
    {"GetObjectSummonerRefNumIndex",          ObjectFunctions::GetObjectSummonerRefNumIndex},\
    {"SetEventCell",                          ObjectFunctions::SetEventCell},\
    {"SetEventAction",                        ObjectFunctions::SetEventAction},\
    {"SetEventConsoleCommand",                ObjectFunctions::SetEventConsoleCommand},\
    {"SetObjectRefNumIndex",                  ObjectFunctions::SetObjectRefNumIndex},\
    {"AddWorldObject",                        ObjectFunctions::AddWorldObject}

namespace ObjectFunctions
{
    /**
    * \brief Use the last object list received by the server as the one being read.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ReadReceivedObjectList() noexcept;

    /**
    * \brief Clear the data from the object list stored on the server.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ClearObjectList() noexcept;

    /**
    * \brief Set the pid attached to the ObjectList.
    *
    * \param pid The player ID to whom the object list should be attached.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectListPid(unsigned short pid) noexcept;

    /**
    * \brief Take the contents of the read-only object list last received by the
    *        server from a player and move its contents to the stored object list
    *        that can be sent by the server.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL CopyReceivedObjectListToStore() noexcept;

    /**
    * \brief Get the number of indexes in the read object list.
    *
    * \return The number of indexes.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectListSize() noexcept;

    /**
    * \brief Get the origin of the read object list.
    *
    * \return The origin (0 for CLIENT_GAMEPLAY, 1 for CLIENT_CONSOLE, 2 for
    * CLIENT_DIALOGUE, 3 for CLIENT_SCRIPT_LOCAL, 4 for CLIENT_SCRIPT_GLOBAL,
    * 5 for SERVER_SCRIPT).
    */
    EXPORT_APIFUNCTION unsigned char CDECL GetObjectListOrigin() noexcept;

    /**
    * \brief Get the client script that the read object list originated from.
    *
    * Note: This is not yet implemented.
    *
    * \return The ID of the client script.
    */
    EXPORT_APIFUNCTION const char *CDECL GetObjectListClientScript() noexcept;

    /**
    * \brief Get the action type used in the read object list.
    *
    * \return The action type (0 for SET, 1 for ADD, 2 for REMOVE, 3 for REQUEST).
    */
    EXPORT_APIFUNCTION unsigned char CDECL GetObjectListAction() noexcept;

    /**
    * \brief Get the container subaction type used in the read object list.
    *
    * \return The action type (0 for NONE, 1 for DRAG, 2 for DROP, 3 for TAKE_ALL).
    */
    EXPORT_APIFUNCTION unsigned char CDECL GetObjectListContainerSubAction() noexcept;

    /**
    * \brief Check whether the object at a certain index in the read object list is a
    * player.
    *
    * Note: Although most player data and events are dealt with in Player packets,
    *       object activation is general enough for players themselves to be included
    *       as objects in ObjectActivate packets.
    *
    * \param index The index of the object.
    * \return Whether the object is a player.
    */
    EXPORT_APIFUNCTION bool CDECL IsObjectPlayer(unsigned int index) noexcept;

    /**
    * \brief Get the player ID of the object at a certain index in the read object list,
    * only valid if the object is a player.
    *
    * Note: Currently, players can only be objects in ObjectActivate and ConsoleCommand
    *       packets.
    *
    * \param index The index of the object.
    * \return The player ID of the object.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectPid(unsigned int index) noexcept;

    /**
    * \brief Get the refId of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The refId.
    */
    EXPORT_APIFUNCTION const char *CDECL GetObjectRefId(unsigned int index) noexcept;

    /**
    * \brief Get the refNum of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The refNum.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectRefNum(unsigned int index) noexcept;

    /**
    * \brief Get the mpNum of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The mpNum.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectMpNum(unsigned int index) noexcept;

    /**
    * \brief Get the count of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The object count.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectCount(unsigned int index) noexcept;

    /**
    * \brief Get the charge of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The charge.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectCharge(unsigned int index) noexcept;

    /**
    * \brief Get the enchantment charge of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The enchantment charge.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectEnchantmentCharge(unsigned int index) noexcept;

    /**
    * \brief Get the soul of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The soul.
    */
    EXPORT_APIFUNCTION const char *CDECL GetObjectSoul(unsigned int index) noexcept;

    /**
    * \brief Get the gold value of the object at a certain index in the read object list.
    *
    * This is used solely to get the gold value of gold. It is not used for other objects.
    *
    * \param index The index of the object.
    * \return The gold value.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectGoldValue(unsigned int index) noexcept;

    /**
    * \brief Get the object scale of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The object scale.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectScale(unsigned int index) noexcept;

    /**
    * \brief Get the object state of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The object state.
    */
    EXPORT_APIFUNCTION bool CDECL GetObjectState(unsigned int index) noexcept;

    /**
    * \brief Get the door state of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The door state.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectDoorState(unsigned int index) noexcept;

    /**
    * \brief Get the lock level of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The lock level.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectLockLevel(unsigned int index) noexcept;

    /**
    * \brief Check whether the object at a certain index in the read object list has been
    * activated by a player.
    *
    * \param index The index of the object.
    * \return Whether the object has been activated by a player.
    */
    EXPORT_APIFUNCTION bool CDECL DoesObjectHavePlayerActivating(unsigned int index) noexcept;

    /**
    * \brief Get the player ID of the player activating the object at a certain index in the
    * read object list.
    *
    * \param index The index of the object.
    * \return The player ID of the activating player.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectActivatingPid(unsigned int index) noexcept;

    /**
    * \brief Get the refId of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The refId of the activating actor.
    */
    EXPORT_APIFUNCTION const char *CDECL GetObjectActivatingRefId(unsigned int index) noexcept;

    /**
    * \brief Get the refNum of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The refNum of the activating actor.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectActivatingRefNum(unsigned int index) noexcept;

    /**
    * \brief Get the mpNum of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The mpNum of the activating actor.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectActivatingMpNum(unsigned int index) noexcept;

    /**
    * \brief Get the name of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The name of the activating actor.
    */
    EXPORT_APIFUNCTION const char *CDECL GetObjectActivatingName(unsigned int index) noexcept;

    /**
    * \brief Check whether the object at a certain index in the read object list is a
    * summon.
    *
    * Only living actors can be summoned.
    *
    * \return The summon state.
    */
    EXPORT_APIFUNCTION bool CDECL GetObjectSummonState(unsigned int index) noexcept;

    /**
    * \brief Get the summon duration of the object at a certain index in the read object list.
    *
    * Note: Returns -1 if indefinite.
    *
    * \param index The index of the object.
    * \return The summon duration.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectSummonDuration(unsigned int index) noexcept;

    /**
    * \brief Check whether the object at a certain index in the read object list has a player
    * as its summoner.
    *
    * Only living actors can be summoned.
    *
    * \param index The index of the object.
    * \return Whether a player is the summoner of the object.
    */
    EXPORT_APIFUNCTION bool CDECL DoesObjectHavePlayerSummoner(unsigned int index) noexcept;

    /**
    * \brief Get the player ID of the summoner of the object at a certain index in the read object
    * list.
    *
    * \param index The index of the object.
    * \return The player ID of the summoner.
    */
    EXPORT_APIFUNCTION int CDECL GetObjectSummonerPid(unsigned int index) noexcept;

    /**
    * \brief Get the refId of the actor summoner of the object at a certain index in the read object
    * list.
    *
    * \param index The index of the object.
    * \return The refId of the summoner.
    */
    EXPORT_APIFUNCTION const char *CDECL GetObjectSummonerRefId(unsigned int index) noexcept;

    /**
    * \brief Get the refNum of the actor summoner of the object at a certain index in the read object
    * list.
    *
    * \param index The index of the object.
    * \return The refNum of the summoner.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectSummonerRefNum(unsigned int index) noexcept;

    /**
    * \brief Get the mpNum of the actor summoner of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The mpNum of the summoner.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectSummonerMpNum(unsigned int index) noexcept;

    /**
    * \brief Get the X position of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The X position.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectPosX(unsigned int index) noexcept;

    /**
    * \brief Get the Y position of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Y position.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectPosY(unsigned int index) noexcept;

    /**
    * \brief Get the Z position at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Z position.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectPosZ(unsigned int index) noexcept;

    /**
    * \brief Get the X rotation of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The X rotation.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectRotX(unsigned int index) noexcept;

    /**
    * \brief Get the Y rotation of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Y rotation.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectRotY(unsigned int index) noexcept;

    /**
    * \brief Get the Z rotation of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Z rotation.
    */
    EXPORT_APIFUNCTION double CDECL GetObjectRotZ(unsigned int index) noexcept;

    /**
    * \brief Get the videoFilename of the object at a certain index in the read object list.
    *
    * \return The videoFilename.
    */
    EXPORT_APIFUNCTION const char *CDECL GetVideoFilename(unsigned int index) noexcept;

    /**
    * \brief Get the number of container item indexes of the object at a certain index in the
    * read object list.
    *
    * \param index The index of the object.
    * \return The number of container item indexes.
    */
    EXPORT_APIFUNCTION unsigned int CDECL GetContainerChangesSize(unsigned int objectIndex) noexcept;

    /**
    * \brief Get the refId of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The refId.
    */
    EXPORT_APIFUNCTION const char *CDECL GetContainerItemRefId(unsigned int objectIndex, unsigned int itemIndex) noexcept;

    /**
    * \brief Get the item count of the container item at a certain itemIndex in the container
    * changes of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The item count.
    */
    EXPORT_APIFUNCTION int CDECL GetContainerItemCount(unsigned int objectIndex, unsigned int itemIndex) noexcept;

    /**
    * \brief Get the charge of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The charge.
    */
    EXPORT_APIFUNCTION int CDECL GetContainerItemCharge(unsigned int objectIndex, unsigned int itemIndex) noexcept;

    /**
    * \brief Get the enchantment charge of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The enchantment charge.
    */
    EXPORT_APIFUNCTION double CDECL GetContainerItemEnchantmentCharge(unsigned int objectIndex, unsigned int itemIndex) noexcept;

    /**
    * \brief Get the soul of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The soul.
    */
    EXPORT_APIFUNCTION const char *CDECL GetContainerItemSoul(unsigned int objectIndex, unsigned int itemIndex) noexcept;

    /**
    * \brief Get the action count of the container item at a certain itemIndex in the container
    * changes of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The action count.
    */
    EXPORT_APIFUNCTION int CDECL GetContainerItemActionCount(unsigned int objectIndex, unsigned int itemIndex) noexcept;

    /**
    * \brief Check whether the object at a certain index in the read object list has a container.
    * 
    * Note: Only ObjectLists from ObjectPlace packets contain this information. Objects from
    *       received ObjectSpawn packets can always be assumed to have a container.
    *
    * \param index The index of the object.
    * \return Whether the object has a container.
    */
    EXPORT_APIFUNCTION bool CDECL DoesObjectHaveContainer(unsigned int index) noexcept;

    /**
    * \brief Set the cell of the temporary object list stored on the server.
    *
    * The cell is determined to be an exterior cell if it fits the pattern of a number followed
    * by a comma followed by another number.
    *
    * \param cellDescription The description of the cell.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectListCell(const char* cellDescription) noexcept;

    /**
    * \brief Set the action type of the temporary object list stored on the server.
    *
    * \param action The action type (0 for SET, 1 for ADD, 2 for REMOVE, 3 for REQUEST).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectListAction(unsigned char action) noexcept;

    /**
    * \brief Set the console command of the temporary object list stored on the server.
    *
    * When sent, the command will run once on every object added to the object list. If no objects
    * have been added, it will run once without any object reference.
    *
    * \param consoleCommand The console command.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectListConsoleCommand(const char* consoleCommand) noexcept;

    /**
    * \brief Set the refId of the temporary object stored on the server.
    *
    * \param refId The refId.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectRefId(const char* refId) noexcept;

    /**
    * \brief Set the refNum of the temporary object stored on the server.
    *
    * Every object loaded from .ESM and .ESP data files has a unique refNum which needs to be
    * retained to refer to it in packets.
    * 
    * On the other hand, objects placed or spawned via the server should always have a refNum
    * of 0.
    *
    * \param refNum The refNum.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectRefNum(int refNum) noexcept;

    /**
    * \brief Set the mpNum of the temporary object stored on the server.
    *
    * Every object placed or spawned via the server is assigned an mpNum by incrementing the last
    * mpNum stored on the server. Scripts should take care to ensure that mpNums are kept unique
    * for these objects.
    * 
    * Objects loaded from .ESM and .ESP data files should always have an mpNum of 0, because they
    * have unique refNumes instead.
    *
    * \param mpNum The mpNum.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectMpNum(int mpNum) noexcept;

    /**
    * \brief Set the object count of the temporary object stored on the server.
    *
    * This determines the quantity of an object, with the exception of gold.
    *
    * \param count The object count.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectCount(int count) noexcept;

    /**
    * \brief Set the charge of the temporary object stored on the server.
    *
    * Object durabilities are set through this value.
    *
    * \param charge The charge.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectCharge(int charge) noexcept;

    /**
    * \brief Set the enchantment charge of the temporary object stored on the server.
    *
    * Object durabilities are set through this value.
    *
    * \param charge The enchantment charge.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectEnchantmentCharge(double enchantmentCharge) noexcept;

    /**
    * \brief Set the soul of the temporary object stored on the server.
    *
    * \param refId The soul.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectSoul(const char* soul) noexcept;

    /**
    * \brief Set the gold value of the temporary object stored on the server.
    *
    * This is used solely to set the gold value for gold. It has no effect on other objects.
    *
    * \param goldValue The gold value.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectGoldValue(int goldValue) noexcept;

    /**
    * \brief Set the scale of the temporary object stored on the server.
    *
    * Objects are smaller or larger than their default size based on their scale.
    *
    * \param scale The scale.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectScale(double scale) noexcept;

    /**
    * \brief Set the object state of the temporary object stored on the server.
    *
    * Objects are enabled or disabled based on their object state.
    *
    * \param objectState The object state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectState(bool objectState) noexcept;

    /**
    * \brief Set the lock level of the temporary object stored on the server.
    *
    * \param lockLevel The lock level.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectLockLevel(int lockLevel) noexcept;

    /**
    * \brief Set the summon duration of the temporary object stored on the server.
    *
    * \param summonDuration The summon duration.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectSummonDuration(float summonDuration) noexcept;

    /**
    * \brief Set the disarm state of the temporary object stored on the server.
    *
    * \param disarmState The disarmState.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectDisarmState(bool disarmState) noexcept;

    /**
    * \brief Set the summon state of the temporary object stored on the server.
    *
    * This only affects living actors and determines whether they are summons of another
    * living actor.
    *
    * \param summonState The summon state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectSummonState(bool summonState) noexcept;

    /**
    * \brief Set the position of the temporary object stored on the server.
    *
    * \param x The X position.
    * \param y The Y position.
    * \param z The Z position.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectPosition(double x, double y, double z) noexcept;

    /**
    * \brief Set the rotation of the temporary object stored on the server.
    *
    * \param x The X rotation.
    * \param y The Y rotation.
    * \param z The Z rotation.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectRotation(double x, double y, double z) noexcept;

    /**
    * \brief Set the player ID of the player activating the temporary object stored on the
    *        server. Currently only used for ObjectActivate packets.
    *
    * \param pid The pid of the player.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectActivatingPid(unsigned short pid) noexcept;

    /**
    * \brief Set the door state of the temporary object stored on the server.
    *
    * Doors are open or closed based on their door state.
    *
    * \param doorState The door state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectDoorState(int doorState) noexcept;

    /**
    * \brief Set the teleport state of the temporary object stored on the server.
    *
    * If a door's teleport state is true, interacting with the door teleports a player to its
    * destination. If it's false, it opens and closes like a regular door.
    *
    * \param teleportState The teleport state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectDoorTeleportState(bool teleportState) noexcept;

    /**
    * \brief Set the door destination cell of the temporary object stored on the server.
    *
    * The cell is determined to be an exterior cell if it fits the pattern of a number followed
    * by a comma followed by another number.
    *
    * \param cellDescription The description of the cell.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectDoorDestinationCell(const char* cellDescription) noexcept;

    /**
    * \brief Set the door destination position of the temporary object stored on the server.
    *
    * \param x The X position.
    * \param y The Y position.
    * \param z The Z position.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectDoorDestinationPosition(double x, double y, double z) noexcept;

    /**
    * \brief Set the door destination rotation of the temporary object stored on the server.
    *
    * Note: Because this sets the rotation a player will have upon using the door, and rotation
    *       on the Y axis has no effect on players, the Y value has been omitted as an argument.
    *
    * \param x The X rotation.
    * \param z The Z rotation.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetObjectDoorDestinationRotation(double x, double z) noexcept;

    /**
    * \brief Set a player as the object in the temporary object stored on the server.
    *        Currently only used for ConsoleCommand packets.
    *
    * \param pid The pid of the player.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetPlayerAsObject(unsigned short pid) noexcept;

    /**
    * \brief Set the refId of the temporary container item stored on the server.
    *
    * \param refId The refId.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetContainerItemRefId(const char* refId) noexcept;

    /**
    * \brief Set the item count of the temporary container item stored on the server.
    *
    * \param count The item count.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetContainerItemCount(int count) noexcept;

    /**
    * \brief Set the charge of the temporary container item stored on the server.
    *
    * \param charge The charge.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetContainerItemCharge(int charge) noexcept;

    /**
    * \brief Set the enchantment charge of the temporary container item stored on the server.
    *
    * \param charge The enchantment charge.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetContainerItemEnchantmentCharge(double enchantmentCharge) noexcept;

    /**
    * \brief Set the soul of the temporary container item stored on the server.
    *
    * \param refId The soul.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetContainerItemSoul(const char* soul) noexcept;

    /**
    * \brief Set the action count of the container item at a certain itemIndex in the container
    * changes of the object at a certain objectIndex in the object list stored on the server.
    *
    * When resending a received Container packet, this allows you to correct the amount of items
    * removed from a container by a player when it conflicts with what other players have already
    * taken.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \param actionCount The action count.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetContainerItemActionCountByIndex(unsigned int objectIndex, unsigned int itemIndex, int actionCount) noexcept;

    /**
    * \brief Add a copy of the server's temporary object to the server's currently stored object
    * list.
    *
    * In the process, the server's temporary object will automatically be cleared so a new
    * one can be set up.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddObject() noexcept;

    /**
    * \brief Add a copy of the server's temporary container item to the container changes of the
    * server's temporary object.
    *
    * In the process, the server's temporary container item will automatically be cleared so a new
    * one can be set up.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddContainerItem() noexcept;

    /**
    * \brief Send an ObjectActivate packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectActivate(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send an ObjectPlace packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectPlace(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send an ObjectSpawn packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectSpawn(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send an ObjectDelete packet.
    *
    * \param broadcast Whether this packet should be sent only to the player for whom the current
    *                  object list was initialized or to everyone on the server.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectDelete(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send an ObjectLock packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectLock(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send an ObjectTrap packet.
    *
    * \param broadcast Whether this packet should be sent only to the player for whom the current
    *                  object list was initialized or to everyone on the server.
    *
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectTrap(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send an ObjectScale packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectScale(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send an ObjectState packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendObjectState(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a DoorState packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendDoorState(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a DoorDestination packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendDoorDestination(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a Container packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendContainer(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a VideoPlay packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendVideoPlay(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a ConsoleCommand packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendConsoleCommand(bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;


    // All methods below are deprecated versions of methods from above

    EXPORT_APIFUNCTION void CDECL ReadLastObjectList() noexcept;
    EXPORT_APIFUNCTION void CDECL ReadLastEvent() noexcept;
    EXPORT_APIFUNCTION void CDECL InitializeObjectList(unsigned short pid) noexcept;
    EXPORT_APIFUNCTION void CDECL InitializeEvent(unsigned short pid) noexcept;
    EXPORT_APIFUNCTION void CDECL CopyLastObjectListToStore() noexcept;
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectChangesSize() noexcept;
    EXPORT_APIFUNCTION unsigned char CDECL GetEventAction() noexcept;
    EXPORT_APIFUNCTION unsigned char CDECL GetEventContainerSubAction() noexcept;
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectRefNumIndex(unsigned int index) noexcept;
    EXPORT_APIFUNCTION unsigned int CDECL GetObjectSummonerRefNumIndex(unsigned int index) noexcept;
    EXPORT_APIFUNCTION void CDECL SetEventCell(const char* cellDescription) noexcept;
    EXPORT_APIFUNCTION void CDECL SetEventAction(unsigned char action) noexcept;
    EXPORT_APIFUNCTION void CDECL SetEventConsoleCommand(const char* consoleCommand) noexcept;
    EXPORT_APIFUNCTION void CDECL SetObjectRefNumIndex(int refNum) noexcept;
    EXPORT_APIFUNCTION void CDECL AddWorldObject() noexcept;
}


#endif //OPENMW_OBJECTAPI_HPP
