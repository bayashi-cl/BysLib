#pragma once
#include "../core/stdlib.hpp"
#include "../core/types.hpp"
/**
 * @file run_length.hpp
 * @brief Run Length Encoding
 */
namespace bys {
//! @brief ランレングス圧縮
template <class Iterable, std::enable_if_t<has_iterator<Iterable>::value, std::nullptr_t> = nullptr>
auto run_length_encode(const Iterable& v) {
    using T = typename Iterable::value_type;
    std::vector<std::pair<T, int>> res;
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
