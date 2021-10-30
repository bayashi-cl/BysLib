#define once
#include <byslib/template/bys.hpp>

namespace bys {
namespace geo {
const double EPS = 1e-9;
const double PI = std::acos(-1.0);
int sgn(double a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }
bool isclose(double a, double b) { return sgn(a - b) == 0; }
double radian(double degree) { return degree * (PI / 180.0); }
double degree(double theta) { return theta * (180.0 / PI); }

// ベクトル・点
struct Point {
    double x, y;
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
    // clang-format off
    friend std::istream& operator>>(std::istream& is, Point& v) { return is >> v.x >> v.y; }
    friend std::ostream& operator<<(std::ostream& os, const Point& v) { return os << v.x << ' ' << v.y; }
    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }
    Point operator+(const Point& rh) const { return Point(x + rh.x, y + rh.y); }
    Point operator-(const Point& rh) const { return Point(x - rh.x, y - rh.y); }
    Point operator*(const double rh) const { return Point(x * rh, y * rh); }
    Point operator/(const double rh) const { return Point(x / rh, y / rh); }
    Point operator+=(const Point& rh) { x += rh.x; y += rh.y; return *this; }
    Point operator-=(const Point& rh) { x -= rh.x; y -= rh.y; return *this; }
    Point operator*=(const double rh) { x *= rh; y *= rh; return *this; }
    Point operator/=(const double rh) { x /= rh; y /= rh; return *this; }
    bool operator==(const Point& rh) const { return isclose(x, rh.x) && isclose(y, rh.y); }
    bool operator!=(const Point& rh) const { return !(*this == rh); }
    // clang-format on

    double norm2() const { return x * x + y * y; }
    double norm() const { return std::sqrt(norm2()); }
    Point normalized() const { return Point(x / norm(), y / norm()); }
    double angle() const { return std::atan2(y, x); }
    Point rotate(double theta) {
        double ct = std::cos(theta), st = std::sin(theta);
        return Point(x * ct - y * st, x * st + y * ct);
    }
    double dot(const Point& rh) const { return x * rh.x + y * rh.y; }
    double det(const Point& rh) const { return x * rh.y - y * rh.x; }
    Point normal() const { return Point(-normalized().y, normalized().x); }
    Point projection(const Point& to) const {
        return to * (dot(to) / to.norm2());
    }
};

/**
 * +1: ab->bcが左に曲がる
 * -1: ab->bcが右に曲がる
 * +2: abcで直線上
 * -2: bacで直線上
 *  0: acbで直線上
 */
int iSP(const Point& a, const Point& b, const Point& c) {
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
    Point p, q;
    Line(Point p, Point q) : p(p), q(q) {}
    Point to_Point() const { return q - p; }
    Point to_unit_Point() const { return to_Point().normalized(); }
    double slope() const { return to_Point().angle(); }
    bool operator==(const Line& rh) const {
        return abs(iSP(p, q, rh.p)) != 1 && abs(iSP(p, q, rh.q)) != 1;
    }
    bool operator!=(const Line& rh) const { return !(*this == rh); }
};
struct Segment : Line {
    Segment(Point& p, Point& q) : Line::Line(p, q) {}
    double length() const { return to_Point().norm(); }
    Point internal_division(double m, double n) const {
        return (p * n + q * m) / (m + n);
    }
    bool operator==(const Segment& rh) const {
        return (p == rh.p && q == rh.q) || (p == rh.q && q == rh.p);
    }
    bool operator!=(const Segment& rh) const { return !(*this == rh); }
};
int iSP(const Point& p, const Line& l) { return iSP(l.p, l.q, p); }

bool is_parallel(const Line& a, const Line& b) {
    return sgn(a.to_Point().det(b.to_Point())) == 0;
}
bool is_vertial(const Line& a, const Line& b) {
    return sgn(a.to_Point().dot(b.to_Point())) == 0;
}

bool is_cross(const Line& a, const Line& b) {
    return sgn(a.to_Point().det(b.to_Point())) != 0 ||
           sgn(a.to_Point().det(b.p - a.p)) == 0;
}

bool is_cross(const Segment& a, const Segment& b) {
    return iSP(b.p, a) * iSP(b.q, a) <= 0 && iSP(a.p, b) * iSP(a.q, b) <= 0;
}

double angle(const Line& a, const Line& b) {
    return std::atan2(a.to_Point().det(b.to_Point()),
                      a.to_Point().dot(b.to_Point()));
}
/**
 * ∠abcが
 * -1: 鈍角
 *  0: 直角
 * +1: 鋭角
 */
int angle_type(const Point& a, const Point& b, const Point& c) {
    return sgn((a - b).dot(c - b));
}

double distance(const Point& p, const Line& l) {
    return abs(l.to_Point().det(p - l.p) / (l.q - l.p).norm());
}
double distance(const Point& p, const Segment& s) {
    if (angle_type(s.p, s.q, p) == -1) {
        return (p - s.q).norm();
    } else if (angle_type(s.q, s.p, p) == -1) {
        return (p - s.p).norm();
    } else {
        return distance(p, Line(s.p, s.q));
    }
}
double distance(const Segment& s, const Segment& t) {
    if (is_cross(s, t)) return 0;

    return min({distance(s.p, t), distance(s.q, t), distance(t.p, s),
                distance(t.q, s)});
}

std::pair<bool, Point> cross_point(const Line& a, const Line& b) {
    if (!is_cross(a, b)) return {false, Point()};
    Point s = b.p - a.p;
    Point res = b.p + b.to_Point() * abs(a.to_Point().det(s) /
                                         a.to_Point().det(b.to_Point()));
    return {true, res};
}

Point projection(const Point& p, const Line& l) {
    return (p - l.p).projection(l.to_Point()) + l.p;
}
Point reflection(const Point& p, const Line& l) {
    return p + (projection(p, l) - p) * 2;
}

// 多角形
struct Polygon {
    int n_vertex;
    std::vector<Point> vertex;
    Polygon(std::initializer_list<Point> init)
        : n_vertex(init.size()), vertex(init.begin(), init.end()) {}
    Polygon(std::vector<Point> vertex)
        : n_vertex(vertex.size()), vertex(vertex) {}
    double area() const {
        if (n_vertex < 3) return 0;
        double s = 0.0;
        for (int i = 0; i < n_vertex; ++i) {
            s += vertex[i].det(vertex[(i + 1) % n_vertex]);
        }
        return s * 0.5;
    };
    bool is_convex() const {
        int left = 0;
        int right = 0;
        for (int i = 0; i < n_vertex; ++i) {
            int res = iSP(vertex[i], vertex[(i + 1) % n_vertex],
                          vertex[(i + 2) % n_vertex]);
            if (res == -1) left++;
            if (res == 1) right++;
        }
        return left == 0 || right == 0;
    }
};
}  // namespace geo
}  // namespace bys
