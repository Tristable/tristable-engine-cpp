#include "rect.hpp"
#include "../core/EngineInstance.hpp"
#include "Renderer.hpp"
#include <iostream>

using namespace tse;

void tse::drawFillRect(Rect2i* rect, SDL_Color color) {
    if (!rect) {
        std::cout << "Null pointer used as rect.\n";
        return;
    }

    SDL_Rect sdlRect = *rect;

    setSDLDrawColor(color);
    SDL_RenderFillRect(EngineInstance::running->sdlRenderer, &sdlRect);
}

void tse::drawBorderRect(Rect2i* rect, SDL_Color color) {
    if (!rect) {
        std::cout << "Null pointer used as rect.\n";
        return;
    }

    SDL_Rect sdlRect = *rect;

    setSDLDrawColor(color);
    SDL_RenderDrawRect(EngineInstance::running->sdlRenderer, &sdlRect);
}

void tse::drawRect(Rect2i* rect, SDL_Color fill, SDL_Color border) {
    if (!rect) {
        std::cout << "Null pointer used as rect.\n";
        return;
    }

    SDL_Rect sdlRect = *rect;

    setSDLDrawColor(fill);
    SDL_RenderFillRect(EngineInstance::running->sdlRenderer, &sdlRect);

    setSDLDrawColor(border);
    SDL_RenderDrawRect(EngineInstance::running->sdlRenderer, &sdlRect);
}