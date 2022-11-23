#pragma once
#include "../core/stdlib.hpp"
#include "../core/traits.hpp"
/**
 * @file transformed.hpp
 * @brief Transformed
 */
namespace bys {
//! @brief vecotrの変換
template <class Iterable, class Lambda>
auto transformed(Iterable const& itr, Lambda f) {
    static_assert(is_iterable_v<Iterable>, "itr is not iterable");
    std::vector<std::invoke_result_t<std::decay_t<Lambda>, typename Iterable::value_type>> res;
    std::transform(itr.begin(), itr.end(), std::back_inserter(res), f);
    return res;
}
}  // namespace bys
