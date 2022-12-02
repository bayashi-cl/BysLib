#pragma once
#include <string>
#include <vector>

#include "../core/int_alias.hpp"

namespace bys {
i32 count_substring(const std::string& s, i32 mod = 998244353) {
    i32 n = s.length();
    std::vector next_char_pos(n + 1, std::vector(26, n));
    for (i32 i = n - 1; i >= 0; --i) {
        for (i32 j = 0; j < 26; ++j) next_char_pos[i][j] = next_char_pos[i + 1][j];
        next_char_pos[i][s[i] - 'a'] = i;
    }
    std::vector<i32> dp(n + 1);
    dp[0] = 1;
    for (i32 i = 0; i < n; ++i) {
        for (i32 c = 0; c < 26; ++c) {
            if (auto p = next_char_pos[i][c]; p < n) {
                dp[p + 1] += dp[i];
                if (dp[p + 1] >= mod) dp[p + 1] -= mod;
            }
        }
    }
    i32 res = 0;
    for (i32 i = 0; i <= n; ++i) {
        res += dp[i];
        if (res >= mod) res -= mod;
    }
    return res;
}
}  // namespace bys
