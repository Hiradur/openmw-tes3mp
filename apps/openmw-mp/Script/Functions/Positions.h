#ifndef OPENMW_POSITIONAPI_HPP
#define OPENMW_POSITIONAPI_HPP

#include "../api.h"

NAMESPACE_BEGIN(PositionFunctions)
    /**
    * \brief Assign the player's positional coordinate values to the variables passed as
    * parameters.
    *
    * \param pid The player ID.
    * \param x The variable for the X position.
    * \param y The variable for the Y position.
    * \param z The variable for the Z position.
    * \return void
    */
    API_FUNCTION void CDECL GetPos(PlayerId pid, float *x, float *y, float *z) NOEXCEPT;

    /**
    * \brief Get the X position of a player.
    *
    * \param pid The player ID.
    * \return The X position.
    */
    API_FUNCTION double CDECL GetPosX(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Y position of a player.
    *
    * \param pid The player ID.
    * \return The Y position.
    */
    API_FUNCTION double CDECL GetPosY(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Z position of a player.
    *
    * \param pid The player ID.
    * \return The Z position.
    */
    API_FUNCTION double CDECL GetPosZ(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the X position of a player from before their latest cell change.
    *
    * \param pid The player ID.
    * \return The X position.
    */
    API_FUNCTION double CDECL GetPreviousCellPosX(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Y position of a player from before their latest cell change.
    *
    * \param pid The player ID.
    * \return The Y position.
    */
    API_FUNCTION double CDECL GetPreviousCellPosY(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Z position of a player from before their latest cell change.
    *
    * \param pid The player ID.
    * \return The Z position.
    */
    API_FUNCTION double CDECL GetPreviousCellPosZ(PlayerId pid) NOEXCEPT;

    /**
    * \brief Assign the player's rotational coordinate values to the variables passed as
    * parameters.
    *
    * \param pid The player ID.
    * \param x The variable for the X rotation.
    * \param y The variable for the Y rotation.
    * \param z The variable for the Z rotation.
    * \return void
    */
    API_FUNCTION void CDECL GetRot(PlayerId pid, float *x, float *y, float *z) NOEXCEPT;

    /**
    * \brief Get the X rotation of a player.
    *
    * \param pid The player ID.
    * \return The X rotation.
    */
    API_FUNCTION double CDECL GetRotX(PlayerId pid) NOEXCEPT;

    /**
    * \brief Get the Z rotation of a player.
    *
    * \param pid The player ID.
    * \return The Z rotation.
    */
    API_FUNCTION double CDECL GetRotZ(PlayerId pid) NOEXCEPT;

    /**
    * \brief Set the position of a player.
    *
    * This changes the positional coordinates recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param x The X position.
    * \param y The Y position.
    * \param z The Z position.
    * \return void
    */
    API_FUNCTION void CDECL SetPos(PlayerId pid, double x, double y, double z) NOEXCEPT;

    /**
    * \brief Set the rotation of a player.
    *
    * This changes the rotational coordinates recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * A player's Y rotation is always 0, which is why there is no Y rotation parameter.
    *
    * \param pid The player ID.
    * \param x The X position.
    * \param z The Z position.
    * \return void
    */
    API_FUNCTION void CDECL SetRot(PlayerId pid, double x, double z) NOEXCEPT;

    /**
    * \brief Set the momentum of a player.
    *
    * This changes the coordinates recorded for that player's momentum in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param x The X momentum.
    * \param y The Y momentum.
    * \param z The Z momentum.
    * \return void
    */
    API_FUNCTION void CDECL SetMomentum(PlayerId pid, double x, double y, double z) NOEXCEPT;

    /**
    * \brief Send a PlayerPosition packet about a player.
    *
    * It is only sent to the affected player.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendPos(PlayerId pid) NOEXCEPT;

    /**
    * \brief Send a PlayerMomentum packet about a player.
    *
    * It is only sent to the affected player.
    *
    * \param pid The player ID.
    * \return void
    */
    API_FUNCTION void CDECL SendMomentum(PlayerId pid) NOEXCEPT;
NAMESPACE_END()

#endif //OPENMW_POSITIONAPI_HPP
