#include "line.hpp"
#include "../core/EngineInstance.hpp"
#include "Renderer.hpp"
#include <iostream>

using namespace tse;

void tse::drawLine(Line2i* line, SDL_Color color) {
    if (!line) {
        std::cout << "Null pointer used as line.\n";
        return;
    }

    setSDLDrawColor(color);
    SDL_RenderDrawLine(EngineInstance::running->sdlRenderer, line->start.x, line->start.y, line->end.x, line->end.y);
}