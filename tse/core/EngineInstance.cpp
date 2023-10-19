#include "EngineInstance.hpp"

#include <iostream>

using namespace tse;

EngineInstance::EngineInstance(int width, int height, std::string title) : width(width), height(height), title(title) {
    if (EngineInstance::running != NULL) delete EngineInstance::running;
    EngineInstance::running = this;
}

EngineInstance::~EngineInstance() {
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
    if (EngineInstance::running == this) EngineInstance::running = NULL;
}

EngineInstance* EngineInstance::running = NULL;