---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/geometry/circle.hpp
    title: byslib/geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/geometry/line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: byslib/geometry/point.hpp
    title: Point
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
    document_title: Base
    links: []
  bundledCode: "#include <cmath>\n\n#include <cstdint>\nnamespace bys {\nusing i8\
    \ = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing\
    \ u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
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
    \ * (180.0 / PI); }\n}  // namespace bys::geo\n"
  code: "#pragma once\n#include <cmath>\n\n#include \"../core/int_alias.hpp\"\n/**\n\
    \ * @file base.hpp\n * @brief Base\n */\n//! @brief \u5E7E\u4F55\nnamespace bys::geo\
    \ {\nconstexpr f128 EPS = 1e-9;\nconst f128 PI = std::acos(-1.0);\nconst f128\
    \ TAU = PI * 2;\ni32 sgn(f128 a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0;\
    \ }\nbool isclose(f128 a, f128 b) { return sgn(a - b) == 0; }\n//! @brief \u5EA6\
    \u6570\u6CD5 -> \u5F27\u5EA6\u6CD5\nf128 radian(f128 degree) { return degree *\
    \ (PI / 180.0); }\n//! @brief \u5F27\u5EA6\u6CD5 -> \u5EA6\u6570\u6CD5\nf128 degree(f128\
    \ theta) { return theta * (180.0 / PI); }\n}  // namespace bys::geo\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/geometry/base.hpp
  requiredBy:
  - byslib/geometry/point.hpp
  - byslib/geometry/line.hpp
  - byslib/geometry/circle.hpp
  - byslib/geometry/polygon.hpp
  timestamp: '2022-11-28 10:41:31+09:00'
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
documentation_of: byslib/geometry/base.hpp
layout: document
redirect_from:
- /library/byslib/geometry/base.hpp
- /library/byslib/geometry/base.hpp.html
title: Base
---
