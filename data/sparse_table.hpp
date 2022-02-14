#pragma once
#include "../core/stdlib.hpp"
namespace bys {
template <class A>
class SparseTable {
    using T = typename A::value_type;
    int n;
    std::vector<int> lookup;
    std::vector<std::vector<T>> table;

   public:
    SparseTable() {}
    SparseTable(const std::vector<T>& v) { build(v); }

    void build(const std::vector<T>& v) {
        n = v.size();
        lookup.resize(n + 1);

        for (int i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;
        int max_k = lookup.back();
        table.assign(max_k + 1, std::vector<T>(n));
        std::copy(v.begin(), v.end(), table[0].begin());
        for (int i = 1; i <= max_k; ++i) {
            for (int j = 0; j <= n - (1 << i); ++j) {
                table[i][j] = A::op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        int w = r - l;
        return A::op(table[lookup[w]][l], table[lookup[w]][r - (1 << lookup[w])]);
    }
};
}  // namespace bys
