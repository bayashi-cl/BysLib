#pragma once
/**
 * @file change.hpp
 * @brief chmin/chmax
 */
namespace bys {
/**
 * @brief 最大値で更新
 * @return true 更新されたとき
 */
template <class T> constexpr bool chmax(T& a, T const& b) { return a < b ? a = b, true : false; }
/**
 * @brief 最小値で更新
 * @return true 更新されたとき
 */
template <class T> constexpr bool chmin(T& a, T const& b) { return a > b ? a = b, true : false; }
}  // namespace bys
