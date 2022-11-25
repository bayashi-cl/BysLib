#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../core/alias.hpp"
/**
 * @file grid.hpp
 * @brief Grid Manager
 */
namespace bys {
//! @brief グリッド探索補助ツール詰め合わせ
struct Grid {
    i32 h, w;
    //! @brief row*colのグリッド
    Grid(i32 row, i32 col) : h(row), w(col) {}

    //! @brief グリッドに含まれるか判定
    bool contain(i32 row, i32 col) const { return 0 <= row && row < h && 0 <= col && col < w; }
    //! @brief グリッドの面積
    i32 area() const { return h * w; }
    //! @brief 一次元化したときのインデックス
    i32 index(i32 row, i32 col) const {
        assert(contain(row, col));
        return row * w + col;
    }
    i32 index(std::pair<i32, i32> p) const { return index(p.first, p.second); }
    //! @brief インデックスから復元
    std::pair<i32, i32> coord(i32 idx) const {
        assert(0 <= idx && idx < area());
        return {idx / w, idx % w};
    }
    //! 周囲のマスのうちグリッドに含まれるもの
    auto next(i32 row, i32 col, const std::vector<std::pair<i32, i32>>& delta) const {
        assert(contain(row, col));
        std::vector<std::pair<i32, i32>> res;
        for (auto [di, dj] : delta) {
            i32 ni = row + di;
            i32 nj = col + dj;
            if (contain(ni, nj)) res.push_back({ni, nj});
        }
        return res;
    }
    //! @brief 右・下
    auto next2(i32 row, i32 col) const { return next(row, col, {{1, 0}, {0, 1}}); }
    //! @brief 上下左右
    auto next4(i32 row, i32 col) const {
        return next(row, col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    }
    //! @brief 8方向
    auto next8(i32 row, i32 col) const {
        std::vector<std::pair<i32, i32>> delta;
        for (i32 di = -1; di <= 1; ++di) {
            for (i32 dj = -1; dj <= 1; ++dj) {
                if (di == 0 && dj == 0) continue;
                delta.push_back({di, dj});
            }
        }
        return next(row, col, delta);
    }
};
}  // namespace bys
