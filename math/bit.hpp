#pragma once
#include "../core/stdlib.hpp"

namespace bys {
int bit_length(ll x) {
    int bits = 0;
    x = (x < 0) ? (-x) : x;
    for (bits = 0; x != 0; bits++) x >>= 1;
    return bits;
}
ll bit_ceil(ll x) {
    if (x == 0) return 1;
    int w = bit_length(x - 1);
    return 1 << w;
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
