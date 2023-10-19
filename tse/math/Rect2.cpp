#include "Rect2.hpp"

using namespace tse;

template <class T> Rect2<T>::Rect2(T x, T y, T width, T height) : x(x), y(y), width(width), height(height) {}

template <class T> Rect2<T>::Rect2(Vector2<T> position, Vector2<T> size) : x(position.x), y(position.y), width(size.x), height(size.y) {}

template <> Rect2<int>::operator SDL_Rect() const {
    return {
        x,
        y,
        w: width,
        h: height
    };
}