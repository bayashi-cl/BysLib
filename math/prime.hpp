#pragma once
#include "../core/stdlib.hpp"
#include "numeric.hpp"
namespace bys {
template <typename T>
vector<T> prime_factorize(T n) {
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

//! @brief Miller-Rabin
constexpr bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d >>= 1;
    constexpr std::array<ll, 7> prime = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (long long p : prime) {
        long long t = d;
        long long y = mod_pow(p, t, n);
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
