#pragma once
#include "byslib/core/stdlib.hpp"

namespace bys {
template <class T>
vector<T> deci2n(T deci, T base) {
    vector<T> res;
    while (deci > 0) {
        res.push_back(deci % base);
        deci /= base;
    }
    return res;
}
ll n2deci(vector<int> n, int base);
}  // namespace bys
