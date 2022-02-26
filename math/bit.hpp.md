---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: data/segment_tree.hpp
    title: data/segment_tree.hpp
  - icon: ':warning:'
    path: math/numeric.hpp
    title: math/numeric.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree_aux.test.cpp
    title: test/data/binary_indexed_tree_aux.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree.test.cpp
    title: test/data/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"core/stdlib.hpp\"\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n#line 3 \"math/bit.hpp\"\n\nnamespace bys {\ntemplate <class T>\nint bit_width(T\
    \ x) {\n    int bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++)\
    \ x >>= 1;\n    return bits;\n}\ntemplate <class T>\nT bit_floor(T x) {\n    assert(x\
    \ >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\ntemplate <class\
    \ T>\nT bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) <<\
    \ bit_width(x - 1);\n}\n\nstring bin(ll n) {\n    assert(n > 0);\n    if (n ==\
    \ 0) return \"0\";\n    string res;\n    while (n > 0) {\n        res.push_back(n\
    \ & 1 ? '1' : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\ninline bool pop(int s, int d) { return s & (1 << d); }\n\
    inline bool pop(ll s, int d) { return s & (1LL << d); }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\ntemplate\
    \ <class T>\nint bit_width(T x) {\n    int bits = 0;\n    x = (x < 0) ? (-x) :\
    \ x;\n    for (; x != 0; bits++) x >>= 1;\n    return bits;\n}\ntemplate <class\
    \ T>\nT bit_floor(T x) {\n    assert(x >= 0);\n    return x == 0 ? 0 : T(1) <<\
    \ (bit_width(x) - 1);\n}\ntemplate <class T>\nT bit_ceil(T x) {\n    assert(x\
    \ >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n\nstring bin(ll\
    \ n) {\n    assert(n > 0);\n    if (n == 0) return \"0\";\n    string res;\n \
    \   while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>=\
    \ 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\ninline\
    \ bool pop(int s, int d) { return s & (1 << d); }\ninline bool pop(ll s, int d)\
    \ { return s & (1LL << d); }\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/bit.hpp
  requiredBy:
  - math/numeric.hpp
  - data/binary_indexed_tree.hpp
  - data/segment_tree.hpp
  timestamp: '2022-02-15 02:40:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/binary_indexed_tree.test.cpp
  - test/data/binary_indexed_tree_aux.test.cpp
  - test/data/segment_tree.test.cpp
documentation_of: math/bit.hpp
layout: document
redirect_from:
- /library/math/bit.hpp
- /library/math/bit.hpp.html
title: math/bit.hpp
---
