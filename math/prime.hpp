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
bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    std::array<ll, 7> prime = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll s = 0, d = n - 1;
    while (d % 2 == 0) {
        ++s;
        d >>= 1;
    }
    for (auto p : prime) {
        if (p % n == 0) return true;
        ll t, x = mod_pow<__int128_t>(p, d, n);
        if (x != 1) {
            for (t = 0; t < s; ++t) {
                if (x == n - 1) break;
                x = __int128_t(x) * x % n;
            }
            if (t == s) return false;
        }
    }
    return true;
}
}  // namespace bys
