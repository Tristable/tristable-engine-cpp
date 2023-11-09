#ifndef TSE_RECT2_H
#define TSE_RECT2_H

#include "Vector2.hpp"

namespace tse {
    template <class T> class Rect2 {
        public:
            T x, y, width, height;

            Rect2(T x, T y, T width, T height);
            Rect2(Vector2<T> position, Vector2<T> size);

            operator SDL_Rect() const;
    };

    template class Rect2<int>;
    template class Rect2<long>;
    template class Rect2<float>;
    template class Rect2<double>;

    typedef Rect2<int> Rect2i;
    typedef Rect2<long> Rect2l;
    typedef Rect2<float> Rect2f;
    typedef Rect2<double> Rect2d;
}

#endif