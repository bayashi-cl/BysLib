#pragma once
#include "../core/const.hpp"
#include "../core/stdlib.hpp"
/**
 * @file combination.hpp
 * @author bayashi_cl
 * @brief Binomial Coefficient
 */
namespace bys {
/**
 * @brief 複数クエリ二項係数
 *
 * 前処理 O(n)
 * クエリ O(1)
 * See: https://drken1215.hatenablog.com/entry/2018/06/08/210000
 */
struct MultiComb {
    int _n;
    int mod;
    std::vector<ll> fact, factinv, inv;

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
    ll hom(int n, int r) {
        if (n == 0 && r == 0) return 1;
        return comb(n + r - 1, r);
    }
};

/**
 * @brief nCr
 *
 * O(min(n, (n - r)))
 *
 * @param n Modintも渡せる
 */
template <class T>
constexpr T comb(T n, int r) {
    T num = 1, den = 1;
    for (int i = 0; i < r; ++i) {
        num *= n - i;
        den *= i + 1;
    }
    return num / den;
}
}  // namespace bys
