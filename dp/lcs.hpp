#pragma once
#include "byslib/core/stdlib.hpp"
#include "byslib/core/types.hpp"
#include "byslib/utility/enumerate.hpp"

namespace bys {
template <class Iterable>
int lcs(Iterable const& a, Iterable const& b) {
    static_assert(is_iterable_v<Iterable>, "not iertable");
    auto n = a.size();
    auto m = b.size();
    std::vector dp(n + 1, std::vector<int>(m + 1));
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
