---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Orderd Pair
    links: []
  bundledCode: "#include <utility>\n/**\n * @file ordered_pair.hpp\n * @brief Orderd\
    \ Pair\n */\nnamespace bys {\n//! @brief first <= second\u306B\u306A\u308Bpair\n\
    template <class T> struct OrderedPair : std::pair<T, T> {\n    OrderedPair(T a,\
    \ T b) {\n        if (a > b) std::swap(a, b);\n        this->first = a;\n    \
    \    this->second = b;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <utility>\n/**\n * @file ordered_pair.hpp\n * @brief\
    \ Orderd Pair\n */\nnamespace bys {\n//! @brief first <= second\u306B\u306A\u308B\
    pair\ntemplate <class T> struct OrderedPair : std::pair<T, T> {\n    OrderedPair(T\
    \ a, T b) {\n        if (a > b) std::swap(a, b);\n        this->first = a;\n \
    \       this->second = b;\n    }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/ordered_pair.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:04:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/ordered_pair.hpp
layout: document
redirect_from:
- /library/byslib/extension/ordered_pair.hpp
- /library/byslib/extension/ordered_pair.hpp.html
title: Orderd Pair
---
