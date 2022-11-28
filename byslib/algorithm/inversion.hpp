#pragma once
#include <algorithm>
#include <vector>

#include "../algorithm/compress.hpp"
#include "../core/int_alias.hpp"
#include "../ds/binary_indexed_tree.hpp"

namespace bys {
template <class T> i64 inversion(const std::vector<T>& v) {
    Compress<T> cp(v);
    std::vector<i32> cp_v;
    cp_v.reserve(v.size());
    std::transform(v.begin(), v.end(), std::back_inserter(cp_v),
                   [&](const T& e) { return cp.get(e); });
    auto sz = cp.size();
    FenwickTree<i32> bit(sz);
    i64 res = 0;
    for (auto e : cp_v) {
        bit.point_append(e, 1);
        res += bit.fold(e + 1, sz);
    }
    return res;
}
}  // namespace bys
