---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: "\u70B9/\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_point.test.cpp
    title: test/geometry/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection.test.cpp
    title: test/geometry/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/parallel_orthogonal.test.cpp
    title: test/geometry/parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/projection.test.cpp
    title: test/geometry/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u76F4\u7DDA"
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <cmath>\n#include <complex>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n\nnamespace bys::geo {\nconst ld EPS = 1e-9;\nconst ld PI = std::acos(-1.0);\n\
    const ld TAU = PI * 2;\nint sgn(ld a) { return (a < -EPS) ? -1 : (a > EPS) ? 1\
    \ : 0; }\nbool isclose(ld a, ld b) { return sgn(a - b) == 0; }\nld radian(ld degree)\
    \ { return degree * (PI / 180.0); }\nld degree(ld theta) { return theta * (180.0\
    \ / PI); }\n}  // namespace bys::geo\n\nnamespace bys::geo {\n//! @brief \u70B9\
    /\u30D9\u30AF\u30C8\u30EB\ntemplate <class T>\nstruct Point {\n    T x, y;\n \
    \   Point() : x(0.0), y(0.0) {}\n    Point(T x, T y) : x(x), y(y) {}\n    // clang-format\
    \ off\n    friend std::istream& operator>>(std::istream& is, Point& v) { return\
    \ is >> v.x >> v.y; }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Point& v) { return os << v.x << ' ' << v.y; }\n    Point operator+() const {\
    \ return *this; }\n    Point operator-() const { return Point(-x, -y); }\n   \
    \ Point operator+(const Point& rh) const { return Point(x + rh.x, y + rh.y); }\n\
    \    Point operator-(const Point& rh) const { return Point(x - rh.x, y - rh.y);\
    \ }\n    Point operator*(const T rh) const { return Point(x * rh, y * rh); }\n\
    \    Point operator/(const T rh) const { return Point(x / rh, y / rh); }\n   \
    \ Point operator+=(const Point& rh) { x += rh.x; y += rh.y; return *this; }\n\
    \    Point operator-=(const Point& rh) { x -= rh.x; y -= rh.y; return *this; }\n\
    \    Point operator*=(const T rh) { x *= rh; y *= rh; return *this; }\n    Point\
    \ operator/=(const T rh) { x /= rh; y /= rh; return *this; }\n    bool operator==(const\
    \ Point& rh) const { return isclose(x, rh.x) && isclose(y, rh.y); }\n    bool\
    \ operator!=(const Point& rh) const { return !(*this == rh); }\n    // clang-format\
    \ on\n\n    T norm2() const { return x * x + y * y; }\n    ld norm() const { return\
    \ std::sqrt(norm2()); }\n    Point normalized() const { return Point(x / norm(),\
    \ y / norm()); }\n    ld angle() const { return std::atan2(y, x); }\n    Point\
    \ rotate(ld theta) const {\n        ld ct = std::cos(theta), st = std::sin(theta);\n\
    \        return Point(x * ct - y * st, x * st + y * ct);\n    }\n    //! @brief\
    \ \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u7528\u300245\u5EA6\u56DE\u8EE2\
    \u3057\u3066\u221A2\u500D\u3059\u308B\n    Point manhattan_rotate() const { return\
    \ Point(x - y, x + y); }\n    T dot(const Point& rh) const { return x * rh.x +\
    \ y * rh.y; }\n    T det(const Point& rh) const { return x * rh.y - y * rh.x;\
    \ }\n    Point normal() const { return Point(-normalized().y, normalized().x);\
    \ }\n    Point projection(const Point& to) const { return to * (dot(to) / to.norm2());\
    \ }\n    int quadrant() const {\n        if (sgn(y) >= 0) return sgn(x) >= 0 ?\
    \ 1 : 2;\n        return sgn(x) >= 0 ? 4 : 3;\n    }\n    // \u504F\u89D2\u30BD\
    \u30FC\u30C8\u7528\n    bool operator<(const Point& rh) const {\n        int q\
    \ = quadrant(), rhq = rh.quadrant();\n        if (q != rhq) return q < rhq;\n\
    \        return sgn(det(rh)) > 0;\n    }\n    bool operator<=(const Point& rh)\
    \ const {\n        int q = quadrant(), rhq = rh.quadrant();\n        if (q !=\
    \ rhq) return q < rhq;\n        return sgn(det(rh)) >= 0;\n    }\n};\n\ntemplate\
    \ <class T>\nbool compx(Point<T>& a, Point<T>& b) {\n    return a.x < b.x;\n}\n\
    template <class T>\nbool compy(Point<T>& a, Point<T>& b) {\n    return a.y < b.y;\n\
    }\n\nenum class Turn { Back = -2, CW, Middle, CCW, Front };\n/**\n * @brief \u8FBA\
    \u306E\u66F2\u304C\u308B\u65B9\u5411\n * @return\n * +1: CCW ab->bc\u304C\u5DE6\
    \u306B\u66F2\u304C\u308B\n * -1: CW  ab->bc\u304C\u53F3\u306B\u66F2\u304C\u308B\
    \n * +2: Front  ab\u306E\u524D\u65B9\n * -2: Back   ab\u306E\u5F8C\u65B9\n * \
    \ 0: Middle ab\u4E0A\n */\ntemplate <class T>\nTurn iSP(const Point<T>& a, const\
    \ Point<T>& b, const Point<T>& c) {\n    int flg = sgn((b - a).det(c - a));\n\
    \    if (flg == 1) {\n        return Turn::CCW;\n    } else if (flg == -1) {\n\
    \        return Turn::CW;\n    } else {\n        if (sgn((b - a).dot(c - b)) >\
    \ 0) {\n            return Turn::Front;\n        } else if (sgn((a - b).dot(c\
    \ - a)) > 0) {\n            return Turn::Back;\n        } else {\n           \
    \ return Turn::Middle;\n        }\n    }\n}\n/**\n * -1: Obtuse \u920D\u89D2\n\
    \ *  0: Right \u76F4\u89D2\n * +1: Acute \u92ED\u89D2\n */\nenum class Angle {\
    \ Obtuse = -1, Right, Acute };\n/**\n * @brief \u89D2\u306E\u7A2E\u985E\n * @return\
    \ Angle\n * -1: Obtuse \u920D\u89D2\n *  0: Right \u76F4\u89D2\n * +1: Acute \u92ED\
    \u89D2\n */\ntemplate <class T>\nAngle angle_type(const Point<T>& a, const Point<T>&\
    \ b, const Point<T>& c) {\n    int t = sgn((a - b).dot(c - b));\n    if (t ==\
    \ -1) {\n        return Angle::Obtuse;\n    } else if (t == 0) {\n        return\
    \ Angle::Right;\n    } else {\n        return Angle::Acute;\n    }\n}\n}  // namespace\
    \ bys::geo\n\nnamespace bys::geo {\ntemplate <class T>\n//! @brief \u76F4\u7DDA\
    \nstruct Line {\n    Point<T> p, q;\n    Line(Point<T> p, Point<T> q) : p(p),\
    \ q(q) {}\n    Point<T> to_Point() const { return q - p; }\n    Point<ld> to_unit_Point()\
    \ const { return to_Point().normalized(); }\n    ld angle() const { return to_Point().angle();\
    \ }\n    bool operator==(const Line& rh) const { return abs((int)iSP(p, q, rh.p))\
    \ != 1 && abs((int)iSP(p, q, rh.q)) != 1; }\n    bool operator!=(const Line& rh)\
    \ const { return !(*this == rh); }\n};\n//! @brief \u7DDA\u5206\ntemplate <class\
    \ T>\nstruct Segment : Line<T> {\n    Segment(Point<T>& p, Point<T>& q) : Line<T>::Line(p,\
    \ q) {}\n    ld length() const { return this->to_Point().norm(); }\n    Point<ld>\
    \ internal_division(ld m, ld n) const { return (this->p * n + this->q * m) / (m\
    \ + n); }\n    bool operator==(const Segment& rh) const {\n        return (this->p\
    \ == rh.p && this->q == rh.q) || (this->p == rh.q && this->q == rh.p);\n    }\n\
    \    bool operator!=(const Segment& rh) const { return !(*this == rh); }\n};\n\
    template <class T>\nTurn iSP(const Point<T>& p, const Line<T>& l) {\n    return\
    \ iSP(l.p, l.q, p);\n}\ntemplate <class T>\nbool is_parallel(const Line<T>& a,\
    \ const Line<T>& b) {\n    return sgn(a.to_Point().det(b.to_Point())) == 0;\n\
    }\ntemplate <class T>\nbool is_vertial(const Line<T>& a, const Line<T>& b) {\n\
    \    return sgn(a.to_Point().dot(b.to_Point())) == 0;\n}\ntemplate <class T>\n\
    bool is_cross(const Line<T>& a, const Line<T>& b) {\n    return sgn(a.to_Point().det(b.to_Point()))\
    \ != 0 || sgn(a.to_Point().det(b.p - a.p)) == 0;\n}\ntemplate <class T>\nbool\
    \ is_cross(const Segment<T>& a, const Segment<T>& b) {\n    return (int)iSP(b.p,\
    \ a) * (int)iSP(b.q, a) <= 0 && (int)iSP(a.p, b) * (int)iSP(a.q, b) <= 0;\n}\n\
    template <class T>\nld angle(const Line<T>& a, const Line<T>& b) {\n    return\
    \ std::atan2(a.to_Point().det(b.to_Point()), a.to_Point().dot(b.to_Point()));\n\
    }\n\ntemplate <class T>\nld distance(const Point<T>& p, const Line<T>& l) {\n\
    \    return abs(l.to_Point().det(p - l.p) / (l.q - l.p).norm());\n}\ntemplate\
    \ <class T>\nld distance(const Point<T>& p, const Segment<T>& s) {\n    if (angle_type(s.p,\
    \ s.q, p) == Angle::Obtuse) {\n        return (p - s.q).norm();\n    } else if\
    \ (angle_type(s.q, s.p, p) == Angle::Obtuse) {\n        return (p - s.p).norm();\n\
    \    } else {\n        return distance(p, Line(s.p, s.q));\n    }\n}\ntemplate\
    \ <class T>\nld distance(const Segment<T>& s, const Segment<T>& t) {\n    if (is_cross(s,\
    \ t)) return 0;\n\n    return min({distance(s.p, t), distance(s.q, t), distance(t.p,\
    \ s), distance(t.q, s)});\n}\ntemplate <class T>\n// std::pair<bool, Point<T>>\
    \ cross_point(const Line<T>& a, const Line<T>& b) {\nstd::optional<Point<T>> cross_point(const\
    \ Line<T>& a, const Line<T>& b) {\n    if (!is_cross(a, b)) return std::nullopt;\n\
    \    Point s = b.p - a.p;\n    return b.p + b.to_Point() * abs(a.to_Point().det(s)\
    \ / a.to_Point().det(b.to_Point()));\n}\ntemplate <class T>\n// std::pair<bool,\
    \ Point<T>> cross_point(const Segment<T>& a, const Segment<T>& b) {\nstd::optional<Point<T>>\
    \ cross_point(const Segment<T>& a, const Segment<T>& b) {\n    if (!is_cross(a,\
    \ b)) return std::nullopt;\n    Point s = b.p - a.p;\n    return b.p + b.to_Point()\
    \ * abs(a.to_Point().det(s) / a.to_Point().det(b.to_Point()));\n}\ntemplate <class\
    \ T>\nPoint<T> projection(const Point<T>& p, const Line<T>& l) {\n    return (p\
    \ - l.p).projection(l.to_Point()) + l.p;\n}\ntemplate <class T>\nPoint<T> reflection(const\
    \ Point<T>& p, const Line<T>& l) {\n    return p + (projection(p, l) - p) * 2;\n\
    }\n}  // namespace bys::geo\n\n/**\n * @todo \u534A\u76F4\u7DDA\u306E\u5B9F\u88C5\
    \n *\n */\n"
  code: "#pragma once\n#include \"point.hpp\"\n\nnamespace bys::geo {\ntemplate <class\
    \ T>\n//! @brief \u76F4\u7DDA\nstruct Line {\n    Point<T> p, q;\n    Line(Point<T>\
    \ p, Point<T> q) : p(p), q(q) {}\n    Point<T> to_Point() const { return q - p;\
    \ }\n    Point<ld> to_unit_Point() const { return to_Point().normalized(); }\n\
    \    ld angle() const { return to_Point().angle(); }\n    bool operator==(const\
    \ Line& rh) const { return abs((int)iSP(p, q, rh.p)) != 1 && abs((int)iSP(p, q,\
    \ rh.q)) != 1; }\n    bool operator!=(const Line& rh) const { return !(*this ==\
    \ rh); }\n};\n//! @brief \u7DDA\u5206\ntemplate <class T>\nstruct Segment : Line<T>\
    \ {\n    Segment(Point<T>& p, Point<T>& q) : Line<T>::Line(p, q) {}\n    ld length()\
    \ const { return this->to_Point().norm(); }\n    Point<ld> internal_division(ld\
    \ m, ld n) const { return (this->p * n + this->q * m) / (m + n); }\n    bool operator==(const\
    \ Segment& rh) const {\n        return (this->p == rh.p && this->q == rh.q) ||\
    \ (this->p == rh.q && this->q == rh.p);\n    }\n    bool operator!=(const Segment&\
    \ rh) const { return !(*this == rh); }\n};\ntemplate <class T>\nTurn iSP(const\
    \ Point<T>& p, const Line<T>& l) {\n    return iSP(l.p, l.q, p);\n}\ntemplate\
    \ <class T>\nbool is_parallel(const Line<T>& a, const Line<T>& b) {\n    return\
    \ sgn(a.to_Point().det(b.to_Point())) == 0;\n}\ntemplate <class T>\nbool is_vertial(const\
    \ Line<T>& a, const Line<T>& b) {\n    return sgn(a.to_Point().dot(b.to_Point()))\
    \ == 0;\n}\ntemplate <class T>\nbool is_cross(const Line<T>& a, const Line<T>&\
    \ b) {\n    return sgn(a.to_Point().det(b.to_Point())) != 0 || sgn(a.to_Point().det(b.p\
    \ - a.p)) == 0;\n}\ntemplate <class T>\nbool is_cross(const Segment<T>& a, const\
    \ Segment<T>& b) {\n    return (int)iSP(b.p, a) * (int)iSP(b.q, a) <= 0 && (int)iSP(a.p,\
    \ b) * (int)iSP(a.q, b) <= 0;\n}\ntemplate <class T>\nld angle(const Line<T>&\
    \ a, const Line<T>& b) {\n    return std::atan2(a.to_Point().det(b.to_Point()),\
    \ a.to_Point().dot(b.to_Point()));\n}\n\ntemplate <class T>\nld distance(const\
    \ Point<T>& p, const Line<T>& l) {\n    return abs(l.to_Point().det(p - l.p) /\
    \ (l.q - l.p).norm());\n}\ntemplate <class T>\nld distance(const Point<T>& p,\
    \ const Segment<T>& s) {\n    if (angle_type(s.p, s.q, p) == Angle::Obtuse) {\n\
    \        return (p - s.q).norm();\n    } else if (angle_type(s.q, s.p, p) == Angle::Obtuse)\
    \ {\n        return (p - s.p).norm();\n    } else {\n        return distance(p,\
    \ Line(s.p, s.q));\n    }\n}\ntemplate <class T>\nld distance(const Segment<T>&\
    \ s, const Segment<T>& t) {\n    if (is_cross(s, t)) return 0;\n\n    return min({distance(s.p,\
    \ t), distance(s.q, t), distance(t.p, s), distance(t.q, s)});\n}\ntemplate <class\
    \ T>\n// std::pair<bool, Point<T>> cross_point(const Line<T>& a, const Line<T>&\
    \ b) {\nstd::optional<Point<T>> cross_point(const Line<T>& a, const Line<T>& b)\
    \ {\n    if (!is_cross(a, b)) return std::nullopt;\n    Point s = b.p - a.p;\n\
    \    return b.p + b.to_Point() * abs(a.to_Point().det(s) / a.to_Point().det(b.to_Point()));\n\
    }\ntemplate <class T>\n// std::pair<bool, Point<T>> cross_point(const Segment<T>&\
    \ a, const Segment<T>& b) {\nstd::optional<Point<T>> cross_point(const Segment<T>&\
    \ a, const Segment<T>& b) {\n    if (!is_cross(a, b)) return std::nullopt;\n \
    \   Point s = b.p - a.p;\n    return b.p + b.to_Point() * abs(a.to_Point().det(s)\
    \ / a.to_Point().det(b.to_Point()));\n}\ntemplate <class T>\nPoint<T> projection(const\
    \ Point<T>& p, const Line<T>& l) {\n    return (p - l.p).projection(l.to_Point())\
    \ + l.p;\n}\ntemplate <class T>\nPoint<T> reflection(const Point<T>& p, const\
    \ Line<T>& l) {\n    return p + (projection(p, l) - p) * 2;\n}\n}  // namespace\
    \ bys::geo\n\n/**\n * @todo \u534A\u76F4\u7DDA\u306E\u5B9F\u88C5\n *\n */\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:16:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/reflection.test.cpp
  - test/geometry/parallel_orthogonal.test.cpp
  - test/geometry/distance.test.cpp
  - test/geometry/projection.test.cpp
  - test/geometry/intersection.test.cpp
  - test/geometry/cross_point.test.cpp
documentation_of: geometry/line.hpp
layout: document
redirect_from:
- /library/geometry/line.hpp
- /library/geometry/line.hpp.html
title: "\u76F4\u7DDA"
---
