#include "text.hpp"
#include "../../include/SDL2/SDL_ttf.h"
#include "renderer.hpp"
#include "../core/EngineInstance.hpp"
#include <iostream>

using namespace tse;

void tse::cacheFont(std::string name, std::string path, int size) {
    TTF_Font* font = TTF_OpenFont(path.c_str(), size);

    if (!font) {
        std::cout << "Failed to cache font. " << TTF_GetError() << std::endl;
        exit(1);
        return;
    }

    Renderer::running->fontCache[name] = font;
}

void tse::closeCachedFont(std::string name) {
    TTF_CloseFont(Renderer::running->fontCache[name]);
}

void tse::drawText(Vector2i position, std::string text, std::string font, SDL_Color color) {
    std::cout << !!Renderer::running->fontCache[font] << std::endl;
    SDL_Surface* surface = TTF_RenderUTF8_Blended(Renderer::running->fontCache[font], text.c_str(), color);

    if (!surface) {
        std::cout << "Failed to create font surface.\n";
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(EngineInstance::running->sdlRenderer, surface);
    SDL_Rect rect = { position.x, position.y, surface->w, surface->h };

    SDL_RenderCopy(EngineInstance::running->sdlRenderer, texture, NULL, &rect);
    std::cout << "hi\n";

    SDL_DestroyTexture(texture);
    std::cout << "hi\n";
}
