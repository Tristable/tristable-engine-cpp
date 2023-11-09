#ifndef TSE_RUNTIME_H
#define TSE_RUNTIME_H

#include "../global.hpp"

namespace tse {
    void startRuntime(void (*runtime)(double), void (*eventHandler)(SDL_Event*));
}

#endif