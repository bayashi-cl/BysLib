#pragma once
#include "../core/stdlib.hpp"

namespace bys {
template <class T>
std::string zfill(const T& n, const int width, char fill = '0') {
    std::stringstream ss;
    ss << std::setw(width) << std::setfill(fill) << n;
    return ss.str();
}
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
