#pragma once
#include "byslib/core/stdlib.hpp"

namespace bys {
//! @brief グリッド探索管理
struct Grid {
    int h, w;
    Grid(int row, int col) : h(row), w(col) {}

    bool contain(int row, int col) const { return 0 <= row && row < h && 0 <= col && col < w; }
    int area() const { return h * w; }
    int index(int row, int col) const {
        assert(contain(row, col));
        return row * w + col;
    }
    pair<int, int> coord(int idx) const {
        assert(0 <= idx && idx < area());
        return {idx / w, idx % w};
    }
    vector<pair<int, int>> next(int row, int col, const vector<pair<int, int>> delta) const {
        assert(contain(row, col));
        vector<pair<int, int>> res;
        for (auto [di, dj] : delta) {
            int ni = row + di;
            int nj = col + dj;
            if (contain(ni, nj)) res.push_back({ni, nj});
        }
        return res;
    }
    //! @brief 右・下
    vector<pair<int, int>> next2(int row, int col) const { return next(row, col, {{1, 0}, {0, 1}}); }
    //! @brief 上下左右
    vector<pair<int, int>> next4(int row, int col) const { return next(row, col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }
    //! @brief 8方向
    vector<pair<int, int>> next8(int row, int col) const {
        vector<pair<int, int>> delta;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (di == 0 && dj == 0) continue;
                delta.push_back({di, dj});
            }
        }
        return next(row, col, delta);
    }
};
}  // namespace bys
