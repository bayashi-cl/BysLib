---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/constant.hpp
    title: Const
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/core/traits.hpp
    title: Types
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binomial Coefficient
    links:
    - https://drken1215.hatenablog.com/entry/2018/06/08/210000
  bundledCode: "#include <vector>\n\n#include <cstddef>\n#include <limits>\n#include\
    \ <tuple>\n#include <utility>\n\n#include <cstdint>\nnamespace bys {\nusing i8\
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
    \n/**\n * @file constant.hpp\n * @brief Const\n */\nnamespace bys {\nconstexpr\
    \ i32 MOD7 = 1000000007;\nconstexpr i32 MOD9 = 998244353;\nconstexpr i32 MOD =\
    \ MOD9;\n\ntemplate <class T> constexpr T get_inf();\nnamespace impl {\ntemplate\
    \ <class Tp, std::size_t... I> constexpr auto get_inf_tuple(std::index_sequence<I...>)\
    \ {\n    return Tp{get_inf<typename std::tuple_element_t<I, Tp>>()...};\n}\n}\
    \  // namespace impl\ntemplate <class T> constexpr T get_inf() {\n    if constexpr\
    \ (std::is_integral_v<T>) {\n        return std::numeric_limits<T>::max() / (T)2;\n\
    \    } else if constexpr (std::is_floating_point_v<T>) {\n        return std::numeric_limits<T>::infinity();\n\
    \    } else if constexpr (is_tuple_like_v<T>) {\n        return impl::get_inf_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \    } else {\n        static_assert([]() { return false; }, \"Type Error\");\n\
    \    }\n}\ntemplate <class T> constexpr bool is_inf(T x) { return x == get_inf<T>();\
    \ }\nconstexpr auto INF = get_inf<i32>();\nconstexpr auto LINF = get_inf<i64>();\n\
    }  // namespace bys\n/**\n * @file combination.hpp\n * @brief Binomial Coefficient\n\
    \ */\nnamespace bys {\n/**\n * @brief \u8907\u6570\u30AF\u30A8\u30EA\u4E8C\u9805\
    \u4FC2\u6570\n *\n * \u524D\u51E6\u7406 O(n)\n * \u30AF\u30A8\u30EA O(1)\n * See:\
    \ https://drken1215.hatenablog.com/entry/2018/06/08/210000\n */\nclass MultiComb\
    \ {\n    i32 mod;\n    std::vector<i32> fact, factinv, inv;\n\n    void extend(i32\
    \ n) {\n        if ((i32)fact.size() > n) return;\n        fact.resize(n + 1);\n\
    \        factinv.resize(n + 1);\n        inv.resize(n + 1);\n        for (i32\
    \ i = fact.size(); i <= n; ++i) {\n            fact[i] = (i64)fact[i - 1] * i\
    \ % mod;\n            inv[i] = mod - (i64)inv[mod % i] * (mod / i) % mod;\n  \
    \          factinv[i] = (i64)factinv[i - 1] * inv[i] % mod;\n        }\n    }\n\
    \n  public:\n    MultiComb(i32 n = 1, i32 mod = MOD) : mod(mod), fact({1, 1}),\
    \ factinv({1, 1}), inv({0, 1}) { extend(n); }\n\n    i32 fac(i32 n) {\n      \
    \  extend(n);\n        return fact[n];\n    }\n\n    i32 comb(i32 n, i32 r) {\n\
    \        if (r < 0 || n < r) return 0;\n        extend(n);\n        return (i64)fact[n]\
    \ * ((i64)factinv[r] * factinv[n - r] % mod) % mod;\n    }\n    i32 perm(i32 n,\
    \ i32 r) {\n        if (r < 0 || n < r) return 0;\n        extend(n);\n      \
    \  return (i64)fact[n] * factinv[n - r] % mod;\n    }\n    i32 hom(i32 n, i32\
    \ r) {\n        if (n == 0 && r == 0) return 1;\n        return comb(n + r - 1,\
    \ r);\n    }\n};\n\n/**\n * @brief nCr\n *\n * O(min(n, (n - r)))\n *\n * @param\
    \ n Modint\u3082\u6E21\u305B\u308B\n */\ntemplate <class T> constexpr T comb(T\
    \ n, i32 r) {\n    T num = 1, den = 1;\n    for (i32 i = 0; i < r; ++i) {\n  \
    \      num *= n - i;\n        den *= i + 1;\n    }\n    return num / den;\n}\n\
    }  // namespace bys\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../core/constant.hpp\"\n#include\
    \ \"../core/int_alias.hpp\"\n/**\n * @file combination.hpp\n * @brief Binomial\
    \ Coefficient\n */\nnamespace bys {\n/**\n * @brief \u8907\u6570\u30AF\u30A8\u30EA\
    \u4E8C\u9805\u4FC2\u6570\n *\n * \u524D\u51E6\u7406 O(n)\n * \u30AF\u30A8\u30EA\
    \ O(1)\n * See: https://drken1215.hatenablog.com/entry/2018/06/08/210000\n */\n\
    class MultiComb {\n    i32 mod;\n    std::vector<i32> fact, factinv, inv;\n\n\
    \    void extend(i32 n) {\n        if ((i32)fact.size() > n) return;\n       \
    \ fact.resize(n + 1);\n        factinv.resize(n + 1);\n        inv.resize(n +\
    \ 1);\n        for (i32 i = fact.size(); i <= n; ++i) {\n            fact[i] =\
    \ (i64)fact[i - 1] * i % mod;\n            inv[i] = mod - (i64)inv[mod % i] *\
    \ (mod / i) % mod;\n            factinv[i] = (i64)factinv[i - 1] * inv[i] % mod;\n\
    \        }\n    }\n\n  public:\n    MultiComb(i32 n = 1, i32 mod = MOD) : mod(mod),\
    \ fact({1, 1}), factinv({1, 1}), inv({0, 1}) { extend(n); }\n\n    i32 fac(i32\
    \ n) {\n        extend(n);\n        return fact[n];\n    }\n\n    i32 comb(i32\
    \ n, i32 r) {\n        if (r < 0 || n < r) return 0;\n        extend(n);\n   \
    \     return (i64)fact[n] * ((i64)factinv[r] * factinv[n - r] % mod) % mod;\n\
    \    }\n    i32 perm(i32 n, i32 r) {\n        if (r < 0 || n < r) return 0;\n\
    \        extend(n);\n        return (i64)fact[n] * factinv[n - r] % mod;\n   \
    \ }\n    i32 hom(i32 n, i32 r) {\n        if (n == 0 && r == 0) return 1;\n  \
    \      return comb(n + r - 1, r);\n    }\n};\n\n/**\n * @brief nCr\n *\n * O(min(n,\
    \ (n - r)))\n *\n * @param n Modint\u3082\u6E21\u305B\u308B\n */\ntemplate <class\
    \ T> constexpr T comb(T n, i32 r) {\n    T num = 1, den = 1;\n    for (i32 i =\
    \ 0; i < r; ++i) {\n        num *= n - i;\n        den *= i + 1;\n    }\n    return\
    \ num / den;\n}\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/constant.hpp
  - byslib/core/int_alias.hpp
  - byslib/core/traits.hpp
  isVerificationFile: false
  path: byslib/ntheory/combination.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ntheory/combination.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/combination.hpp
- /library/byslib/ntheory/combination.hpp.html
title: Binomial Coefficient
---
