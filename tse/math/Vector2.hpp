#ifndef TSE_VECTOR2_H
#define TSE_VECTOR2_H

#include "../global.hpp"
#include <string>

namespace tse {
    template <class T> class Vector2 {
        public:
            T x, y;

            Vector2(T x, T y);

            operator SDL_Point() const;
            operator std::string() const;
            Vector2<T> operator = (Vector2<T> other);
            Vector2<T> operator + (Vector2<T> other) const;
            Vector2<T> operator += (Vector2<T> other);
            Vector2<T> operator - (Vector2<T> other) const;
            Vector2<T> operator -= (Vector2<T> other);
            Vector2<T> operator * (T other) const;
            Vector2<T> operator *= (T other);
            Vector2<T> operator / (T other) const;
            Vector2<T> operator /= (T other);
            bool operator == (Vector2<T> other) const;
            bool operator != (Vector2<T> other) const;

            T magnitudeSquared() const;
            T magnitude() const;
            Vector2<T> normalize();
            Vector2<T> normalized() const;
            T distSquared(Vector2<T> other) const;
            T dist(Vector2<T> other) const;
            Vector2<T> direction(Vector2<T> other) const;
            double angle(Vector2<T> other) const;
            Vector2<T> towards(Vector2<T> other, T dist) const;
            Vector2<T> towardsAssign(Vector2<T> other, T dist);

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