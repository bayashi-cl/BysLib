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
std::vector<std::string> split(std::string s, char delim) {
    std::vector<std::string> res;
    s.push_back(delim);
    auto n = s.length();
    std::size_t crr_left = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (s[i] == delim) {
            res.emplace_back(s.substr(crr_left, i - crr_left));
        }
        crr_left = i + 1;
    }
    return res;
}
}  // namespace bys
