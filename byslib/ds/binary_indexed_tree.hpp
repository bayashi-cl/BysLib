#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

#include "../algebra/monoid.hpp"
#include "../core/int_alias.hpp"
#include "../ntheory/bit.hpp"
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
template <class Abelian> struct BinaryIndexedTree {
    using T = typename Abelian::set_type;
    static_assert(Abelian::commutative);
    const i32 _n;
    std::vector<T> data;

    BinaryIndexedTree(i32 n) : _n(n), data(_n + 1, Abelian::identity) {}
    BinaryIndexedTree(const std::vector<T>& val) : _n(val.size()), data(_n + 1, Abelian::identity) {
        std::copy(val.begin(), val.end(), data.begin() + 1);
        for (i32 i = 1; i <= _n; i++) {
            if (i32 j = i + (i & -i); j <= _n) data[j] = Abelian::operation(data[j], data[i]);
        }
    }

    void point_append(i32 i, T val) {
        assert(0 <= i && i < _n);
        for (++i; i <= _n; i += i & -i) data[i] = Abelian::operation(data[i], val);
    }

    void set(i32 i, T val) {
        assert(0 <= i and i < _n);
        point_append(i, Abelian::operation(Abelian::inverse(fold(i, i + 1)), val));
    }
    T operator[](std::size_t i) const { return fold(i, i + 1); }

    T prefix_fold(i32 right) const {
        assert(0 <= right and right <= _n);
        T res = Abelian::identity;
        for (; right > 0; right -= right & -right) res = Abelian::operation(res, data[right]);
        return res;
    }
    T fold(i32 left, i32 right) const {
        if (left < right) {
            return Abelian::operation(Abelian::inverse(prefix_fold(left)), prefix_fold(right));
        } else {
            return Abelian::identity;
        }
    }
};

template <class T> struct BinaryIndexedTree<Add<T>> {
    const i32 _n;
    std::vector<T> data;

    BinaryIndexedTree(i32 n) : _n(n), data(_n + 1) {}
    BinaryIndexedTree(const std::vector<T>& val) : _n(val.size()), data(_n + 1) {
        std::copy(val.begin(), val.end(), data.begin() + 1);
        for (i32 i = 1; i <= _n; i++) {
            if (i32 j = i + (i & -i); j <= _n) data[j] += data[i];
        }
    }

    void point_append(i32 i, T val) {
        assert(0 <= i && i < _n);
        for (++i; i <= _n; i += i & -i) data[i] += val;
    }

    void set(i32 i, T val) {
        assert(0 <= i and i < _n);
        point_append(i, val - fold(i, i + 1));
    }
    T operator[](std::size_t i) const { return fold(i, i + 1); }

    T prefix_fold(i32 right) const {
        assert(0 <= right and right <= _n);
        T res = 0;
        for (; right > 0; right -= right & -right) res += data[right];
        return res;
    }
    T fold(i32 left, i32 right) const {
        return left < right ? prefix_fold(right) - prefix_fold(left) : 0;
    }

    //! @brief sum[0, r) >= xとなる最小のrを求める
    i32 bisect(T x) const {
        if (x <= 0) return 0;
        if (x > prefix_fold(_n)) return -1;
        i32 res = 0;
        for (i32 w = bit_floor(_n); w > 0; w >>= 1) {
            if (res + w < _n && data[res + w] < x) {
                x -= data[res + w];
                res += w;
            }
        }
        return res + 1;
    }
};

template <class T> using FenwickTree = BinaryIndexedTree<Add<T>>;
template <class T> BinaryIndexedTree<Add<T>> fenwick_tree(const std::vector<T>& val) {
    return BinaryIndexedTree<Add<T>>(val);
}
}  // namespace bys
