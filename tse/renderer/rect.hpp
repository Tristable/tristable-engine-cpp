#ifndef TSE_RECT_H
#define TSE_RECT_H

#include "../math/Rect2.hpp"

namespace tse {
    void drawFillRect(Rect2i* rect, SDL_Color color);

    void drawBorderRect(Rect2i* rect, SDL_Color color);

    void drawRect(Rect2i* rect, SDL_Color fill, SDL_Color border);
}

#endif