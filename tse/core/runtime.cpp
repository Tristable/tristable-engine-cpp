#include "runtime.hpp"
#include "EngineInstance.hpp"
#include <chrono>
#include <unistd.h>
#include <iostream>

using namespace tse;

void tse::startRuntime(void (*runtime)(double), void (*eventHandler)(SDL_Event*)) {
    using namespace std::chrono;

    EngineInstance* ei = EngineInstance::running;

    while (ei->keepWindowOpen) {
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch()).count();
        int64_t diff = now - ei->lastFrameTime;
        ei->lastFrameTime = now;
        ei->deltaTime = double(diff) / 1000.0;

        SDL_Event e;

        while (SDL_PollEvent(&e) > 0) {
            switch (e.type) {
                case SDL_QUIT:
                    ei->keepWindowOpen = false;
                    break;
            }
            
            eventHandler(&e);
        }
        
        SDL_RenderClear(EngineInstance::running->sdlRenderer);

        runtime(ei->deltaTime);

        SDL_SetRenderDrawColor(EngineInstance::running->sdlRenderer, 0, 0, 0, 255);
        SDL_RenderPresent(EngineInstance::running->sdlRenderer);
    }
}