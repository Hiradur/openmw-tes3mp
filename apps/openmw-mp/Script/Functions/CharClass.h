//
// Created by koncord on 29.08.16.
//

#ifndef OPENMW_CHARCLASSAPI_HPP
#define OPENMW_CHARCLASSAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(CharClassFunctions)
    /**
    * \brief Get the default class used by a player.
    *
    * \param pid The player ID.
    * \return The ID of the default class.
    */
    API_FUNCTION const char *CDECL GetDefaultClass(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the name of the custom class used by a player.
    *
    * \param pid The player ID.
    * \return The name of the custom class.
    */
    API_FUNCTION const char *CDECL GetClassName(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the description of the custom class used by a player.
    *
    * \param pid The player ID.
    * \return The description of the custom class.
    */
    API_FUNCTION const char *CDECL GetClassDesc(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the ID of one of the two major attributes of a custom class used by a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the major attribute (0 or 1).
    * \return The ID of the major attribute.
    */
    API_FUNCTION int CDECL GetClassMajorAttribute(PlayerId pid, unsigned char slot) NOEXCEPT;

    /**
    * \brief Get the specialization ID of the custom class used by a player.
    *
    * \param pid The player ID.
    * \return The specialization ID of the custom class (0 for Combat, 1 for Magic, 2 for Stealth).
    */
    API_FUNCTION int CDECL GetClassSpecialization(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the ID of one of the five major skills of a custom class used by a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the major skill (0 to 4).
    * \return The ID of the major skill.
    */
    API_FUNCTION int CDECL GetClassMajorSkill(PlayerId pid, unsigned char slot) NOEXCEPT;

    /**
    * \brief Get the ID of one of the five minor skills of a custom class used by a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the minor skill (0 to 4).
    * \return The ID of the minor skill.
    */
    API_FUNCTION int CDECL GetClassMinorSkill(PlayerId pid, unsigned char slot) NOEXCEPT;

    /**
    * \brief Check whether the player is using a default class instead of a custom one.
    *
    * \param pid The player ID.
    * \return Whether the player is using a default class.
    */
    API_FUNCTION int CDECL IsClassDefault(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the default class used by a player.
    *
    * If this is left blank, the custom class data set for the player will be used instead.
    *
    * \param pid The player ID.
    * \param id The ID of the default class.
    * \return void
    */
    API_FUNCTION void CDECL SetDefaultClass(PlayerId pid, const char *id) NOEXCEPT;

    /**
    * \brief Set the name of the custom class used by a player.
    *
    * \param pid The player ID.
    * \param name The name of the custom class.
    * \return void
    */
    API_FUNCTION void CDECL SetClassName(PlayerId pid, const char *name) NOEXCEPT;

    /**
    * \brief Set the description of the custom class used by a player.
    *
    * \param pid The player ID.
    * \param desc The description of the custom class.
    * \return void
    */
    API_FUNCTION void CDECL SetClassDesc(PlayerId pid, const char *desc) NOEXCEPT;

    /**
    * \brief Set the ID of one of the two major attributes of the custom class used by a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the major attribute (0 or 1).
    * \param attrId The ID to use for the attribute.
    * \return void
    */
    API_FUNCTION void CDECL SetClassMajorAttribute(PlayerId pid, unsigned char slot, int attrId) NOEXCEPT;

    /**
    * \brief Set the specialization of the custom class used by a player.
    *
    * \param pid The player ID.
    * \param spec The specialization ID to use (0 for Combat, 1 for Magic, 2 for Stealth).
    * \return void
    */
    API_FUNCTION void CDECL SetClassSpecialization(PlayerId pid, int spec) NOEXCEPT;

     /**
     * \brief Set the ID of one of the five major skills of the custom class used by a player.
     *
     * \param pid The player ID.
     * \param slot The slot of the major skill (0 to 4).
     * \param skillId The ID to use for the skill.
     * \return void
     */
    API_FUNCTION void CDECL SetClassMajorSkill(PlayerId pid, unsigned char slot, int skillId) NOEXCEPT;

    /**
    * \brief Set the ID of one of the five minor skills of the custom class used by a player.
    *
    * \param pid The player ID.
    * \param slot The slot of the minor skill (0 to 4).
    * \param skillId The ID to use for the skill.
    * \return void
    */
    API_FUNCTION void CDECL SetClassMinorSkill(PlayerId pid, unsigned char slot, int skillId) NOEXCEPT;

    /**
    * \brief Send a PlayerCharClass packet about a player.
    *
    * It is only sent to the affected player.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendClass(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_CHARCLASSAPI_HPP
