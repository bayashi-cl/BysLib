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
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"core/stdlib.hpp\"\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n#line 3 \"geometry/base.hpp\"\n\nnamespace bys::geo {\nconst ld EPS = 1e-9;\n\
    const ld PI = std::acos(-1.0);\nconst ld TAU = PI * 2;\nint sgn(ld a) { return\
    \ (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }\nbool isclose(ld a, ld b) { return sgn(a\
    \ - b) == 0; }\nld radian(ld degree) { return degree * (PI / 180.0); }\nld degree(ld\
    \ theta) { return theta * (180.0 / PI); }\n}  // namespace bys::geo\n#line 3 \"\
    geometry/point.hpp\"\n\nnamespace bys::geo {\n//! @brief \u70B9/\u30D9\u30AF\u30C8\
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
    \ const { return !(*this == rh); }\n    // clang-format on\n\n    T norm2() const\
    \ { return x * x + y * y; }\n    ld norm() const { return std::sqrt(norm2());\
    \ }\n    Point normalized() const { return Point(x / norm(), y / norm()); }\n\
    \    ld angle() const { return std::atan2(y, x); }\n    Point rotate(ld theta)\
    \ const {\n        ld ct = std::cos(theta), st = std::sin(theta);\n        return\
    \ Point(x * ct - y * st, x * st + y * ct);\n    }\n    //! @brief \u30DE\u30F3\
    \u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u7528\u300245\u5EA6\u56DE\u8EE2\u3057\u3066\
    \u221A2\u500D\u3059\u308B\n    Point manhattan_rotate() const { return Point(x\
    \ - y, x + y); }\n    T dot(const Point& rh) const { return x * rh.x + y * rh.y;\
    \ }\n    T det(const Point& rh) const { return x * rh.y - y * rh.x; }\n    Point\
    \ normal() const { return Point(-normalized().y, normalized().x); }\n    Point\
    \ projection(const Point& to) const { return to * (dot(to) / to.norm2()); }\n\
    \    int quadrant() const {\n        if (sgn(y) >= 0) return sgn(x) >= 0 ? 1 :\
    \ 2;\n        return sgn(x) >= 0 ? 4 : 3;\n    }\n    // \u504F\u89D2\u30BD\u30FC\
    \u30C8\u7528\n    bool operator<(const Point& rh) const {\n        int q = quadrant(),\
    \ rhq = rh.quadrant();\n        if (q != rhq) return q < rhq;\n        return\
    \ sgn(det(rh)) > 0;\n    }\n    bool operator<=(const Point& rh) const {\n   \
    \     int q = quadrant(), rhq = rh.quadrant();\n        if (q != rhq) return q\
    \ < rhq;\n        return sgn(det(rh)) >= 0;\n    }\n};\n\ntemplate <class T>\n\
    bool compx(Point<T>& a, Point<T>& b) {\n    return a.x < b.x;\n}\ntemplate <class\
    \ T>\nbool compy(Point<T>& a, Point<T>& b) {\n    return a.y < b.y;\n}\n\nenum\
    \ class Turn { Back = -2, CW, Middle, CCW, Front };\n/**\n * @brief \u8FBA\u306E\
    \u66F2\u304C\u308B\u65B9\u5411\n * @return\n * +1: CCW ab->bc\u304C\u5DE6\u306B\
    \u66F2\u304C\u308B\n * -1: CW  ab->bc\u304C\u53F3\u306B\u66F2\u304C\u308B\n *\
    \ +2: Front  ab\u306E\u524D\u65B9\n * -2: Back   ab\u306E\u5F8C\u65B9\n *  0:\
    \ Middle ab\u4E0A\n */\ntemplate <class T>\nTurn iSP(const Point<T>& a, const\
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
    \ bys::geo\n#line 3 \"geometry/polygon.hpp\"\n\nnamespace bys::geo {\ntemplate\
    \ <class T>\nstruct Polygon {\n    int n_vertex;\n    std::vector<Point<T>> vertex;\n\
    \    Polygon(std::initializer_list<Point<T>> init) : n_vertex(init.size()), vertex(init.begin(),\
    \ init.end()) {}\n    Polygon(std::vector<Point<T>> vertex) : n_vertex(vertex.size()),\
    \ vertex(vertex) {}\n    T area2() const {\n        if (n_vertex < 3) return 0;\n\
    \        ld s = 0.0;\n        for (int i = 0; i < n_vertex; ++i) {\n         \
    \   s += vertex[i].det(vertex[(i + 1) % n_vertex]);\n        }\n        return\
    \ s;\n    };\n    ld area() const { return area2() * 0.5; }\n    bool is_convex()\
    \ const {\n        int left = 0;\n        int right = 0;\n        for (int i =\
    \ 0; i < n_vertex; ++i) {\n            auto res = iSP(vertex[i], vertex[(i + 1)\
    \ % n_vertex], vertex[(i + 2) % n_vertex]);\n            if (res == Turn::CW)\
    \ left++;\n            if (res == Turn::CCW) right++;\n        }\n        return\
    \ left == 0 || right == 0;\n    }\n};\n}  // namespace bys::geo\n"
  code: "#pragma once\n#include \"point.hpp\"\n\nnamespace bys::geo {\ntemplate <class\
    \ T>\nstruct Polygon {\n    int n_vertex;\n    std::vector<Point<T>> vertex;\n\
    \    Polygon(std::initializer_list<Point<T>> init) : n_vertex(init.size()), vertex(init.begin(),\
    \ init.end()) {}\n    Polygon(std::vector<Point<T>> vertex) : n_vertex(vertex.size()),\
    \ vertex(vertex) {}\n    T area2() const {\n        if (n_vertex < 3) return 0;\n\
    \        ld s = 0.0;\n        for (int i = 0; i < n_vertex; ++i) {\n         \
    \   s += vertex[i].det(vertex[(i + 1) % n_vertex]);\n        }\n        return\
    \ s;\n    };\n    ld area() const { return area2() * 0.5; }\n    bool is_convex()\
    \ const {\n        int left = 0;\n        int right = 0;\n        for (int i =\
    \ 0; i < n_vertex; ++i) {\n            auto res = iSP(vertex[i], vertex[(i + 1)\
    \ % n_vertex], vertex[(i + 2) % n_vertex]);\n            if (res == Turn::CW)\
    \ left++;\n            if (res == Turn::CCW) right++;\n        }\n        return\
    \ left == 0 || right == 0;\n    }\n};\n}  // namespace bys::geo\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/base.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: geometry/polygon.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:16:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/area.test.cpp
  - test/geometry/is_convex.test.cpp
documentation_of: geometry/polygon.hpp
layout: document
redirect_from:
- /library/geometry/polygon.hpp
- /library/geometry/polygon.hpp.html
title: geometry/polygon.hpp
---
