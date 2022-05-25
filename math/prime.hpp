#pragma once
#include "../core/alias.hpp"
#include "../core/stdlib.hpp"
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
template <typename T>
std::vector<T> prime_factorize(T n) {
    vector<T> res;
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

/**
 * @brief Miller-Rabin素数判定
 *
 * 2^64以下なら正確に判定できる
 * See: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
 * See: https://miller-rabin.appspot.com
 */
constexpr bool is_prime(i16 n) {
    if (not(n & 1)) return n == 2;
    if (n <= 1) return false;
    auto d = n - 1;
    while (d % 2 == 0) d >>= 1;
    std::array<i16, 9> base = {2, 7, 61, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (auto b : base) {
        if (n <= b) break;
        auto t = d;
        auto y = mod_pow(b, t, n);
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
}  // namespace bys
