#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>

namespace {

bool processEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }
    }

    return true;
}

void update()
{
}

bool render(SDL_Renderer* renderer)
{
    if (!SDL_SetRenderDrawColor(renderer, 18, 18, 24, SDL_ALPHA_OPAQUE)) {
        std::cerr << "Failed to set the render color: " << SDL_GetError() << '\n';
        return false;
    }

    if (!SDL_RenderClear(renderer)) {
        std::cerr << "Failed to clear the renderer: " << SDL_GetError() << '\n';
        return false;
    }

    if (!SDL_RenderPresent(renderer)) {
        std::cerr << "Failed to present the frame: " << SDL_GetError() << '\n';
        return false;
    }

    return true;
}

} // namespace

int main(int, char*[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("RestPK", 1280, 720, 0);
    if (window == nullptr) {
        std::cerr << "Failed to create the window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (renderer == nullptr) {
        std::cerr << "Failed to create the renderer: " << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int exitCode = 0;
    bool running = true;

    while (running) {
        running = processEvents();
        if (!running) {
            break;
        }

        update();

        if (!render(renderer)) {
            exitCode = 1;
            break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return exitCode;
}
