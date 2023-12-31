#ifndef TSE_RENDERER_H
#define TSE_RENDERER_H

#include "../global.hpp"
#include <map>

namespace tse {
    class Renderer {
        public:
            static Renderer* running;
            std::map<std::string, TTF_Font*> fontCache;
            std::map<std::string, SDL_Texture*> textureCache;
            std::string defaultFont;

            Renderer();

            ~Renderer();
    };

    void createSDLRenderer();

    void setSDLDrawColor(SDL_Color color);
}

#endif