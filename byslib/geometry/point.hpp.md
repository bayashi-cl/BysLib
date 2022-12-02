---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/geometry/base.hpp
    title: Base
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/geometry/circle.hpp
    title: byslib/geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/geometry/line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: byslib/geometry/polygon.hpp
    title: Polygon
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_A.test.cpp
    title: test/AOJ/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_B.test.cpp
    title: test/AOJ/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_C.test.cpp
    title: test/AOJ/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_A.test.cpp
    title: test/AOJ/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_B.test.cpp
    title: test/AOJ/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_C.test.cpp
    title: test/AOJ/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_D.test.cpp
    title: test/AOJ/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_A.test.cpp
    title: test/AOJ/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_B.test.cpp
    title: test/AOJ/CGL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Point
    links: []
  bundledCode: "#include <iostream>\n\n#include <cmath>\n\n#include <cstdint>\nnamespace\
    \ bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\n\
    using i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128\
    \ = long double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    \n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n/**\n * @file base.hpp\n * @brief\
    \ Base\n */\n//! @brief \u5E7E\u4F55\nnamespace bys::geo {\nconstexpr f128 EPS\
    \ = 1e-9;\nconst f128 PI = std::acos(-1.0);\nconst f128 TAU = PI * 2;\ni32 sgn(f128\
    \ a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }\nbool isclose(f128 a, f128\
    \ b) { return sgn(a - b) == 0; }\n//! @brief \u5EA6\u6570\u6CD5 -> \u5F27\u5EA6\
    \u6CD5\nf128 radian(f128 degree) { return degree * (PI / 180.0); }\n//! @brief\
    \ \u5F27\u5EA6\u6CD5 -> \u5EA6\u6570\u6CD5\nf128 degree(f128 theta) { return theta\
    \ * (180.0 / PI); }\n}  // namespace bys::geo\n/**\n * @file point.hpp\n * @brief\
    \ Point\n */\nnamespace bys::geo {\n//! @brief \u70B9/\u30D9\u30AF\u30C8\u30EB\
    \ntemplate <class T> struct Point {\n    T x, y;\n    Point() : x(0.0), y(0.0)\
    \ {}\n    Point(T x, T y) : x(x), y(y) {}\n    // clang-format off\n    friend\
    \ std::istream& operator>>(std::istream& is, Point& v) { return is >> v.x >> v.y;\
    \ }\n    friend std::ostream& operator<<(std::ostream& os, const Point& v) { return\
    \ os << v.x << ' ' << v.y; }\n    Point operator+() const { return *this; }\n\
    \    Point operator-() const { return Point(-x, -y); }\n    Point operator+(const\
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
    \ \u30CE\u30EB\u30E0\n    f128 norm() const { return std::sqrt(norm2()); }\n \
    \   //! @brief \u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\n    Point normalized() const\
    \ { return Point(x / norm(), y / norm()); }\n    //! @brief \u504F\u89D2\n   \
    \ f128 angle() const { return std::atan2(y, x); }\n    //! @brief \u56DE\u8EE2\
    \n    Point rotate(f128 theta) const {\n        f128 ct = std::cos(theta), st\
    \ = std::sin(theta);\n        return Point(x * ct - y * st, x * st + y * ct);\n\
    \    }\n    Point rotate90() const { return Point(-y, x); }\n    //! @brief \u30DE\
    \u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u7528\u300245\u5EA6\u56DE\u8EE2\u3057\
    \u3066\u221A2\u500D\u3059\u308B\n    Point manhattan_rotate() const { return Point(x\
    \ - y, x + y); }\n    //! @brief \u5185\u7A4D\n    T dot(const Point& rh) const\
    \ { return x * rh.x + y * rh.y; }\n    //! @brief \u5916\u7A4D\n    T det(const\
    \ Point& rh) const { return x * rh.y - y * rh.x; }\n    //! @brief \u6CD5\u7DDA\
    \u30D9\u30AF\u30C8\u30EB\n    Point normal() const { return Point(-normalized().y,\
    \ normalized().x); }\n    //! @brief \u6B63\u5C04\u5F71\u30D9\u30AF\u30C8\u30EB\
    \n    Point projection(const Point& to) const { return to * (dot(to) / to.norm2());\
    \ }\n    //! @brief \u8C61\u9650\n    i32 quadrant() const {\n        if (sgn(y)\
    \ >= 0) return sgn(x) >= 0 ? 1 : 2;\n        return sgn(x) >= 0 ? 4 : 3;\n   \
    \ }\n    //! @brief \u504F\u89D2\u30BD\u30FC\u30C8\u7528\n    bool operator<(const\
    \ Point& rh) const {\n        i32 q = quadrant(), rhq = rh.quadrant();\n     \
    \   if (q != rhq) return q < rhq;\n        return sgn(det(rh)) > 0;\n    }\n \
    \   bool operator<=(const Point& rh) const {\n        i32 q = quadrant(), rhq\
    \ = rh.quadrant();\n        if (q != rhq) return q < rhq;\n        return sgn(det(rh))\
    \ >= 0;\n    }\n};\n\ntemplate <class T> bool compx(Point<T>& a, Point<T>& b)\
    \ { return a.x < b.x; }\ntemplate <class T> bool compy(Point<T>& a, Point<T>&\
    \ b) { return a.y < b.y; }\n//! @brief \u66F2\u304C\u308B\u65B9\u5411\nenum class\
    \ Turn {\n    //! ab\u306E\u5F8C\u65B9\n    Back = -2,\n    //! ab->bc\u304C\u53F3\
    \u306B\u66F2\u304C\u308B\n    CW = -1,\n    //! ab\u4E0A\n    Middle = 0,\n  \
    \  //! ab->bc\u304C\u5DE6\u306B\u66F2\u304C\u308B\n    CCW = 1,\n    //! ab\u306E\
    \u524D\u65B9\n    Front = 2,\n};\n//! @brief \u8FBA\u306E\u66F2\u304C\u308B\u65B9\
    \u5411\ntemplate <class T> Turn iSP(const Point<T>& a, const Point<T>& b, const\
    \ Point<T>& c) {\n    i32 flg = sgn((b - a).det(c - a));\n    if (flg == 1) {\n\
    \        return Turn::CCW;\n    } else if (flg == -1) {\n        return Turn::CW;\n\
    \    } else {\n        if (sgn((b - a).dot(c - b)) > 0) {\n            return\
    \ Turn::Front;\n        } else if (sgn((a - b).dot(c - a)) > 0) {\n          \
    \  return Turn::Back;\n        } else {\n            return Turn::Middle;\n  \
    \      }\n    }\n}\nenum class Angle {\n    //! \u920D\u89D2\n    Obtuse = -1,\n\
    \    //! \u76F4\u89D2\n    Right = 0,\n    //! \u92ED\u89D2\n    Acute = 1,\n\
    };\n\n//! @brief \u89D2\u306E\u7A2E\u985E\ntemplate <class T> Angle angle_type(const\
    \ Point<T>& a, const Point<T>& b, const Point<T>& c) {\n    i32 t = sgn((a - b).dot(c\
    \ - b));\n    if (t == -1) {\n        return Angle::Obtuse;\n    } else if (t\
    \ == 0) {\n        return Angle::Right;\n    } else {\n        return Angle::Acute;\n\
    \    }\n}\ntemplate <class T> T distance2(const Point<T>& a, const Point<T>& b)\
    \ {\n    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);\n}\ntemplate\
    \ <class T> T distance(const Point<T>& a, const Point<T>& b) { return sqrt(distance2(a,\
    \ b)); }\n}  // namespace bys::geo\n"
  code: "#pragma once\n#include <iostream>\n\n#include \"base.hpp\"\n/**\n * @file\
    \ point.hpp\n * @brief Point\n */\nnamespace bys::geo {\n//! @brief \u70B9/\u30D9\
    \u30AF\u30C8\u30EB\ntemplate <class T> struct Point {\n    T x, y;\n    Point()\
    \ : x(0.0), y(0.0) {}\n    Point(T x, T y) : x(x), y(y) {}\n    // clang-format\
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
    \ on\n\n    //! @brief \u30CE\u30EB\u30E0^2\n    T norm2() const { return x *\
    \ x + y * y; }\n    //! @brief \u30CE\u30EB\u30E0\n    f128 norm() const { return\
    \ std::sqrt(norm2()); }\n    //! @brief \u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\n\
    \    Point normalized() const { return Point(x / norm(), y / norm()); }\n    //!\
    \ @brief \u504F\u89D2\n    f128 angle() const { return std::atan2(y, x); }\n \
    \   //! @brief \u56DE\u8EE2\n    Point rotate(f128 theta) const {\n        f128\
    \ ct = std::cos(theta), st = std::sin(theta);\n        return Point(x * ct - y\
    \ * st, x * st + y * ct);\n    }\n    Point rotate90() const { return Point(-y,\
    \ x); }\n    //! @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u7528\
    \u300245\u5EA6\u56DE\u8EE2\u3057\u3066\u221A2\u500D\u3059\u308B\n    Point manhattan_rotate()\
    \ const { return Point(x - y, x + y); }\n    //! @brief \u5185\u7A4D\n    T dot(const\
    \ Point& rh) const { return x * rh.x + y * rh.y; }\n    //! @brief \u5916\u7A4D\
    \n    T det(const Point& rh) const { return x * rh.y - y * rh.x; }\n    //! @brief\
    \ \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB\n    Point normal() const { return Point(-normalized().y,\
    \ normalized().x); }\n    //! @brief \u6B63\u5C04\u5F71\u30D9\u30AF\u30C8\u30EB\
    \n    Point projection(const Point& to) const { return to * (dot(to) / to.norm2());\
    \ }\n    //! @brief \u8C61\u9650\n    i32 quadrant() const {\n        if (sgn(y)\
    \ >= 0) return sgn(x) >= 0 ? 1 : 2;\n        return sgn(x) >= 0 ? 4 : 3;\n   \
    \ }\n    //! @brief \u504F\u89D2\u30BD\u30FC\u30C8\u7528\n    bool operator<(const\
    \ Point& rh) const {\n        i32 q = quadrant(), rhq = rh.quadrant();\n     \
    \   if (q != rhq) return q < rhq;\n        return sgn(det(rh)) > 0;\n    }\n \
    \   bool operator<=(const Point& rh) const {\n        i32 q = quadrant(), rhq\
    \ = rh.quadrant();\n        if (q != rhq) return q < rhq;\n        return sgn(det(rh))\
    \ >= 0;\n    }\n};\n\ntemplate <class T> bool compx(Point<T>& a, Point<T>& b)\
    \ { return a.x < b.x; }\ntemplate <class T> bool compy(Point<T>& a, Point<T>&\
    \ b) { return a.y < b.y; }\n//! @brief \u66F2\u304C\u308B\u65B9\u5411\nenum class\
    \ Turn {\n    //! ab\u306E\u5F8C\u65B9\n    Back = -2,\n    //! ab->bc\u304C\u53F3\
    \u306B\u66F2\u304C\u308B\n    CW = -1,\n    //! ab\u4E0A\n    Middle = 0,\n  \
    \  //! ab->bc\u304C\u5DE6\u306B\u66F2\u304C\u308B\n    CCW = 1,\n    //! ab\u306E\
    \u524D\u65B9\n    Front = 2,\n};\n//! @brief \u8FBA\u306E\u66F2\u304C\u308B\u65B9\
    \u5411\ntemplate <class T> Turn iSP(const Point<T>& a, const Point<T>& b, const\
    \ Point<T>& c) {\n    i32 flg = sgn((b - a).det(c - a));\n    if (flg == 1) {\n\
    \        return Turn::CCW;\n    } else if (flg == -1) {\n        return Turn::CW;\n\
    \    } else {\n        if (sgn((b - a).dot(c - b)) > 0) {\n            return\
    \ Turn::Front;\n        } else if (sgn((a - b).dot(c - a)) > 0) {\n          \
    \  return Turn::Back;\n        } else {\n            return Turn::Middle;\n  \
    \      }\n    }\n}\nenum class Angle {\n    //! \u920D\u89D2\n    Obtuse = -1,\n\
    \    //! \u76F4\u89D2\n    Right = 0,\n    //! \u92ED\u89D2\n    Acute = 1,\n\
    };\n\n//! @brief \u89D2\u306E\u7A2E\u985E\ntemplate <class T> Angle angle_type(const\
    \ Point<T>& a, const Point<T>& b, const Point<T>& c) {\n    i32 t = sgn((a - b).dot(c\
    \ - b));\n    if (t == -1) {\n        return Angle::Obtuse;\n    } else if (t\
    \ == 0) {\n        return Angle::Right;\n    } else {\n        return Angle::Acute;\n\
    \    }\n}\ntemplate <class T> T distance2(const Point<T>& a, const Point<T>& b)\
    \ {\n    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);\n}\ntemplate\
    \ <class T> T distance(const Point<T>& a, const Point<T>& b) { return sqrt(distance2(a,\
    \ b)); }\n}  // namespace bys::geo\n"
  dependsOn:
  - byslib/geometry/base.hpp
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/geometry/point.hpp
  requiredBy:
  - byslib/geometry/line.hpp
  - byslib/geometry/circle.hpp
  - byslib/geometry/polygon.hpp
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/CGL_2_B.test.cpp
  - test/AOJ/CGL_2_A.test.cpp
  - test/AOJ/CGL_2_C.test.cpp
  - test/AOJ/CGL_1_C.test.cpp
  - test/AOJ/CGL_1_B.test.cpp
  - test/AOJ/CGL_2_D.test.cpp
  - test/AOJ/CGL_3_A.test.cpp
  - test/AOJ/CGL_1_A.test.cpp
  - test/AOJ/CGL_3_B.test.cpp
documentation_of: byslib/geometry/point.hpp
layout: document
redirect_from:
- /library/byslib/geometry/point.hpp
- /library/byslib/geometry/point.hpp.html
title: Point
---
