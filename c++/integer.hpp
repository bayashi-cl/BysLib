#pragma once

#include "bys.hpp"

namespace bys {

ll int_pow(int a, int b) {
    ll res = 1;
    for (int i = 0; i < b; ++i) res *= a;
    return res;
}

template <typename T>
vector<T> make_divisor(T n) {
    vector<T> lower, upper;
    int i = 1;

    while (i * i <= n) {
        if (n % i == 0) {
            lower.push_back(i);
            if (i != n / i) upper.push_back(n / i);
        }
        ++i;
    }
    std::reverse(std::begin(upper), std::end(upper));
    std::copy(std::begin(upper), std::end(upper), std::back_inserter(lower));

    return lower;
}

struct MultiComb {
    int _n;
    int mod;
    vector<ll> fact, factinv, inv;

    MultiComb(int n, int mod = MOD) : _n(n), mod(mod) {
        fact.resize(_n + 1);
        factinv.resize(_n + 1);
        inv.resize(_n + 1);

        fact[0] = fact[1] = 1;
        factinv[0] = factinv[1] = 1;
        inv[1] = 1;

        for (int i = 2; i <= _n; i++) {
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            factinv[i] = factinv[i - 1] * inv[i] % mod;
        }
    }

    ll comb(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact[n] * (factinv[r] * factinv[n - r] % mod) % mod;
    }
};

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

}  // namespace bys
