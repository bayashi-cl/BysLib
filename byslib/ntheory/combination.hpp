#pragma once
#include <vector>

#include "../core/constant.hpp"
#include "../core/int_alias.hpp"
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
class MultiComb {
    i32 mod;
    std::vector<i32> fact, factinv, inv;

    void extend(i32 n) {
        if ((i32)fact.size() > n) return;
        fact.resize(n + 1);
        factinv.resize(n + 1);
        inv.resize(n + 1);
        for (i32 i = fact.size(); i <= n; ++i) {
            fact[i] = (i64)fact[i - 1] * i % mod;
            inv[i] = mod - (i64)inv[mod % i] * (mod / i) % mod;
            factinv[i] = (i64)factinv[i - 1] * inv[i] % mod;
        }
    }

  public:
    MultiComb(i32 n = 1, i32 mod = MOD) : mod(mod), fact({1, 1}), factinv({1, 1}), inv({0, 1}) { extend(n); }

    i32 fac(i32 n) {
        extend(n);
        return fact[n];
    }

    i32 comb(i32 n, i32 r) {
        if (r < 0 || n < r) return 0;
        extend(n);
        return (i64)fact[n] * ((i64)factinv[r] * factinv[n - r] % mod) % mod;
    }
    i32 perm(i32 n, i32 r) {
        if (r < 0 || n < r) return 0;
        extend(n);
        return (i64)fact[n] * factinv[n - r] % mod;
    }
    i32 hom(i32 n, i32 r) {
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
template <class T> constexpr T comb(T n, i32 r) {
    T num = 1, den = 1;
    for (i32 i = 0; i < r; ++i) {
        num *= n - i;
        den *= i + 1;
    }
    return num / den;
}
}  // namespace bys
