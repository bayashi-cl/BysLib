---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: acl/acl.hpp
    title: acl/acl.hpp
  - icon: ':heavy_check_mark:'
    path: monoid/mapping.hpp
    title: monoid/mapping.hpp
  - icon: ':heavy_check_mark:'
    path: monoid/monoid.hpp
    title: monoid/monoid.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoid/mapping_modint.hpp
    title: monoid/mapping_modint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <iostream>\n#include <atcoder/math>\n#include <atcoder/modint>\n\
    \nnamespace bys {\nusing atcoder::pow_mod, atcoder::inv_mod;\nusing mint = atcoder::modint998244353;\n\
    using mint7 = atcoder::modint1000000007;\ntemplate <int MOD>\ninline std::istream&\
    \ operator>>(std::istream& is, atcoder::static_modint<MOD>& m) {\n    long long\
    \ int n;\n    is >> n;\n    m = n;\n    return is;\n}\ntemplate <typename T, typename\
    \ std::enable_if_t<atcoder::internal::is_modint<T>::value, std::nullptr_t> = nullptr>\n\
    std::ostream& operator<<(std::ostream& os, const T& m) {\n    return os << m.val();\n\
    }\n}  // namespace bys\n#include <optional>\n#include <utility>\nnamespace bys\
    \ {\ntemplate <class T>\nstruct Magma {\n    using set_type = T;\n    static constexpr\
    \ set_type operation(set_type a, set_type b);\n    static constexpr bool commutative{false};\n\
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
    \ identity{1, 0};\n};\n}  // namespace bys\nnamespace bys {\ntemplate <class T,\
    \ class ActMonoid>\nstruct MappingToSet {\n    static constexpr void mapping(T&,\
    \ typename ActMonoid::set_type) {\n        static_assert([] { return false; }(),\
    \ \"mapping function does not defined.\");\n    }\n};\ntemplate <class T, class\
    \ S>\nstruct MappingToSet<T, Add<S>> {\n    static constexpr void mapping(T& t,\
    \ typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class T, class S>\n\
    struct MappingToSet<T, Update<S>> {\n    static constexpr void mapping(T& t, typename\
    \ Update<S>::set_type u) {\n        if (u.has_value()) t = u.value();\n    }\n\
    };\ntemplate <class Monoid, class ActMonoid>\nstruct Mapping {\n    static constexpr\
    \ void mapping(typename Monoid::set_type&, typename ActMonoid::set_type, int)\
    \ {\n        static_assert([] { return false; }(), \"mapping function does not\
    \ defined.\");\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Min<T>,\
    \ Update<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t,\
    \ typename Update<S>::set_type s, int) {\n        if (s.has_value()) t = s.value();\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>, Add<S>> {\n  \
    \  static constexpr void mapping(typename Add<T>::set_type& t, typename Add<S>::set_type\
    \ s, int w) { t += s * w; }\n};\ntemplate <class T, class S>\nstruct Mapping<Min<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t, typename\
    \ Add<S>::set_type s, int) { t += s; }\n};\ntemplate <class T, class S>\nstruct\
    \ Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename Add<T>::set_type&\
    \ t, typename Update<S>::set_type s, int w) {\n        if (s.has_value()) t =\
    \ s.value() * w;\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, int w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Max<T>, Update<S>> {\n\
    \    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, int) {\n        if (s.has_value()) t = s.value();\n    }\n};\n}  // namespace\
    \ bys\nnamespace bys {\ntemplate <class T>\nstruct AddModint : Magma<T> {\n  \
    \  using typename Magma<T>::set_type;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return a + b; }\n    static inline const set_type identity\
    \ = {0};\n    static constexpr bool commutative{true};\n};\ntemplate <class T>\n\
    struct AffineModint : Magma<T> {\n    using set_type = std::pair<T, T>;\n    static\
    \ constexpr set_type operation(set_type a, set_type b) { return {a.first * b.first,\
    \ a.second * b.first + b.second}; }\n    static inline const set_type identity\
    \ = {1, 0};\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../acl/acl.hpp\"\n#include \"mapping.hpp\"\nnamespace\
    \ bys {\ntemplate <class T>\nstruct AddModint : Magma<T> {\n    using typename\
    \ Magma<T>::set_type;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return a + b; }\n    static inline const set_type identity = {0};\n   \
    \ static constexpr bool commutative{true};\n};\ntemplate <class T>\nstruct AffineModint\
    \ : Magma<T> {\n    using set_type = std::pair<T, T>;\n    static constexpr set_type\
    \ operation(set_type a, set_type b) { return {a.first * b.first, a.second * b.first\
    \ + b.second}; }\n    static inline const set_type identity = {1, 0};\n};\n} \
    \ // namespace bys\n"
  dependsOn:
  - acl/acl.hpp
  - monoid/mapping.hpp
  - monoid/monoid.hpp
  isVerificationFile: false
  path: monoid/monoid_modint.hpp
  requiredBy:
  - monoid/mapping_modint.hpp
  timestamp: '2022-03-23 17:02:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/monoid_modint.hpp
layout: document
redirect_from:
- /library/monoid/monoid_modint.hpp
- /library/monoid/monoid_modint.hpp.html
title: monoid/monoid_modint.hpp
---
