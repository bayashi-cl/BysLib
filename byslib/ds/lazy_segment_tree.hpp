#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

#include "../algebra/mapping.hpp"
#include "../core/int_alias.hpp"
#include "../ntheory/bit.hpp"
/**
 * @file lazy_segment_tree.hpp
 * @brief Lazy Segment Tree
 */
namespace bys {
/**
 * @brief 遅延伝播セグメント木
 *
 * 区間更新: O(logN)
 * 区間クエリ: O(logN)
 * 一点取得: O(logN)
 * See:
 * https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree/lazy_segment_tree
 *
 * @tparam Monoid モノイド
 * @tparam ActMonoid 作用素モノイド
 * @tparam Action 作用関数オブジェクト 区間の幅も渡される
 * @todo 二分探索: O(logN)
 */
template <class Monoid, class ActMonoid, class Action = Mapping<Monoid, ActMonoid>> class LazySegmentTree {
    using value_type = typename Monoid::set_type;
    using act_type = typename ActMonoid::set_type;
    i32 _n, n_leaf, logsize;
    std::vector<act_type> lazy;
    std::vector<value_type> data;

    void reload(i32 p) { data[p] = Monoid::operation(data[p * 2], data[p * 2 + 1]); }
    void push(const i32 p) {
        i32 w = n_leaf >> bit_width(p);
        apply_segment(p * 2, lazy[p], w);
        apply_segment(p * 2 + 1, lazy[p], w);
        lazy[p] = ActMonoid::identity;
    }
    void apply_segment(const i32 p, act_type f, i32 w) {
        Action::mapping(data[p], f, w);
        if (p < n_leaf) lazy[p] = ActMonoid::operation(lazy[p], f);
    }

  public:
    LazySegmentTree(i32 n)
        : _n(n),
          n_leaf(bit_ceil(_n)),
          logsize(bit_width(_n - 1)),
          lazy(n_leaf, ActMonoid::identity),
          data(n_leaf * 2, Monoid::identity) {}
    LazySegmentTree(i32 n, value_type init)
        : _n(n),
          n_leaf(bit_ceil(_n)),
          logsize(bit_width(_n - 1)),
          lazy(n_leaf, ActMonoid::identity),
          data(n_leaf * 2, Monoid::identity) {
        std::fill_n(data.begin() + n_leaf, _n, init);
        for (i32 i = n_leaf - 1; i > 0; --i) {
            data[i] = Monoid::operation(data[i * 2], data[i * 2 + 1]);
        }
    }
    LazySegmentTree(std::vector<value_type> v)
        : _n(v.size()),
          n_leaf(bit_ceil(_n)),
          logsize(bit_width(_n - 1)),
          lazy(n_leaf, ActMonoid::identity),
          data(n_leaf * 2, Monoid::identity) {
        std::copy(v.begin(), v.end(), data.begin() + n_leaf);
        for (i32 i = n_leaf - 1; i > 0; --i) {
            data[i] = Monoid::operation(data[i * 2], data[i * 2 + 1]);
        }
    }
    value_type operator[](i32 p) {
        assert(0 <= p && p < _n);
        p += n_leaf;
        for (i32 i = logsize; i > 0; --i) push(p >> i);
        return data[p];
    }
    void update(i32 p, const value_type& x) {
        assert(0 <= p && p < _n);
        p += n_leaf;
        for (i32 i = logsize; i > 0; --i) push(p >> i);
        data[p] = x;
        for (i32 i = 1; i <= logsize; ++i) reload(p >> i);
    }
    value_type query(i32 l, i32 r) {
        assert(0 <= l);
        assert(l <= r);
        assert(r <= _n);
        if (l == r) return Monoid::identity;

        l += n_leaf;
        r += n_leaf;

        for (i32 i = logsize; i > 0; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        value_type left = Monoid::identity, right = Monoid::identity;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left = Monoid::operation(left, data[l++]);
            if (r & 1) right = Monoid::operation(data[--r], right);
        }
        return Monoid::operation(left, right);
    }

    value_type query_all() { return data[1]; }
    void apply(i32 i, act_type f) { apply(i, i + 1, f); }

    void apply(i32 l, i32 r, act_type f) {
        assert(0 <= l);
        assert(l <= r);
        assert(r <= _n);
        if (l == r) return;
        l += n_leaf;
        r += n_leaf;

        for (i32 i = logsize; i > 0; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        i32 l2 = l, r2 = r;
        i32 w = 1;
        while (l2 < r2) {
            if (l2 & 1) apply_segment(l2++, f, w);
            if (r2 & 1) apply_segment(--r2, f, w);
            l2 >>= 1;
            r2 >>= 1;
            w <<= 1;
        }

        for (i32 i = 1; i <= logsize; i++) {
            if (((l >> i) << i) != l) reload(l >> i);
            if (((r >> i) << i) != r) reload((r - 1) >> i);
        }
    }
};
}  // namespace bys
