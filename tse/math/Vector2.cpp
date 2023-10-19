#include "Vector2.hpp"

using namespace tse;

template <class T> Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template <> Vector2<int>::operator SDL_Point() const {
    return { x, y };
}