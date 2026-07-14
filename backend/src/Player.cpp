#include "restpk/Player.hpp"

namespace restpk {

Player::Player(Position initialPosition) noexcept
    : position_(initialPosition)
{
}

const Position& Player::position() const noexcept
{
    return position_;
}

void Player::setPosition(Position position) noexcept
{
    position_ = position;
}

} // namespace restpk
