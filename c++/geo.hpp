#define once

#include "bys.hpp"

namespace bys {
namespace geo {
const double EPS = 1e-9;
const double PI = std::acos(-1.0);
int sgn(double a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }
bool isclose(double a, double b) { return sgn(a - b) == 0; }
double radian(double degree) { return degree * (PI / 180.0); }
double degree(double theta) { return theta * (180.0 / PI); }

// ベクトル・点
struct Vec2d {
    double x, y;
    Vec2d() : x(0.0), y(0.0) {}
    Vec2d(double x, double y) : x(x), y(y) {}
    std::istream& operator>>(std::istream& is) { return is >> x >> y; }
    std::ostream& operator<<(std::ostream& os) { return os << x << ' ' << y; }

    Vec2d operator+() const { return *this; }
    Vec2d operator-() const { return Vec2d(-x, -y); }
    Vec2d operator+(const Vec2d& rh) const { return Vec2d(x + rh.x, y + rh.y); }
    Vec2d operator-(const Vec2d& rh) const { return Vec2d(x - rh.x, y - rh.y); }
    Vec2d operator*(const double rh) const { return Vec2d(x * rh, y * rh); }
    Vec2d operator/(const double rh) const { return Vec2d(x / rh, y / rh); }
    // clang-format off
    Vec2d operator+=(const Vec2d& rh) { x += rh.x; y += rh.y; return *this; }
    Vec2d operator-=(const Vec2d& rh) { x -= rh.x; y -= rh.y; return *this; }
    Vec2d operator*=(const double rh) { x *= rh; y *= rh; return *this; }
    Vec2d operator/=(const double rh) { x /= rh; y /= rh; return *this; }
    bool operator==(const Vec2d& rh) const { return isclose(x, rh.x) && isclose(y, rh.y); }
    bool operator!=(const Vec2d& rh) const { return !(*this == rh); }
    // clang-format on

    double norm2() const { return x * x + y * y; }
    double norm() const { return std::sqrt(norm2()); }
    Vec2d normalized() const { return Vec2d(x / norm(), y / norm()); }
    double angle() const { return std::atan2(y, x); }
    Vec2d rotate(double theta) {
        double ct = std::cos(theta), st = std::sin(theta);
        return Vec2d(x * ct - y * st, x * st + y * ct);
    }
    Vec2d normal() const { return Vec2d(-normalized().y, normalized().x); }
    double dot(const Vec2d& rh) const { return x * rh.x + y * rh.y; }
    double det(const Vec2d& rh) const { return x * rh.y - y * rh.x; }
};

/*
+1: ab->bcが左に曲がる
-1: ab->bcが右に曲がる
+2: abcで直線上
-2: bacで直線上
 0: acbで直線上
 */
int iSP(const Vec2d& a, const Vec2d& b, const Vec2d& c) {
    int flg = sgn((b - a).det(c - a));
    if (flg == 1) {
        return +1;
    } else if (flg == -1) {
        return -1;
    } else {
        if (sgn((b - a).dot(c - b)) > 0) {
            return +2;
        } else if (sgn((a - b).dot(c - a)) > 0) {
            return -2;
        } else {
            return 0;
        }
    }
}

// 直線・線分
struct Line {
    Vec2d p, q;
    Line(Vec2d p, Vec2d q) : p(p), q(q) {}
    Vec2d to_Vec2d() const { return q - p; }
    Vec2d to_unit_Vec2d() const { return to_Vec2d().normalized(); }
    double slope() const { return to_Vec2d().angle(); }
    bool operator==(const Line& rh) const {
        return abs(iSP(p, q, rh.p)) != 1 && abs(iSP(p, q, rh.q)) != 1;
    }
    bool operator!=(const Line& rh) const { return !(*this == rh); }
};
struct Segment : Line {
    using Line::Line;
    double length() const { return to_Vec2d().norm(); }
    Vec2d internal_division(double m, double n) const {
        return (p * n + q * m) / (m + n);
    }
    bool operator==(const Segment& rh) const {
        return (p == rh.p && q == rh.q) || (p == rh.q && q == rh.p);
    }
    bool operator!=(const Segment& rh) const { return !(*this == rh); }
};

int iSP(const Segment& s, const Vec2d& c) { return iSP(s.p, s.q, c); }
int iSP(const Line& l, const Vec2d& c) { return iSP(l.p, l.q, c); }

bool cross(Line& a, Line& b) {
    return sgn(a.to_Vec2d().det(b.to_Vec2d())) != 0;
}
bool cross(Segment& a, Segment& b) {
    return iSP(a, b.p) * iSP(a, b.q) <= 0 && iSP(b, a.p) * iSP(b, a.q) <= 0;
}

// 多角形
struct Polygon {
    std::vector<Vec2d> vertex;
    Polygon(std::initializer_list<Vec2d> init)
        : vertex(init.begin(), init.end()) {}
    Polygon(std::vector<Vec2d> vertex) : vertex(vertex) {}
    double area() const {
        int n_vertex = vertex.size();
        if (n_vertex < 3) return 0;
        double s = 0.0;
        for (int i = 0; i < n_vertex; ++i) {
            s += vertex[i].det(vertex[(i + 1) % n_vertex]);
        }
        return s * 0.5;
    };
};
}  // namespace geo
}  // namespace bys
