#include <SFML/Graphics.hpp>
#include <string>

namespace tse {
    class WindowManager {
        private:
            sf::RenderWindow* window;
        public:
            WindowManager(std::string title);
            ~WindowManager();

            void start();
    };

    WindowManager* getCurrentWindow();
}