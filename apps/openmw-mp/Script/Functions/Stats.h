#ifndef OPENMW_STATAPI_HPP
#define OPENMW_STATAPI_HPP

#include "../api.h"

#define STATAPI \
    {"GetAttributeCount",       StatsFunctions::GetAttributeCount},\
    {"GetSkillCount",           StatsFunctions::GetSkillCount},\
    {"GetAttributeId",          StatsFunctions::GetAttributeId},\
    {"GetSkillId",              StatsFunctions::GetSkillId},\
    {"GetAttributeName",        StatsFunctions::GetAttributeName},\
    {"GetSkillName",            StatsFunctions::GetSkillName},\
    \
    {"GetName",                 StatsFunctions::GetName},\
    {"GetRace",                 StatsFunctions::GetRace},\
    {"GetHead",                 StatsFunctions::GetHead},\
    {"GetHair",                 StatsFunctions::GetHairstyle},\
    {"GetIsMale",               StatsFunctions::GetIsMale},\
    {"GetBirthsign",            StatsFunctions::GetBirthsign},\
    \
    {"GetLevel",                StatsFunctions::GetLevel},\
    {"GetLevelProgress",        StatsFunctions::GetLevelProgress},\
    \
    {"GetHealthBase",           StatsFunctions::GetHealthBase},\
    {"GetHealthCurrent",        StatsFunctions::GetHealthCurrent},\
    \
    {"GetMagickaBase",          StatsFunctions::GetMagickaBase},\
    {"GetMagickaCurrent",       StatsFunctions::GetMagickaCurrent},\
    \
    {"GetFatigueBase",          StatsFunctions::GetFatigueBase},\
    {"GetFatigueCurrent",       StatsFunctions::GetFatigueCurrent},\
    \
    {"GetAttributeBase",        StatsFunctions::GetAttributeBase},\
    {"GetAttributeModifier",    StatsFunctions::GetAttributeModifier},\
    \
    {"GetSkillBase",            StatsFunctions::GetSkillBase},\
    {"GetSkillModifier",        StatsFunctions::GetSkillModifier},\
    {"GetSkillProgress",        StatsFunctions::GetSkillProgress},\
    {"GetSkillIncrease",        StatsFunctions::GetSkillIncrease},\
    \
    {"GetBounty",               StatsFunctions::GetBounty},\
    \
    {"SetName",                 StatsFunctions::SetName},\
    {"SetRace",                 StatsFunctions::SetRace},\
    {"SetHead",                 StatsFunctions::SetHead},\
    {"SetHair",                 StatsFunctions::SetHairstyle},\
    {"SetIsMale",               StatsFunctions::SetIsMale},\
    {"SetBirthsign",            StatsFunctions::SetBirthsign},\
    {"SetResetStats",           StatsFunctions::SetResetStats},\
    \
    {"SetLevel",                StatsFunctions::SetLevel},\
    {"SetLevelProgress",        StatsFunctions::SetLevelProgress},\
    \
    {"SetHealthBase",           StatsFunctions::SetHealthBase},\
    {"SetHealthCurrent",        StatsFunctions::SetHealthCurrent},\
    {"SetMagickaBase",          StatsFunctions::SetMagickaBase},\
    {"SetMagickaCurrent",       StatsFunctions::SetMagickaCurrent},\
    {"SetFatigueBase",          StatsFunctions::SetFatigueBase},\
    {"SetFatigueCurrent",       StatsFunctions::SetFatigueCurrent},\
    \
    {"SetAttributeBase",        StatsFunctions::SetAttributeBase},\
    {"ClearAttributeModifier",  StatsFunctions::ClearAttributeModifier},\
    \
    {"SetSkillBase",            StatsFunctions::SetSkillBase},\
    {"ClearSkillModifier",      StatsFunctions::ClearSkillModifier},\
    {"SetSkillProgress",        StatsFunctions::SetSkillProgress},\
    {"SetSkillIncrease",        StatsFunctions::SetSkillIncrease},\
    \
    {"SetBounty",               StatsFunctions::SetBounty},\
    {"SetCharGenStage",         StatsFunctions::SetCharGenStage},\
    \
    {"SendBaseInfo",            StatsFunctions::SendBaseInfo},\
    \
    {"SendStatsDynamic",        StatsFunctions::SendStatsDynamic},\
    {"SendAttributes",          StatsFunctions::SendAttributes},\
    {"SendSkills",              StatsFunctions::SendSkills},\
    {"SendLevel",               StatsFunctions::SendLevel},\
    {"SendBounty",              StatsFunctions::SendBounty}

