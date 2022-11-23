#pragma once
#include <vector>

#include "../core/alias.hpp"
#include "../core/const.hpp"
/**
 * @file combination.hpp
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
    i32 _n;
    i32 mod;
    std::vector<i64> fact, factinv, inv;

    MultiComb(i32 n, i32 mod = MOD) : _n(n), mod(mod) {
        fact.resize(_n + 1);
        factinv.resize(_n + 1);
        inv.resize(_n + 1);

        fact[0] = fact[1] = 1;
        factinv[0] = factinv[1] = 1;
        inv[1] = 1;

        for (i32 i = 2; i <= _n; i++) {
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            factinv[i] = factinv[i - 1] * inv[i] % mod;
        }
    }

    i64 fac(i32 n) const { return fact[n]; }

    i64 comb(i32 n, i32 r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * (factinv[r] * factinv[n - r] % mod) % mod;
    }
    i64 perm(i32 n, i32 r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * factinv[n - r] % mod;
    }
    i64 hom(i32 n, i32 r) const {
        if (n == 0 && r == 0) return 1;
        return comb(n + r - 1, r);
    }
};

/**
 * @brief nCr
 *
 * O(min(n, (n - r)))
 *
 * @param n Modi32も渡せる
 */
template <class T> constexpr T comb(T n, i32 r) {
    T num = 1, den = 1;
    for (i32 i = 0; i < r; ++i) {
        num *= n - i;
        den *= i + 1;
    }
    return num / den;
}
}  // namespace bys
