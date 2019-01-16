#ifndef OPENMW_OBJECTAPI_HPP
#define OPENMW_OBJECTAPI_HPP

#include "../api.h"

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

NAMESPACE_BEGIN(ObjectFunctions)
    /**
    * \brief Use the last object list received by the server as the one being read.
    *
    * \return void
    */
    API_FUNCTION void CDECL ReadReceivedObjectList() NOEXCEPT;

    /**
    * \brief Clear the data from the object list stored on the server.
    *
    * \return void
    */
    API_FUNCTION void CDECL ClearObjectList() NOEXCEPT;

    /**
    * \brief Set the pid attached to the ObjectList.
    *
    * \param pid The player ID to whom the object list should be attached.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectListPid(PlayerId pid) NOEXCEPT;

    /**
    * \brief Take the contents of the read-only object list last received by the
    *        server from a player and move its contents to the stored object list
    *        that can be sent by the server.
    *
    * \return void
    */
    API_FUNCTION void CDECL CopyReceivedObjectListToStore() NOEXCEPT;

    /**
    * \brief Get the number of indexes in the read object list.
    *
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetObjectListSize() NOEXCEPT;

    /**
    * \brief Get the origin of the read object list.
    *
    * \return The origin (0 for CLIENT_GAMEPLAY, 1 for CLIENT_CONSOLE, 2 for
    * CLIENT_DIALOGUE, 3 for CLIENT_SCRIPT_LOCAL, 4 for CLIENT_SCRIPT_GLOBAL,
    * 5 for SERVER_SCRIPT).
    */
    API_FUNCTION unsigned char CDECL GetObjectListOrigin() NOEXCEPT;

    /**
    * \brief Get the client script that the read object list originated from.
    *
    * Note: This is not yet implemented.
    *
    * \return The ID of the client script.
    */
    API_FUNCTION const char *CDECL GetObjectListClientScript() NOEXCEPT;

    /**
    * \brief Get the action type used in the read object list.
    *
    * \return The action type (0 for SET, 1 for ADD, 2 for REMOVE, 3 for REQUEST).
    */
    API_FUNCTION unsigned char CDECL GetObjectListAction() NOEXCEPT;

    /**
    * \brief Get the container subaction type used in the read object list.
    *
    * \return The action type (0 for NONE, 1 for DRAG, 2 for DROP, 3 for TAKE_ALL).
    */
    API_FUNCTION unsigned char CDECL GetObjectListContainerSubAction() NOEXCEPT;

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
    API_FUNCTION bool CDECL IsObjectPlayer(unsigned int index) NOEXCEPT;

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
    API_FUNCTION int CDECL GetObjectPid(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the refId of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The refId.
    */
    API_FUNCTION const char *CDECL GetObjectRefId(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the refNum of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The refNum.
    */
    API_FUNCTION unsigned int CDECL GetObjectRefNum(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the mpNum of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The mpNum.
    */
    API_FUNCTION unsigned int CDECL GetObjectMpNum(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the count of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The object count.
    */
    API_FUNCTION int CDECL GetObjectCount(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the charge of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The charge.
    */
    API_FUNCTION int CDECL GetObjectCharge(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the enchantment charge of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The enchantment charge.
    */
    API_FUNCTION double CDECL GetObjectEnchantmentCharge(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the soul of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The soul.
    */
    API_FUNCTION const char *CDECL GetObjectSoul(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the gold value of the object at a certain index in the read object list.
    *
    * This is used solely to get the gold value of gold. It is not used for other objects.
    *
    * \param index The index of the object.
    * \return The gold value.
    */
    API_FUNCTION int CDECL GetObjectGoldValue(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the object scale of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The object scale.
    */
    API_FUNCTION double CDECL GetObjectScale(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the object state of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The object state.
    */
    API_FUNCTION bool CDECL GetObjectState(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the door state of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The door state.
    */
    API_FUNCTION int CDECL GetObjectDoorState(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the lock level of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The lock level.
    */
    API_FUNCTION int CDECL GetObjectLockLevel(unsigned int index) NOEXCEPT;

    /**
    * \brief Check whether the object at a certain index in the read object list has been
    * activated by a player.
    *
    * \param index The index of the object.
    * \return Whether the object has been activated by a player.
    */
    API_FUNCTION bool CDECL DoesObjectHavePlayerActivating(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the player ID of the player activating the object at a certain index in the
    * read object list.
    *
    * \param index The index of the object.
    * \return The player ID of the activating player.
    */
    API_FUNCTION int CDECL GetObjectActivatingPid(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the refId of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The refId of the activating actor.
    */
    API_FUNCTION const char *CDECL GetObjectActivatingRefId(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the refNum of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The refNum of the activating actor.
    */
    API_FUNCTION unsigned int CDECL GetObjectActivatingRefNum(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the mpNum of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The mpNum of the activating actor.
    */
    API_FUNCTION unsigned int CDECL GetObjectActivatingMpNum(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the name of the actor activating the object at a certain index in the read
    * object list.
    *
    * \param index The index of the object.
    * \return The name of the activating actor.
    */
    API_FUNCTION const char *CDECL GetObjectActivatingName(unsigned int index) NOEXCEPT;

    /**
    * \brief Check whether the object at a certain index in the read object list is a
    * summon.
    *
    * Only living actors can be summoned.
    *
    * \return The summon state.
    */
    API_FUNCTION bool CDECL GetObjectSummonState(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the summon duration of the object at a certain index in the read object list.
    *
    * Note: Returns -1 if indefinite.
    *
    * \param index The index of the object.
    * \return The summon duration.
    */
    API_FUNCTION double CDECL GetObjectSummonDuration(unsigned int index) NOEXCEPT;

    /**
    * \brief Check whether the object at a certain index in the read object list has a player
    * as its summoner.
    *
    * Only living actors can be summoned.
    *
    * \param index The index of the object.
    * \return Whether a player is the summoner of the object.
    */
    API_FUNCTION bool CDECL DoesObjectHavePlayerSummoner(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the player ID of the summoner of the object at a certain index in the read object
    * list.
    *
    * \param index The index of the object.
    * \return The player ID of the summoner.
    */
    API_FUNCTION int CDECL GetObjectSummonerPid(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the refId of the actor summoner of the object at a certain index in the read object
    * list.
    *
    * \param index The index of the object.
    * \return The refId of the summoner.
    */
    API_FUNCTION const char *CDECL GetObjectSummonerRefId(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the refNum of the actor summoner of the object at a certain index in the read object
    * list.
    *
    * \param index The index of the object.
    * \return The refNum of the summoner.
    */
    API_FUNCTION unsigned int CDECL GetObjectSummonerRefNum(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the mpNum of the actor summoner of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The mpNum of the summoner.
    */
    API_FUNCTION unsigned int CDECL GetObjectSummonerMpNum(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the X position of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The X position.
    */
    API_FUNCTION double CDECL GetObjectPosX(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the Y position of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Y position.
    */
    API_FUNCTION double CDECL GetObjectPosY(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the Z position at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Z position.
    */
    API_FUNCTION double CDECL GetObjectPosZ(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the X rotation of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The X rotation.
    */
    API_FUNCTION double CDECL GetObjectRotX(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the Y rotation of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Y rotation.
    */
    API_FUNCTION double CDECL GetObjectRotY(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the Z rotation of the object at a certain index in the read object list.
    *
    * \param index The index of the object.
    * \return The Z rotation.
    */
    API_FUNCTION double CDECL GetObjectRotZ(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the videoFilename of the object at a certain index in the read object list.
    *
    * \return The videoFilename.
    */
    API_FUNCTION const char *CDECL GetVideoFilename(unsigned int index) NOEXCEPT;

    /**
    * \brief Get the number of container item indexes of the object at a certain index in the
    * read object list.
    *
    * \param index The index of the object.
    * \return The number of container item indexes.
    */
    API_FUNCTION unsigned int CDECL GetContainerChangesSize(unsigned int objectIndex) NOEXCEPT;

    /**
    * \brief Get the refId of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The refId.
    */
    API_FUNCTION const char *CDECL GetContainerItemRefId(unsigned int objectIndex, unsigned int itemIndex) NOEXCEPT;

    /**
    * \brief Get the item count of the container item at a certain itemIndex in the container
    * changes of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The item count.
    */
    API_FUNCTION int CDECL GetContainerItemCount(unsigned int objectIndex, unsigned int itemIndex) NOEXCEPT;

    /**
    * \brief Get the charge of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The charge.
    */
    API_FUNCTION int CDECL GetContainerItemCharge(unsigned int objectIndex, unsigned int itemIndex) NOEXCEPT;

    /**
    * \brief Get the enchantment charge of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The enchantment charge.
    */
    API_FUNCTION double CDECL GetContainerItemEnchantmentCharge(unsigned int objectIndex, unsigned int itemIndex) NOEXCEPT;

    /**
    * \brief Get the soul of the container item at a certain itemIndex in the container changes
    * of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The soul.
    */
    API_FUNCTION const char *CDECL GetContainerItemSoul(unsigned int objectIndex, unsigned int itemIndex) NOEXCEPT;

    /**
    * \brief Get the action count of the container item at a certain itemIndex in the container
    * changes of the object at a certain objectIndex in the read object list.
    *
    * \param objectIndex The index of the object.
    * \param itemIndex The index of the container item.
    * \return The action count.
    */
    API_FUNCTION int CDECL GetContainerItemActionCount(unsigned int objectIndex, unsigned int itemIndex) NOEXCEPT;

    /**
    * \brief Check whether the object at a certain index in the read object list has a container.
    * 
    * Note: Only ObjectLists from ObjectPlace packets contain this information. Objects from
    *       received ObjectSpawn packets can always be assumed to have a container.
    *
    * \param index The index of the object.
    * \return Whether the object has a container.
    */
    API_FUNCTION bool CDECL DoesObjectHaveContainer(unsigned int index) NOEXCEPT;

    /**
    * \brief Set the cell of the temporary object list stored on the server.
    *
    * The cell is determined to be an exterior cell if it fits the pattern of a number followed
    * by a comma followed by another number.
    *
    * \param cellDescription The description of the cell.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectListCell(const char* cellDescription) NOEXCEPT;

    /**
    * \brief Set the action type of the temporary object list stored on the server.
    *
    * \param action The action type (0 for SET, 1 for ADD, 2 for REMOVE, 3 for REQUEST).
    * \return void
    */
    API_FUNCTION void CDECL SetObjectListAction(unsigned char action) NOEXCEPT;

    /**
    * \brief Set the console command of the temporary object list stored on the server.
    *
    * When sent, the command will run once on every object added to the object list. If no objects
    * have been added, it will run once without any object reference.
    *
    * \param consoleCommand The console command.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectListConsoleCommand(const char* consoleCommand) NOEXCEPT;

    /**
    * \brief Set the refId of the temporary object stored on the server.
    *
    * \param refId The refId.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectRefId(const char* refId) NOEXCEPT;

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
    API_FUNCTION void CDECL SetObjectRefNum(int refNum) NOEXCEPT;

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
    API_FUNCTION void CDECL SetObjectMpNum(int mpNum) NOEXCEPT;

    /**
    * \brief Set the object count of the temporary object stored on the server.
    *
    * This determines the quantity of an object, with the exception of gold.
    *
    * \param count The object count.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectCount(int count) NOEXCEPT;

    /**
    * \brief Set the charge of the temporary object stored on the server.
    *
    * Object durabilities are set through this value.
    *
    * \param charge The charge.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectCharge(int charge) NOEXCEPT;

    /**
    * \brief Set the enchantment charge of the temporary object stored on the server.
    *
    * Object durabilities are set through this value.
    *
    * \param charge The enchantment charge.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectEnchantmentCharge(double enchantmentCharge) NOEXCEPT;

    /**
    * \brief Set the soul of the temporary object stored on the server.
    *
    * \param refId The soul.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectSoul(const char* soul) NOEXCEPT;

    /**
    * \brief Set the gold value of the temporary object stored on the server.
    *
    * This is used solely to set the gold value for gold. It has no effect on other objects.
    *
    * \param goldValue The gold value.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectGoldValue(int goldValue) NOEXCEPT;

    /**
    * \brief Set the scale of the temporary object stored on the server.
    *
    * Objects are smaller or larger than their default size based on their scale.
    *
    * \param scale The scale.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectScale(double scale) NOEXCEPT;

    /**
    * \brief Set the object state of the temporary object stored on the server.
    *
    * Objects are enabled or disabled based on their object state.
    *
    * \param objectState The object state.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectState(bool objectState) NOEXCEPT;

    /**
    * \brief Set the lock level of the temporary object stored on the server.
    *
    * \param lockLevel The lock level.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectLockLevel(int lockLevel) NOEXCEPT;

    /**
    * \brief Set the summon duration of the temporary object stored on the server.
    *
    * \param summonDuration The summon duration.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectSummonDuration(float summonDuration) NOEXCEPT;

    /**
    * \brief Set the disarm state of the temporary object stored on the server.
    *
    * \param disarmState The disarmState.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectDisarmState(bool disarmState) NOEXCEPT;

    /**
    * \brief Set the summon state of the temporary object stored on the server.
    *
    * This only affects living actors and determines whether they are summons of another
    * living actor.
    *
    * \param summonState The summon state.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectSummonState(bool summonState) NOEXCEPT;

    /**
    * \brief Set the position of the temporary object stored on the server.
    *
    * \param x The X position.
    * \param y The Y position.
    * \param z The Z position.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectPosition(double x, double y, double z) NOEXCEPT;

    /**
    * \brief Set the rotation of the temporary object stored on the server.
    *
    * \param x The X rotation.
    * \param y The Y rotation.
    * \param z The Z rotation.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectRotation(double x, double y, double z) NOEXCEPT;

    /**
    * \brief Set the player ID of the player activating the temporary object stored on the
    *        server. Currently only used for ObjectActivate packets.
    *
    * \param pid The pid of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectActivatingPid(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the door state of the temporary object stored on the server.
    *
    * Doors are open or closed based on their door state.
    *
    * \param doorState The door state.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectDoorState(int doorState) NOEXCEPT;

    /**
    * \brief Set the teleport state of the temporary object stored on the server.
    *
    * If a door's teleport state is true, interacting with the door teleports a player to its
    * destination. If it's false, it opens and closes like a regular door.
    *
    * \param teleportState The teleport state.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectDoorTeleportState(bool teleportState) NOEXCEPT;

    /**
    * \brief Set the door destination cell of the temporary object stored on the server.
    *
    * The cell is determined to be an exterior cell if it fits the pattern of a number followed
    * by a comma followed by another number.
    *
    * \param cellDescription The description of the cell.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectDoorDestinationCell(const char* cellDescription) NOEXCEPT;

    /**
    * \brief Set the door destination position of the temporary object stored on the server.
    *
    * \param x The X position.
    * \param y The Y position.
    * \param z The Z position.
    * \return void
    */
    API_FUNCTION void CDECL SetObjectDoorDestinationPosition(double x, double y, double z) NOEXCEPT;

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
    API_FUNCTION void CDECL SetObjectDoorDestinationRotation(double x, double z) NOEXCEPT;

    /**
    * \brief Set a player as the object in the temporary object stored on the server.
    *        Currently only used for ConsoleCommand packets.
    *
    * \param pid The pid of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetPlayerAsObject(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the refId of the temporary container item stored on the server.
    *
    * \param refId The refId.
    * \return void
    */
    API_FUNCTION void CDECL SetContainerItemRefId(const char* refId) NOEXCEPT;

    /**
    * \brief Set the item count of the temporary container item stored on the server.
    *
    * \param count The item count.
    * \return void
    */
    API_FUNCTION void CDECL SetContainerItemCount(int count) NOEXCEPT;

    /**
    * \brief Set the charge of the temporary container item stored on the server.
    *
    * \param charge The charge.
    * \return void
    */
    API_FUNCTION void CDECL SetContainerItemCharge(int charge) NOEXCEPT;

    /**
    * \brief Set the enchantment charge of the temporary container item stored on the server.
    *
    * \param charge The enchantment charge.
    * \return void
    */
    API_FUNCTION void CDECL SetContainerItemEnchantmentCharge(double enchantmentCharge) NOEXCEPT;

    /**
    * \brief Set the soul of the temporary container item stored on the server.
    *
    * \param refId The soul.
    * \return void
    */
    API_FUNCTION void CDECL SetContainerItemSoul(const char* soul) NOEXCEPT;

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
    API_FUNCTION void CDECL SetContainerItemActionCountByIndex(unsigned int objectIndex, unsigned int itemIndex, int actionCount) NOEXCEPT;

    /**
    * \brief Add a copy of the server's temporary object to the server's currently stored object
    * list.
    *
    * In the process, the server's temporary object will automatically be cleared so a new
    * one can be set up.
    *
    * \return void
    */
    API_FUNCTION void CDECL AddObject() NOEXCEPT;

    /**
    * \brief Add a copy of the server's temporary container item to the container changes of the
    * server's temporary object.
    *
    * In the process, the server's temporary container item will automatically be cleared so a new
    * one can be set up.
    *
    * \return void
    */
    API_FUNCTION void CDECL AddContainerItem() NOEXCEPT;

    /**
    * \brief Send an ObjectActivate packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendObjectActivate(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send an ObjectPlace packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendObjectPlace(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send an ObjectSpawn packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendObjectSpawn(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send an ObjectDelete packet.
    *
    * \param broadcast Whether this packet should be sent only to the player for whom the current
    *                  object list was initialized or to everyone on the server.
    *
    * \return void
    */
    API_FUNCTION void CDECL SendObjectDelete(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send an ObjectLock packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendObjectLock(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send an ObjectTrap packet.
    *
    * \param broadcast Whether this packet should be sent only to the player for whom the current
    *                  object list was initialized or to everyone on the server.
    *
    * \return void
    */
    API_FUNCTION void CDECL SendObjectTrap(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send an ObjectScale packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendObjectScale(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send an ObjectState packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendObjectState(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send a DoorState packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendDoorState(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send a DoorDestination packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendDoorDestination(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send a Container packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendContainer(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send a VideoPlay packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendVideoPlay(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send a ConsoleCommand packet.
    *
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendConsoleCommand(bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;


    // All methods below are deprecated versions of methods from above

    API_FUNCTION void CDECL ReadLastObjectList() NOEXCEPT;
    API_FUNCTION void CDECL ReadLastEvent() NOEXCEPT;
    API_FUNCTION void CDECL InitializeObjectList(PlayerId pid) NOEXCEPT;
    API_FUNCTION void CDECL InitializeEvent(PlayerId pid) NOEXCEPT;
    API_FUNCTION void CDECL CopyLastObjectListToStore() NOEXCEPT;
    API_FUNCTION unsigned int CDECL GetObjectChangesSize() NOEXCEPT;
    API_FUNCTION unsigned char CDECL GetEventAction() NOEXCEPT;
    API_FUNCTION unsigned char CDECL GetEventContainerSubAction() NOEXCEPT;
    API_FUNCTION unsigned int CDECL GetObjectRefNumIndex(unsigned int index) NOEXCEPT;
    API_FUNCTION unsigned int CDECL GetObjectSummonerRefNumIndex(unsigned int index) NOEXCEPT;
    API_FUNCTION void CDECL SetEventCell(const char* cellDescription) NOEXCEPT;
    API_FUNCTION void CDECL SetEventAction(unsigned char action) NOEXCEPT;
    API_FUNCTION void CDECL SetEventConsoleCommand(const char* consoleCommand) NOEXCEPT;
    API_FUNCTION void CDECL SetObjectRefNumIndex(int refNum) NOEXCEPT;
    API_FUNCTION void CDECL AddWorldObject() NOEXCEPT;
NAMESPACE_END()


#endif //OPENMW_OBJECTAPI_HPP
