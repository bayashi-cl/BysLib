---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Sequence
    links: []
  bundledCode: "/**\n * @file sequence.hpp\n * @brief Sequence\n *\n * \u6570\u5217\
    \n */\nnamespace bys {\n//! @brief \u7B49\u5DEE\u6570\u5217\ntemplate <class T>\
    \ struct Arithmetic {\n    T a0, d;\n    Arithmetic(T a0, T d) : a0(a0), d(d)\
    \ {}\n    T an(T n) { return a0 + d * n; }\n\n    //! @brief \u03A3[0, n)\n  \
    \  T sn(T n) { return (a0 + an(n - 1)) * n / 2; }\n    //! @brief \u03A3[l, r)\n\
    \    T sn(T l, T r) { return sn(r) - sn(l); }\n};\n}  // namespace bys\n"
  code: "#pragma once\n/**\n * @file sequence.hpp\n * @brief Sequence\n *\n * \u6570\
    \u5217\n */\nnamespace bys {\n//! @brief \u7B49\u5DEE\u6570\u5217\ntemplate <class\
    \ T> struct Arithmetic {\n    T a0, d;\n    Arithmetic(T a0, T d) : a0(a0), d(d)\
    \ {}\n    T an(T n) { return a0 + d * n; }\n\n    //! @brief \u03A3[0, n)\n  \
    \  T sn(T n) { return (a0 + an(n - 1)) * n / 2; }\n    //! @brief \u03A3[l, r)\n\
    \    T sn(T l, T r) { return sn(r) - sn(l); }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/ntheory/sequence.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ntheory/sequence.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/sequence.hpp
- /library/byslib/ntheory/sequence.hpp.html
title: Sequence
---
