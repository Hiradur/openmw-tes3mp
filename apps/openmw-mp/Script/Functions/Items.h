#ifndef OPENMW_ITEMAPI_HPP
#define OPENMW_ITEMAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(ItemFunctions)
    /**
    * \brief Clear the last recorded inventory changes for a player.
    *
    * This is used to initialize the sending of new PlayerInventory packets.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL ClearInventoryChanges(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the number of slots used for equipment.
    *
    * The number is 19 before any dehardcoding is done in OpenMW.
    *
    * \return The number of slots.
    */
    API_FUNCTION int CDECL GetEquipmentSize() NOEXCEPT;

    /**
    * \brief Get the number of indexes in a player's latest inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetInventoryChangesSize(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the action type used in a player's latest inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \return The action type (0 for SET, 1 for ADD, 2 for REMOVE).
    */
    API_FUNCTION unsigned int CDECL GetInventoryChangesAction(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the action type in a player's inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param action The action (0 for SET, 1 for ADD, 2 for REMOVE).
    * \return void
    */
    API_FUNCTION void CDECL SetInventoryChangesAction(PlayerId pid, unsigned char action) NOEXCEPT;

    /**
    * \brief Equip an item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The equipment slot.
    * \param refId The refId of the item.
    * \param count The count of the item.
    * \param charge The charge of the item.
    * \param enchantmentCharge The enchantment charge of the item.
    * \return void
    */
    API_FUNCTION void CDECL EquipItem(PlayerId pid, unsigned short slot, const char* refId, unsigned int count, int charge,
        double enchantmentCharge = -1) NOEXCEPT;
    
    /**
    * \brief Unequip the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The equipment slot.
    * \return void
    */
    API_FUNCTION void CDECL UnequipItem(PlayerId pid, unsigned short slot) NOEXCEPT;

    /**
    * \brief Add an item change to a player's inventory changes.
    *
    * \param pid The player ID.
    * \param refId The refId of the item.
    * \param count The count of the item.
    * \param charge The charge of the item.
    * \param enchantmentCharge The enchantment charge of the item.
    * \param soul The soul of the item.
    * \return void
    */
    API_FUNCTION void CDECL AddItemChange(PlayerId pid, const char* refId, unsigned int count, int charge,
        double enchantmentCharge, const char* soul) NOEXCEPT;

    /**
    * \brief Check whether a player has equipped an item with a certain refId in any slot.
    *
    * \param pid The player ID.
    * \param refId The refId of the item.
    * \return Whether the player has the item equipped.
    */
    API_FUNCTION bool CDECL HasItemEquipped(PlayerId pid, const char* refId);

    /**
    * \brief Get the refId of the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The refId.
    */
    API_FUNCTION const char *CDECL GetEquipmentItemRefId(PlayerId pid, unsigned short slot) NOEXCEPT;

    /**
    * \brief Get the count of the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The item count.
    */
    API_FUNCTION int CDECL GetEquipmentItemCount(PlayerId pid, unsigned short slot) NOEXCEPT;

    /**
    * \brief Get the charge of the item in a certain slot of the equipment of a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The charge.
    */
    API_FUNCTION int CDECL GetEquipmentItemCharge(PlayerId pid, unsigned short slot) NOEXCEPT;

    /**
    * \brief Get the enchantment charge of the item in a certain slot of the equipment of
    *        a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the equipment item.
    * \return The enchantment charge.
    */
    API_FUNCTION double CDECL GetEquipmentItemEnchantmentCharge(PlayerId pid, unsigned short slot) NOEXCEPT;

    /**
    * \brief Get the refId of the item at a certain index in a player's latest inventory
    *        changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param index The index of the inventory item.
    * \return The refId.
    */
    API_FUNCTION const char *CDECL GetInventoryItemRefId(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the count of the item at a certain index in a player's latest inventory
    *        changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param index The index of the inventory item.
    * \return The item count.
    */
    API_FUNCTION int CDECL GetInventoryItemCount(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the charge of the item at a certain index in a player's latest inventory
    *        changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param index The index of the inventory item.
    * \return The charge.
    */
    API_FUNCTION int CDECL GetInventoryItemCharge(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the enchantment charge of the item at a certain index in a player's
    *        latest inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param index The index of the inventory item.
    * \return The enchantment charge.
    */
    API_FUNCTION double CDECL GetInventoryItemEnchantmentCharge(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the soul of the item at a certain index in a player's latest inventory
    *        changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param index The index of the inventory item.
    * \return The soul.
    */
    API_FUNCTION const char *CDECL GetInventoryItemSoul(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Get the refId of the item last used by a player.
    *
    * \param pid The player ID.
    * \return The refId.
    */
    API_FUNCTION const char *CDECL GetUsedItemRefId(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the count of the item last used by a player.
    *
    * \param pid The player ID.
    * \return The item count.
    */
    API_FUNCTION int CDECL GetUsedItemCount(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the charge of the item last used by a player.
    *
    * \param pid The player ID.
    * \return The charge.
    */
    API_FUNCTION int CDECL GetUsedItemCharge(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the enchantment charge of the item last used by a player.
    *
    * \param pid The player ID.
    * \return The enchantment charge.
    */
    API_FUNCTION double CDECL GetUsedItemEnchantmentCharge(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the soul of the item last used by a player.
    *
    * \param pid The player ID.
    * \return The soul.
    */
    API_FUNCTION const char *CDECL GetUsedItemSoul(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerEquipment packet with a player's equipment.
    *
    * It is always sent to all players.
    *
    * \param pid The player ID whose equipment should be sent.
    * \return void
    */
    API_FUNCTION void CDECL SendEquipment(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerInventory packet with a player's recorded inventory changes.
    *
    * \param pid The player ID whose inventory changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendInventoryChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Send a PlayerItemUse causing a player to use their recorded usedItem.
    *
    * \param pid The player ID affected.
    * \return void
    */
    API_FUNCTION void CDECL SendItemUse(PlayerId pid) NOEXCEPT;

    // All methods below are deprecated versions of methods from above

    API_FUNCTION void CDECL InitializeInventoryChanges(PlayerId pid) NOEXCEPT;

    API_FUNCTION void CDECL AddItem(PlayerId pid, const char* refId, unsigned int count, int charge,
        double enchantmentCharge, const char* soul) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_ITEMAPI_HPP
