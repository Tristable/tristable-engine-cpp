#include <iostream>

#include "EngineInstance.hpp"
#include "window.hpp"

using namespace tse;

void tse::createWindow() {
    EngineInstance* ei = EngineInstance::running;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize the SDL2 library\n";
        exit(1);
        return;
    }

    ei->sdlWindow = SDL_CreateWindow(
        ei->title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        ei->width, ei->height,
        0
    );

    if (!ei->sdlWindow) {
        std::cout << "Failed to create SDL2 window.\n";
        exit(1);
        return;
    }
}