---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: math/bit.hpp
    title: Bit
  _extendedRequiredBy:
  - icon: ':warning:'
    path: dp/inversion.hpp
    title: dp/inversion.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree_aux.test.cpp
    title: test/data/binary_indexed_tree_aux.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Indexed Tree
    links:
    - https://algo-logic.info/binary-indexed-tree/
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
    \ T>;\n}  // namespace bys\n/**\n * @file bit.hpp\n * @author bayashi_cl\n * @brief\
    \ Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\u3055\u308C\u308B\n */\nnamespace\
    \ bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x) - 1  < log2(x) <= bit_width(x)\n\
    \ */\ntemplate <class T>\nconstexpr int bit_width(T x) {\n    int bits = 0;\n\
    \    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return\
    \ bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\ntemplate <class\
    \ T>\nconstexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return x == 0 ? 0\
    \ : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0A\
    \u3052\ntemplate <class T>\nconstexpr T bit_ceil(T x) {\n    assert(x >= 0);\n\
    \    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\u6587\
    \u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T>\nstd::string bin(T n) {\n \
    \   assert(n > 0);\n    if (n == 0) return \"0\";\n    std::string res;\n    while\
    \ (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>= 1;\n   \
    \ }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//! @brief\
    \ d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class T>\n\
    constexpr bool pop(T s, int d) {\n    return s & (T(1) << d);\n}\n}  // namespace\
    \ bys\n/**\n * @file binary_indexed_tree.hpp\n * @author bayashi_cl\n * @brief\
    \ Binary Indexed Tree\n */\nnamespace bys {\n/**\n * @brief Binary Indexed Tree\n\
    \ *\n * \u4E00\u70B9\u66F4\u65B0: O(logN)\n * \u533A\u9593\u548C: O(logN)\n *\
    \ See: https://algo-logic.info/binary-indexed-tree/\n */\ntemplate <class T>\n\
    class BinaryIndexedTree {\n    const int _n;\n    std::vector<T> data;\n\n   public:\n\
    \    BinaryIndexedTree() : _n(0) {}\n    BinaryIndexedTree(int n) : _n(n), data(n\
    \ + 1) {}\n    BinaryIndexedTree(const std::vector<T>& v) : _n(v.size()), data(_n\
    \ + 1) {\n        for (int i = 0; i < _n; ++i) add(i, v[i]);\n    }\n\n    void\
    \ add(int i, T x) {\n        assert(0 <= i && i < _n);\n        ++i;\n       \
    \ while (i <= _n) {\n            data[i] += x;\n            i += i & -i;\n   \
    \     }\n    }\n    T sum(int r) {\n        assert(0 <= r && r <= _n);\n     \
    \   T res = 0;\n        while (r > 0) {\n            res += data[r];\n       \
    \     r -= r & -r;\n        }\n        return res;\n    }\n    T sum(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) -\
    \ sum(l);\n    }\n\n    //! @brief O(log N)\n    T get(int i) {\n        assert(0\
    \ <= i && i < _n);\n        return sum(i, i + 1);\n    }\n\n    //! @brief sum[0,\
    \ r) >= x\u3068\u306A\u308B\u6700\u5C0F\u306Er\u3092\u6C42\u3081\u308B\n    int\
    \ bisect(T x) {\n        if (x <= 0) return 0;\n        if (x > sum(_n)) return\
    \ -1;\n        int res = 0;\n        for (int w = bit_floor(_n); w > 0; w >>=\
    \ 1) {\n            if (res + w < _n && data[res + w] < x) {\n               \
    \ x -= data[res + w];\n                res += w;\n            }\n        }\n \
    \       return res + 1;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"../math/bit.hpp\"\
    \n/**\n * @file binary_indexed_tree.hpp\n * @author bayashi_cl\n * @brief Binary\
    \ Indexed Tree\n */\nnamespace bys {\n/**\n * @brief Binary Indexed Tree\n *\n\
    \ * \u4E00\u70B9\u66F4\u65B0: O(logN)\n * \u533A\u9593\u548C: O(logN)\n * See:\
    \ https://algo-logic.info/binary-indexed-tree/\n */\ntemplate <class T>\nclass\
    \ BinaryIndexedTree {\n    const int _n;\n    std::vector<T> data;\n\n   public:\n\
    \    BinaryIndexedTree() : _n(0) {}\n    BinaryIndexedTree(int n) : _n(n), data(n\
    \ + 1) {}\n    BinaryIndexedTree(const std::vector<T>& v) : _n(v.size()), data(_n\
    \ + 1) {\n        for (int i = 0; i < _n; ++i) add(i, v[i]);\n    }\n\n    void\
    \ add(int i, T x) {\n        assert(0 <= i && i < _n);\n        ++i;\n       \
    \ while (i <= _n) {\n            data[i] += x;\n            i += i & -i;\n   \
    \     }\n    }\n    T sum(int r) {\n        assert(0 <= r && r <= _n);\n     \
    \   T res = 0;\n        while (r > 0) {\n            res += data[r];\n       \
    \     r -= r & -r;\n        }\n        return res;\n    }\n    T sum(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) -\
    \ sum(l);\n    }\n\n    //! @brief O(log N)\n    T get(int i) {\n        assert(0\
    \ <= i && i < _n);\n        return sum(i, i + 1);\n    }\n\n    //! @brief sum[0,\
    \ r) >= x\u3068\u306A\u308B\u6700\u5C0F\u306Er\u3092\u6C42\u3081\u308B\n    int\
    \ bisect(T x) {\n        if (x <= 0) return 0;\n        if (x > sum(_n)) return\
    \ -1;\n        int res = 0;\n        for (int w = bit_floor(_n); w > 0; w >>=\
    \ 1) {\n            if (res + w < _n && data[res + w] < x) {\n               \
    \ x -= data[res + w];\n                res += w;\n            }\n        }\n \
    \       return res + 1;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - math/bit.hpp
  isVerificationFile: false
  path: data/binary_indexed_tree.hpp
  requiredBy:
  - dp/inversion.hpp
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/binary_indexed_tree.test.cpp
  - test/data/binary_indexed_tree_aux.test.cpp
documentation_of: data/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data/binary_indexed_tree.hpp
- /library/data/binary_indexed_tree.hpp.html
title: Binary Indexed Tree
---
