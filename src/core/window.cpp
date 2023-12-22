#include "window.hpp"
#include <iostream>

using namespace tse;

WindowManager* globalWindowInstance = nullptr;

WindowManager::WindowManager(std::string title) : window(nullptr) {
    if (globalWindowInstance != nullptr) {
        std::cout << "Failed to create window: Cannot create a window if one already exists.\n";
        return;
    }

    window = new sf::RenderWindow(sf::VideoMode(1280, 720), title);
    globalWindowInstance = this;
}

void WindowManager::start() {
    if (!sf::Shader::isAvailable()) {
        std::cout << "Failed to start window: Your graphics card does not support shaders.\n";
        return;
    }

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->display();
    }
}

WindowManager::~WindowManager() {
    delete window;

    globalWindowInstance = nullptr;
}

WindowManager* tse::getCurrentWindow() {
    return globalWindowInstance;
}