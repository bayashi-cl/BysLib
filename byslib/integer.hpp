#pragma once
#include "byslib/template/bys.hpp"

namespace bys {
constexpr ll int_pow(int a, int b) {
    ll res = 1;
    for (int i = 0; i < b; ++i) res *= a;
    return res;
}

template <typename T>
vector<T> make_divisor(T n) {
    vector<T> lower, upper;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            lower.push_back(i);
            if (T j = n / i; i != j) upper.push_back(j);
        }
    }
    std::copy(upper.rbegin(), upper.rend(), std::back_inserter(lower));
    return lower;
}

vector<vector<int>> eratosthenes_factorize(int n) {
    vector<vector<int>> res(n + 1);
    for (int i = 2; i <= n; i += 2) res[i].push_back(2);
    for (int p = 3; p <= n; p += 2) {
        if (!res[p].empty()) continue;
        for (int k = 1; p * k <= n; ++k) {
            res[p * k].push_back(p);
        }
    }
    return res;
}
struct Osa_K {
    int mx;
    vector<int> spf;  // smallest prime factor
    Osa_K(int n) : mx(n), spf(n + 1) {
        std::iota(spf.begin(), spf.end(), 0);
        sieve();
    }

    void sieve() {
        for (int i = 2; i <= mx; i += 2) spf[i] = 2;
        for (int p = 3; p * p <= mx; p += 2) {
            if (spf[p] != p) continue;
            for (int k = p * p; k <= mx; k += p) {
                if (spf[k] == k) spf[k] = p;
            }
        }
    }
    bool is_prime(int n) const {
        assert(n <= mx);
        if (n <= 1) return false;
        return spf[n] == n;
    }
    map<int, int> factorize(int n) const {
        assert(n <= mx);
        map<int, int> res;
        while (n > 1) {
            res[spf[n]]++;
            n /= spf[n];
        }
        return res;
    }
    vector<int> divisor(int n) const {
        vector<int> res;
        map<int, int> factor_ = factorize(n);
        vector<pair<int, int>> factor(factor_.begin(), factor_.end());
        int k = factor.size();
        auto dfs = [&](auto dfs, int depth, int prod) {
            if (depth == k) {
                res.push_back(prod);
                return;
            }
            auto [p, q] = factor[depth];
            for (int i = 0; i <= q; ++i) {
                dfs(dfs, depth + 1, prod);
                prod *= p;
            }
        };
        dfs(dfs, 0, 1);
        sort(res.begin(), res.end());
        return res;
    }
};

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
template <class T>
vector<T> deci2n(T deci, T base) {
    vector<T> res;
    while (deci > 0) {
        res.push_back(deci % base);
        deci /= base;
    }
    return res;
}
array<int, 3> ext_gcd(int a, int b) {
    if (b == 0) return {a, 1, 0};
    auto [d, y, x] = ext_gcd(b, a % b);
    y -= (a / b) * x;
    return {d, x, y};
}
}  // namespace bys
