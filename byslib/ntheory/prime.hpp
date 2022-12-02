#pragma once
#include <array>
#include <vector>

#include "../core/int_alias.hpp"
#include "numeric.hpp"
/**
 * @file prime.hpp
 * @brief Prime
 */
namespace bys {
/**
 * @brief 素因数分解
 *
 * 試し割り法
 * O(√n)
 */
template <typename T> std::vector<T> prime_factorize(T n) {
    std::vector<T> res;
    while (n % 2 == 0) {
        res.push_back(2);
        n /= 2;
    }
    T f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            res.push_back(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}

namespace impl {
template <std::size_t N> constexpr bool miller_rabin(i64 n, std::array<i64, N> bases) {
    auto d = n - 1;
    while (d % 2 == 0) d >>= 1;
    for (auto b : bases) {
        if (n <= b) break;
        auto t = d;
        i128 y = mod_pow(b, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
}  // namespace impl
/**
 * @brief Miller-Rabin素数判定
 *
 * 2^64以下なら正確に判定できる
 * See: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
 * See: https://miller-rabin.appspot.com
 *
 * @note c++20でconstexpr関数内でもvectorが使えるように
 */
constexpr bool is_prime(i64 n) {
    if (not(n & 1)) return n == 2;
    if (n <= 1) return false;
    if (n <= std::numeric_limits<i32>::max()) {
        std::array<i64, 3> bases = {2, 7, 61};
        return impl::miller_rabin(n, bases);
    } else {
        std::array<i64, 7> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        return impl::miller_rabin(n, bases);
    }
}
}  // namespace bys
