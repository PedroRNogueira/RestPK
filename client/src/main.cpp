#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <restpk/Game.hpp>

int main(int, char*[])
{
    restpk::Game game;
    return game.run();
}
