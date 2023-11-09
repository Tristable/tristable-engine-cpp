#include "runtime.hpp"
#include "EngineInstance.hpp"
#include "../renderer/text.hpp"
#include "../renderer/Renderer.hpp"
#include <chrono>
#include <iostream>
#include <numeric>

using namespace tse;

void tse::startRuntime(void (*runtime)(double), void (*eventHandler)(SDL_Event*)) {
    using namespace std::chrono;

    EngineInstance* ei = EngineInstance::running;

    while (ei->keepWindowOpen) {
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch()).count();
        int64_t diff = ei->lastFrameTime == 0 ? 0 : now - ei->lastFrameTime;
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

        for (int i = 0; i < (int)ei->lastDeltaTimes.size(); i++) if (i != (int)ei->lastDeltaTimes.size() - 1) ei->lastDeltaTimes[i] = ei->lastDeltaTimes[i + 1];
        ei->lastDeltaTimes[ei->lastDeltaTimes.size() - 1] = ei->deltaTime;
        
        SDL_RenderClear(ei->sdlRenderer);

        runtime(ei->deltaTime);

        if (ei->debug.showFps) {
            double avg = std::reduce(ei->lastDeltaTimes.begin(), ei->lastDeltaTimes.end()) / ei->lastDeltaTimes.size();

            Vector2i textPos = { 0, 0 };
            drawText(&textPos, "FPS: " + std::to_string(1.0 / avg), Renderer::running->defaultFont, { 255, 255, 255 });
        }

        SDL_SetRenderDrawColor(ei->sdlRenderer, 0, 0, 0, 255);
        SDL_RenderPresent(ei->sdlRenderer);
    }
}