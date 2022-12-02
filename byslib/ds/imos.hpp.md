---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_5_A.test.cpp
    title: test/AOJ/DSL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_5_B.test.cpp
    title: test/AOJ/DSL_5_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <numeric>\n#include <vector>\n\n#include <cstdint>\nnamespace\
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
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n\nnamespace bys {\ntemplate <class\
    \ T> class Imos {\n    const i32 _n;\n    std::vector<T> vec;\n\n  public:\n \
    \   Imos(i32 n) : _n(n), vec(_n) {}\n    void add(i32 l, i32 r, T v) {\n     \
    \   vec[l] += v;\n        if (r < _n) vec[r] -= v;\n    }\n    std::vector<T>\
    \ build() const {\n        std::vector<T> res;\n        res.reserve(_n);\n   \
    \     std::partial_sum(vec.begin(), vec.end(), std::back_inserter(res));\n   \
    \     return res;\n    }\n};\ntemplate <class T> class Imos2D {\n    const i32\
    \ _h, _w;\n    std::vector<std::vector<T>> vec;\n\n  public:\n    Imos2D(i32 h,\
    \ i32 w) : _h(h), _w(w), vec(_h, std::vector<T>(w)) {}\n    void add(i32 si, i32\
    \ sj, i32 ti, i32 tj, T v) {\n        ++ti, ++tj;\n        vec[si][sj] += v;\n\
    \        if (tj < _w) vec[si][tj] -= v;\n        if (ti < _h) vec[ti][sj] -= v;\n\
    \        if (ti < _h and tj < _w) vec[ti][tj] += v;\n    }\n    std::vector<std::vector<T>>\
    \ build() const {\n        auto res = vec;\n        for (i32 i = 0; i < _h; ++i)\
    \ {\n            for (i32 j = 0; j < _w; ++j) {\n                if (i != 0) res[i][j]\
    \ += res[i - 1][j];\n                if (j != 0) res[i][j] += res[i][j - 1];\n\
    \                if (i != 0 and j != 0) res[i][j] -= res[i - 1][j - 1];\n    \
    \        }\n        }\n        return res;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n\n#include \"../core/int_alias.hpp\"\
    \n\nnamespace bys {\ntemplate <class T> class Imos {\n    const i32 _n;\n    std::vector<T>\
    \ vec;\n\n  public:\n    Imos(i32 n) : _n(n), vec(_n) {}\n    void add(i32 l,\
    \ i32 r, T v) {\n        vec[l] += v;\n        if (r < _n) vec[r] -= v;\n    }\n\
    \    std::vector<T> build() const {\n        std::vector<T> res;\n        res.reserve(_n);\n\
    \        std::partial_sum(vec.begin(), vec.end(), std::back_inserter(res));\n\
    \        return res;\n    }\n};\ntemplate <class T> class Imos2D {\n    const\
    \ i32 _h, _w;\n    std::vector<std::vector<T>> vec;\n\n  public:\n    Imos2D(i32\
    \ h, i32 w) : _h(h), _w(w), vec(_h, std::vector<T>(w)) {}\n    void add(i32 si,\
    \ i32 sj, i32 ti, i32 tj, T v) {\n        ++ti, ++tj;\n        vec[si][sj] +=\
    \ v;\n        if (tj < _w) vec[si][tj] -= v;\n        if (ti < _h) vec[ti][sj]\
    \ -= v;\n        if (ti < _h and tj < _w) vec[ti][tj] += v;\n    }\n    std::vector<std::vector<T>>\
    \ build() const {\n        auto res = vec;\n        for (i32 i = 0; i < _h; ++i)\
    \ {\n            for (i32 j = 0; j < _w; ++j) {\n                if (i != 0) res[i][j]\
    \ += res[i - 1][j];\n                if (j != 0) res[i][j] += res[i][j - 1];\n\
    \                if (i != 0 and j != 0) res[i][j] -= res[i - 1][j - 1];\n    \
    \        }\n        }\n        return res;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ds/imos.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:04:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_5_B.test.cpp
  - test/AOJ/DSL_5_A.test.cpp
documentation_of: byslib/ds/imos.hpp
layout: document
redirect_from:
- /library/byslib/ds/imos.hpp
- /library/byslib/ds/imos.hpp.html
title: byslib/ds/imos.hpp
---
