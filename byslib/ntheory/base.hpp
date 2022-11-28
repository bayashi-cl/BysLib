#pragma once
#include <algorithm>
#include <string>
#include <vector>

#include "../core/int_alias.hpp"
/**
 * @file base.hpp
 * @brief Base conversion
 *
 * 進数変換
 * 153(10) -> std::vector<i64>({3, 5, 1})
 *
 * @todo クラス化
 */
namespace bys {
//! @brief 10進数 -> n進数
template <class T> std::vector<T> deci2n(T deci, T base) {
    std::vector<T> res;
    while (deci > 0) {
        res.push_back(deci % base);
        deci /= base;
    }
    return res;
}
//! @brief n進数 -> 10進数
i64 n2deci(std::vector<i64> n, i32 base) {
    i64 b = 1;
    i64 res = 0;
    for (auto&& d : n) {
        res += d * b;
        b *= base;
    }
    return res;
}
std::vector<i64> strbase(std::string n) {
    std::vector<i64> res;
    std::for_each(n.rbegin(), n.rend(), [&](char d) { res.push_back(d - '0'); });
    return res;
}
}  // namespace bys
