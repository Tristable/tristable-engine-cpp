#ifndef TSE_ENGINEINSTANCE_H
#define TSE_ENGINEINSTANCE_H

#include "../../include/SDL2/SDL.h"
#include <string>
#include "../math/Vector2.hpp"

namespace tse {
    class EngineInstance {
        public:
            static EngineInstance* running;

            int width, height;
            std::string title;
            SDL_Window* sdlWindow;
            SDL_Renderer* sdlRenderer;
            bool keepWindowOpen = true;
            double deltaTime = 0;
            int64_t lastFrameTime = 0;

            EngineInstance(int width, int height, std::string title);

            ~EngineInstance();
    };
}

#endif