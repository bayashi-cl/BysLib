---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graphv2/lca.hpp
    title: graphv2/lca.hpp
  _extendedVerifiedWith:
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
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <optional>\nnamespace bys {\ntemplate <class T>\nstruct Magma\
    \ {\n    using set_type = T;\n    static constexpr set_type operation(set_type\
    \ a, set_type b);\n    static constexpr bool commutative{false};\n};\ntemplate\
    \ <class T>\nstruct Add : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type identity{0};\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return a + b; }\n    // template <class S>\n    // static constexpr\
    \ void mapping(S& a, set_type b) {\n    //     a += b;\n    // }\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T>\nstruct Min : Magma<T> {\n \
    \   using typename Magma<T>::set_type;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T>\nstruct Max : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::max(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T>\nstruct Update : Magma<T> {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n    // template\
    \ <class S>\n    // static constexpr void mapping(S& a, set_type b) {\n    //\
    \     if (b.has_value()) a = b.value();\n    // }\n    static constexpr bool commutative{false};\n\
    };\n}  // namespace bys\n"
  code: "#pragma once\n#include <optional>\nnamespace bys {\ntemplate <class T>\n\
    struct Magma {\n    using set_type = T;\n    static constexpr set_type operation(set_type\
    \ a, set_type b);\n    static constexpr bool commutative{false};\n};\ntemplate\
    \ <class T>\nstruct Add : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type identity{0};\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return a + b; }\n    // template <class S>\n    // static constexpr\
    \ void mapping(S& a, set_type b) {\n    //     a += b;\n    // }\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T>\nstruct Min : Magma<T> {\n \
    \   using typename Magma<T>::set_type;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T>\nstruct Max : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::max(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T>\nstruct Update : Magma<T> {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n    // template\
    \ <class S>\n    // static constexpr void mapping(S& a, set_type b) {\n    //\
    \     if (b.has_value()) a = b.value();\n    // }\n    static constexpr bool commutative{false};\n\
    };\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: math/algebra.hpp
  requiredBy:
  - graphv2/lca.hpp
  timestamp: '2022-03-19 14:12:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/segment_tree_RSQ2.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree_RMQ.test.cpp
  - test/data/segment_tree_RSQ.test.cpp
  - test/graphv2/lca.test.cpp
documentation_of: math/algebra.hpp
layout: document
redirect_from:
- /library/math/algebra.hpp
- /library/math/algebra.hpp.html
title: math/algebra.hpp
---
