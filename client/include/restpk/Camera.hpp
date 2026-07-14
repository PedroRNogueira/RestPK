#pragma once

#include <SDL3/SDL_rect.h>

#include <restpk/Position.hpp>

namespace restpk {

class Camera final {
public:
    Camera(int viewportWidth, int viewportHeight, int tileSize) noexcept;

    void centerOn(const Position& target, int worldWidth, int worldHeight) noexcept;

    [[nodiscard]] SDL_FPoint worldToScreen(int worldX, int worldY) const noexcept;

private:
    int viewportWidth_;
    int viewportHeight_;
    int tileSize_;
    float x_ {0.0F};
    float y_ {0.0F};
};

} // namespace restpk
