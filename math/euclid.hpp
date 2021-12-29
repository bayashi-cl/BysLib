#pragma once
#include "byslib/core/stdlib.hpp"

namespace bys {
array<int, 3> ext_gcd(int a, int b) {
    if (b == 0) return {a, 1, 0};
    auto [d, y, x] = ext_gcd(b, a % b);
    y -= (a / b) * x;
    return {d, x, y};
}
}  // namespace bys
