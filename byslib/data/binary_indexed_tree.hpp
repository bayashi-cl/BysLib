#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

#include "../algebra/monoid.hpp"
#include "../math/bit.hpp"
/**
 * @file binary_indexed_tree.hpp
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
template <class Abelian>
struct BinaryIndexedTree {
    using T = typename Abelian::set_type;
    static_assert(Abelian::commutative);
    const int _n;
    std::vector<T> data;

    BinaryIndexedTree(int n) : _n(n), data(_n + 1, Abelian::identity) {}
    BinaryIndexedTree(const std::vector<T>& val) : _n(val.size()), data(_n + 1, Abelian::identity) {
        std::copy(val.begin(), val.end(), data.begin() + 1);
        for (int i = 1; i <= _n; i++) {
            if (int j = i + (i & -i); j <= _n) data[j] = Abelian::operation(data[j], data[i]);
        }
    }

    void point_append(int i, T val) {
        assert(0 <= i && i < _n);
        for (++i; i <= _n; i += i & -i) data[i] = Abelian::operation(data[i], val);
    }

    void set(std::size_t i, T val) {
        assert(0 <= i and i < _n);
        point_append(i, Abelian::operation(Abelian::inverse(fold(i, i + 1)), val));
    }
    T operator[](std::size_t i) const { return fold(i, i + 1); }

    T prefix_fold(int right) const {
        assert(0 <= right and right <= _n);
        T res = Abelian::identity;
        for (; right > 0; right -= right & -right) res = Abelian::operation(res, data[right]);
        return res;
    }
    T fold(int left, int right) const {
        if (left < right) {
            return Abelian::operation(Abelian::inverse(prefix_fold(left)), prefix_fold(right));
        } else {
            return Abelian::identity;
        }
    }
};

template <class T>
struct BinaryIndexedTree<Add<T>> {
    const int _n;
    std::vector<T> data;

    BinaryIndexedTree(int n) : _n(n), data(_n + 1) {}
    BinaryIndexedTree(const std::vector<T>& val) : _n(val.size()), data(_n + 1) {
        std::copy(val.begin(), val.end(), data.begin() + 1);
        for (int i = 1; i <= _n; i++) {
            if (int j = i + (i & -i); j <= _n) data[j] += data[i];
        }
    }

    void point_append(int i, T val) {
        assert(0 <= i && i < _n);
        for (++i; i <= _n; i += i & -i) data[i] += val;
    }

    void set(std::size_t i, T val) {
        assert(0 <= i and i < _n);
        point_append(i, val - fold(i, i + 1));
    }
    T operator[](std::size_t i) const { return fold(i, i + 1); }

    T prefix_fold(int right) const {
        assert(0 <= right and right <= _n);
        T res = 0;
        for (; right > 0; right -= right & -right) res += data[right];
        return res;
    }
    T fold(int left, int right) const { return left < right ? prefix_fold(right) - prefix_fold(left) : 0; }

    //! @brief sum[0, r) >= xとなる最小のrを求める
    int bisect(T x) const {
        if (x <= 0) return 0;
        if (x > prefix_fold(_n)) return -1;
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

template <class T>
using FenwickTree = BinaryIndexedTree<Add<T>>;
template <class T>
BinaryIndexedTree<Add<T>> fenwick_tree(const std::vector<T>& val) {
    return BinaryIndexedTree<Add<T>>(val);
}
}  // namespace bys
