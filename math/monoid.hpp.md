---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/monoid.hpp\"\n\nnamespace bys {\ntemplate <class T>\n\
    struct Monoid {\n    virtual T e() = 0;\n    virtual T op(T& a, T& b) = 0;\n};\n\
    \ntemplate <class T>\nstruct Add : Monoid<T> {\n    T e() { return 0; };\n   \
    \ T op(T a, T b) { return a + b; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n\nnamespace bys {\ntemplate <class T>\nstruct Monoid {\n  \
    \  virtual T e() = 0;\n    virtual T op(T& a, T& b) = 0;\n};\n\ntemplate <class\
    \ T>\nstruct Add : Monoid<T> {\n    T e() { return 0; };\n    T op(T a, T b) {\
    \ return a + b; }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid.hpp
  requiredBy: []
  timestamp: '2021-12-29 22:40:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid.hpp
layout: document
redirect_from:
- /library/math/monoid.hpp
- /library/math/monoid.hpp.html
title: math/monoid.hpp
---
