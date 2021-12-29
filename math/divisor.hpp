#pragma once
#include "byslib/core/stdlib.hpp"

namespace bys {
template <typename T>
vector<T> make_divisor(T n) {
    vector<T> lower, upper;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            lower.push_back(i);
            if (T j = n / i; i != j) upper.push_back(j);
        }
    }
    std::copy(upper.rbegin(), upper.rend(), std::back_inserter(lower));
    return lower;
}
}  // namespace bys
