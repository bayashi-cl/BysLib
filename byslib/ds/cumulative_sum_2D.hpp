#pragma once
#include <cassert>
#include <vector>
#include "../core/int_alias.hpp"
#include "../io/io.hpp"

namespace bys {
template <class T> class CumulativeSum2D {
    std::vector<std::vector<T>> data;

    void build() {
        i32 n = data.size();
        i32 m = data[0].size();
        for (i32 i = 1; i < n; ++i) {
            for (i32 j = 1; j < m; ++j) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }

  public:
    CumulativeSum2D(std::vector<std::vector<T>> const& v) : data(v.size() + 1, std::vector<T>(v[0].size() + 1)) {
        i32 n = v.size();
        for (i32 i = 0; i < n; ++i) {
            std::copy(v[i].begin(), v[i].end(), std::next(data[i + 1].begin()));
        }
        build();
    };

    T prefix_fold(i32 i, i32 j) const { return data[i][j]; }

    // [si, gi), [sj, gj)
    T fold(i32 si, i32 sj, i32 gi, i32 gj) const {
        return prefix_fold(gi, gj) - prefix_fold(si, gj) - prefix_fold(gi, sj) + prefix_fold(si, sj);
    }
    T fold_close(i32 si, i32 sj, i32 gi, i32 gj) { return fold(si, sj, gi + 1, gj + 1); }
};
}  // namespace bys
