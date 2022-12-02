---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/core/traits.hpp
    title: Types
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
    links: []
  bundledCode: "#include <algorithm>\n#include <vector>\n\n#include <cstdint>\nnamespace\
    \ bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\n\
    using i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128\
    \ = long double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    \n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n#include <array>\n#include <iostream>\n\
    #include <type_traits>\n/**\n * @file traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\
    \u5F35\n */\nnamespace bys {\ntemplate <class, class = void> struct has_rshift_from_istream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_rshift_from_istream<T,\
    \ std::void_t<decltype(std::declval<std::istream&>() >> std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_rshift_from_istream_v\
    \ = has_rshift_from_istream<T>::value;\n\ntemplate <class, class = void> struct\
    \ has_lshift_to_ostream : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T,\
    \ std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_lshft_to_ostream_v\
    \ = has_lshift_to_ostream<T>::value;\n\ntemplate <class, class = void> struct\
    \ is_tuple_like : std::false_type {};\ntemplate <class T> struct is_tuple_like<T,\
    \ std::void_t<decltype(std::tuple_size<T>())>> : std::true_type {};\ntemplate\
    \ <class T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\n\ntemplate\
    \ <class, class = void> struct is_iterable : std::false_type {};\ntemplate <class\
    \ T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \ntemplate <class T> struct Indexed {\n    static_assert(std::is_integral_v<T>);\n\
    \    using resolve_to = T;\n};\nusing i32_1 = Indexed<i32>;\nusing i64_1 = Indexed<i64>;\n\
    \ntemplate <class, class = void> struct is_indexed : std::false_type {};\ntemplate\
    \ <class T> struct is_indexed<Indexed<T>> : std::true_type {};\ntemplate <class\
    \ T> constexpr bool is_indexed_v = is_indexed<T>::value;\n\ntemplate <class T,\
    \ class = void> struct resolve_type { using type = T; };\ntemplate <class T> struct\
    \ resolve_type<T, std::void_t<typename T::resolve_to>> { using type = typename\
    \ T::resolve_to; };\ntemplate <class T, std::size_t N> struct resolve_type<std::array<T,\
    \ N>> {\n    using type = std::array<typename resolve_type<T>::type, N>;\n};\n\
    template <class T, class U> struct resolve_type<std::pair<T, U>> {\n    using\
    \ type = std::pair<typename resolve_type<T>::type, typename resolve_type<U>::type>;\n\
    };\ntemplate <class... Args> struct resolve_type<std::tuple<Args...>> {\n    using\
    \ type = std::tuple<typename resolve_type<Args>::type...>;\n};\ntemplate <class\
    \ T> using resolve_type_t = typename resolve_type<T>::type;\n}  // namespace bys\n\
    namespace bys {\n/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n *\n\
    \ * @tparam Iterable\n * @param v\n * @param strict \u72ED\u7FA9\u5358\u8ABF\u5897\
    \u52A0 or \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\n * @return std::vector<i32> \u90E8\
    \u5206\u5217\u3092\u69CB\u6210\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n */\ntemplate <class Iterable> auto lis(const Iterable& v, bool strict = true)\
    \ {\n    static_assert(is_iterable_v<Iterable>, \"v is not iterable\");\n    using\
    \ T = typename Iterable::value_type;\n    auto n = v.size();\n\n    std::vector<T>\
    \ dp;\n    std::vector<i32> restore(n);\n    for (i32 i = 0; i < n; ++i) {\n \
    \       auto vi = v[i];\n        auto itr = strict ? std::lower_bound(dp.begin(),\
    \ dp.end(), vi) : std::upper_bound(dp.begin(), dp.end(), vi);\n        restore[i]\
    \ = itr - dp.begin();\n        if (itr == dp.end()) {\n            dp.push_back(vi);\n\
    \        } else {\n            *itr = vi;\n        }\n    }\n    i32 idx = dp.size()\
    \ - 1;\n    std::vector<i32> res(dp.size());\n    for (i32 i = n - 1; i >= 0;\
    \ --i) {\n        if (restore[i] == idx) res[idx--] = i;\n    }\n    return res;\n\
    }\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n#include \"../core/int_alias.hpp\"\
    \n#include \"../core/traits.hpp\"\nnamespace bys {\n/**\n * @brief \u6700\u9577\
    \u5897\u52A0\u90E8\u5206\u5217\n *\n * @tparam Iterable\n * @param v\n * @param\
    \ strict \u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 or \u5E83\u7FA9\u5358\u8ABF\u5897\
    \u52A0\n * @return std::vector<i32> \u90E8\u5206\u5217\u3092\u69CB\u6210\u3059\
    \u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n */\ntemplate <class Iterable> auto\
    \ lis(const Iterable& v, bool strict = true) {\n    static_assert(is_iterable_v<Iterable>,\
    \ \"v is not iterable\");\n    using T = typename Iterable::value_type;\n    auto\
    \ n = v.size();\n\n    std::vector<T> dp;\n    std::vector<i32> restore(n);\n\
    \    for (i32 i = 0; i < n; ++i) {\n        auto vi = v[i];\n        auto itr\
    \ = strict ? std::lower_bound(dp.begin(), dp.end(), vi) : std::upper_bound(dp.begin(),\
    \ dp.end(), vi);\n        restore[i] = itr - dp.begin();\n        if (itr == dp.end())\
    \ {\n            dp.push_back(vi);\n        } else {\n            *itr = vi;\n\
    \        }\n    }\n    i32 idx = dp.size() - 1;\n    std::vector<i32> res(dp.size());\n\
    \    for (i32 i = n - 1; i >= 0; --i) {\n        if (restore[i] == idx) res[idx--]\
    \ = i;\n    }\n    return res;\n}\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/core/traits.hpp
  isVerificationFile: false
  path: byslib/dp/lis.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/dp/lis.hpp
layout: document
redirect_from:
- /library/byslib/dp/lis.hpp
- /library/byslib/dp/lis.hpp.html
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
