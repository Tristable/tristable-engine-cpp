#ifndef TSE_VECTOR2_H
#define TSE_VECTOR2_H

#include "../../include/SDL2/SDL.h"

namespace tse {
    template <class T> class Vector2 {
        public:
            T x, y;

            Vector2(T x, T y);

            operator SDL_Point() const;
    };

    template class Vector2<int>;
    template class Vector2<long>;
    template class Vector2<float>;
    template class Vector2<double>;

    typedef Vector2<int> Vector2i;
    typedef Vector2<long> Vector2l;
    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;
}

#endif