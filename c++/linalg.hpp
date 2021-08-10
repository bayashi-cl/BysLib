#pragma once

#include "bys.hpp"

namespace bys {
namespace linalg {
const double EPS = 1e-10;
int sgn(double a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }
bool isclose(double a, double b) { return sgn(a - b) == 0; }

struct Point {
    double x, y;
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
    Point(pair<double, double>& p) : x(p.first), y(p.second) {}
    // clang-format off
    Point operator+() const { return *this; }
    Point operator+(const Point& other) const { return {x + other.x, y + other.y}; }
    Point operator+(const double other) const { return {x + other, y + other}; }
    Point& operator+=(const Point& other) { x += other.x; y += other.y; return *this; }
    Point& operator+=(const double other) { x += other; y += other; return *this; }
    Point operator-() const { return {-x, -y}; }
    Point operator-(const Point& other) const { return {x - other.x, y - other.y}; }
    Point operator-(const double other) const { return {x - other, y - other}; }
    Point& operator-=(const Point& other) { x -= other.x; y -= other.y; return *this; }
    Point& operator-=(const double other) { x -= other; y -= other; return *this; }
    Point operator*(double other) const { return {x * other, y * other}; }
    Point& operator*=(double other) { x *= other; y *= other; return *this; }
    Point operator/(double other) const { return {x / other, y / other}; }
    Point& operator*=(double other) { x /= other; y /= other; return *this; }
    bool operator==(const Point& other) const { return isclose(x, other.x) && isclose(y, other.y); }
    bool operator!=(const Point& other) const { return !(*this==other);}
    // clang-format on

    double norm2() const { return x * x + y * y; }
    double norm() const { return std::sqrt(norm2()); }
    Point normalized() const { return *this / norm(); }
};
inline bool operator<(const Point& a, const Point& b) {
    if (sgn(a.x - b.x)) return sgn(a.x - b.x) < 0;
    return sgn(a.y - b.y) < 0;
}
Point operator+(double lh, const Point& rh) { return {lh + rh.x, lh + rh.y}; };
Point operator-(double lh, const Point& rh) { return {lh - rh.x, lh - rh.y}; };
Point operator*(double lh, const Point& rh) { return {lh * rh.x, lh * rh.y}; };
Point operator/(double lh, const Point& rh) { return {lh / rh.x, lh / rh.y}; };
double dist(Point& lh, Point& rh) { return (rh - lh).norm(); }
double dot(Point& lh, Point& rh) { return lh.x * lh.y + rh.x * rh.y; }

}  // namespace linalg
}  // namespace bys
