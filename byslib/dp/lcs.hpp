#pragma once
#include <algorithm>
#include <vector>

#include "../core/alias.hpp"
#include "../core/traits.hpp"
#include "../utility/enumerate.hpp"

namespace bys {
template <class Iterable> i32 lcs(Iterable const& a, Iterable const& b) {
    static_assert(is_iterable_v<Iterable>, "not iertable");
    i32 n = a.size();
    i32 m = b.size();
    std::vector dp(n + 1, std::vector<i32>(m + 1));
    for (auto [i, ai] : cenumerate(a)) {
        for (auto [j, bj] : cenumerate(b)) {
            if (ai == bj) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[n][m];
}
}  // namespace bys
