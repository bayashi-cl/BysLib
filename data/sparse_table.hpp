#pragma once
#include "core/stdlib.hpp"

namespace bys {
template <class T>
struct SparseTable {
    int n;
    vector<int> lookup;
    vector<vector<T>> table;

    SparseTable(const vector<T>& v) : n(v.size()), lookup(n + 1) {
        for (int i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;
    }
};
}  // namespace bys
