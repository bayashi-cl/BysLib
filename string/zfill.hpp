#pragma once
#include "../core/stdlib.hpp"

namespace bys {
template <class T>
std::string zfill(const T& n, const int width, char fill = '0') {
    std::stringstream ss;
    ss << std::setw(width) << std::setfill(fill) << n;
    return ss.str();
}
}  // namespace bys
