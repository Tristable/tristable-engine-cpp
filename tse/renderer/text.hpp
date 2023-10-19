#ifndef TSE_TEXT_H
#define TSE_TEXT_H

#include <string>
#include "../math/Vector2.hpp"

namespace tse {
    void cacheFont(std::string name, std::string path, int size);

    void closeCachedFont(std::string name);

    void drawText(Vector2i position, std::string text, std::string font, SDL_Color color);
}

#endif