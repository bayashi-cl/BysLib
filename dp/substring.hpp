#pragma once
#include <string>
#include <vector>
namespace bys {
int count_substring(const std::string& s, int mod = 998244353) {
    const int n = s.length();
    std::vector next_char_pos(n + 1, std::vector<int>(26, n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) next_char_pos[i][j] = next_char_pos[i + 1][j];
        next_char_pos[i][s[i] - 'a'] = i;
    }
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 26; ++c) {
            if (auto p = next_char_pos[i][c]; p < n) {
                dp[p + 1] += dp[i];
                if (dp[p + 1] >= mod) dp[p + 1] -= mod;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        res += dp[i];
        if (res >= mod) res -= mod;
    }
    return res;
}
}  // namespace bys
