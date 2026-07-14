#pragma once

namespace restpk {

struct Position {
    int x;
    int y;
    int z;

    bool operator==(const Position&) const = default;
};

} // namespace restpk
