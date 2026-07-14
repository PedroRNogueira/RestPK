#pragma once

#include <SDL3/SDL.h>

#include <restpk/Camera.hpp>
#include <restpk/Direction.hpp>
#include <restpk/World.hpp>

#include <vector>

namespace restpk {

class Game final {
public:
    Game();
    ~Game();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(Game&&) = delete;

    [[nodiscard]] int run();

private:
    static constexpr int WindowWidth = 1280;
    static constexpr int WindowHeight = 720;
    static constexpr int TileSize = 32;

    [[nodiscard]] bool initialize();
    void processEvents();
    void queueMovement(SDL_Keycode key);
    void update();
    [[nodiscard]] bool render();
    void shutdown() noexcept;

    SDL_Window* window_ {nullptr};
    SDL_Renderer* renderer_ {nullptr};
    bool sdlInitialized_ {false};
    bool running_ {false};
    World world_;
    Camera camera_;
    std::vector<Direction> pendingMovements_;
};

} // namespace restpk
