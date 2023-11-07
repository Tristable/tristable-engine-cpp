#include "Vector2.hpp"
#include <cmath>

using namespace tse;

template <class T> Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template <> Vector2<int>::operator SDL_Point() const {
    return { x, y };
}

template <class T> Vector2<T>::operator std::string() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

template <class T> Vector2<T> Vector2<T>::operator = (Vector2<T> other) {
    x = other.x;
    y = other.y;

    return *this;
}

template <class T> Vector2<T> Vector2<T>::operator + (Vector2<T> other) const {
    return { x + other.x, y + other.y };
}

template <class T> Vector2<T> Vector2<T>::operator += (Vector2<T> other) {
    x += other.x;
    y += other.y;

    return *this;
}

template <class T> Vector2<T> Vector2<T>::operator - (Vector2<T> other) const {
    return { x - other.x, y - other.y };
}

template <class T> Vector2<T> Vector2<T>::operator -= (Vector2<T> other) {
    x -= other.x;
    y -= other.y;

    return *this;
}

template <class T> Vector2<T> Vector2<T>::operator * (T other) const {
    return { x * other, y * other };
}

template <class T> Vector2<T> Vector2<T>::operator *= (T other) {
    x *= other;
    y *= other;

    return *this;
}

template <class T> Vector2<T> Vector2<T>::operator / (T other) const {
    return { x / other, y / other };
}

template <class T> Vector2<T> Vector2<T>::operator /= (T other) {
    x /= other;
    y /= other;

    return *this;
}

template <class T> bool Vector2<T>::operator == (Vector2<T> other) const {
    return x == other.x && y == other.y;
}

template <class T> bool Vector2<T>::operator != (Vector2<T> other) const {
    return !(*this == other);
}

template <class T> T Vector2<T>::magnitudeSquared() const {
    return x * x + y * y;
}

template <class T> T Vector2<T>::magnitude() const {
    return sqrt(magnitudeSquared());
}

template <class T> Vector2<T> Vector2<T>::normalize() {
    return *this /= magnitude();
}

template <class T> Vector2<T> Vector2<T>::normalized() const {
    return *this / magnitude();
}

template <class T> T Vector2<T>::distSquared(Vector2<T> other) const {
    return (*this - other).magnitudeSquared();
}

template <class T> T Vector2<T>::dist(Vector2<T> other) const {
    return (*this - other).magnitude();
}

template <class T> Vector2<T> Vector2<T>::direction(Vector2<T> other) const {
    return (other - *this).normalize();
}

template <class T> double Vector2<T>::angle(Vector2<T> other) const {
    return atan2(other.y - y, other.x - x);
}

template <class T> Vector2<T> Vector2<T>::towards(Vector2<T> other, T dist) const {
    return *this + direction(other) * dist;
}

template <class T> Vector2<T> Vector2<T>::towardsAssign(Vector2<T> other, T dist) {
    return *this += direction(other) * dist;
}