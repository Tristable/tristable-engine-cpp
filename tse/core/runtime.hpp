#ifndef TSE_RUNTIME_H
#define TSE_RUNTIME_H

#include "../../include/SDL2/SDL.h"

namespace tse {
    void startRuntime(void (*runtime)(double), void (*eventHandler)(SDL_Event*));
}

#endif