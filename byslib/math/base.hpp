#pragma once
#include "../core/stdlib.hpp"
/**
 * @file base.hpp
 * @brief Base conversion
 *
 * 進数変換
 * 153(10) -> std::vector<ll>({3, 5, 1})
 *
 * @todo クラス化
 */
namespace bys {
//! @brief 10進数 -> n進数
template <class T>
std::vector<T> deci2n(T deci, T base) {
    std::vector<T> res;
    while (deci > 0) {
        res.push_back(deci % base);
        deci /= base;
    }
    return res;
}
//! @brief n進数 -> 10進数
ll n2deci(std::vector<ll> n, int base) {
    ll b = 1;
    ll res = 0;
    for (auto&& d : n) {
        res += d * b;
        b *= base;
    }
    return res;
}
std::vector<ll> strbase(string n) {
    std::vector<ll> res;
    std::for_each(n.rbegin(), n.rend(), [&](char d) { res.push_back(d - '0'); });
    return res;
}
}  // namespace bys
