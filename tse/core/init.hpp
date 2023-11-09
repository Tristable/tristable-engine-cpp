#ifndef TSE_INIT_H
#define TSE_INIT_H

#include "../global.hpp"
#include <string>

int main(int argc, char* argv[]);

namespace tse {
    void _preload();
    void _init();
    void _event(SDL_Event* e);
    void _process(double delta);

    void configure(int windowWidth, int windowHeight, std::string windowTitle);
}

#endif