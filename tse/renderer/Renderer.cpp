#include "../core/EngineInstance.hpp"
#include "renderer.hpp"
#include <iostream>

using namespace tse;

Renderer::Renderer() {
    if (Renderer::running != NULL) delete Renderer::running;
    TTF_Init();
    Renderer::running = this;
    createSDLRenderer();
}

Renderer::~Renderer() {
    
}

Renderer* Renderer::running = NULL;

void tse::createSDLRenderer() {
    EngineInstance::running->sdlRenderer = SDL_CreateRenderer(EngineInstance::running->sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!EngineInstance::running->sdlRenderer) {
        std::cout << "Failed to create SDL2 renderer. " << SDL_GetError() << "\n";
        exit(1);
        return;
    }
}