#include "restpk/World.hpp"

#include <stdexcept>

namespace restpk {

World::World()
    : tiles_(static_cast<std::size_t>(kWidth * kHeight)),
      player_(Position{2, 2, 0})
{
    generateMap();
}

int World::width() const noexcept
{
    return kWidth;
}

int World::height() const noexcept
{
    return kHeight;
}

const Tile& World::tileAt(int x, int y) const
{
    if (!isWithinBounds(x, y)) {
        throw std::out_of_range("Tile coordinates are outside the world");
    }

    return tiles_[tileIndex(x, y)];
}

const Player& World::player() const noexcept
{
    return player_;
}

MovementResult World::movePlayer(Direction direction)
{
    Position destination = player_.position();

    switch (direction) {
    case Direction::North:
        --destination.y;
        break;
    case Direction::East:
        ++destination.x;
        break;
    case Direction::South:
        ++destination.y;
        break;
    case Direction::West:
        --destination.x;
        break;
    }

    if (!isWithinBounds(destination.x, destination.y)) {
        return MovementResult::BlockedByBounds;
    }

    if (!tileAt(destination.x, destination.y).isWalkable()) {
        return MovementResult::BlockedByTile;
    }

    player_.setPosition(destination);
    return MovementResult::Moved;
}

bool World::isWithinBounds(int x, int y) const noexcept
{
    return x >= 0 && x < kWidth && y >= 0 && y < kHeight;
}

std::size_t World::tileIndex(int x, int y) const noexcept
{
    return static_cast<std::size_t>(y * kWidth + x);
}

void World::setBlocked(int x, int y) noexcept
{
    if (isWithinBounds(x, y)) {
        tiles_[tileIndex(x, y)] = Tile{TileType::Blocked};
    }
}

void World::generateMap()
{
    for (int x = 0; x < kWidth; ++x) {
        setBlocked(x, 0);
        setBlocked(x, kHeight - 1);
    }

    for (int y = 0; y < kHeight; ++y) {
        setBlocked(0, y);
        setBlocked(kWidth - 1, y);
    }

    for (int x = 6; x <= 14; ++x) {
        setBlocked(x, 5);
    }

    for (int y = 9; y <= 21; ++y) {
        setBlocked(18, y);
    }

    for (int x = 25; x <= 39; ++x) {
        if (x != 32) {
            setBlocked(x, 14);
        }
    }

    for (int y = 20; y <= 29; ++y) {
        if (y != 25) {
            setBlocked(36, y);
        }
    }

    for (int x = 5; x <= 11; ++x) {
        setBlocked(x, 27);
    }
}

} // namespace restpk
