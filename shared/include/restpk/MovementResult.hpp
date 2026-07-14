#pragma once

namespace restpk {

enum class MovementResult {
    Moved,
    BlockedByBounds,
    BlockedByTile,
};

} // namespace restpk
