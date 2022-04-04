---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: data/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: math/bit.hpp
    title: Bit
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "/**\n * @file stdlib.hpp\n * @brief STL Template\n */\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n/**\n * @file bit.hpp\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\
    \u52A0\u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n\
    \ * bit_width(x) - 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T>\nconstexpr\
    \ int bit_width(T x) {\n    int bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for\
    \ (; x != 0; bits++) x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\
    \u308A\u4E0B\u3052\ntemplate <class T>\nconstexpr T bit_floor(T x) {\n    assert(x\
    \ >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\
    \u306B\u5207\u308A\u4E0A\u3052\ntemplate <class T>\nconstexpr T bit_ceil(T x)\
    \ {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n\
    }\n//! @brief 2\u9032\u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T>\n\
    std::string bin(T n) {\n    assert(n > 0);\n    if (n == 0) return \"0\";\n  \
    \  std::string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1' :\
    \ '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\n//! @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\
    \u304B\ntemplate <class T>\nconstexpr bool pop(T s, int d) {\n    return s & (T(1)\
    \ << d);\n}\n}  // namespace bys\n/**\n * @file binary_indexed_tree.hpp\n * @brief\
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
    \       return res + 1;\n    }\n};\n}  // namespace bys\nnamespace bys {\nlong\
    \ long inversion(const vector<int>& v) {\n    int sz = *std::max_element(v.begin(),\
    \ v.end()) + 1;\n    BinaryIndexedTree<int> bit(sz);\n    ll res = 0;\n    for\
    \ (auto e : v) {\n        bit.add(e, 1);\n        res += bit.sum(e + 1, sz);\n\
    \    }\n    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../data/binary_indexed_tree.hpp\"\nnamespace bys\
    \ {\nlong long inversion(const vector<int>& v) {\n    int sz = *std::max_element(v.begin(),\
    \ v.end()) + 1;\n    BinaryIndexedTree<int> bit(sz);\n    ll res = 0;\n    for\
    \ (auto e : v) {\n        bit.add(e, 1);\n        res += bit.sum(e + 1, sz);\n\
    \    }\n    return res;\n}\n}  // namespace bys\n"
  dependsOn:
  - data/binary_indexed_tree.hpp
  - core/stdlib.hpp
  - math/bit.hpp
  isVerificationFile: false
  path: dp/inversion.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/inversion.hpp
layout: document
redirect_from:
- /library/dp/inversion.hpp
- /library/dp/inversion.hpp.html
title: dp/inversion.hpp
---
