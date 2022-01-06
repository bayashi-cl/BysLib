#pragma once
#include "../core/stdlib.hpp"

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
ll n2deci(vector<ll> n, int base) {
    ll b = 1;
    ll res = 0;
    for (auto&& d : n) {
        res += d * b;
        b *= base;
    }
    return res;
}
vector<ll> strbase(string n) {
    vector<ll> res;
    std::for_each(n.rbegin(), n.rend(), [&](char d) { res.push_back(d - '0'); });
    return res;
}
}  // namespace bys
