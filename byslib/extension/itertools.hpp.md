---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Python::itertools
    links:
    - https://docs.python.org/ja/3/library/itertools.html
  bundledCode: "#include <array>\n#include <numeric>\n#include <vector>\n#include\
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
    \ bys\n/**\n * @file itertools.hpp\n * @brief Python::itertools\n *\n * Python\u518D\
    \u73FE\u30B7\u30EA\u30FC\u30BA itertools\u7DE8\n * See: https://docs.python.org/ja/3/library/itertools.html\n\
    \ */\nnamespace bys {\n/**\n * @brief itertools.conbination()\n *\n * \u5165\u529B\
    \u306E\u8981\u7D20\u304B\u3089\u306A\u308B\u9577\u3055r\u306E\u90E8\u5206\u5217\
    \u3092\u8FD4\u3059\u3002\n */\ntemplate <class T> class Combinations {\n    const\
    \ std::vector<T> pool;\n    i32 n, r;\n    std::vector<T> comb;\n    std::vector<i32>\
    \ indices;\n    bool term = false;\n\n  public:\n    Combinations(const std::vector<T>&\
    \ vec, i32 r) : pool(vec), n(vec.size()), r(r), comb(r), indices(r) {\n      \
    \  if (r > n) {\n            term = true;\n            return;\n        }\n  \
    \      std::iota(indices.begin(), indices.end(), 0);\n        for (i32 i = 0;\
    \ i < r; ++i) comb[i] = pool[indices[i]];\n    }\n    Combinations<T> begin()\
    \ const { return *this; }\n    bool end() const { return true; }\n    bool operator!=(bool)\
    \ const { return !term; }\n    void operator++() {\n        bool flg = true;\n\
    \        i32 i = r - 1;\n        for (; i >= 0; --i) {\n            if (indices[i]\
    \ != i + n - r) {\n                flg = false;\n                break;\n    \
    \        }\n        }\n        if (flg) {\n            term = true;\n        \
    \    return;\n        }\n        indices[i]++;\n        for (i32 j = i + 1; j\
    \ < r; ++j) {\n            indices[j] = indices[j - 1] + 1;\n        }\n     \
    \   for (i32 k = 0; k < r; ++k) comb[k] = pool[indices[k]];\n    }\n    const\
    \ std::vector<T>& operator*() const { return comb; }\n};\n/**\n * @brief itertools.combinations(range(n),\
    \ r)\n *\n * [0, n) \u304B\u3089R\u500B\u3092\u9078\u3076\u7D44\u307F\u5408\u308F\
    \u305B\u5168\u63A2\u7D22\n */\ntemplate <std::size_t R> class IndexCombinations\
    \ {\n    std::array<std::size_t, R> indices;\n    i32 n, r;\n    bool term = false;\n\
    \n  public:\n    IndexCombinations(i32 n) : n(n), r(indices.size()) {\n      \
    \  if (r > n) {\n            term = true;\n            return;\n        }\n  \
    \      std::iota(indices.begin(), indices.end(), 0);\n    }\n    IndexCombinations\
    \ begin() const { return *this; }\n    bool end() const { return true; }\n   \
    \ bool operator!=(bool) const { return !term; }\n    void operator++() {\n   \
    \     bool flg = true;\n        i32 i = r - 1;\n        for (; i >= 0; --i) {\n\
    \            if (indices[i] != i + n - r) {\n                flg = false;\n  \
    \              break;\n            }\n        }\n        if (flg) {\n        \
    \    term = true;\n            return;\n        }\n        indices[i]++;\n   \
    \     for (i32 j = i + 1; j < r; ++j) {\n            indices[j] = indices[j -\
    \ 1] + 1;\n        }\n    }\n    const std::array<std::size_t, R>& operator*()\
    \ const { return indices; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <array>\n#include <numeric>\n#include <vector>\n#include\
    \ \"../core/int_alias.hpp\"\n/**\n * @file itertools.hpp\n * @brief Python::itertools\n\
    \ *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA itertools\u7DE8\n * See: https://docs.python.org/ja/3/library/itertools.html\n\
    \ */\nnamespace bys {\n/**\n * @brief itertools.conbination()\n *\n * \u5165\u529B\
    \u306E\u8981\u7D20\u304B\u3089\u306A\u308B\u9577\u3055r\u306E\u90E8\u5206\u5217\
    \u3092\u8FD4\u3059\u3002\n */\ntemplate <class T> class Combinations {\n    const\
    \ std::vector<T> pool;\n    i32 n, r;\n    std::vector<T> comb;\n    std::vector<i32>\
    \ indices;\n    bool term = false;\n\n  public:\n    Combinations(const std::vector<T>&\
    \ vec, i32 r) : pool(vec), n(vec.size()), r(r), comb(r), indices(r) {\n      \
    \  if (r > n) {\n            term = true;\n            return;\n        }\n  \
    \      std::iota(indices.begin(), indices.end(), 0);\n        for (i32 i = 0;\
    \ i < r; ++i) comb[i] = pool[indices[i]];\n    }\n    Combinations<T> begin()\
    \ const { return *this; }\n    bool end() const { return true; }\n    bool operator!=(bool)\
    \ const { return !term; }\n    void operator++() {\n        bool flg = true;\n\
    \        i32 i = r - 1;\n        for (; i >= 0; --i) {\n            if (indices[i]\
    \ != i + n - r) {\n                flg = false;\n                break;\n    \
    \        }\n        }\n        if (flg) {\n            term = true;\n        \
    \    return;\n        }\n        indices[i]++;\n        for (i32 j = i + 1; j\
    \ < r; ++j) {\n            indices[j] = indices[j - 1] + 1;\n        }\n     \
    \   for (i32 k = 0; k < r; ++k) comb[k] = pool[indices[k]];\n    }\n    const\
    \ std::vector<T>& operator*() const { return comb; }\n};\n/**\n * @brief itertools.combinations(range(n),\
    \ r)\n *\n * [0, n) \u304B\u3089R\u500B\u3092\u9078\u3076\u7D44\u307F\u5408\u308F\
    \u305B\u5168\u63A2\u7D22\n */\ntemplate <std::size_t R> class IndexCombinations\
    \ {\n    std::array<std::size_t, R> indices;\n    i32 n, r;\n    bool term = false;\n\
    \n  public:\n    IndexCombinations(i32 n) : n(n), r(indices.size()) {\n      \
    \  if (r > n) {\n            term = true;\n            return;\n        }\n  \
    \      std::iota(indices.begin(), indices.end(), 0);\n    }\n    IndexCombinations\
    \ begin() const { return *this; }\n    bool end() const { return true; }\n   \
    \ bool operator!=(bool) const { return !term; }\n    void operator++() {\n   \
    \     bool flg = true;\n        i32 i = r - 1;\n        for (; i >= 0; --i) {\n\
    \            if (indices[i] != i + n - r) {\n                flg = false;\n  \
    \              break;\n            }\n        }\n        if (flg) {\n        \
    \    term = true;\n            return;\n        }\n        indices[i]++;\n   \
    \     for (i32 j = i + 1; j < r; ++j) {\n            indices[j] = indices[j -\
    \ 1] + 1;\n        }\n    }\n    const std::array<std::size_t, R>& operator*()\
    \ const { return indices; }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/extension/itertools.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/itertools.hpp
layout: document
redirect_from:
- /library/byslib/extension/itertools.hpp
- /library/byslib/extension/itertools.hpp.html
title: Python::itertools
---
