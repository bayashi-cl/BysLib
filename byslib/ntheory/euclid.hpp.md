---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Extended Euclidean Algorithm
    links:
    - https://qiita.com/drken/items/b97ff231e43bce50199a
  bundledCode: "#include <tuple>\n/**\n * @file euclid.hpp\n * @brief Extended Euclidean\
    \ Algorithm\n */\nnamespace bys {\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n *\n * ax + by = gcd(a, b) \u3092\u6E80\
    \u305F\u3059 (x, y) \u3092\u6C42\u3081\u308B\n * See: https://qiita.com/drken/items/b97ff231e43bce50199a\n\
    \ *\n * @return std::tuple<T, T, T> {d, x, y} s.t. ax + by = d\n */\ntemplate\
    \ <class T> std::tuple<T, T, T> ext_gcd(T a, T b) {\n    if (b == 0) return {a,\
    \ 1, (T)0};\n    auto [d, y, x] = ext_gcd(b, a % b);\n    y -= (a / b) * x;\n\
    \    return {d, x, y};\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <tuple>\n/**\n * @file euclid.hpp\n * @brief Extended\
    \ Euclidean Algorithm\n */\nnamespace bys {\n/**\n * @brief \u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n *\n * ax + by = gcd(a,\
    \ b) \u3092\u6E80\u305F\u3059 (x, y) \u3092\u6C42\u3081\u308B\n * See: https://qiita.com/drken/items/b97ff231e43bce50199a\n\
    \ *\n * @return std::tuple<T, T, T> {d, x, y} s.t. ax + by = d\n */\ntemplate\
    \ <class T> std::tuple<T, T, T> ext_gcd(T a, T b) {\n    if (b == 0) return {a,\
    \ 1, (T)0};\n    auto [d, y, x] = ext_gcd(b, a % b);\n    y -= (a / b) * x;\n\
    \    return {d, x, y};\n}\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/ntheory/euclid.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ntheory/euclid.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/euclid.hpp
- /library/byslib/ntheory/euclid.hpp.html
title: Extended Euclidean Algorithm
---
