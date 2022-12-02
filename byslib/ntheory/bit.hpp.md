---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: byslib/algebra/modint.hpp
    title: Modint
  - icon: ':warning:'
    path: byslib/algorithm/inversion.hpp
    title: byslib/algorithm/inversion.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/ds/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: byslib/ds/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':heavy_check_mark:'
    path: byslib/ds/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: byslib/ds/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: byslib/ntheory/numeric.hpp
    title: Numeric
  - icon: ':heavy_check_mark:'
    path: byslib/ntheory/prime.hpp
    title: Prime
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_A.test.cpp
    title: test/AOJ/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bit
    links: []
  bundledCode: "#include <algorithm>\n#include <cassert>\n#include <string>\n#include\
    \ <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    using u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\nusing u128 = __uint128_t;\nusing f32 = float;\nusing\
    \ f64 = double;\nusing f128 = long double;\n\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr\
    \ auto operator\"\" name(unsigned long long x) { return static_cast<type>(x);\
    \ }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16, std::int16_t);\n\
    DEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64, std::int64_t);\n\
    DEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8, std::uint8_t);\n\
    DEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32, std::uint32_t);\n\
    DEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128, __uint128_t);\n\
    DEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n}  // namespace\
    \ bys\n/**\n * @file bit.hpp\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\
    \u52A0\u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n\
    \ * bit_width(x) - 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T> constexpr\
    \ i32 bit_width(T x) {\n    i32 bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for\
    \ (; x != 0; bits++) x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\
    \u308A\u4E0B\u3052\ntemplate <class T> constexpr T bit_floor(T x) {\n    assert(x\
    \ >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\
    \u306B\u5207\u308A\u4E0A\u3052\ntemplate <class T> constexpr T bit_ceil(T x) {\n\
    \    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//!\
    \ @brief 2\u9032\u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T> std::string\
    \ bin(T n) {\n    assert(n >= 0);\n    if (n == 0) return \"0\";\n    std::string\
    \ res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n     \
    \   n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n\
    }\n//! @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate\
    \ <class T> constexpr bool pop(T s, i32 d) { return s & (T(1) << d); }\n}  //\
    \ namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <string>\n\
    #include \"../core/int_alias.hpp\"\n/**\n * @file bit.hpp\n * @brief Bit\n * @note\
    \ c++20\u3067<bit>\u304C\u8FFD\u52A0\u3055\u308C\u308B\n */\nnamespace bys {\n\
    /**\n * @brief bit\u5E45\n *\n * bit_width(x) - 1  < log2(x) <= bit_width(x)\n\
    \ */\ntemplate <class T> constexpr i32 bit_width(T x) {\n    i32 bits = 0;\n \
    \   x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return bits;\n\
    }\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\ntemplate <class T> constexpr\
    \ T bit_floor(T x) {\n    assert(x >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x)\
    \ - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0A\u3052\ntemplate <class\
    \ T> constexpr T bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 :\
    \ T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\u6587\u5B57\u5217\u306B\u5909\
    \u63DB\ntemplate <class T> std::string bin(T n) {\n    assert(n >= 0);\n    if\
    \ (n == 0) return \"0\";\n    std::string res;\n    while (n > 0) {\n        res.push_back(n\
    \ & 1 ? '1' : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\n//! @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\
    \u304B\ntemplate <class T> constexpr bool pop(T s, i32 d) { return s & (T(1) <<\
    \ d); }\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ntheory/bit.hpp
  requiredBy:
  - byslib/ntheory/numeric.hpp
  - byslib/ntheory/prime.hpp
  - byslib/algorithm/inversion.hpp
  - byslib/ds/binary_indexed_tree.hpp
  - byslib/ds/dual_segment_tree.hpp
  - byslib/ds/segment_tree.hpp
  - byslib/ds/lazy_segment_tree.hpp
  - byslib/algebra/modint.hpp
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_A.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/ntheory/bit.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/bit.hpp
- /library/byslib/ntheory/bit.hpp.html
title: Bit
---
