#pragma once
#include <array>
#include <numeric>
#include <vector>
/**
 * @file itertools.hpp
 * @brief Python::itertools
 *
 * Python再現シリーズ itertools編
 * See: https://docs.python.org/ja/3/library/itertools.html
 */
namespace bys {
/**
 * @brief itertools.conbination()
 *
 * 入力の要素からなる長さrの部分列を返す。
 */
template <class T> class Combinations {
    const std::vector<T> pool;
    int n, r;
    std::vector<T> comb;
    std::vector<int> indices;
    bool term = false;

  public:
    Combinations(const std::vector<T>& vec, int r)
        : pool(vec), n(vec.size()), r(r), comb(r), indices(r) {
        if (r > n) {
            term = true;
            return;
        }
        std::iota(indices.begin(), indices.end(), 0);
        for (int i = 0; i < r; ++i) comb[i] = pool[indices[i]];
    }
    Combinations<T> begin() const { return *this; }
    bool end() const { return true; }
    bool operator!=(bool) const { return !term; }
    void operator++() {
        bool flg = true;
        int i = r - 1;
        for (; i >= 0; --i) {
            if (indices[i] != i + n - r) {
                flg = false;
                break;
            }
        }
        if (flg) {
            term = true;
            return;
        }
        indices[i]++;
        for (int j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
        for (int k = 0; k < r; ++k) comb[k] = pool[indices[k]];
    }
    const std::vector<T>& operator*() const { return comb; }
};
/**
 * @brief itertools.combinations(range(n), r)
 *
 * [0, n) からR個を選ぶ組み合わせ全探索
 */
template <std::size_t R> class IndexCombinations {
    std::array<std::size_t, R> indices;
    std::size_t n, r;
    bool term = false;

  public:
    IndexCombinations(std::size_t n) : n(n), r(indices.size()) {
        if (r > n) {
            term = true;
            return;
        }
        std::iota(indices.begin(), indices.end(), 0);
    }
    IndexCombinations begin() const { return *this; }
    bool end() const { return true; }
    bool operator!=(bool) const { return !term; }
    void operator++() {
        bool flg = true;
        int i = r - 1;
        for (; i >= 0; --i) {
            if (indices[i] != i + n - r) {
                flg = false;
                break;
            }
        }
        if (flg) {
            term = true;
            return;
        }
        indices[i]++;
        for (std::size_t j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
    }
    const std::array<std::size_t, R>& operator*() const { return indices; }
};
}  // namespace bys
