#ifndef TSE_LINE2_H
#define TSE_LINE2_H

#include "Vector2.hpp"

namespace tse {
    template <class T> class Line2 {
        public:
            Vector2<T> start, end;

            Line2(T x1, T y1, T x2, T y2);
            Line2(Vector2<T> start, Vector2<T> end);

            T length();
    };

    template class Line2<int>;
    template class Line2<long>;
    template class Line2<float>;
    template class Line2<double>;

    typedef Line2<int> Line2i;
    typedef Line2<long> Line2l;
    typedef Line2<float> Line2f;
    typedef Line2<double> Line2d;
}

#endif