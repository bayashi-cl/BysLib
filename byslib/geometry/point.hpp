#pragma once
#include <iostream>

#include "base.hpp"
/**
 * @file point.hpp
 * @brief Point
 */
namespace bys::geo {
//! @brief 点/ベクトル
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

    //! @brief ノルム^2
    T norm2() const { return x * x + y * y; }
    //! @brief ノルム
    f128 norm() const { return std::sqrt(norm2()); }
    //! @brief 単位ベクトル
    Point normalized() const { return Point(x / norm(), y / norm()); }
    //! @brief 偏角
    f128 angle() const { return std::atan2(y, x); }
    //! @brief 回転
    Point rotate(f128 theta) const {
        f128 ct = std::cos(theta), st = std::sin(theta);
        return Point(x * ct - y * st, x * st + y * ct);
    }
    Point rotate90() const { return Point(-y, x); }
    //! @brief マンハッタン距離用。45度回転して√2倍する
    Point manhattan_rotate() const { return Point(x - y, x + y); }
    //! @brief 内積
    T dot(const Point& rh) const { return x * rh.x + y * rh.y; }
    //! @brief 外積
    T det(const Point& rh) const { return x * rh.y - y * rh.x; }
    //! @brief 法線ベクトル
    Point normal() const { return Point(-normalized().y, normalized().x); }
    //! @brief 正射影ベクトル
    Point projection(const Point& to) const { return to * (dot(to) / to.norm2()); }
    //! @brief 象限
    int quadrant() const {
        if (sgn(y) >= 0) return sgn(x) >= 0 ? 1 : 2;
        return sgn(x) >= 0 ? 4 : 3;
    }
    //! @brief 偏角ソート用
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
//! @brief 曲がる方向
enum class Turn {
    //! abの後方
    Back = -2,
    //! ab->bcが右に曲がる
    CW = -1,
    //! ab上
    Middle = 0,
    //! ab->bcが左に曲がる
    CCW = 1,
    //! abの前方
    Front = 2,
};
//! @brief 辺の曲がる方向
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
enum class Angle {
    //! 鈍角
    Obtuse = -1,
    //! 直角
    Right = 0,
    //! 鋭角
    Acute = 1,
};

//! @brief 角の種類
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
template <class T>
T distance2(const Point<T>& a, const Point<T>& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
template <class T>
T distance(const Point<T>& a, const Point<T>& b) {
    return sqrt(distance2(a, b));
}
}  // namespace bys::geo
