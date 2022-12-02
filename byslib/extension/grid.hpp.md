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
    document_title: Grid Manager
    links: []
  bundledCode: "#include <cassert>\n#include <utility>\n#include <vector>\n#include\
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
    \ bys\n/**\n * @file grid.hpp\n * @brief Grid Manager\n */\nnamespace bys {\n\
    //! @brief \u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u88DC\u52A9\u30C4\u30FC\u30EB\u8A70\
    \u3081\u5408\u308F\u305B\nstruct Grid {\n    i32 h, w;\n    //! @brief row*col\u306E\
    \u30B0\u30EA\u30C3\u30C9\n    Grid(i32 row, i32 col) : h(row), w(col) {}\n\n \
    \   //! @brief \u30B0\u30EA\u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u304B\u5224\
    \u5B9A\n    bool contain(i32 row, i32 col) const { return 0 <= row && row < h\
    \ && 0 <= col && col < w; }\n    //! @brief \u30B0\u30EA\u30C3\u30C9\u306E\u9762\
    \u7A4D\n    i32 area() const { return h * w; }\n    //! @brief \u4E00\u6B21\u5143\
    \u5316\u3057\u305F\u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n   \
    \ i32 index(i32 row, i32 col) const {\n        assert(contain(row, col));\n  \
    \      return row * w + col;\n    }\n    i32 index(std::pair<i32, i32> p) const\
    \ { return index(p.first, p.second); }\n    //! @brief \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u304B\u3089\u5FA9\u5143\n    std::pair<i32, i32> coord(i32 idx) const\
    \ {\n        assert(0 <= idx && idx < area());\n        return {idx / w, idx %\
    \ w};\n    }\n    //! \u5468\u56F2\u306E\u30DE\u30B9\u306E\u3046\u3061\u30B0\u30EA\
    \u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u3082\u306E\n    auto next(i32 row,\
    \ i32 col, const std::vector<std::pair<i32, i32>>& delta) const {\n        assert(contain(row,\
    \ col));\n        std::vector<std::pair<i32, i32>> res;\n        for (auto [di,\
    \ dj] : delta) {\n            i32 ni = row + di;\n            i32 nj = col + dj;\n\
    \            if (contain(ni, nj)) res.push_back({ni, nj});\n        }\n      \
    \  return res;\n    }\n    //! @brief \u53F3\u30FB\u4E0B\n    auto next2(i32 row,\
    \ i32 col) const { return next(row, col, {{1, 0}, {0, 1}}); }\n    //! @brief\
    \ \u4E0A\u4E0B\u5DE6\u53F3\n    auto next4(i32 row, i32 col) const { return next(row,\
    \ col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }\n    //! @brief 8\u65B9\u5411\n\
    \    auto next8(i32 row, i32 col) const {\n        std::vector<std::pair<i32,\
    \ i32>> delta;\n        for (i32 di = -1; di <= 1; ++di) {\n            for (i32\
    \ dj = -1; dj <= 1; ++dj) {\n                if (di == 0 && dj == 0) continue;\n\
    \                delta.push_back({di, dj});\n            }\n        }\n      \
    \  return next(row, col, delta);\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../core/int_alias.hpp\"\n/**\n * @file grid.hpp\n * @brief Grid Manager\n\
    \ */\nnamespace bys {\n//! @brief \u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u88DC\u52A9\
    \u30C4\u30FC\u30EB\u8A70\u3081\u5408\u308F\u305B\nstruct Grid {\n    i32 h, w;\n\
    \    //! @brief row*col\u306E\u30B0\u30EA\u30C3\u30C9\n    Grid(i32 row, i32 col)\
    \ : h(row), w(col) {}\n\n    //! @brief \u30B0\u30EA\u30C3\u30C9\u306B\u542B\u307E\
    \u308C\u308B\u304B\u5224\u5B9A\n    bool contain(i32 row, i32 col) const { return\
    \ 0 <= row && row < h && 0 <= col && col < w; }\n    //! @brief \u30B0\u30EA\u30C3\
    \u30C9\u306E\u9762\u7A4D\n    i32 area() const { return h * w; }\n    //! @brief\
    \ \u4E00\u6B21\u5143\u5316\u3057\u305F\u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n    i32 index(i32 row, i32 col) const {\n        assert(contain(row,\
    \ col));\n        return row * w + col;\n    }\n    i32 index(std::pair<i32, i32>\
    \ p) const { return index(p.first, p.second); }\n    //! @brief \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u304B\u3089\u5FA9\u5143\n    std::pair<i32, i32> coord(i32\
    \ idx) const {\n        assert(0 <= idx && idx < area());\n        return {idx\
    \ / w, idx % w};\n    }\n    //! \u5468\u56F2\u306E\u30DE\u30B9\u306E\u3046\u3061\
    \u30B0\u30EA\u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u3082\u306E\n    auto next(i32\
    \ row, i32 col, const std::vector<std::pair<i32, i32>>& delta) const {\n     \
    \   assert(contain(row, col));\n        std::vector<std::pair<i32, i32>> res;\n\
    \        for (auto [di, dj] : delta) {\n            i32 ni = row + di;\n     \
    \       i32 nj = col + dj;\n            if (contain(ni, nj)) res.push_back({ni,\
    \ nj});\n        }\n        return res;\n    }\n    //! @brief \u53F3\u30FB\u4E0B\
    \n    auto next2(i32 row, i32 col) const { return next(row, col, {{1, 0}, {0,\
    \ 1}}); }\n    //! @brief \u4E0A\u4E0B\u5DE6\u53F3\n    auto next4(i32 row, i32\
    \ col) const { return next(row, col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }\n\
    \    //! @brief 8\u65B9\u5411\n    auto next8(i32 row, i32 col) const {\n    \
    \    std::vector<std::pair<i32, i32>> delta;\n        for (i32 di = -1; di <=\
    \ 1; ++di) {\n            for (i32 dj = -1; dj <= 1; ++dj) {\n               \
    \ if (di == 0 && dj == 0) continue;\n                delta.push_back({di, dj});\n\
    \            }\n        }\n        return next(row, col, delta);\n    }\n};\n\
    }  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/extension/grid.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/grid.hpp
layout: document
redirect_from:
- /library/byslib/extension/grid.hpp
- /library/byslib/extension/grid.hpp.html
title: Grid Manager
---
