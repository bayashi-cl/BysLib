---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: Monoid
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':heavy_check_mark:'
    path: data/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  _extendedVerifiedWith:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mapping
    links: []
  bundledCode: "#include <optional>\n#include <utility>\n/**\n * @file monoid.hpp\n\
    \ * @brief Monoid\n *\n * \u30E2\u30CE\u30A4\u30C9\n */\nnamespace bys {\ntemplate\
    \ <class T>\nstruct Magma {\n    using set_type = T;\n    static constexpr set_type\
    \ operation(set_type a, set_type b);\n    static constexpr bool commutative{false};\n\
    };\ntemplate <class T>\nstruct Add : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return a +\
    \ b; }\n    static constexpr set_type identity{0};\n    static constexpr bool\
    \ commutative{true};\n};\ntemplate <class T>\nstruct Min : Magma<T> {\n    using\
    \ typename Magma<T>::set_type;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T>\nstruct Max : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::max(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T>\nstruct Update : Magma<T> {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\ntemplate\
    \ <class T>\nstruct Affine : Magma<T> {\n    using set_type = std::pair<T, T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return {a.first\
    \ * b.first, a.second * b.first + b.second}; }\n    static constexpr set_type\
    \ identity{1, 0};\n};\n}  // namespace bys\n/**\n * @file mapping.hpp\n * @brief\
    \ Mapping\n *\n * \u9045\u5EF6\u30BB\u30B0\u6728 \u4F5C\u7528\u7D20\n */\nnamespace\
    \ bys {\ntemplate <class T, class ActMonoid>\nstruct MappingToSet {\n    static\
    \ constexpr void mapping(T&, typename ActMonoid::set_type) {\n        static_assert([]\
    \ { return false; }(), \"mapping function does not defined.\");\n    }\n};\ntemplate\
    \ <class T, class S>\nstruct MappingToSet<T, Add<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class\
    \ T, class S>\nstruct MappingToSet<T, Update<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Update<S>::set_type u) {\n        if (u.has_value())\
    \ t = u.value();\n    }\n};\ntemplate <class Monoid, class ActMonoid>\nstruct\
    \ Mapping {\n    static constexpr void mapping(typename Monoid::set_type&, typename\
    \ ActMonoid::set_type, int) {\n        static_assert([] { return false; }(), \"\
    mapping function does not defined.\");\n    }\n};\ntemplate <class T, class S>\n\
    struct Mapping<Min<T>, Update<S>> {\n    static constexpr void mapping(typename\
    \ Min<T>::set_type& t, typename Update<S>::set_type s, int) {\n        if (s.has_value())\
    \ t = s.value();\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t, typename\
    \ Add<S>::set_type s, int w) { t += s * w; }\n};\ntemplate <class T, class S>\n\
    struct Mapping<Min<T>, Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type&\
    \ t, typename Add<S>::set_type s, int) { t += s; }\n};\ntemplate <class T, class\
    \ S>\nstruct Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename\
    \ Add<T>::set_type& t, typename Update<S>::set_type s, int w) {\n        if (s.has_value())\
    \ t = s.value() * w;\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, int w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Max<T>, Update<S>> {\n\
    \    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, int) {\n        if (s.has_value()) t = s.value();\n    }\n};\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include \"monoid.hpp\"\n/**\n * @file mapping.hpp\n * @brief\
    \ Mapping\n *\n * \u9045\u5EF6\u30BB\u30B0\u6728 \u4F5C\u7528\u7D20\n */\nnamespace\
    \ bys {\ntemplate <class T, class ActMonoid>\nstruct MappingToSet {\n    static\
    \ constexpr void mapping(T&, typename ActMonoid::set_type) {\n        static_assert([]\
    \ { return false; }(), \"mapping function does not defined.\");\n    }\n};\ntemplate\
    \ <class T, class S>\nstruct MappingToSet<T, Add<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class\
    \ T, class S>\nstruct MappingToSet<T, Update<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Update<S>::set_type u) {\n        if (u.has_value())\
    \ t = u.value();\n    }\n};\ntemplate <class Monoid, class ActMonoid>\nstruct\
    \ Mapping {\n    static constexpr void mapping(typename Monoid::set_type&, typename\
    \ ActMonoid::set_type, int) {\n        static_assert([] { return false; }(), \"\
    mapping function does not defined.\");\n    }\n};\ntemplate <class T, class S>\n\
    struct Mapping<Min<T>, Update<S>> {\n    static constexpr void mapping(typename\
    \ Min<T>::set_type& t, typename Update<S>::set_type s, int) {\n        if (s.has_value())\
    \ t = s.value();\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t, typename\
    \ Add<S>::set_type s, int w) { t += s * w; }\n};\ntemplate <class T, class S>\n\
    struct Mapping<Min<T>, Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type&\
    \ t, typename Add<S>::set_type s, int) { t += s; }\n};\ntemplate <class T, class\
    \ S>\nstruct Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename\
    \ Add<T>::set_type& t, typename Update<S>::set_type s, int w) {\n        if (s.has_value())\
    \ t = s.value() * w;\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, int w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Max<T>, Update<S>> {\n\
    \    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, int) {\n        if (s.has_value()) t = s.value();\n    }\n};\n}  // namespace\
    \ bys\n"
  dependsOn:
  - algebra/monoid.hpp
  isVerificationFile: false
  path: algebra/mapping.hpp
  requiredBy:
  - data/dual_segment_tree.hpp
  - data/lazy_segment_tree.hpp
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/dual_segment_tree_RAQ.test.cpp
  - test/data/dual_segment_tree_RUQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
documentation_of: algebra/mapping.hpp
layout: document
redirect_from:
- /library/algebra/mapping.hpp
- /library/algebra/mapping.hpp.html
title: Mapping
---
