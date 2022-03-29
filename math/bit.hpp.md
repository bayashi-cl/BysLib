---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: data/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':heavy_check_mark:'
    path: data/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: data/segment_tree.hpp
    title: Segment Tree
  - icon: ':warning:'
    path: dp/inversion.hpp
    title: dp/inversion.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: math/numeric.hpp
    title: Numeric
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: Prime
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree_aux.test.cpp
    title: test/data/binary_indexed_tree_aux.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RAQ.test.cpp
    title: test/data/dual_segment_tree_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RUQ.test.cpp
    title: test/data/dual_segment_tree_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
    title: test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
    title: test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
    title: test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
    title: test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
    title: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RMQ.test.cpp
    title: test/data/segment_tree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RSQ.test.cpp
    title: test/data/segment_tree_RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RSQ2.test.cpp
    title: test/data/segment_tree_RSQ2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/prime.test.cpp
    title: test/math/prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bit
    links: []
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
    \ bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file bit.hpp\n *\
    \ @author bayashi_cl\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\
    \u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x)\
    \ - 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T>\nconstexpr int bit_width(T\
    \ x) {\n    int bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++)\
    \ x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\
    \ntemplate <class T>\nconstexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return\
    \ x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\
    \u4E0A\u3052\ntemplate <class T>\nconstexpr T bit_ceil(T x) {\n    assert(x >=\
    \ 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\
    \u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T>\nstd::string bin(T n)\
    \ {\n    assert(n > 0);\n    if (n == 0) return \"0\";\n    std::string res;\n\
    \    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>=\
    \ 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//!\
    \ @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class\
    \ T>\nconstexpr bool pop(T s, int d) {\n    return s & (T(1) << d);\n}\n}  //\
    \ namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/bit.hpp
  requiredBy:
  - math/modint.hpp
  - math/numeric.hpp
  - math/prime.hpp
  - data/dual_segment_tree.hpp
  - data/binary_indexed_tree.hpp
  - data/lazy_segment_tree.hpp
  - data/segment_tree.hpp
  - dp/inversion.hpp
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime.test.cpp
  - test/data/binary_indexed_tree.test.cpp
  - test/data/segment_tree_RSQ2.test.cpp
  - test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  - test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - test/data/dual_segment_tree_RAQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - test/data/binary_indexed_tree_aux.test.cpp
  - test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
  - test/data/segment_tree_RMQ.test.cpp
  - test/data/dual_segment_tree_RUQ.test.cpp
  - test/data/segment_tree_RSQ.test.cpp
documentation_of: math/bit.hpp
layout: document
redirect_from:
- /library/math/bit.hpp
- /library/math/bit.hpp.html
title: Bit
---
