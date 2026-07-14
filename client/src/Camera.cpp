#include <restpk/Camera.hpp>

#include <algorithm>

namespace restpk {
namespace {

float calculateOffset(
    int targetCoordinate,
    int worldSizeInTiles,
    int viewportSize,
    int tileSize) noexcept
{
    const float worldSize = static_cast<float>(worldSizeInTiles) * static_cast<float>(tileSize);
    const float viewport = static_cast<float>(viewportSize);

    if (worldSize <= viewport) {
        return (worldSize - viewport) * 0.5F;
    }

    const float targetCenter =
        (static_cast<float>(targetCoordinate) + 0.5F) * static_cast<float>(tileSize);
    const float desiredOffset = targetCenter - viewport * 0.5F;

    return std::clamp(desiredOffset, 0.0F, worldSize - viewport);
}

} // namespace

Camera::Camera(int viewportWidth, int viewportHeight, int tileSize) noexcept
    : viewportWidth_(viewportWidth)
    , viewportHeight_(viewportHeight)
    , tileSize_(tileSize)
{
}

void Camera::centerOn(const Position& target, int worldWidth, int worldHeight) noexcept
{
    x_ = calculateOffset(target.x, worldWidth, viewportWidth_, tileSize_);
    y_ = calculateOffset(target.y, worldHeight, viewportHeight_, tileSize_);
}

SDL_FPoint Camera::worldToScreen(int worldX, int worldY) const noexcept
{
    return {
        static_cast<float>(worldX * tileSize_) - x_,
        static_cast<float>(worldY * tileSize_) - y_,
    };
}

} // namespace restpk
