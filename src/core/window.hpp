#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <vector>

namespace tse {
    class WindowManager {
        private:
            sf::RenderWindow* window;
            std::vector<std::function<void(double)>> renderFunctions;
        public:
            WindowManager(std::string title);
            ~WindowManager();

            void start();
            void onRender(std::function<void(double)> callback);
    };

    WindowManager* getCurrentWindow();
}