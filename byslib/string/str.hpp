#pragma once
/**
 * @file zfill.hpp
 * @brief Python::str
 *
 * Python再現シリーズ str編
 */
#include "../core/stdlib.hpp"
namespace bys {
/**
 * @brief str.zfill()
 * @param n 埋める対象
 * @param width 幅
 * @param fill 埋める文字
 */
template <class T>
std::string zfill(const T& n, const int width, char fill = '0') {
    std::stringstream ss;
    ss << std::setw(width) << std::setfill(fill) << n;
    return ss.str();
}
/**
 * @brief str.split()
 * @param s 分割する文字列
 * @param delim 区切り文字
 */
std::vector<std::string> split(const std::string& s, char delim = ' ') {
    std::vector<std::string> res;
    auto n = static_cast<int>(s.length());
    int left = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == delim) {
            if (i != left) {
                res.emplace_back(s.substr(left, i - left));
            }
            left = i + 1;
        }
    }
    if (left != n) res.emplace_back(s.substr(left, n - left));
    return res;
}
}  // namespace bys
