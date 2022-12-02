---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Base conversion
    links: []
  bundledCode: "#include <algorithm>\n#include <string>\n#include <vector>\n\n#include\
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
    \ bys\n/**\n * @file base.hpp\n * @brief Base conversion\n *\n * \u9032\u6570\u5909\
    \u63DB\n * 153(10) -> std::vector<i64>({3, 5, 1})\n *\n * @todo \u30AF\u30E9\u30B9\
    \u5316\n */\nnamespace bys {\n//! @brief 10\u9032\u6570 -> n\u9032\u6570\ntemplate\
    \ <class T> std::vector<T> deci2n(T deci, T base) {\n    std::vector<T> res;\n\
    \    while (deci > 0) {\n        res.push_back(deci % base);\n        deci /=\
    \ base;\n    }\n    return res;\n}\n//! @brief n\u9032\u6570 -> 10\u9032\u6570\
    \ni64 n2deci(std::vector<i64> n, i32 base) {\n    i64 b = 1;\n    i64 res = 0;\n\
    \    for (auto&& d : n) {\n        res += d * b;\n        b *= base;\n    }\n\
    \    return res;\n}\nstd::vector<i64> strbase(std::string n) {\n    std::vector<i64>\
    \ res;\n    std::for_each(n.rbegin(), n.rend(), [&](char d) { res.push_back(d\
    \ - '0'); });\n    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    \n#include \"../core/int_alias.hpp\"\n/**\n * @file base.hpp\n * @brief Base conversion\n\
    \ *\n * \u9032\u6570\u5909\u63DB\n * 153(10) -> std::vector<i64>({3, 5, 1})\n\
    \ *\n * @todo \u30AF\u30E9\u30B9\u5316\n */\nnamespace bys {\n//! @brief 10\u9032\
    \u6570 -> n\u9032\u6570\ntemplate <class T> std::vector<T> deci2n(T deci, T base)\
    \ {\n    std::vector<T> res;\n    while (deci > 0) {\n        res.push_back(deci\
    \ % base);\n        deci /= base;\n    }\n    return res;\n}\n//! @brief n\u9032\
    \u6570 -> 10\u9032\u6570\ni64 n2deci(std::vector<i64> n, i32 base) {\n    i64\
    \ b = 1;\n    i64 res = 0;\n    for (auto&& d : n) {\n        res += d * b;\n\
    \        b *= base;\n    }\n    return res;\n}\nstd::vector<i64> strbase(std::string\
    \ n) {\n    std::vector<i64> res;\n    std::for_each(n.rbegin(), n.rend(), [&](char\
    \ d) { res.push_back(d - '0'); });\n    return res;\n}\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ntheory/base.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ntheory/base.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/base.hpp
- /library/byslib/ntheory/base.hpp.html
title: Base conversion
---