NAMESPACE_BEGIN(StatsFunctions)
    /**
    * \brief Get the number of attributes.
    *
    * The number is 8 before any dehardcoding is done in OpenMW.
    *
    * \return The number of attributes.
    */
    API_FUNCTION int CDECL GetAttributeCount() NOEXCEPT;

    /**
    * \brief Get the number of skills.
    *
    * The number is 27 before any dehardcoding is done in OpenMW.
    *
    * \return The number of skills.
    */
    API_FUNCTION int CDECL GetSkillCount() NOEXCEPT;

    /**
    * \brief Get the numerical ID of an attribute with a certain name.
    *
    * If an invalid name is used, the ID returned is -1
    *
    * \param name The name of the attribute.
    * \return The ID of the attribute.
    */
    API_FUNCTION int CDECL GetAttributeId(const char *name) NOEXCEPT;

    /**
    * \brief Get the numerical ID of a skill with a certain name.
    *
    * If an invalid name is used, the ID returned is -1
    *
    * \param name The name of the skill.
    * \return The ID of the skill.
    */
    API_FUNCTION int CDECL GetSkillId(const char *name) NOEXCEPT;

    /**
    * \brief Get the name of the attribute with a certain numerical ID.
    *
    * If an invalid ID is used, "invalid" is returned.
    *
    * \param attributeId The ID of the attribute.
    * \return The name of the attribute.
    */
    API_FUNCTION const char *CDECL GetAttributeName(unsigned short attributeId) NOEXCEPT;

    /**
    * \brief Get the name of the skill with a certain numerical ID.
    *
    * If an invalid ID is used, "invalid" is returned.
    *
    * \param skillId The ID of the skill.
    * \return The name of the skill.
    */
    API_FUNCTION const char *CDECL GetSkillName(unsigned short skillId) NOEXCEPT;

    /**
    * \brief Get the name of a player.
    *
    * \param pid The player ID.
    * \return The name of the player.
    */
    API_FUNCTION const char *CDECL GetName(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the race of a player.
    *
    * \param pid The player ID.
    * \return The race of the player.
    */
    API_FUNCTION const char *CDECL GetRace(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the head mesh used by a player.
    *
    * \param pid The player ID.
    * \return The head mesh of the player.
    */
    API_FUNCTION const char *CDECL GetHead(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the hairstyle mesh used by a player.
    *
    * \param pid The player ID.
    * \return The hairstyle mesh of the player.
    */
    API_FUNCTION const char *CDECL GetHairstyle(PlayerId pid) NOEXCEPT;

    /**
    * \brief Check whether a player is male or not.
    *
    * \param pid The player ID.
    * \return Whether the player is male.
    */
    API_FUNCTION int CDECL GetIsMale(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the birthsign of a player.
    *
    * \param pid The player ID.
    * \return The birthsign of the player.
    */
    API_FUNCTION const char *CDECL GetBirthsign(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the character level of a player.
    *
    * \param pid The player ID.
    * \return The level of the player.
    */
    API_FUNCTION int CDECL GetLevel(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the player's progress to their next character level.
    *
    * \param pid The player ID.
    * \return The level progress.
    */
    API_FUNCTION int CDECL GetLevelProgress(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the base health of the player.
    *
    * \param pid The player ID.
    * \return The base health.
    */
    API_FUNCTION double CDECL GetHealthBase(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the current health of the player.
    *
    * \param pid The player ID.
    * \return The current health.
    */
    API_FUNCTION double CDECL GetHealthCurrent(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the base magicka of the player.
    *
    * \param pid The player ID.
    * \return The base magicka.
    */
    API_FUNCTION double CDECL GetMagickaBase(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the current magicka of the player.
    *
    * \param pid The player ID.
    * \return The current magicka.
    */
    API_FUNCTION double CDECL GetMagickaCurrent(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the base fatigue of the player.
    *
    * \param pid The player ID.
    * \return The base fatigue.
    */
    API_FUNCTION double CDECL GetFatigueBase(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the current fatigue of the player.
    *
    * \param pid The player ID.
    * \return The current fatigue.
    */
    API_FUNCTION double CDECL GetFatigueCurrent(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the base value of a player's attribute.
    *
    * \param pid The player ID.
    * \param attributeId The attribute ID.
    * \return The base value of the attribute.
    */
    API_FUNCTION int CDECL GetAttributeBase(PlayerId pid, unsigned short attributeId) NOEXCEPT;

    /**
    * \brief Get the modifier value of a player's attribute.
    *
    * \param pid The player ID.
    * \param attributeId The attribute ID.
    * \return The modifier value of the attribute.
    */
    API_FUNCTION int CDECL GetAttributeModifier(PlayerId pid, unsigned short attributeId) NOEXCEPT;

    /**
    * \brief Get the base value of a player's skill.
    *
    * \param pid The player ID.
    * \param skillId The skill ID.
    * \return The base value of the skill.
    */
    API_FUNCTION int CDECL GetSkillBase(PlayerId pid, unsigned short skillId) NOEXCEPT;

    /**
    * \brief Get the modifier value of a player's skill.
    *
    * \param pid The player ID.
    * \param skillId The skill ID.
    * \return The modifier value of the skill.
    */
    API_FUNCTION int CDECL GetSkillModifier(PlayerId pid, unsigned short skillId) NOEXCEPT;

    /**
    * \brief Get the progress the player has made towards increasing a certain skill by 1.
    *
    * \param pid The player ID.
    * \param skillId The skill ID.
    * \return The skill progress.
    */
    API_FUNCTION double CDECL GetSkillProgress(PlayerId pid, unsigned short skillId) NOEXCEPT;

    /**
    * \brief Get the bonus applied to a certain attribute at the next level up as a result
    *        of associated skill increases.
    *
    * Although confusing, the term "skill increase" for this is taken from OpenMW itself.
    *
    * \param pid The player ID.
    * \param skillId The attribute ID.
    * \return The increase in the attribute caused by skills.
    */
    API_FUNCTION int CDECL GetSkillIncrease(PlayerId pid, unsigned int attributeId) NOEXCEPT;

    /**
    * \brief Get the bounty of the player.
    *
    * \param pid The player ID.
    * \return The bounty.
    */
    API_FUNCTION int CDECL GetBounty(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the name of a player.
    *
    * \param pid The player ID.
    * \param name The new name of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetName(PlayerId pid, const char *name) NOEXCEPT;

    /**
    * \brief Set the race of a player.
    *
    * \param pid The player ID.
    * \param race The new race of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetRace(PlayerId pid, const char *race) NOEXCEPT;

    /**
    * \brief Set the head mesh used by a player.
    *
    * \param pid The player ID.
    * \param head The new head mesh of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetHead(PlayerId pid, const char *head) NOEXCEPT;

    /**
    * \brief Set the hairstyle mesh used by a player.
    *
    * \param pid The player ID.
    * \param hairstyle The new hairstyle mesh of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetHairstyle(PlayerId pid, const char *hairstyle) NOEXCEPT;

    /**
    * \brief Set whether a player is male or not.
    *
    * \param pid The player ID.
    * \param state Whether the player is male.
    * \return void
    */
    API_FUNCTION void CDECL SetIsMale(PlayerId pid, int state) NOEXCEPT;

    /**
    * \brief Set the birthsign of a player.
    *
    * \param pid The player ID.
    * \param name The new birthsign of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetBirthsign(PlayerId pid, const char *name) NOEXCEPT;

    /**
    * \brief Set whether the player's stats should be reset based on their
    *        current race as the result of a PlayerBaseInfo packet.
    *
    * This changes the resetState for that player in the server memory, but does not by itself
    * send a packet.
    *
    * \param pid The player ID.
    * \param resetStats The stat reset state.
    * \return void
    */
    API_FUNCTION void CDECL SetResetStats(PlayerId pid, bool resetStats) NOEXCEPT;
    
    /**
    * \brief Set the character level of a player.
    *
    * \param pid The player ID.
    * \param value The new level of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetLevel(PlayerId pid, int value) NOEXCEPT;

    /**
    * \brief Set the player's progress to their next character level.
    *
    * \param pid The player ID.
    * \param value The new level progress of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetLevelProgress(PlayerId pid, int value) NOEXCEPT;

    /**
    * \brief Set the base health of a player.
    *
    * \param pid The player ID.
    * \param name The new base health of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetHealthBase(PlayerId pid, double value) NOEXCEPT;

    /**
    * \brief Set the current health of a player.
    *
    * \param pid The player ID.
    * \param name The new current health of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetHealthCurrent(PlayerId pid, double value) NOEXCEPT;

    /**
    * \brief Set the base magicka of a player.
    *
    * \param pid The player ID.
    * \param name The new base magicka of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetMagickaBase(PlayerId pid, double value) NOEXCEPT;

    /**
    * \brief Set the current magicka of a player.
    *
    * \param pid The player ID.
    * \param name The new current magicka of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetMagickaCurrent(PlayerId pid, double value) NOEXCEPT;

    /**
    * \brief Set the base fatigue of a player.
    *
    * \param pid The player ID.
    * \param name The new base fatigue of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetFatigueBase(PlayerId pid, double value) NOEXCEPT;

    /**
    * \brief Set the current fatigue of a player.
    *
    * \param pid The player ID.
    * \param name The new current fatigue of the player.
    * \return void
    */
    API_FUNCTION void CDECL SetFatigueCurrent(PlayerId pid, double value) NOEXCEPT;

    /**
    * \brief Set the base value of a player's attribute.
    *
    * \param pid The player ID.
    * \param attributeId The attribute ID.
    * \param value The new base value of the player's attribute.
    * \return void
    */
    API_FUNCTION void CDECL SetAttributeBase(PlayerId pid, unsigned short attributeId, int value) NOEXCEPT;

    /**
    * \brief Clear the modifier value of a player's attribute.
    *
    * There's no way to set a modifier to a specific value because it can come from
    * multiple different sources, but clearing it is a straightforward process that
    * dispels associated effects on a client and, if necessary, unequips associated
    * items.
    *
    * \param pid The player ID.
    * \param attributeId The attribute ID.
    * \return void
    */
    API_FUNCTION void CDECL ClearAttributeModifier(PlayerId pid, unsigned short attributeId) NOEXCEPT;

    /**
    * \brief Set the base value of a player's skill.
    *
    * \param pid The player ID.
    * \param skillId The skill ID.
    * \param value The new base value of the player's skill.
    * \return void
    */
    API_FUNCTION void CDECL SetSkillBase(PlayerId pid, unsigned short skillId, int value) NOEXCEPT;

    /**
    * \brief Clear the modifier value of a player's skill.
    *
    * There's no way to set a modifier to a specific value because it can come from
    * multiple different sources, but clearing it is a straightforward process that
    * dispels associated effects on a client and, if necessary, unequips associated
    * items.
    *
    * \param pid The player ID.
    * \param skillId The skill ID.
    * \return void
    */
    API_FUNCTION void CDECL ClearSkillModifier(PlayerId pid, unsigned short skillId) NOEXCEPT;

    /**
    * \brief Set the progress the player has made towards increasing a certain skill by 1.
    *
    * \param pid The player ID.
    * \param skillId The skill ID.
    * \param value The progress value.
    * \return void
    */
    API_FUNCTION void CDECL SetSkillProgress(PlayerId pid, unsigned short skillId, double value) NOEXCEPT;

    /**
    * \brief Set the bonus applied to a certain attribute at the next level up as a result
    *        of associated skill increases.
    *
    * Although confusing, the term "skill increase" for this is taken from OpenMW itself.
    *
    * \param pid The player ID.
    * \param skillId The attribute ID.
    * \param value The increase in the attribute caused by skills.
    * \return void
    */
    API_FUNCTION void CDECL SetSkillIncrease(PlayerId pid, unsigned int attributeId, int value) NOEXCEPT;

    /**
    * \brief Set the bounty of a player.
    *
    * \param pid The player ID.
    * \param value The new bounty.
    * \return void
    */
    API_FUNCTION void CDECL SetBounty(PlayerId pid, int value) NOEXCEPT;

    /**
    * \brief Set the current and ending stages of character generation for a player.
    *
    * This is used to repeat part of character generation or to only go through part of it.
    *
    * \param pid The player ID.
    * \param currentStage The new current stage.
    * \param endStage The new ending stage.
    * \return void
    */
    API_FUNCTION void CDECL SetCharGenStage(PlayerId pid, int currentStage, int endStage) NOEXCEPT;

    /**
    * \brief Send a PlayerBaseInfo packet with a player's name, race, head mesh,
    *        hairstyle mesh, birthsign and stat reset state.
    *
    * It is always sent to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendBaseInfo(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerStatsDynamic packet with a player's dynamic stats (health,
    *        magicka and fatigue).
    *
    * It is always sent to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendStatsDynamic(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerAttribute packet with a player's attributes and bonuses
    *        to those attributes at the next level up (the latter being called
    *        "skill increases" as in OpenMW).
    *
    * It is always sent to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendAttributes(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerSkill packet with a player's skills.
    *
    * It is always sent to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendSkills(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerLevel packet with a player's character level and
    *        progress towards the next level up
    *
    * It is always sent to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendLevel(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerBounty packet with a player's bounty.
    *
    * It is always sent to all players.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendBounty(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_STATAPI_HPP
