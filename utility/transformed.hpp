#pragma once
#include "../core/stdlib.hpp"
/**
 * @file transformed.hpp
 * @brief Transformed
 */
namespace bys {
//! @brief vecotrの変換
template <class T, class Lambda, typename R = std::invoke_result_t<std::decay_t<Lambda>, T>>
std::vector<R> transformed(const std::vector<T>& vec, Lambda f) {
    std::vector<R> res(vec.size());
    std::transform(vec.begin(), vec.end(), res.begin(), f);
    return res;
}
}  // namespace bys
