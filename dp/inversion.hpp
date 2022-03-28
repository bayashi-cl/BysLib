#pragma once
#include "../data/binary_indexed_tree.hpp"
namespace bys {
long long inversion(const vector<int>& v) {
    int sz = *std::max_element(v.begin(), v.end()) + 1;
    BinaryIndexedTree<int> bit(sz);
    ll res = 0;
    for (auto e : v) {
        bit.add(e, 1);
        res += bit.sum(e + 1, sz);
    }
    return res;
}
}  // namespace bys
