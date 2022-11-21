#pragma once
#include "../data/binary_indexed_tree.hpp"
#include "../utility/compress.hpp"

namespace bys {
template <class T>
long long inversion(const vector<T>& v) {
    Compress<T> cp(v);
    vector<int> cp_v(v.size());
    std::transform(v.begin(), v.end(), cp_v.begin(), [&](const T& e) { return cp.get(e); });
    auto sz = cp.size();
    FenwickTree<int> bit(sz);
    ll res = 0;
    for (auto e : cp_v) {
        bit.point_append(e, 1);
        res += bit.fold(e + 1, sz);
    }
    return res;
}
}  // namespace bys
