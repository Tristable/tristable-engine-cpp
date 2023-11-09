#include "../core/EngineInstance.hpp"
#include "Renderer.hpp"
#include <iostream>

#define IMG_INIT_ALL IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_AVIF | IMG_INIT_JXL | IMG_INIT_TIF | IMG_INIT_WEBP

using namespace tse;

Renderer::Renderer() {
    if (Renderer::running != NULL) delete Renderer::running;
    TTF_Init();
    IMG_Init(IMG_INIT_ALL);
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

void tse::setSDLDrawColor(SDL_Color color) {
    SDL_SetRenderDrawColor(EngineInstance::running->sdlRenderer, color.r, color.g, color.b, color.a);
}