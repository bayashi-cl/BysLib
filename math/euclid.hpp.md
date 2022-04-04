---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/euclid.test.cpp
    title: test/math/euclid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Extended Euclidean Algorithm
    links:
    - https://qiita.com/drken/items/b97ff231e43bce50199a
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
    \ bys\n/**\n * @file euclid.hpp\n * @brief Extended Euclidean Algorithm\n */\n\
    namespace bys {\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u4E92\u9664\u6CD5\n *\n * ax + by = gcd(a, b) \u3092\u6E80\u305F\u3059\
    \ (x, y) \u3092\u6C42\u3081\u308B\n * See: https://qiita.com/drken/items/b97ff231e43bce50199a\n\
    \ *\n * @return std::tuple<int, int, int> {d, x, y} s.t. ax + by = d\n */\ntemplate\
    \ <class T>\nstd::tuple<T, T, T> ext_gcd(T a, T b) {\n    if (b == 0) return {a,\
    \ 1, T(0)};\n    auto [d, y, x] = ext_gcd(b, a % b);\n    y -= (a / b) * x;\n\
    \    return {d, x, y};\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file euclid.hpp\n\
    \ * @brief Extended Euclidean Algorithm\n */\nnamespace bys {\n/**\n * @brief\
    \ \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n *\n\
    \ * ax + by = gcd(a, b) \u3092\u6E80\u305F\u3059 (x, y) \u3092\u6C42\u3081\u308B\
    \n * See: https://qiita.com/drken/items/b97ff231e43bce50199a\n *\n * @return std::tuple<int,\
    \ int, int> {d, x, y} s.t. ax + by = d\n */\ntemplate <class T>\nstd::tuple<T,\
    \ T, T> ext_gcd(T a, T b) {\n    if (b == 0) return {a, 1, T(0)};\n    auto [d,\
    \ y, x] = ext_gcd(b, a % b);\n    y -= (a / b) * x;\n    return {d, x, y};\n}\n\
    }  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/euclid.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/euclid.test.cpp
documentation_of: math/euclid.hpp
layout: document
redirect_from:
- /library/math/euclid.hpp
- /library/math/euclid.hpp.html
title: Extended Euclidean Algorithm
---
