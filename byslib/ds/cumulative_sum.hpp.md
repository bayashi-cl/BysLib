---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/algebra/monoid.hpp
    title: Monoid
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Cumulative Sum
    links: []
  bundledCode: "#include <numeric>\n#include <vector>\n#include <array>\n#include\
    \ <optional>\n#include <utility>\n#include <cstdint>\nnamespace bys {\nusing i8\
    \ = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing\
    \ u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128\
    \ = long double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    \n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n\n/**\n * @file monoid.hpp\n *\
    \ @brief Monoid\n *\n * \u30E2\u30CE\u30A4\u30C9\n */\nnamespace bys {\nstruct\
    \ Magma {\n    using set_type = std::nullptr_t;\n    static constexpr set_type\
    \ operation(set_type, set_type);\n    static constexpr set_type inverse(set_type);\n\
    \    static constexpr set_type identity{nullptr};\n    static constexpr bool commutative{false};\n\
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
    \    }();\n};\n}  // namespace bys\n\n/**\n * @file cumulative_sum.hpp\n * @brief\
    \ Cumulative Sum\n *\n * \u7D2F\u7A4D\u548C\n */\nnamespace bys {\ntemplate <class\
    \ Alg> struct CumulativeSum {\n    using T = typename Alg::set_type;\n    std::vector<T>\
    \ data;\n    CumulativeSum(const std::vector<T>& value) {\n        data.reserve(value.size()\
    \ + 1);\n        data.emplace_back(Alg::identity);\n        std::partial_sum(value.begin(),\
    \ value.end(), std::back_inserter(data), Alg::operation);\n    }\n    T prefix_fold(i32\
    \ right) { return data[right]; }\n    T fold(i32 left, i32 right) { return left\
    \ < right ? Alg::operation(Alg::inverse(data[left]), data[right]) : Alg::identity;\
    \ }\n};\n\ntemplate <class T> struct CumulativeSum<Add<T>> {\n    std::vector<T>\
    \ data;\n    CumulativeSum(const std::vector<T>& value) {\n        data.reserve(value.size()\
    \ + 1);\n        data.emplace_back(0);\n        std::partial_sum(value.begin(),\
    \ value.end(), std::back_inserter(data));\n    }\n    T prefix_fold(i32 right)\
    \ { return data[right]; }\n    T fold(i32 left, i32 right) { return left < right\
    \ ? data[right] - data[left] : T(0); }\n};\n\ntemplate <class T> CumulativeSum<Add<T>>\
    \ cumsum(const std::vector<T>& val) { return CumulativeSum<Add<T>>(val); }\n}\
    \  // namespace bys\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"../algebra/monoid.hpp\"\
    \n#include \"../core/int_alias.hpp\"\n\n/**\n * @file cumulative_sum.hpp\n * @brief\
    \ Cumulative Sum\n *\n * \u7D2F\u7A4D\u548C\n */\nnamespace bys {\ntemplate <class\
    \ Alg> struct CumulativeSum {\n    using T = typename Alg::set_type;\n    std::vector<T>\
    \ data;\n    CumulativeSum(const std::vector<T>& value) {\n        data.reserve(value.size()\
    \ + 1);\n        data.emplace_back(Alg::identity);\n        std::partial_sum(value.begin(),\
    \ value.end(), std::back_inserter(data), Alg::operation);\n    }\n    T prefix_fold(i32\
    \ right) { return data[right]; }\n    T fold(i32 left, i32 right) { return left\
    \ < right ? Alg::operation(Alg::inverse(data[left]), data[right]) : Alg::identity;\
    \ }\n};\n\ntemplate <class T> struct CumulativeSum<Add<T>> {\n    std::vector<T>\
    \ data;\n    CumulativeSum(const std::vector<T>& value) {\n        data.reserve(value.size()\
    \ + 1);\n        data.emplace_back(0);\n        std::partial_sum(value.begin(),\
    \ value.end(), std::back_inserter(data));\n    }\n    T prefix_fold(i32 right)\
    \ { return data[right]; }\n    T fold(i32 left, i32 right) { return left < right\
    \ ? data[right] - data[left] : T(0); }\n};\n\ntemplate <class T> CumulativeSum<Add<T>>\
    \ cumsum(const std::vector<T>& val) { return CumulativeSum<Add<T>>(val); }\n}\
    \  // namespace bys\n"
  dependsOn:
  - byslib/algebra/monoid.hpp
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ds/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/static_range_sum.test.cpp
documentation_of: byslib/ds/cumulative_sum.hpp
layout: document
redirect_from:
- /library/byslib/ds/cumulative_sum.hpp
- /library/byslib/ds/cumulative_sum.hpp.html
title: Cumulative Sum
---
