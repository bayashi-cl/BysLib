---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: byslib/algebra/mapping.hpp
    title: Mapping
  - icon: ':warning:'
    path: byslib/algorithm/inversion.hpp
    title: byslib/algorithm/inversion.hpp
  - icon: ':x:'
    path: byslib/ds/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':x:'
    path: byslib/ds/cumulative_sum.hpp
    title: Cumulative Sum
  - icon: ':x:'
    path: byslib/ds/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':question:'
    path: byslib/ds/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  - icon: ':warning:'
    path: byslib/graph/lca.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_2_A.test.cpp
    title: test/AOJ/DSL_2_A.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Monoid
    links: []
  bundledCode: "#include <array>\n#include <optional>\n#include <utility>\n#include\
    \ <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    using u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\nusing u128 = __uint128_t;\nusing f32 = float;\nusing\
    \ f64 = double;\nusing f128 = long double;\n\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr\
    \ auto operator\"\" name(unsigned long long x) { return static_cast<type>(x);\
    \ }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16, std::int16_t);\n\
    DEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64, std::int64_t);\n\
    DEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8, std::uint8_t);\n\
    DEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32, std::uint32_t);\n\
    DEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128, __uint128_t);\n\
    DEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n}  // namespace\
    \ bys\n\n/**\n * @file monoid.hpp\n * @brief Monoid\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\n */\nnamespace bys {\nstruct Magma {\n    using set_type = std::nullptr_t;\n\
    \    static constexpr set_type operation(set_type, set_type);\n    static constexpr\
    \ set_type inverse(set_type);\n    static constexpr set_type identity{nullptr};\n\
    \    static constexpr bool commutative{false};\n};\ntemplate <class T> struct\
    \ Add : Magma {\n    using set_type = T;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return a + b; }\n    static constexpr set_type inverse(set_type\
    \ a) { return -a; }\n    static constexpr set_type identity{0};\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T> struct Min : Magma {\n    using\
    \ set_type = T;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
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
    \    }();\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <array>\n#include <optional>\n#include <utility>\n\
    #include \"../core/int_alias.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief Monoid\n\
    \ *\n * \u30E2\u30CE\u30A4\u30C9\n */\nnamespace bys {\nstruct Magma {\n    using\
    \ set_type = std::nullptr_t;\n    static constexpr set_type operation(set_type,\
    \ set_type);\n    static constexpr set_type inverse(set_type);\n    static constexpr\
    \ set_type identity{nullptr};\n    static constexpr bool commutative{false};\n\
    };\ntemplate <class T> struct Add : Magma {\n    using set_type = T;\n    static\
    \ constexpr set_type operation(set_type a, set_type b) { return a + b; }\n   \
    \ static constexpr set_type inverse(set_type a) { return -a; }\n    static constexpr\
    \ set_type identity{0};\n    static constexpr bool commutative{true};\n};\ntemplate\
    \ <class T> struct Min : Magma {\n    using set_type = T;\n    static constexpr\
    \ set_type operation(set_type a, set_type b) { return std::min(a, b); }\n    static\
    \ constexpr set_type identity{std::numeric_limits<set_type>::max()};\n};\ntemplate\
    \ <class T> struct Max : Magma {\n    using set_type = T;\n    static constexpr\
    \ set_type operation(set_type a, set_type b) { return std::max(a, b); }\n    static\
    \ constexpr set_type identity{std::numeric_limits<set_type>::min()};\n};\ntemplate\
    \ <class T> struct Update : Magma {\n    using set_type = std::optional<T>;\n\
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
    \    }();\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/algebra/monoid.hpp
  requiredBy:
  - byslib/algorithm/inversion.hpp
  - byslib/ds/cumulative_sum.hpp
  - byslib/ds/binary_indexed_tree.hpp
  - byslib/ds/dual_segment_tree.hpp
  - byslib/ds/lazy_segment_tree.hpp
  - byslib/algebra/mapping.hpp
  - byslib/graph/lca.hpp
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_A.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/yosupo/staticrmq.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/static_range_sum.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/algebra/monoid.hpp
layout: document
redirect_from:
- /library/byslib/algebra/monoid.hpp
- /library/byslib/algebra/monoid.hpp.html
title: Monoid
---
