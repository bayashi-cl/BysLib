#pragma once
#include <algorithm>
#include <vector>

#include "../core/int_alias.hpp"
#include "../core/traits.hpp"
namespace bys {
/**
 * @brief 最長増加部分列
 *
 * @tparam Iterable
 * @param v
 * @param strict 狭義単調増加 or 広義単調増加
 * @return std::vector<i32> 部分列を構成するインデックス
 */
template <class Iterable> auto lis(const Iterable& v, bool strict = true) {
    static_assert(is_iterable_v<Iterable>, "v is not iterable");
    using T = typename Iterable::value_type;
    auto n = v.size();

    std::vector<T> dp;
    std::vector<i32> restore(n);
    for (i32 i = 0; i < n; ++i) {
        auto vi = v[i];
        auto itr = strict ? std::lower_bound(dp.begin(), dp.end(), vi) : std::upper_bound(dp.begin(), dp.end(), vi);
        restore[i] = itr - dp.begin();
        if (itr == dp.end()) {
            dp.push_back(vi);
        } else {
            *itr = vi;
        }
    }
    i32 idx = dp.size() - 1;
    std::vector<i32> res(dp.size());
    for (i32 i = n - 1; i >= 0; --i) {
        if (restore[i] == idx) res[idx--] = i;
    }
    return res;
}
}  // namespace bys
