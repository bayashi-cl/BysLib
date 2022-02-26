#pragma once
#include "../core/stdlib.hpp"
#include "../core/const.hpp"

namespace bys {
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
    ll perm(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact[n] * factinv[n - r] % mod;
    }
};

template <class T>
T comb(T n, int r) {
    T num = 1, den = 1;
    for (int i = 0; i < r; ++i) {
        num *= n - i;
        den *= i + 1;
    }
    return num / den;
}
}  // namespace bys
