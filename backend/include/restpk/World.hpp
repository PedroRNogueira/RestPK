#pragma once

#include <cstddef>
#include <vector>

#include "restpk/Direction.hpp"
#include "restpk/MovementResult.hpp"
#include "restpk/Player.hpp"
#include "restpk/Tile.hpp"

namespace restpk {

class World {
public:
    World();

    [[nodiscard]] int width() const noexcept;
    [[nodiscard]] int height() const noexcept;
    [[nodiscard]] const Tile& tileAt(int x, int y) const;
    [[nodiscard]] const Player& player() const noexcept;

    MovementResult movePlayer(Direction direction);

private:
    static constexpr int kWidth = 50;
    static constexpr int kHeight = 35;

    [[nodiscard]] bool isWithinBounds(int x, int y) const noexcept;
    [[nodiscard]] std::size_t tileIndex(int x, int y) const noexcept;
    void setBlocked(int x, int y) noexcept;
    void generateMap();

    std::vector<Tile> tiles_;
    Player player_;
};

} // namespace restpk
