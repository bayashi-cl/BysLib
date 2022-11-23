#pragma once
#include <tuple>
/**
 * @file euclid.hpp
 * @brief Extended Euclidean Algorithm
 */
namespace bys {
/**
 * @brief 拡張ユークリッドの互除法
 *
 * ax + by = gcd(a, b) を満たす (x, y) を求める
 * See: https://qiita.com/drken/items/b97ff231e43bce50199a
 *
 * @return std::tuple<int, int, int> {d, x, y} s.t. ax + by = d
 */
template <class T>
std::tuple<T, T, T> ext_gcd(T a, T b) {
    if (b == 0) return {a, 1, T(0)};
    auto [d, y, x] = ext_gcd(b, a % b);
    y -= (a / b) * x;
    return {d, x, y};
}
}  // namespace bys
