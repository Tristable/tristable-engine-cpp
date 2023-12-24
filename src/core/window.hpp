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
            sf::Clock* clock;

            WindowManager(std::string title, sf::Vector2u size);
            ~WindowManager();

            void start();
            void onRender(std::function<void(double)> callback);
            sf::RenderWindow* getWindow();
    };

    WindowManager* getCurrentWindow();
}