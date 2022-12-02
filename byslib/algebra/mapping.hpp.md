---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/algebra/monoid.hpp
    title: Monoid
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: byslib/ds/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':heavy_check_mark:'
    path: byslib/ds/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mapping
    links: []
  bundledCode: "#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
    \ i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
    using i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\n\
    using u32 = std::uint32_t;\nusing u64 = std::uint64_t;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\n\nusing isize\
    \ = std::ptrdiff_t;\nusing usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name,\
    \ type) \\\n    constexpr auto operator\"\" name(unsigned long long x) { return\
    \ static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16,\
    \ std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64,\
    \ std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8,\
    \ std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32,\
    \ std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128,\
    \ __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n\
    }  // namespace bys\n#include <array>\n#include <limits>\n#include <optional>\n\
    #include <utility>\n\n/**\n * @file monoid.hpp\n * @brief Monoid\n *\n * \u30E2\
    \u30CE\u30A4\u30C9\n */\nnamespace bys {\nstruct Magma {\n    using set_type =\
    \ std::nullptr_t;\n    static constexpr set_type operation(set_type, set_type);\n\
    \    static constexpr set_type inverse(set_type);\n    static constexpr set_type\
    \ identity{nullptr};\n    static constexpr bool commutative{false};\n};\ntemplate\
    \ <class T> struct Add : Magma {\n    using set_type = T;\n    static constexpr\
    \ set_type operation(set_type a, set_type b) { return a + b; }\n    static constexpr\
    \ set_type inverse(set_type a) { return -a; }\n    static constexpr set_type identity{0};\n\
    \    static constexpr bool commutative{true};\n};\ntemplate <class T> struct Min\
    \ : Magma {\n    using set_type = T;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T> struct Max : Magma {\n    using set_type = T;\n    static\
    \ constexpr set_type operation(set_type a, set_type b) { return std::max(a, b);\
    \ }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T> struct Update : Magma {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\ntemplate\
    \ <class T> struct Affine : Magma {\n    using set_type = std::pair<T, T>;\n \
    \   static constexpr set_type operation(set_type a, set_type b) { return {a.first\
    \ * b.first, a.second * b.first + b.second}; }\n    static constexpr set_type\
    \ identity{1, 0};\n};\ntemplate <class Modint> struct ModMul : Magma {\n    using\
    \ set_type = Modint;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return a * b; }\n    static constexpr set_type inverse(set_type a) { return\
    \ a.inv(); }\n    static constexpr set_type identity{1};\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T> struct Xor : Magma {\n    using\
    \ set_type = T;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return a ^ b; }\n    static constexpr set_type inverse(set_type a) { return\
    \ a; }\n    static constexpr set_type identity{0};\n    static constexpr bool\
    \ commutative{true};\n};\ntemplate <std::size_t N> struct Perm : Magma {\n   \
    \ using set_type = std::array<i32, N>;\n    static constexpr set_type operation(const\
    \ set_type& a, const set_type& b) {\n        set_type res = {};\n        for (auto\
    \ i = 0UL; i < N; ++i) res[i] = b[a[i]];\n        return res;\n    }\n    static\
    \ constexpr set_type inverse(const set_type& a) {\n        set_type res = {};\n\
    \        for (auto i = 0UL; i < N; ++i) res[a[i]] = i;\n        return res;\n\
    \    }\n    static constexpr set_type identity = []() {\n        set_type res\
    \ = {};\n        for (auto i = 0UL; i < N; ++i) res[i] = i;\n        return res;\n\
    \    }();\n};\n}  // namespace bys\n/**\n * @file mapping.hpp\n * @brief Mapping\n\
    \ *\n * \u9045\u5EF6\u30BB\u30B0\u6728 \u4F5C\u7528\u7D20\n */\nnamespace bys\
    \ {\ntemplate <class T, class ActMonoid> struct MappingToSet {\n    static constexpr\
    \ void mapping(T&, typename ActMonoid::set_type) {\n        static_assert([] {\
    \ return false; }(), \"mapping function does not defined.\");\n    }\n};\ntemplate\
    \ <class T, class S> struct MappingToSet<T, Add<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class\
    \ T, class S> struct MappingToSet<T, Min<S>> {\n    static constexpr void mapping(T&\
    \ t, typename Min<S>::set_type u) {\n        if (t > u) t = u;\n    }\n};\ntemplate\
    \ <class T, class S> struct MappingToSet<T, Update<S>> {\n    static constexpr\
    \ void mapping(T& t, typename Update<S>::set_type u) {\n        if (u.has_value())\
    \ t = u.value();\n    }\n};\ntemplate <class Monoid, class ActMonoid> struct Mapping\
    \ {\n    static constexpr void mapping(typename Monoid::set_type&, typename ActMonoid::set_type,\
    \ i32) {\n        static_assert([] { return false; }(), \"mapping function does\
    \ not defined.\");\n    }\n};\ntemplate <class T, class S> struct Mapping<Min<T>,\
    \ Update<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t,\
    \ typename Update<S>::set_type s, i32) {\n        if (s.has_value()) t = s.value();\n\
    \    }\n};\ntemplate <class T, class S> struct Mapping<Add<T>, Add<S>> {\n   \
    \ static constexpr void mapping(typename Add<T>::set_type& t, typename Add<S>::set_type\
    \ s, i32 w) { t += s * w; }\n};\ntemplate <class T, class S> struct Mapping<Min<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t, typename\
    \ Add<S>::set_type s, i32) { t += s; }\n};\ntemplate <class T, class S> struct\
    \ Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename Add<T>::set_type&\
    \ t, typename Update<S>::set_type s, i32 w) {\n        if (s.has_value()) t =\
    \ s.value() * w;\n    }\n};\ntemplate <class T, class S> struct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, i32 w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\ntemplate <class T, class S> struct Mapping<Max<T>, Update<S>> {\n\
    \    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, i32) {\n        if (s.has_value()) t = s.value();\n    }\n};\ntemplate <class\
    \ T, class Modint> struct Mapping<Add<T>, ModMul<Modint>> {\n    static constexpr\
    \ void mapping(typename Add<T>::set_type& t, typename ModMul<Modint>::set_type\
    \ s, i32) { t *= s; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/int_alias.hpp\"\n#include \"monoid.hpp\"\
    \n/**\n * @file mapping.hpp\n * @brief Mapping\n *\n * \u9045\u5EF6\u30BB\u30B0\
    \u6728 \u4F5C\u7528\u7D20\n */\nnamespace bys {\ntemplate <class T, class ActMonoid>\
    \ struct MappingToSet {\n    static constexpr void mapping(T&, typename ActMonoid::set_type)\
    \ {\n        static_assert([] { return false; }(), \"mapping function does not\
    \ defined.\");\n    }\n};\ntemplate <class T, class S> struct MappingToSet<T,\
    \ Add<S>> {\n    static constexpr void mapping(T& t, typename Add<S>::set_type\
    \ u) { t += u; }\n};\ntemplate <class T, class S> struct MappingToSet<T, Min<S>>\
    \ {\n    static constexpr void mapping(T& t, typename Min<S>::set_type u) {\n\
    \        if (t > u) t = u;\n    }\n};\ntemplate <class T, class S> struct MappingToSet<T,\
    \ Update<S>> {\n    static constexpr void mapping(T& t, typename Update<S>::set_type\
    \ u) {\n        if (u.has_value()) t = u.value();\n    }\n};\ntemplate <class\
    \ Monoid, class ActMonoid> struct Mapping {\n    static constexpr void mapping(typename\
    \ Monoid::set_type&, typename ActMonoid::set_type, i32) {\n        static_assert([]\
    \ { return false; }(), \"mapping function does not defined.\");\n    }\n};\ntemplate\
    \ <class T, class S> struct Mapping<Min<T>, Update<S>> {\n    static constexpr\
    \ void mapping(typename Min<T>::set_type& t, typename Update<S>::set_type s, i32)\
    \ {\n        if (s.has_value()) t = s.value();\n    }\n};\ntemplate <class T,\
    \ class S> struct Mapping<Add<T>, Add<S>> {\n    static constexpr void mapping(typename\
    \ Add<T>::set_type& t, typename Add<S>::set_type s, i32 w) { t += s * w; }\n};\n\
    template <class T, class S> struct Mapping<Min<T>, Add<S>> {\n    static constexpr\
    \ void mapping(typename Min<T>::set_type& t, typename Add<S>::set_type s, i32)\
    \ { t += s; }\n};\ntemplate <class T, class S> struct Mapping<Add<T>, Update<S>>\
    \ {\n    static constexpr void mapping(typename Add<T>::set_type& t, typename\
    \ Update<S>::set_type s, i32 w) {\n        if (s.has_value()) t = s.value() *\
    \ w;\n    }\n};\ntemplate <class T, class S> struct Mapping<Add<T>, Affine<S>>\
    \ {\n    static constexpr void mapping(typename Add<T>::set_type& t, typename\
    \ Affine<S>::set_type s, i32 w) {\n        t = t * s.first + w * s.second;\n \
    \   }\n};\ntemplate <class T, class S> struct Mapping<Max<T>, Update<S>> {\n \
    \   static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, i32) {\n        if (s.has_value()) t = s.value();\n    }\n};\ntemplate <class\
    \ T, class Modint> struct Mapping<Add<T>, ModMul<Modint>> {\n    static constexpr\
    \ void mapping(typename Add<T>::set_type& t, typename ModMul<Modint>::set_type\
    \ s, i32) { t *= s; }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/algebra/monoid.hpp
  isVerificationFile: false
  path: byslib/algebra/mapping.hpp
  requiredBy:
  - byslib/ds/dual_segment_tree.hpp
  - byslib/ds/lazy_segment_tree.hpp
  timestamp: '2022-12-02 17:23:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/algebra/mapping.hpp
layout: document
redirect_from:
- /library/byslib/algebra/mapping.hpp
- /library/byslib/algebra/mapping.hpp.html
title: Mapping
---
