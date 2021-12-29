#pragma once
#include "base.hpp"

namespace bys::geo {
template <class T>
struct Point {
    T x, y;
    Point() : x(0.0), y(0.0) {}
    Point(T x, T y) : x(x), y(y) {}
    // clang-format off
    friend std::istream& operator>>(std::istream& is, Point& v) { return is >> v.x >> v.y; }
    friend std::ostream& operator<<(std::ostream& os, const Point& v) { return os << v.x << ' ' << v.y; }
    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }
    Point operator+(const Point& rh) const { return Point(x + rh.x, y + rh.y); }
    Point operator-(const Point& rh) const { return Point(x - rh.x, y - rh.y); }
    Point operator*(const T rh) const { return Point(x * rh, y * rh); }
    Point operator/(const T rh) const { return Point(x / rh, y / rh); }
    Point operator+=(const Point& rh) { x += rh.x; y += rh.y; return *this; }
    Point operator-=(const Point& rh) { x -= rh.x; y -= rh.y; return *this; }
    Point operator*=(const T rh) { x *= rh; y *= rh; return *this; }
    Point operator/=(const T rh) { x /= rh; y /= rh; return *this; }
    bool operator==(const Point& rh) const { return isclose(x, rh.x) && isclose(y, rh.y); }
    bool operator!=(const Point& rh) const { return !(*this == rh); }
    // clang-format on

    T norm2() const { return x * x + y * y; }
    ld norm() const { return std::sqrt(norm2()); }
    Point normalized() const { return Point(x / norm(), y / norm()); }
    ld angle() const { return std::atan2(y, x); }
    Point rotate(ld theta) const {
        ld ct = std::cos(theta), st = std::sin(theta);
        return Point(x * ct - y * st, x * st + y * ct);
    }
    // マンハッタン距離用。45度回転して√2倍する
    Point manhattan_rotate() const { return Point(x - y, x + y); }
    T dot(const Point& rh) const { return x * rh.x + y * rh.y; }
    T det(const Point& rh) const { return x * rh.y - y * rh.x; }
    Point normal() const { return Point(-normalized().y, normalized().x); }
    Point projection(const Point& to) const { return to * (dot(to) / to.norm2()); }
    int quadrant() const {
        if (sgn(y) >= 0) return sgn(x) >= 0 ? 1 : 2;
        return sgn(x) >= 0 ? 4 : 3;
    }
    // 偏角ソート用
    bool operator<(const Point& rh) const {
        int q = quadrant(), rhq = rh.quadrant();
        if (q != rhq) return q < rhq;
        return sgn(det(rh)) > 0;
    }
    bool operator<=(const Point& rh) const {
        int q = quadrant(), rhq = rh.quadrant();
        if (q != rhq) return q < rhq;
        return sgn(det(rh)) >= 0;
    }
};

template <class T>
bool compx(Point<T>& a, Point<T>& b) {
    return a.x < b.x;
}
template <class T>
bool compy(Point<T>& a, Point<T>& b) {
    return a.y < b.y;
}

/**
 * +1: CCW ab->bcが左に曲がる
 * -1: CW  ab->bcが右に曲がる
 * +2: Front  abの前方
 * -2: Back   abの後方
 *  0: Middle ab上
 */
enum class Turn { Back = -2, CW, Middle, CCW, Front };
template <class T>
Turn iSP(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    int flg = sgn((b - a).det(c - a));
    if (flg == 1) {
        return Turn::CCW;
    } else if (flg == -1) {
        return Turn::CW;
    } else {
        if (sgn((b - a).dot(c - b)) > 0) {
            return Turn::Front;
        } else if (sgn((a - b).dot(c - a)) > 0) {
            return Turn::Back;
        } else {
            return Turn::Middle;
        }
    }
}
/**
 * -1: Obtuse 鈍角
 *  0: Right 直角
 * +1: Acute 鋭角
 */
enum class Angle { Obtuse = -1, Right, Acute };
template <class T>
Angle angle_type(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    int t = sgn((a - b).dot(c - b));
    if (t == -1) {
        return Angle::Obtuse;
    } else if (t == 0) {
        return Angle::Right;
    } else {
        return Angle::Acute;
    }
}
}  // namespace bys::geo
