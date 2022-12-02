#pragma once
#include "point.hpp"
namespace bys::geo {
template <class T> struct Circle {
    Point<T> c;
    T r;
    Circle(Point<T> c, T r) : c(c), r(r) {}
};
template <class T> bool is_cross(const Circle<T>& a, const Circle<T>& b) {
    auto d = distance2(a.c, b.c);
    return sgn(d - (a.r - b.r) * (a.r - b.r)) >= 0 and sgn((a.r + b.r) * (a.r + b.r) - d) >= 0;
}
}  // namespace bys::geo
