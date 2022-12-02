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
  - icon: ':heavy_check_mark:'
    path: byslib/ntheory/bit.hpp
    title: Bit
  - icon: ':heavy_check_mark:'
    path: byslib/ntheory/numeric.hpp
    title: Numeric
  - icon: ':heavy_check_mark:'
    path: byslib/ntheory/prime.hpp
    title: Prime
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Modint
    links:
    - https://atcoder.github.io/ac-library/document_ja/modint.html
  bundledCode: "#include <cstddef>\n#include <limits>\n#include <tuple>\n#include\
    \ <utility>\n\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\n\
    using i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
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
    }  // namespace bys\n#include <array>\n#include <iostream>\n#include <type_traits>\n\
    /**\n * @file traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\n\
    namespace bys {\ntemplate <class, class = void> struct has_rshift_from_istream\
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
    }  // namespace bys\n#include <vector>\n\n#include <algorithm>\n#include <cassert>\n\
    #include <string>\n/**\n * @file bit.hpp\n * @brief Bit\n * @note c++20\u3067\
    <bit>\u304C\u8FFD\u52A0\u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief\
    \ bit\u5E45\n *\n * bit_width(x) - 1  < log2(x) <= bit_width(x)\n */\ntemplate\
    \ <class T> constexpr i32 bit_width(T x) {\n    i32 bits = 0;\n    x = (x < 0)\
    \ ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return bits;\n}\n//! @brief\
    \ 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\ntemplate <class T> constexpr T bit_floor(T\
    \ x) {\n    assert(x >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n\
    }\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0A\u3052\ntemplate <class T> constexpr\
    \ T bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x\
    \ - 1);\n}\n//! @brief 2\u9032\u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class\
    \ T> std::string bin(T n) {\n    assert(n >= 0);\n    if (n == 0) return \"0\"\
    ;\n    std::string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1'\
    \ : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\n//! @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\
    \u304B\ntemplate <class T> constexpr bool pop(T s, i32 d) { return s & (T(1) <<\
    \ d); }\n}  // namespace bys\n/**\n * @file numeric.hpp\n * @brief Numeric\n *\n\
    \ * \u6570\u5024\u8A08\u7B97\u8A70\u3081\u5408\u308F\u305B\n */\nnamespace bys\
    \ {\n//! @brief \u6574\u6570\u306E\u7D2F\u4E57\nconstexpr i64 int_pow(i32 a, i32\
    \ b) {\n    i64 res = 1;\n    for (i32 i = 0; i < b; ++i) res *= a;\n    return\
    \ res;\n}\n/**\n * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n *\n * O(log\
    \ q)\n */\nconstexpr i64 mod_pow(i64 p, i64 q, i64 mod) {\n    if (mod == 1) return\
    \ 0_i64;\n    i128 res = 1;\n    i128 b = p % mod;\n    while (q) {\n        if\
    \ (q & 1) res = res * b % mod;\n        b = b * b % mod;\n        q >>= 1;\n \
    \   }\n    return (i64)res;\n}\n//! @brief ceil(x / y)\ntemplate <class T> constexpr\
    \ T ceildiv(T x, T y) {\n    if ((x < T(0)) ^ (y < T(0))) {\n        return x\
    \ / y;\n    } else {\n        return (x + y + (x < T(0) ? 1 : -1)) / y;\n    }\n\
    }\n//! @brief floor(x / y)\ntemplate <class T> constexpr T floordiv(T x, T y)\
    \ {\n    if ((x < T(0)) ^ (y < T(0))) {\n        return (x - y + (x < T(0) ? 1\
    \ : -1)) / y;\n    } else {\n        return x / y;\n    }\n}\n/**\n * @brief Python::divmod\n\
    \ *\n * See: https://docs.python.org/ja/3/library/functions.html#divmod\n */\n\
    template <class T> constexpr std::pair<T, T> divmod(T x, T y) {\n    auto q =\
    \ floordiv(x, y);\n    return {q, x - q * y};\n}\n\n/**\n * @brief Python::%\n\
    \ *\n * See: https://docs.python.org/ja/3/reference/expressions.html#index-68\n\
    \ */\ntemplate <class T, class S> constexpr T floormod(T x, S mod) {\n    x %=\
    \ mod;\n    if (x < 0) x += mod;\n    return x;\n}\n\nnamespace impl {\nconstexpr\
    \ i64 isqrt_aux(i64 c, i64 n) {\n    if (c == 0) return 1;\n    i64 k = (c - 1)\
    \ / 2;\n    i64 a = isqrt_aux(c / 2, n >> (2 * k + 2));\n    return (a << k) +\
    \ (n >> (k + 2)) / a;\n}\n}  // namespace impl\n/**\n * @brief Python::math.isqrt\n\
    \ *\n * floor(sqrt(n))\n * See: https://docs.python.org/ja/3/library/math.html#math.isqrt\n\
    \ */\ntemplate <class T> constexpr T isqrt(T n) {\n    assert(n >= 0);\n    if\
    \ (n == T(0)) return T(0);\n    i64 a = impl::isqrt_aux((bit_width(n) - 1) / 2,\
    \ n);\n    return n < a * a ? a - 1 : a;\n}\n/**\n * @brief Nim::math::almostEqual\n\
    \ *\n * See: https://nim-lang.org/docs/math.html#almostEqual,T,T,Natural\n */\n\
    template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t>\
    \ = nullptr>\nconstexpr bool isclose(T x, T y, T coef = 4.0) {\n    if (x == y)\
    \ return true;\n    auto diff = std::abs(x - y);\n    return diff <= std::numeric_limits<T>::epsilon()\
    \ * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n}\n\nconstexpr\
    \ std::pair<i64, i64> inv_gcd(i64 a, i64 b) {\n    a = floormod(a, b);\n    if\
    \ (a == 0) return {b, 0};\n    i64 s = b, t = a;\n    i64 m0 = 0, m1 = 1;\n\n\
    \    while (t) {\n        i64 u = s / t;\n        s -= t * u;\n        m0 -= m1\
    \ * u;\n        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp =\
    \ m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n\
    \    return {s, m0};\n}\n\n//! @brief Count multipules of k in the [left, right)\n\
    template <class T> constexpr T range_multiples(T left, T right, T k) { return\
    \ (right - 1) / k - (left - 1) / k; }\ntemplate <class T> constexpr T multiple_floor(T\
    \ x, T k) { return x / k * k; }\ntemplate <class T> constexpr T multiple_ceil(T\
    \ x, T k) { return ceildiv(x, k) * k; }\n}  // namespace bys\n/**\n * @file prime.hpp\n\
    \ * @brief Prime\n */\nnamespace bys {\n/**\n * @brief \u7D20\u56E0\u6570\u5206\
    \u89E3\n *\n * \u8A66\u3057\u5272\u308A\u6CD5\n * O(\u221An)\n */\ntemplate <typename\
    \ T> std::vector<T> prime_factorize(T n) {\n    std::vector<T> res;\n    while\
    \ (n % 2 == 0) {\n        res.push_back(2);\n        n /= 2;\n    }\n    T f =\
    \ 3;\n    while (f * f <= n) {\n        if (n % f == 0) {\n            res.push_back(f);\n\
    \            n /= f;\n        } else {\n            f += 2;\n        }\n    }\n\
    \    if (n != 1) res.push_back(n);\n    return res;\n}\n\nnamespace impl {\ntemplate\
    \ <std::size_t N> constexpr bool miller_rabin(i64 n, std::array<i64, N> bases)\
    \ {\n    auto d = n - 1;\n    while (d % 2 == 0) d >>= 1;\n    for (auto b : bases)\
    \ {\n        if (n <= b) break;\n        auto t = d;\n        i128 y = mod_pow(b,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    }  // namespace impl\n/**\n * @brief Miller-Rabin\u7D20\u6570\u5224\u5B9A\n *\n\
    \ * 2^64\u4EE5\u4E0B\u306A\u3089\u6B63\u78BA\u306B\u5224\u5B9A\u3067\u304D\u308B\
    \n * See: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test\n\
    \ * See: https://miller-rabin.appspot.com\n *\n * @note c++20\u3067constexpr\u95A2\
    \u6570\u5185\u3067\u3082vector\u304C\u4F7F\u3048\u308B\u3088\u3046\u306B\n */\n\
    constexpr bool is_prime(i64 n) {\n    if (not(n & 1)) return n == 2;\n    if (n\
    \ <= 1) return false;\n    if (n <= std::numeric_limits<i32>::max()) {\n     \
    \   std::array<i64, 3> bases = {2, 7, 61};\n        return impl::miller_rabin(n,\
    \ bases);\n    } else {\n        std::array<i64, 7> bases = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022};\n        return impl::miller_rabin(n, bases);\n\
    \    }\n}\n}  // namespace bys\n/**\n * @file modint.hpp\n * @brief Modint\n */\n\
    namespace bys {\n/**\n * @brief ModInt\n *\n * ac-library\u306Emodint\u3092constexpr\u5316\
    \u3057\u305F\u3082\u306E\n * See: https://atcoder.github.io/ac-library/document_ja/modint.html\n\
    \ *\n * @tparam Modulo \u6CD5\n */\ntemplate <u32 Modulo> class ModInt {\n   \
    \ u32 _v;\n\n  public:\n    static constexpr u32 mod = Modulo;\n    // static_assert(is_prime(mod),\
    \ \"Modulo need to be prime.\");\n    static_assert(mod < (std::numeric_limits<u32>::max()\
    \ >> 1), \"Modulo need to be <2^31.\");\n\n    constexpr ModInt() noexcept : _v(0)\
    \ {}\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>, std::nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T v) noexcept : _v(v % mod) {}\n    template\
    \ <class T, std::enable_if_t<std::is_signed_v<T>, std::nullptr_t> = nullptr>\n\
    \    constexpr ModInt(T v) noexcept : _v(floormod(v, mod)) {}\n\n    constexpr\
    \ ModInt pow(i64 n) const noexcept {\n        ModInt res = 1, p = *this;\n   \
    \     while (n) {\n            if (n & 1) res *= p;\n            p *= p;\n   \
    \         n >>= 1;\n        }\n        return res;\n    }\n    constexpr ModInt\
    \ inv() const noexcept {\n        if constexpr (is_prime(mod)) {\n           \
    \ return pow(mod - 2);\n        } else {\n            return inv_gcd(_v, mod).second;\n\
    \        }\n    }\n\n    constexpr ModInt& operator+=(const ModInt rhs) noexcept\
    \ {\n        _v += rhs._v;\n        if (_v >= mod) _v -= mod;\n        return\
    \ *this;\n    }\n    constexpr ModInt& operator-=(const ModInt rhs) noexcept {\n\
    \        if (rhs._v > _v) _v += mod;\n        _v -= rhs._v;\n        return *this;\n\
    \    }\n    constexpr ModInt& operator*=(const ModInt rhs) noexcept {\n      \
    \  u64 z = _v;\n        z *= rhs._v;\n        _v = (u32)(z % mod);\n        return\
    \ *this;\n    }\n    constexpr ModInt& operator/=(const ModInt rhs) noexcept {\
    \ return *this = *this * rhs.inv(); }\n\n    constexpr ModInt operator+() const\
    \ noexcept { return *this; }\n    constexpr ModInt operator-() const noexcept\
    \ { return ModInt() - *this; }\n    constexpr ModInt& operator++() noexcept {\n\
    \        _v++;\n        if (_v == mod) _v = 0;\n        return *this;\n    }\n\
    \    constexpr ModInt& operator--() noexcept {\n        if (_v == 0) _v = mod;\n\
    \        --_v;\n        return *this;\n    }\n    constexpr ModInt operator++(i32)\
    \ noexcept {\n        ModInt res = *this;\n        ++*this;\n        return res;\n\
    \    }\n    constexpr ModInt operator--(i32) noexcept {\n        ModInt res =\
    \ *this;\n        --*this;\n        return res;\n    }\n\n    friend constexpr\
    \ ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\n    friend constexpr ModInt operator-(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend constexpr ModInt operator*(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n  \
    \  friend constexpr ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n    friend constexpr bool operator==(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return lhs._v == rhs._v; }\n    friend constexpr\
    \ bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs._v\
    \ != rhs._v; }\n\n    friend std::istream& operator>>(std::istream& is, ModInt&\
    \ m) noexcept { return is >> m._v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const ModInt& m) noexcept { return os << m._v; }\n};\nusing Mint = ModInt<MOD>;\n\
    using Mint7 = ModInt<MOD7>;\nusing Mint9 = ModInt<MOD9>;\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/constant.hpp\"\n#include \"../core/int_alias.hpp\"\
    \n#include \"../ntheory/prime.hpp\"\n/**\n * @file modint.hpp\n * @brief Modint\n\
    \ */\nnamespace bys {\n/**\n * @brief ModInt\n *\n * ac-library\u306Emodint\u3092\
    constexpr\u5316\u3057\u305F\u3082\u306E\n * See: https://atcoder.github.io/ac-library/document_ja/modint.html\n\
    \ *\n * @tparam Modulo \u6CD5\n */\ntemplate <u32 Modulo> class ModInt {\n   \
    \ u32 _v;\n\n  public:\n    static constexpr u32 mod = Modulo;\n    // static_assert(is_prime(mod),\
    \ \"Modulo need to be prime.\");\n    static_assert(mod < (std::numeric_limits<u32>::max()\
    \ >> 1), \"Modulo need to be <2^31.\");\n\n    constexpr ModInt() noexcept : _v(0)\
    \ {}\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>, std::nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T v) noexcept : _v(v % mod) {}\n    template\
    \ <class T, std::enable_if_t<std::is_signed_v<T>, std::nullptr_t> = nullptr>\n\
    \    constexpr ModInt(T v) noexcept : _v(floormod(v, mod)) {}\n\n    constexpr\
    \ ModInt pow(i64 n) const noexcept {\n        ModInt res = 1, p = *this;\n   \
    \     while (n) {\n            if (n & 1) res *= p;\n            p *= p;\n   \
    \         n >>= 1;\n        }\n        return res;\n    }\n    constexpr ModInt\
    \ inv() const noexcept {\n        if constexpr (is_prime(mod)) {\n           \
    \ return pow(mod - 2);\n        } else {\n            return inv_gcd(_v, mod).second;\n\
    \        }\n    }\n\n    constexpr ModInt& operator+=(const ModInt rhs) noexcept\
    \ {\n        _v += rhs._v;\n        if (_v >= mod) _v -= mod;\n        return\
    \ *this;\n    }\n    constexpr ModInt& operator-=(const ModInt rhs) noexcept {\n\
    \        if (rhs._v > _v) _v += mod;\n        _v -= rhs._v;\n        return *this;\n\
    \    }\n    constexpr ModInt& operator*=(const ModInt rhs) noexcept {\n      \
    \  u64 z = _v;\n        z *= rhs._v;\n        _v = (u32)(z % mod);\n        return\
    \ *this;\n    }\n    constexpr ModInt& operator/=(const ModInt rhs) noexcept {\
    \ return *this = *this * rhs.inv(); }\n\n    constexpr ModInt operator+() const\
    \ noexcept { return *this; }\n    constexpr ModInt operator-() const noexcept\
    \ { return ModInt() - *this; }\n    constexpr ModInt& operator++() noexcept {\n\
    \        _v++;\n        if (_v == mod) _v = 0;\n        return *this;\n    }\n\
    \    constexpr ModInt& operator--() noexcept {\n        if (_v == 0) _v = mod;\n\
    \        --_v;\n        return *this;\n    }\n    constexpr ModInt operator++(i32)\
    \ noexcept {\n        ModInt res = *this;\n        ++*this;\n        return res;\n\
    \    }\n    constexpr ModInt operator--(i32) noexcept {\n        ModInt res =\
    \ *this;\n        --*this;\n        return res;\n    }\n\n    friend constexpr\
    \ ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\n    friend constexpr ModInt operator-(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend constexpr ModInt operator*(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n  \
    \  friend constexpr ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n    friend constexpr bool operator==(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return lhs._v == rhs._v; }\n    friend constexpr\
    \ bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs._v\
    \ != rhs._v; }\n\n    friend std::istream& operator>>(std::istream& is, ModInt&\
    \ m) noexcept { return is >> m._v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const ModInt& m) noexcept { return os << m._v; }\n};\nusing Mint = ModInt<MOD>;\n\
    using Mint7 = ModInt<MOD7>;\nusing Mint9 = ModInt<MOD9>;\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/constant.hpp
  - byslib/core/int_alias.hpp
  - byslib/core/traits.hpp
  - byslib/ntheory/prime.hpp
  - byslib/ntheory/numeric.hpp
  - byslib/ntheory/bit.hpp
  isVerificationFile: false
  path: byslib/algebra/modint.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/algebra/modint.hpp
layout: document
redirect_from:
- /library/byslib/algebra/modint.hpp
- /library/byslib/algebra/modint.hpp.html
title: Modint
---
