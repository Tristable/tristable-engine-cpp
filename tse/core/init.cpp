#include "init.hpp"
#include "EngineInstance.hpp"
#include "window.hpp"
#include "../renderer/Renderer.hpp"
#include "runtime.hpp"

using namespace tse;

int winWidth = 1280;
int winHeight = 720;
std::string winTitle = "Tristable Engine Window";

int main(int argc, char* argv[]) {
    _preload();

    new EngineInstance(winWidth, winHeight, winTitle);
    createWindow();
    new Renderer();

    _init();

    startRuntime(_process, _event);

    return 0;
}

void tse::configure(int windowWidth, int windowHeight, std::string windowTitle) {
    winWidth = windowWidth;
    winHeight = windowHeight;
    winTitle = windowTitle;
}