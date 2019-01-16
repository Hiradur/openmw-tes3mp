#ifndef OPENMW_DIALOGUEAPI_HPP
#define OPENMW_DIALOGUEAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(DialogueFunctions)
    /**
    * \brief Clear the last recorded topic changes for a player.
    *
    * This is used to initialize the sending of new PlayerTopic packets.
    *
    * \param pid The player ID whose topic changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL ClearTopicChanges(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the number of indexes in a player's latest topic changes.
    *
    * \param pid The player ID whose topic changes should be used.
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetTopicChangesSize(PlayerId pid) NOEXCEPT;

    /**
    * \brief Add a new topic to the topic changes for a player.
    *
    * \param pid The player ID whose topic changes should be used.
    * \param topicId The topicId of the topic.
    * \return void
    */
    API_FUNCTION void CDECL AddTopic(PlayerId pid, const char* topicId) NOEXCEPT;

    /**
    * \brief Get the topicId at a certain index in a player's latest topic changes.
    *
    * \param pid The player ID whose topic changes should be used.
    * \param index The index of the topic.
    * \return The topicId.
    */
    API_FUNCTION const char *CDECL GetTopicId(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Send a PlayerTopic packet with a player's recorded topic changes.
    *
    * \param pid The player ID whose topic changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendTopicChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    /**
    * \brief Play a certain animation on a player's character by sending a PlayerAnimation
    *        packet.
    *
    * \param pid The player ID of the character playing the animation.
    * \param groupname The groupname of the animation.
    * \param mode The mode of the animation.
    * \param count The number of times the animation should be played.
    * \param bool Whether the animation should persist or not.
    * \return void
    */
    API_FUNCTION void CDECL PlayAnimation(PlayerId pid, const char* groupname, int mode, int count, bool persist) NOEXCEPT;

    /**
    * \brief Play a certain sound for a player as spoken by their character by sending
    *        a PlayerSpeech packet.
    *
    * \param pid The player ID of the character playing the sound.
    * \param sound The path of the sound file.
    * \return void
    */
    API_FUNCTION void CDECL PlaySpeech(PlayerId pid, const char* sound) NOEXCEPT;

    // All methods below are deprecated versions of methods from above

    API_FUNCTION void CDECL InitializeTopicChanges(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_DIALOGUEAPI_HPP
