#pragma once
#include "../core/stdlib.hpp"
#include "../math/bit.hpp"
/**
 * @file binary_indexed_tree.hpp
 * @author bayashi_cl
 * @brief Binary Indexed Tree
 */
namespace bys {
/**
 * @brief Binary Indexed Tree
 *
 * 一点更新: O(logN)
 * 区間和: O(logN)
 * See: https://algo-logic.info/binary-indexed-tree/
 */
template <class T>
class BinaryIndexedTree {
    const int _n;
    std::vector<T> data;

   public:
    BinaryIndexedTree() : _n(0) {}
    BinaryIndexedTree(int n) : _n(n), data(n + 1) {}
    BinaryIndexedTree(const std::vector<T>& v) : _n(v.size()), data(_n + 1) {
        for (int i = 0; i < _n; ++i) add(i, v[i]);
    }

    void add(int i, T x) {
        assert(0 <= i && i < _n);
        ++i;
        while (i <= _n) {
            data[i] += x;
            i += i & -i;
        }
    }
    T sum(int r) {
        assert(0 <= r && r <= _n);
        T res = 0;
        while (r > 0) {
            res += data[r];
            r -= r & -r;
        }
        return res;
    }
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

    //! @brief O(log N)
    T get(int i) {
        assert(0 <= i && i < _n);
        return sum(i, i + 1);
    }

    //! @brief sum[0, r) >= xとなる最小のrを求める
    int bisect(T x) {
        if (x <= 0) return 0;
        if (x > sum(_n)) return -1;
        int res = 0;
        for (int w = bit_floor(_n); w > 0; w >>= 1) {
            if (res + w < _n && data[res + w] < x) {
                x -= data[res + w];
                res += w;
            }
        }
        return res + 1;
    }
};
}  // namespace bys
