#pragma once
#include <utility>
#include <vector>

#include "../core/alias.hpp"
#include "../core/traits.hpp"

/**
 * @file run_length.hpp
 * @brief Run Length Encoding
 */
namespace bys {
//! @brief ランレングス圧縮
template <class Iterable>
auto run_length_encode(const Iterable& v) {
    static_assert(is_iterable_v<Iterable>, "arg is not iterable.");
    using T = typename Iterable::value_type;
    std::vector<std::pair<T, i32>> res;
    if (v.empty()) return res;
    res.emplace_back(v.front(), 0);
    for (auto&& e : v) {
        if (e == res.back().first) {
            res.back().second++;
        } else {
            res.emplace_back(e, 1);
        }
    }
    return res;
}
}  // namespace bys
