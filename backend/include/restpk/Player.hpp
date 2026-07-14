#pragma once

#include "restpk/Position.hpp"

namespace restpk {

class World;

class Player {
public:
    explicit Player(Position initialPosition) noexcept;

    [[nodiscard]] const Position& position() const noexcept;

private:
    friend class World;

    void setPosition(Position position) noexcept;

    Position position_;
};

} // namespace restpk
