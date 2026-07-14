#include <restpk/Game.hpp>

#include <restpk/Tile.hpp>

#include <iostream>

namespace restpk {
namespace {

struct Color {
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    Uint8 alpha;
};

constexpr Color BackgroundColor {18, 18, 24, SDL_ALPHA_OPAQUE};
constexpr Color GroundColor {66, 122, 72, SDL_ALPHA_OPAQUE};
constexpr Color BlockedColor {67, 73, 85, SDL_ALPHA_OPAQUE};
constexpr Color PlayerColor {240, 197, 71, SDL_ALPHA_OPAQUE};
constexpr Uint32 FrameDelayMilliseconds = 16;

bool setRenderColor(SDL_Renderer* renderer, const Color& color)
{
    if (SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha)) {
        return true;
    }

    std::cerr << "Failed to set the render color: " << SDL_GetError() << '\n';
    return false;
}

bool fillRectangle(SDL_Renderer* renderer, const SDL_FRect& rectangle)
{
    if (SDL_RenderFillRect(renderer, &rectangle)) {
        return true;
    }

    std::cerr << "Failed to draw a rectangle: " << SDL_GetError() << '\n';
    return false;
}

} // namespace

Game::Game()
    : camera_(WindowWidth, WindowHeight, TileSize)
{
}

Game::~Game()
{
    shutdown();
}

int Game::run()
{
    if (!initialize()) {
        return 1;
    }

    int exitCode = 0;
    running_ = true;

    while (running_) {
        processEvents();
        if (!running_) {
            break;
        }

        update();

        if (!render()) {
            exitCode = 1;
            break;
        }

        SDL_Delay(FrameDelayMilliseconds);
    }

    return exitCode;
}

bool Game::initialize()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << '\n';
        return false;
    }
    sdlInitialized_ = true;

    window_ = SDL_CreateWindow("RestPK", WindowWidth, WindowHeight, 0);
    if (window_ == nullptr) {
        std::cerr << "Failed to create the window: " << SDL_GetError() << '\n';
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, nullptr);
    if (renderer_ == nullptr) {
        std::cerr << "Failed to create the renderer: " << SDL_GetError() << '\n';
        return false;
    }

    camera_.centerOn(world_.player().position(), world_.width(), world_.height());
    return true;
}

void Game::processEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running_ = false;
            return;
        }

        if (event.type == SDL_EVENT_KEY_DOWN && !event.key.repeat) {
            queueMovement(event.key.key);
        }
    }
}

void Game::queueMovement(SDL_Keycode key)
{
    switch (key) {
    case SDLK_W:
    case SDLK_UP:
        pendingMovements_.push_back(Direction::North);
        break;
    case SDLK_D:
    case SDLK_RIGHT:
        pendingMovements_.push_back(Direction::East);
        break;
    case SDLK_S:
    case SDLK_DOWN:
        pendingMovements_.push_back(Direction::South);
        break;
    case SDLK_A:
    case SDLK_LEFT:
        pendingMovements_.push_back(Direction::West);
        break;
    default:
        break;
    }
}

void Game::update()
{
    if (pendingMovements_.empty()) {
        return;
    }

    for (const Direction direction : pendingMovements_) {
        static_cast<void>(world_.movePlayer(direction));
    }
    pendingMovements_.clear();

    camera_.centerOn(world_.player().position(), world_.width(), world_.height());
}

bool Game::render()
{
    if (!setRenderColor(renderer_, BackgroundColor)) {
        return false;
    }
    if (!SDL_RenderClear(renderer_)) {
        std::cerr << "Failed to clear the renderer: " << SDL_GetError() << '\n';
        return false;
    }

    for (int y = 0; y < world_.height(); ++y) {
        for (int x = 0; x < world_.width(); ++x) {
            const Tile& tile = world_.tileAt(x, y);
            const Color& tileColor =
                tile.type() == TileType::Blocked ? BlockedColor : GroundColor;

            if (!setRenderColor(renderer_, tileColor)) {
                return false;
            }

            const SDL_FPoint screenPosition = camera_.worldToScreen(x, y);
            const SDL_FRect tileRectangle {
                screenPosition.x,
                screenPosition.y,
                static_cast<float>(TileSize),
                static_cast<float>(TileSize),
            };

            if (!fillRectangle(renderer_, tileRectangle)) {
                return false;
            }
        }
    }

    const Position& playerPosition = world_.player().position();
    const SDL_FPoint playerScreenPosition =
        camera_.worldToScreen(playerPosition.x, playerPosition.y);
    constexpr float PlayerInset = 6.0F;
    const SDL_FRect playerRectangle {
        playerScreenPosition.x + PlayerInset,
        playerScreenPosition.y + PlayerInset,
        static_cast<float>(TileSize) - PlayerInset * 2.0F,
        static_cast<float>(TileSize) - PlayerInset * 2.0F,
    };

    if (!setRenderColor(renderer_, PlayerColor)) {
        return false;
    }
    if (!fillRectangle(renderer_, playerRectangle)) {
        return false;
    }

    if (!SDL_RenderPresent(renderer_)) {
        std::cerr << "Failed to present the frame: " << SDL_GetError() << '\n';
        return false;
    }

    return true;
}

void Game::shutdown() noexcept
{
    if (renderer_ != nullptr) {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }

    if (window_ != nullptr) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }

    if (sdlInitialized_) {
        SDL_Quit();
        sdlInitialized_ = false;
    }
}

} // namespace restpk
