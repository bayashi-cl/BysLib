#pragma once
#include "../core/stdlib.hpp"
/**
 * @file transformed.hpp
 * @author bayashi_cl
 * @brief Transformed
 */
namespace bys {
//! @brief vecotrの変換
template <class T, class Lambda, typename R = std::invoke_result_t<std::decay_t<Lambda>, T>>
std::vector<R> transformed(const std::vector<T>& vec, Lambda f) {
    std::vector<R> res;
    std::transform(vec.begin(), vec.end(), std::back_inserter(res), f);
    return res;
}
}  // namespace bys
