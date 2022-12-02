---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/graph/lca.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Sparse Table
    links:
    - https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table
  bundledCode: "#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#include\
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
    \ bys\n/**\n * @file sparse_table.hpp\n * @brief Sparse Table\n */\nnamespace\
    \ bys {\n/**\n * @brief Sparse Table\n *\n * \u69CB\u7BC9: O(NlogN)\n * \u30AF\
    \u30A8\u30EA: O(1)\n * See:\n * https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table\n\
    \ *\n * @tparam Band \u30E2\u30CE\u30A4\u30C9\u3067\u51AA\u7B49\u6027\u304C\u3042\
    \u308B\u3082\u306E\n */\ntemplate <class Band> class SparseTable {\n    using\
    \ T = typename Band::set_type;\n    i32 n;\n    std::vector<i32> lookup;\n   \
    \ std::vector<std::vector<T>> table;\n\n  public:\n    SparseTable() {}\n    SparseTable(const\
    \ std::vector<T>& v) { build(v); }\n\n    void build(const std::vector<T>& v)\
    \ {\n        n = v.size();\n        lookup.resize(n + 1);\n\n        for (i32\
    \ i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;\n        i32 max_k =\
    \ lookup.back();\n        table.assign(max_k + 1, std::vector<T>(n));\n      \
    \  std::copy(v.begin(), v.end(), table[0].begin());\n        for (i32 i = 1; i\
    \ <= max_k; ++i) {\n            for (i32 j = 0; j <= n - (1 << i); ++j) {\n  \
    \              table[i][j] = Band::operation(table[i - 1][j], table[i - 1][j +\
    \ (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T fold(i32 l, i32\
    \ r) {\n        assert(0 <= l && l <= n);\n        assert(0 <= r && r <= n);\n\
    \        if (l >= r) return Band::identity;\n        i32 w = r - l;\n        return\
    \ Band::operation(table[lookup[w]][l], table[lookup[w]][r - (1 << lookup[w])]);\n\
    \    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include \"../core/int_alias.hpp\"\n/**\n * @file sparse_table.hpp\n * @brief\
    \ Sparse Table\n */\nnamespace bys {\n/**\n * @brief Sparse Table\n *\n * \u69CB\
    \u7BC9: O(NlogN)\n * \u30AF\u30A8\u30EA: O(1)\n * See:\n * https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table\n\
    \ *\n * @tparam Band \u30E2\u30CE\u30A4\u30C9\u3067\u51AA\u7B49\u6027\u304C\u3042\
    \u308B\u3082\u306E\n */\ntemplate <class Band> class SparseTable {\n    using\
    \ T = typename Band::set_type;\n    i32 n;\n    std::vector<i32> lookup;\n   \
    \ std::vector<std::vector<T>> table;\n\n  public:\n    SparseTable() {}\n    SparseTable(const\
    \ std::vector<T>& v) { build(v); }\n\n    void build(const std::vector<T>& v)\
    \ {\n        n = v.size();\n        lookup.resize(n + 1);\n\n        for (i32\
    \ i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;\n        i32 max_k =\
    \ lookup.back();\n        table.assign(max_k + 1, std::vector<T>(n));\n      \
    \  std::copy(v.begin(), v.end(), table[0].begin());\n        for (i32 i = 1; i\
    \ <= max_k; ++i) {\n            for (i32 j = 0; j <= n - (1 << i); ++j) {\n  \
    \              table[i][j] = Band::operation(table[i - 1][j], table[i - 1][j +\
    \ (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T fold(i32 l, i32\
    \ r) {\n        assert(0 <= l && l <= n);\n        assert(0 <= r && r <= n);\n\
    \        if (l >= r) return Band::identity;\n        i32 w = r - l;\n        return\
    \ Band::operation(table[lookup[w]][l], table[lookup[w]][r - (1 << lookup[w])]);\n\
    \    }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ds/sparse_table.hpp
  requiredBy:
  - byslib/graph/lca.hpp
  timestamp: '2022-12-02 16:14:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: byslib/ds/sparse_table.hpp
layout: document
redirect_from:
- /library/byslib/ds/sparse_table.hpp
- /library/byslib/ds/sparse_table.hpp.html
title: Sparse Table
---
