---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree.test.cpp
    title: test/data/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/algebra.hpp\"\nnamespace bys {\ntemplate <class T>\n\
    struct Add {\n    using value_type = T;\n    static constexpr T op(T a, T b) {\
    \ return a + b; }\n    static constexpr T id{0};\n};\ntemplate <class T>\nstruct\
    \ Min {\n    using value_type = T;\n    static constexpr T op(T a, T b) { return\
    \ std::min(a, b); }\n    static constexpr T id{std::numeric_limits<T>::max()};\n\
    };\ntemplate <class T>\nstruct Max {\n    using value_type = T;\n    static constexpr\
    \ T op(T a, T b) { return std::max(a, b); }\n    static constexpr T id{std::numeric_limits<T>::min()};\n\
    };\n}  // namespace bys\n"
  code: "#pragma once\nnamespace bys {\ntemplate <class T>\nstruct Add {\n    using\
    \ value_type = T;\n    static constexpr T op(T a, T b) { return a + b; }\n   \
    \ static constexpr T id{0};\n};\ntemplate <class T>\nstruct Min {\n    using value_type\
    \ = T;\n    static constexpr T op(T a, T b) { return std::min(a, b); }\n    static\
    \ constexpr T id{std::numeric_limits<T>::max()};\n};\ntemplate <class T>\nstruct\
    \ Max {\n    using value_type = T;\n    static constexpr T op(T a, T b) { return\
    \ std::max(a, b); }\n    static constexpr T id{std::numeric_limits<T>::min()};\n\
    };\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: math/algebra.hpp
  requiredBy: []
  timestamp: '2022-02-15 02:40:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree.test.cpp
documentation_of: math/algebra.hpp
layout: document
redirect_from:
- /library/math/algebra.hpp
- /library/math/algebra.hpp.html
title: math/algebra.hpp
---
