#pragma once

namespace restpk {

enum class TileType {
    Ground,
    Blocked,
};

class Tile {
public:
    explicit Tile(TileType type = TileType::Ground) noexcept
        : type_(type)
    {
    }

    [[nodiscard]] TileType type() const noexcept
    {
        return type_;
    }

    [[nodiscard]] bool isWalkable() const noexcept
    {
        return type_ == TileType::Ground;
    }

private:
    TileType type_;
};

} // namespace restpk
