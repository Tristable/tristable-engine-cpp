#include "texture.hpp"
#include "../../include/SDL2/SDL_image.h"
#include "../core/EngineInstance.hpp"
#include "Renderer.hpp"
#include "rect.hpp"
#include <iostream>

using namespace tse;

void tse::cacheTextureFromFile(std::string name, std::string path) {
    SDL_Texture* texture = IMG_LoadTexture(EngineInstance::running->sdlRenderer, "tests/img/hmmm.png");

    if (!texture) {
        std::cout << "Failed to cache image. " << IMG_GetError() << std::endl;
        exit(1);
        return;
    }

    Renderer::running->textureCache[name] = texture;
}

void tse::deleteCachedTexture(std::string name) {
    SDL_DestroyTexture(Renderer::running->textureCache[name]);
    // TODO: remove the texture from the cache
}

void tse::drawTexture(std::string texture, Rect2i* destination, Rect2i* source, double rotationDeg) {
    SDL_Texture* img = Renderer::running->textureCache["hmmm"];

    SDL_Rect dest = *destination;

    if (EngineInstance::running->debug.showTextureRenderRects) drawBorderRect(destination, { 0, 0, 255 });

    if (!source) return (void)SDL_RenderCopyEx(EngineInstance::running->sdlRenderer, img, NULL, &dest, rotationDeg, NULL, SDL_FLIP_NONE);

    SDL_Rect src = *source;

    SDL_RenderCopyEx(EngineInstance::running->sdlRenderer, img, &src, &dest, rotationDeg, NULL, SDL_FLIP_NONE);
}