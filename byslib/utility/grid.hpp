#pragma once
#include <cassert>
#include <utility>
#include <vector>
/**
 * @file grid.hpp
 * @brief Grid Manager
 */
namespace bys {
//! @brief グリッド探索補助ツール詰め合わせ
struct Grid {
    int h, w;
    //! @brief row*colのグリッド
    Grid(int row, int col) : h(row), w(col) {}

    //! @brief グリッドに含まれるか判定
    bool contain(int row, int col) const { return 0 <= row && row < h && 0 <= col && col < w; }
    //! @brief グリッドの面積
    int area() const { return h * w; }
    //! @brief 一次元化したときのインデックス
    int index(int row, int col) const {
        assert(contain(row, col));
        return row * w + col;
    }
    int index(std::pair<int, int> p) const { return index(p.first, p.second); }
    //! @brief インデックスから復元
    std::pair<int, int> coord(int idx) const {
        assert(0 <= idx && idx < area());
        return {idx / w, idx % w};
    }
    //! 周囲のマスのうちグリッドに含まれるもの
    auto next(int row, int col, const std::vector<std::pair<int, int>>& delta) const {
        assert(contain(row, col));
        std::vector<std::pair<int, int>> res;
        for (auto [di, dj] : delta) {
            int ni = row + di;
            int nj = col + dj;
            if (contain(ni, nj)) res.push_back({ni, nj});
        }
        return res;
    }
    //! @brief 右・下
    auto next2(int row, int col) const { return next(row, col, {{1, 0}, {0, 1}}); }
    //! @brief 上下左右
    auto next4(int row, int col) const { return next(row, col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }
    //! @brief 8方向
    auto next8(int row, int col) const {
        std::vector<std::pair<int, int>> delta;
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
