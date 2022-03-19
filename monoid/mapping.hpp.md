---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoid/monoid.hpp
    title: monoid/monoid.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data/dual_segment_tree.hpp
    title: data/dual_segment_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RAQ.test.cpp
    title: test/data/dual_segment_tree_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RUQ.test.cpp
    title: test/data/dual_segment_tree_RUQ.test.cpp
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
    \ a, set_type b) { return a + b; }\n    static constexpr bool commutative{true};\n\
    };\ntemplate <class T>\nstruct Min : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::min(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T>\nstruct Max : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::max(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T>\nstruct Update : Magma<T> {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\n}  //\
    \ namespace bys\nnamespace bys {\ntemplate <class T, class ActMonoid>\nstruct\
    \ MappingToSet {};\ntemplate <class T, class S>\nstruct MappingToSet<T, Add<S>>\
    \ {\n    static constexpr void mapping(T& t, typename Add<S>::set_type u) { t\
    \ += u; }\n};\ntemplate <class T, class S>\nstruct MappingToSet<T, Update<S>>\
    \ {\n    static constexpr void mapping(T& t, typename Update<S>::set_type u) {\n\
    \        if (u.has_value()) t = u.value();\n    }\n};\ntemplate <class Monoid,\
    \ class ActMonoid>\nstruct Mapping {};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"monoid.hpp\"\nnamespace bys {\ntemplate <class T,\
    \ class ActMonoid>\nstruct MappingToSet {};\ntemplate <class T, class S>\nstruct\
    \ MappingToSet<T, Add<S>> {\n    static constexpr void mapping(T& t, typename\
    \ Add<S>::set_type u) { t += u; }\n};\ntemplate <class T, class S>\nstruct MappingToSet<T,\
    \ Update<S>> {\n    static constexpr void mapping(T& t, typename Update<S>::set_type\
    \ u) {\n        if (u.has_value()) t = u.value();\n    }\n};\ntemplate <class\
    \ Monoid, class ActMonoid>\nstruct Mapping {};\n}  // namespace bys\n"
  dependsOn:
  - monoid/monoid.hpp
  isVerificationFile: false
  path: monoid/mapping.hpp
  requiredBy:
  - data/dual_segment_tree.hpp
  timestamp: '2022-03-19 14:12:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/dual_segment_tree_RAQ.test.cpp
  - test/data/dual_segment_tree_RUQ.test.cpp
documentation_of: monoid/mapping.hpp
layout: document
redirect_from:
- /library/monoid/mapping.hpp
- /library/monoid/mapping.hpp.html
title: monoid/mapping.hpp
---
