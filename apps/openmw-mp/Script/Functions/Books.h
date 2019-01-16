#ifndef OPENMW_BOOKAPI_HPP
#define OPENMW_BOOKAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(BookFunctions)

    /**
    * \brief Clear the last recorded book changes for a player.
    *
    * This is used to initialize the sending of new PlayerBook packets.
    *
    * \param pid The player ID whose book changes should be used.
    * \return void
    */
    API_FUNCTION void CDECL ClearBookChanges(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the number of indexes in a player's latest book changes.
    *
    * \param pid The player ID whose book changes should be used.
    * \return The number of indexes.
    */
    API_FUNCTION unsigned int CDECL GetBookChangesSize(PlayerId pid) NOEXCEPT;

    /**
    * \brief Add a new book to the book changes for a player.
    *
    * \param pid The player ID whose book changes should be used.
    * \param bookId The bookId of the book.
    * \return void
    */
    API_FUNCTION void CDECL AddBook(PlayerId pid, const char* bookId) NOEXCEPT;

    /**
    * \brief Get the bookId at a certain index in a player's latest book changes.
    *
    * \param pid The player ID whose book changes should be used.
    * \param index The index of the book.
    * \return The bookId.
    */
    API_FUNCTION const char *CDECL GetBookId(PlayerId pid, unsigned int index) NOEXCEPT;

    /**
    * \brief Send a PlayerBook packet with a player's recorded book changes.
    *
    * \param pid The player ID whose book changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    API_FUNCTION void CDECL SendBookChanges(PlayerId pid, bool sendToOtherPlayers, bool skipAttachedPlayer) NOEXCEPT;

    // All methods below are deprecated versions of methods from above

    API_FUNCTION void CDECL InitializeBookChanges(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_BOOKAPI_HPP
