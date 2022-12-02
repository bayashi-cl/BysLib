#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
#include <vector>
#include "../core/int_alias.hpp"
/**
 * @file osa_k.hpp
 * @brief Osa-k
 */
namespace bys {
/**
 * @brief osa_k法
 *
 * 素因数分解もできる
 * See: https://osak.jp/diary/diary_201310.html#20131017
 * See: https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
 *
 */
struct Osa_K {
    i32 mx;
    std::vector<i32> spf;  // smallest prime factor
    Osa_K(i32 n) : mx(n), spf(n + 1) {
        std::iota(spf.begin(), spf.end(), 0);
        sieve();
    }

    void sieve() {
        for (i32 i = 2; i <= mx; i += 2) spf[i] = 2;
        for (i32 p = 3; p * p <= mx; p += 2) {
            if (spf[p] != p) continue;
            for (i32 k = p * p; k <= mx; k += p) {
                if (spf[k] == k) spf[k] = p;
            }
        }
    }
    bool is_prime(i32 n) const {
        assert(n <= mx);
        if (n <= 1) return false;
        return spf[n] == n;
    }
    std::map<i32, i32> factorize(i32 n) const {
        assert(n <= mx);
        std::map<i32, i32> res;
        while (n > 1) {
            res[spf[n]]++;
            n /= spf[n];
        }
        return res;
    }
    std::vector<i32> divisor(i32 n) const {
        std::vector<i32> res;
        std::map<i32, i32> factor_ = factorize(n);
        std::vector<std::pair<i32, i32>> factor(factor_.begin(), factor_.end());
        i32 k = factor.size();
        auto dfs = [&](auto dfs, i32 depth, i32 prod) {
            if (depth == k) {
                res.push_back(prod);
                return;
            }
            auto [p, q] = factor[depth];
            for (i32 i = 0; i <= q; ++i) {
                dfs(dfs, depth + 1, prod);
                prod *= p;
            }
        };
        dfs(dfs, 0, 1);
        std::sort(res.begin(), res.end());
        return res;
    }
};
}  // namespace bys
