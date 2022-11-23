#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
#include <vector>
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
 * @todo c++20でvectorもconstexpr化できるようになる
 */
struct Osa_K {
    int mx;
    std::vector<int> spf;  // smallest prime factor
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
    std::map<int, int> factorize(int n) const {
        assert(n <= mx);
        std::map<int, int> res;
        while (n > 1) {
            res[spf[n]]++;
            n /= spf[n];
        }
        return res;
    }
    std::vector<int> divisor(int n) const {
        std::vector<int> res;
        std::map<int, int> factor_ = factorize(n);
        std::vector<std::pair<int, int>> factor(factor_.begin(), factor_.end());
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
        std::sort(res.begin(), res.end());
        return res;
    }
};
}  // namespace bys
