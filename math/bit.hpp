#pragma once
#include "../core/stdlib.hpp"

namespace bys {
template <class T>
int bit_width(T x) {
    int bits = 0;
    x = (x < 0) ? (-x) : x;
    for (; x != 0; bits++) x >>= 1;
    return bits;
}
template <class T>
T bit_floor(T x) {
    assert(x >= 0);
    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);
}
template <class T>
T bit_ceil(T x) {
    assert(x >= 0);
    return x == 0 ? 1 : T(1) << bit_width(x - 1);
}

string bin(ll n) {
    assert(n > 0);
    if (n == 0) return "0";
    string res;
    while (n > 0) {
        res.push_back(n & 1 ? '1' : '0');
        n >>= 1;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
inline bool pop(int s, int d) { return s & (1 << d); }
inline bool pop(ll s, int d) { return s & (1LL << d); }
}  // namespace bys
