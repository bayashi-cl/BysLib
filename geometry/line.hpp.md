---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: Base
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: Point
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
    document_title: Line
    links: []
  bundledCode: "/**\n * @file stdlib.hpp\n * @author bayashi_cl\n * @brief STL Template\n\
    \ */\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\n\
    using ll = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\n\
    using Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\n/**\n * @file base.hpp\n * @author bayashi_cl\n *\
    \ @brief Base\n */\n//! @brief \u5E7E\u4F55\nnamespace bys::geo {\nconst ld EPS\
    \ = 1e-9;\nconst ld PI = std::acos(-1.0);\nconst ld TAU = PI * 2;\nint sgn(ld\
    \ a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }\nbool isclose(ld a, ld b)\
    \ { return sgn(a - b) == 0; }\n//! @brief \u5EA6\u6570\u6CD5 -> \u5F27\u5EA6\u6CD5\
    \nld radian(ld degree) { return degree * (PI / 180.0); }\n//! @brief \u5F27\u5EA6\
    \u6CD5 -> \u5EA6\u6570\u6CD5\nld degree(ld theta) { return theta * (180.0 / PI);\
    \ }\n}  // namespace bys::geo\n/**\n * @file point.hpp\n * @author bayashi_cl\n\
    \ * @brief Point\n */\nnamespace bys::geo {\n//! @brief \u70B9/\u30D9\u30AF\u30C8\
    \u30EB\ntemplate <class T>\nstruct Point {\n    T x, y;\n    Point() : x(0.0),\
    \ y(0.0) {}\n    Point(T x, T y) : x(x), y(y) {}\n    // clang-format off\n  \
    \  friend std::istream& operator>>(std::istream& is, Point& v) { return is >>\
    \ v.x >> v.y; }\n    friend std::ostream& operator<<(std::ostream& os, const Point&\
    \ v) { return os << v.x << ' ' << v.y; }\n    Point operator+() const { return\
    \ *this; }\n    Point operator-() const { return Point(-x, -y); }\n    Point operator+(const\
    \ Point& rh) const { return Point(x + rh.x, y + rh.y); }\n    Point operator-(const\
    \ Point& rh) const { return Point(x - rh.x, y - rh.y); }\n    Point operator*(const\
    \ T rh) const { return Point(x * rh, y * rh); }\n    Point operator/(const T rh)\
    \ const { return Point(x / rh, y / rh); }\n    Point operator+=(const Point& rh)\
    \ { x += rh.x; y += rh.y; return *this; }\n    Point operator-=(const Point& rh)\
    \ { x -= rh.x; y -= rh.y; return *this; }\n    Point operator*=(const T rh) {\
    \ x *= rh; y *= rh; return *this; }\n    Point operator/=(const T rh) { x /= rh;\
    \ y /= rh; return *this; }\n    bool operator==(const Point& rh) const { return\
    \ isclose(x, rh.x) && isclose(y, rh.y); }\n    bool operator!=(const Point& rh)\
    \ const { return !(*this == rh); }\n    // clang-format on\n\n    //! @brief \u30CE\
    \u30EB\u30E0^2\n    T norm2() const { return x * x + y * y; }\n    //! @brief\
    \ \u30CE\u30EB\u30E0\n    ld norm() const { return std::sqrt(norm2()); }\n   \
    \ //! @brief \u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\n    Point normalized() const\
    \ { return Point(x / norm(), y / norm()); }\n    //! @brief \u504F\u89D2\n   \
    \ ld angle() const { return std::atan2(y, x); }\n    //! @brief \u56DE\u8EE2\n\
    \    Point rotate(ld theta) const {\n        ld ct = std::cos(theta), st = std::sin(theta);\n\
    \        return Point(x * ct - y * st, x * st + y * ct);\n    }\n    Point rotate90()\
    \ const { return Point(-y, x); }\n    //! @brief \u30DE\u30F3\u30CF\u30C3\u30BF\
    \u30F3\u8DDD\u96E2\u7528\u300245\u5EA6\u56DE\u8EE2\u3057\u3066\u221A2\u500D\u3059\
    \u308B\n    Point manhattan_rotate() const { return Point(x - y, x + y); }\n \
    \   //! @brief \u5185\u7A4D\n    T dot(const Point& rh) const { return x * rh.x\
    \ + y * rh.y; }\n    //! @brief \u5916\u7A4D\n    T det(const Point& rh) const\
    \ { return x * rh.y - y * rh.x; }\n    //! @brief \u6CD5\u7DDA\u30D9\u30AF\u30C8\
    \u30EB\n    Point normal() const { return Point(-normalized().y, normalized().x);\
    \ }\n    //! @brief \u6B63\u5C04\u5F71\u30D9\u30AF\u30C8\u30EB\n    Point projection(const\
    \ Point& to) const { return to * (dot(to) / to.norm2()); }\n    //! @brief \u8C61\
    \u9650\n    int quadrant() const {\n        if (sgn(y) >= 0) return sgn(x) >=\
    \ 0 ? 1 : 2;\n        return sgn(x) >= 0 ? 4 : 3;\n    }\n    //! @brief \u504F\
    \u89D2\u30BD\u30FC\u30C8\u7528\n    bool operator<(const Point& rh) const {\n\
    \        int q = quadrant(), rhq = rh.quadrant();\n        if (q != rhq) return\
    \ q < rhq;\n        return sgn(det(rh)) > 0;\n    }\n    bool operator<=(const\
    \ Point& rh) const {\n        int q = quadrant(), rhq = rh.quadrant();\n     \
    \   if (q != rhq) return q < rhq;\n        return sgn(det(rh)) >= 0;\n    }\n\
    };\n\ntemplate <class T>\nbool compx(Point<T>& a, Point<T>& b) {\n    return a.x\
    \ < b.x;\n}\ntemplate <class T>\nbool compy(Point<T>& a, Point<T>& b) {\n    return\
    \ a.y < b.y;\n}\n//! @brief \u66F2\u304C\u308B\u65B9\u5411\nenum class Turn {\n\
    \    //! ab\u306E\u5F8C\u65B9\n    Back = -2,\n    //! ab->bc\u304C\u53F3\u306B\
    \u66F2\u304C\u308B\n    CW = -1,\n    //! ab\u4E0A\n    Middle = 0,\n    //! ab->bc\u304C\
    \u5DE6\u306B\u66F2\u304C\u308B\n    CCW = 1,\n    //! ab\u306E\u524D\u65B9\n \
    \   Front = 2,\n};\n//! @brief \u8FBA\u306E\u66F2\u304C\u308B\u65B9\u5411\ntemplate\
    \ <class T>\nTurn iSP(const Point<T>& a, const Point<T>& b, const Point<T>& c)\
    \ {\n    int flg = sgn((b - a).det(c - a));\n    if (flg == 1) {\n        return\
    \ Turn::CCW;\n    } else if (flg == -1) {\n        return Turn::CW;\n    } else\
    \ {\n        if (sgn((b - a).dot(c - b)) > 0) {\n            return Turn::Front;\n\
    \        } else if (sgn((a - b).dot(c - a)) > 0) {\n            return Turn::Back;\n\
    \        } else {\n            return Turn::Middle;\n        }\n    }\n}\nenum\
    \ class Angle {\n    //! \u920D\u89D2\n    Obtuse = -1,\n    //! \u76F4\u89D2\n\
    \    Right = 0,\n    //! \u92ED\u89D2\n    Acute = 1,\n};\n\n//! @brief \u89D2\
    \u306E\u7A2E\u985E\ntemplate <class T>\nAngle angle_type(const Point<T>& a, const\
    \ Point<T>& b, const Point<T>& c) {\n    int t = sgn((a - b).dot(c - b));\n  \
    \  if (t == -1) {\n        return Angle::Obtuse;\n    } else if (t == 0) {\n \
    \       return Angle::Right;\n    } else {\n        return Angle::Acute;\n   \
    \ }\n}\n}  // namespace bys::geo\n\n/**\n * @file line.hpp\n * @author bayashi_cl\n\
    \ * @brief Line\n * @todo \u534A\u76F4\u7DDA\u306E\u5B9F\u88C5\n */\nnamespace\
    \ bys::geo {\ntemplate <class T>\n//! @brief \u76F4\u7DDA\nstruct Line {\n   \
    \ Point<T> p, q;\n    Line(Point<T> p, Point<T> q) : p(p), q(q) {}\n    Point<T>\
    \ to_Point() const { return q - p; }\n    Point<ld> to_unit_Point() const { return\
    \ to_Point().normalized(); }\n    ld angle() const { return to_Point().angle();\
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
    \ s), distance(t.q, s)});\n}\ntemplate <class T>\nstd::optional<Point<T>> cross_point(const\
    \ Line<T>& a, const Line<T>& b) {\n    if (!is_cross(a, b)) return std::nullopt;\n\
    \    return a.p + a.to_Point() * (b.p - a.p).det(b.to_Point()) / a.to_Point().det(b.to_Point());\n\
    }\n//! @brief \u5782\u7DDA\u306E\u8DB3\ntemplate <class T>\nPoint<T> projection(const\
    \ Point<T>& p, const Line<T>& l) {\n    return (p - l.p).projection(l.to_Point())\
    \ + l.p;\n}\n//! @brief \u7DDA\u5BFE\u79F0\u306E\u70B9\ntemplate <class T>\nPoint<T>\
    \ reflection(const Point<T>& p, const Line<T>& l) {\n    return p + (projection(p,\
    \ l) - p) * 2;\n}\n}  // namespace bys::geo\n"
  code: "#pragma once\n#include \"point.hpp\"\n\n/**\n * @file line.hpp\n * @author\
    \ bayashi_cl\n * @brief Line\n * @todo \u534A\u76F4\u7DDA\u306E\u5B9F\u88C5\n\
    \ */\nnamespace bys::geo {\ntemplate <class T>\n//! @brief \u76F4\u7DDA\nstruct\
    \ Line {\n    Point<T> p, q;\n    Line(Point<T> p, Point<T> q) : p(p), q(q) {}\n\
    \    Point<T> to_Point() const { return q - p; }\n    Point<ld> to_unit_Point()\
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
    \ s), distance(t.q, s)});\n}\ntemplate <class T>\nstd::optional<Point<T>> cross_point(const\
    \ Line<T>& a, const Line<T>& b) {\n    if (!is_cross(a, b)) return std::nullopt;\n\
    \    return a.p + a.to_Point() * (b.p - a.p).det(b.to_Point()) / a.to_Point().det(b.to_Point());\n\
    }\n//! @brief \u5782\u7DDA\u306E\u8DB3\ntemplate <class T>\nPoint<T> projection(const\
    \ Point<T>& p, const Line<T>& l) {\n    return (p - l.p).projection(l.to_Point())\
    \ + l.p;\n}\n//! @brief \u7DDA\u5BFE\u79F0\u306E\u70B9\ntemplate <class T>\nPoint<T>\
    \ reflection(const Point<T>& p, const Line<T>& l) {\n    return p + (projection(p,\
    \ l) - p) * 2;\n}\n}  // namespace bys::geo\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
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
title: Line
---
