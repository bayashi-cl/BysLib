#pragma once
#include <optional>

#include "point.hpp"

/**
 * @file line.hpp
 * @brief Line
 * @todo 半直線の実装
 */
namespace bys::geo {
template <class T>
//! @brief 直線
struct Line {
    Point<T> p, q;
    Line(Point<T> p, Point<T> q) : p(p), q(q) {}
    Point<T> to_Point() const { return q - p; }
    Point<f128> to_unit_Point() const { return to_Point().normalized(); }
    f128 angle() const { return to_Point().angle(); }
    bool operator==(const Line& rh) const {
        return abs((int)iSP(p, q, rh.p)) != 1 && abs((int)iSP(p, q, rh.q)) != 1;
    }
    bool operator!=(const Line& rh) const { return !(*this == rh); }
};
//! @brief 線分
template <class T> struct Segment : Line<T> {
    Segment(Point<T>& p, Point<T>& q) : Line<T>::Line(p, q) {}
    f128 length() const { return this->to_Point().norm(); }
    Point<f128> internal_division(f128 m, f128 n) const {
        return (this->p * n + this->q * m) / (m + n);
    }
    bool operator==(const Segment& rh) const {
        return (this->p == rh.p && this->q == rh.q) || (this->p == rh.q && this->q == rh.p);
    }
    bool operator!=(const Segment& rh) const { return !(*this == rh); }
};
template <class T> Turn iSP(const Point<T>& p, const Line<T>& l) { return iSP(l.p, l.q, p); }
template <class T> bool is_parallel(const Line<T>& a, const Line<T>& b) {
    return sgn(a.to_Point().det(b.to_Point())) == 0;
}
template <class T> bool is_vertial(const Line<T>& a, const Line<T>& b) {
    return sgn(a.to_Point().dot(b.to_Point())) == 0;
}
template <class T> bool is_cross(const Line<T>& a, const Line<T>& b) {
    return sgn(a.to_Point().det(b.to_Point())) != 0 || sgn(a.to_Point().det(b.p - a.p)) == 0;
}
template <class T> bool is_cross(const Segment<T>& a, const Segment<T>& b) {
    return (int)iSP(b.p, a) * (int)iSP(b.q, a) <= 0 && (int)iSP(a.p, b) * (int)iSP(a.q, b) <= 0;
}
template <class T> f128 angle(const Line<T>& a, const Line<T>& b) {
    return std::atan2(a.to_Point().det(b.to_Point()), a.to_Point().dot(b.to_Point()));
}

template <class T> f128 distance(const Point<T>& p, const Line<T>& l) {
    return abs(l.to_Point().det(p - l.p) / (l.q - l.p).norm());
}
template <class T> f128 distance(const Point<T>& p, const Segment<T>& s) {
    if (angle_type(s.p, s.q, p) == Angle::Obtuse) {
        return (p - s.q).norm();
    } else if (angle_type(s.q, s.p, p) == Angle::Obtuse) {
        return (p - s.p).norm();
    } else {
        return distance(p, Line(s.p, s.q));
    }
}
template <class T> f128 distance(const Segment<T>& s, const Segment<T>& t) {
    if (is_cross(s, t)) return 0;

    return min({distance(s.p, t), distance(s.q, t), distance(t.p, s), distance(t.q, s)});
}
template <class T> std::optional<Point<T>> cross_point(const Line<T>& a, const Line<T>& b) {
    if (!is_cross(a, b)) return std::nullopt;
    return a.p + a.to_Point() * (b.p - a.p).det(b.to_Point()) / a.to_Point().det(b.to_Point());
}
//! @brief 垂線の足
template <class T> Point<T> projection(const Point<T>& p, const Line<T>& l) {
    return (p - l.p).projection(l.to_Point()) + l.p;
}
//! @brief 線対称の点
template <class T> Point<T> reflection(const Point<T>& p, const Line<T>& l) {
    return p + (projection(p, l) - p) * 2;
}
}  // namespace bys::geo
