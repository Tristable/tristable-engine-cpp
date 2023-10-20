#ifndef TSE_TEXTURE_H
#define TSE_TEXTURE_H

#include <string>
#include "../math/Rect2.hpp"

namespace tse {
    void cacheTextureFromFile(std::string name, std::string path);

    void deleteCachedTexture(std::string name);

    void drawTexture(std::string texture, Rect2i* destination, Rect2i* source);
}

#endif