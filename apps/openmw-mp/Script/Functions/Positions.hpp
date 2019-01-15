#ifndef OPENMW_POSITIONAPI_HPP
#define OPENMW_POSITIONAPI_HPP

#include "../Types.hpp"

#include <Script/Platform.hpp>

#define POSITIONAPI \
    {"GetPos",              PositionFunctions::GetPos},\
    {"GetPosX",             PositionFunctions::GetPosX},\
    {"GetPosY",             PositionFunctions::GetPosY},\
    {"GetPosZ",             PositionFunctions::GetPosZ},\
    \
    {"GetPreviousCellPosX", PositionFunctions::GetPreviousCellPosX},\
    {"GetPreviousCellPosY", PositionFunctions::GetPreviousCellPosY},\
    {"GetPreviousCellPosZ", PositionFunctions::GetPreviousCellPosZ},\
    \
    {"GetRot",              PositionFunctions::GetRot},\
    {"GetRotX",             PositionFunctions::GetRotX},\
    {"GetRotZ",             PositionFunctions::GetRotZ},\
    \
    {"SetPos",              PositionFunctions::SetPos},\
    {"SetRot",              PositionFunctions::SetRot},\
    {"SetMomentum",         PositionFunctions::SetMomentum},\
    \
    {"SendPos",             PositionFunctions::SendPos},\
    {"SendMomentum",        PositionFunctions::SendMomentum}


namespace PositionFunctions
{
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
    EXPORT_APIFUNCTION void CDECL GetPos(unsigned short pid, float *x, float *y, float *z) noexcept;

    /**
    * \brief Get the X position of a player.
    *
    * \param pid The player ID.
    * \return The X position.
    */
    EXPORT_APIFUNCTION double CDECL GetPosX(unsigned short pid) noexcept;

    /**
    * \brief Get the Y position of a player.
    *
    * \param pid The player ID.
    * \return The Y position.
    */
    EXPORT_APIFUNCTION double CDECL GetPosY(unsigned short pid) noexcept;

    /**
    * \brief Get the Z position of a player.
    *
    * \param pid The player ID.
    * \return The Z position.
    */
    EXPORT_APIFUNCTION double CDECL GetPosZ(unsigned short pid) noexcept;

    /**
    * \brief Get the X position of a player from before their latest cell change.
    *
    * \param pid The player ID.
    * \return The X position.
    */
    EXPORT_APIFUNCTION double CDECL GetPreviousCellPosX(unsigned short pid) noexcept;

    /**
    * \brief Get the Y position of a player from before their latest cell change.
    *
    * \param pid The player ID.
    * \return The Y position.
    */
    EXPORT_APIFUNCTION double CDECL GetPreviousCellPosY(unsigned short pid) noexcept;

    /**
    * \brief Get the Z position of a player from before their latest cell change.
    *
    * \param pid The player ID.
    * \return The Z position.
    */
    EXPORT_APIFUNCTION double CDECL GetPreviousCellPosZ(unsigned short pid) noexcept;

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
    EXPORT_APIFUNCTION void CDECL GetRot(unsigned short pid, float *x, float *y, float *z) noexcept;

    /**
    * \brief Get the X rotation of a player.
    *
    * \param pid The player ID.
    * \return The X rotation.
    */
    EXPORT_APIFUNCTION double CDECL GetRotX(unsigned short pid) noexcept;

    /**
    * \brief Get the Z rotation of a player.
    *
    * \param pid The player ID.
    * \return The Z rotation.
    */
    EXPORT_APIFUNCTION double CDECL GetRotZ(unsigned short pid) noexcept;

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
    EXPORT_APIFUNCTION void CDECL SetPos(unsigned short pid, double x, double y, double z) noexcept;

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
    EXPORT_APIFUNCTION void CDECL SetRot(unsigned short pid, double x, double z) noexcept;

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
    EXPORT_APIFUNCTION void CDECL SetMomentum(unsigned short pid, double x, double y, double z) noexcept;

    /**
    * \brief Send a PlayerPosition packet about a player.
    *
    * It is only sent to the affected player.
    *
    * \param pid The player ID.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendPos(unsigned short pid) noexcept;

    /**
    * \brief Send a PlayerMomentum packet about a player.
    *
    * It is only sent to the affected player.
    *
    * \param pid The player ID.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendMomentum(unsigned short pid) noexcept;
}

#endif //OPENMW_POSITIONAPI_HPP
