#include "Line2.hpp"
#include <cmath>

using namespace tse;

template <class T> Line2<T>::Line2(T x1, T y1, T x2, T y2) : start(Vector2<T>(x1, y1)), end(Vector2<T>(x2, y2)) {}

template <class T> Line2<T>::Line2(Vector2<T> start, Vector2<T> end) : start(start), end(end) {}

template <class T> T Line2<T>::length() {
    return (start - end).magnitude();
}