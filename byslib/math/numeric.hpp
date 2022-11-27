#pragma once
#include "../core/alias.hpp"
#include "bit.hpp"
/**
 * @file numeric.hpp
 * @brief Numeric
 *
 * 数値計算詰め合わせ
 */
namespace bys {
//! @brief 整数の累乗
constexpr i64 int_pow(i32 a, i32 b) {
    i64 res = 1;
    for (i32 i = 0; i < b; ++i) res *= a;
    return res;
}
/**
 * @brief 繰り返し二乗法
 *
 * O(log q)
 */
constexpr i64 mod_pow(i64 p, i64 q, i64 mod) {
    if (mod == 1) return 0_i64;
    i128 res = 1;
    i128 b = p % mod;
    while (q) {
        if (q & 1) res = res * b % mod;
        b = b * b % mod;
        q >>= 1;
    }
    return (i64)res;
}
//! @brief ceil(x / y)
template <class T> constexpr T ceildiv(T x, T y) {
    if ((x < T(0)) ^ (y < T(0))) {
        return x / y;
    } else {
        return (x + y + (x < T(0) ? 1 : -1)) / y;
    }
}
//! @brief floor(x / y)
template <class T> constexpr T floordiv(T x, T y) {
    if ((x < T(0)) ^ (y < T(0))) {
        return (x - y + (x < T(0) ? 1 : -1)) / y;
    } else {
        return x / y;
    }
}
/**
 * @brief Python::divmod
 *
 * See: https://docs.python.org/ja/3/library/functions.html#divmod
 */
template <class T> constexpr std::pair<T, T> divmod(T x, T y) {
    auto q = floordiv(x, y);
    return {q, x - q * y};
}

/**
 * @brief Python::%
 *
 * See: https://docs.python.org/ja/3/reference/expressions.html#index-68
 */
template <class T, class S> constexpr T floormod(T x, S mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

constexpr i64 isqrt_aux(i64 c, i64 n) {
    if (c == 0) return 1;
    i64 k = (c - 1) / 2;
    i64 a = isqrt_aux(c / 2, n >> (2 * k + 2));
    return (a << k) + (n >> (k + 2)) / a;
}
/**
 * @brief Python::math.isqrt
 *
 * floor(sqrt(n))
 * See: https://docs.python.org/ja/3/library/math.html#math.isqrt
 */
template <class T> constexpr T isqrt(T n) {
    assert(n >= 0);
    if (n == T(0)) return T(0);
    i64 a = isqrt_aux((bit_width(n) - 1) / 2, n);
    return n < a * a ? a - 1 : a;
}
/**
 * @brief Nim::math::almostEqual
 *
 * See: https://nim-lang.org/docs/math.html#almostEqual,T,T,Natural
 */
template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
constexpr bool isclose(T x, T y, T coef = 4.0) {
    if (x == y) return true;
    auto diff = std::abs(x - y);
    return diff <= std::numeric_limits<T>::epsilon() * std::abs(x + y) * coef ||
           diff < std::numeric_limits<T>::min();
}

constexpr std::pair<i64, i64> inv_gcd(i64 a, i64 b) {
    a = floormod(a, b);
    if (a == 0) return {b, 0};
    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;

    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

//! @brief Count multipules of k in the [left, right)
template <class T> constexpr T range_multiples(T left, T right, T k) {
    return (right - 1) / k - (left - 1) / k;
}
template <class T> constexpr T multiple_floor(T x, T k) { return x / k * k; }
template <class T> constexpr T multiple_ceil(T x, T k) { return ceildiv(x, k) * k; }
}  // namespace bys
