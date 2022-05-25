#pragma once
#include "../core/stdlib.hpp"
#include "../math/bit.hpp"
/**
 * @file segment_tree.hpp
 * @brief Segment Tree
 */
namespace bys {
/**
 * @brief セグメント木
 *
 * 一点更新: O(logN)
 * 区間取得: O(logN)
 *
 * @tparam Monoid モノイド
 */
template <class Monoid>
class SegmentTree {
    using value_type = typename Monoid::set_type;
    int _n, n_leaf;
    std::vector<value_type> data;

   public:
    SegmentTree(int n) : _n(n), n_leaf(bit_ceil(n)), data(n_leaf * 2, Monoid::identity) {}
    SegmentTree(const vector<value_type>& v) : _n(v.size()), n_leaf(bit_ceil(_n)), data(n_leaf * 2, Monoid::identity) {
        std::copy(v.begin(), v.end(), data.begin() + n_leaf);
        for (int i = n_leaf - 1; i > 0; --i) data[i] = Monoid::operation(data[i * 2], data[i * 2 + 1]);
    }

    value_type query(int l, int r) const {
        assert(0 <= l && l <= _n);
        assert(l <= r);
        assert(r <= _n);

        value_type left = Monoid::identity, right = Monoid::identity;
        for (l += n_leaf, r += n_leaf; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left = Monoid::operation(left, data[l++]);
            if (r & 1) right = Monoid::operation(data[--r], right);
        }
        return Monoid::operation(left, right);
    }

    value_type query_all() const { return data[1]; }

    void update(int i, value_type val) {
        assert(0 <= i && i < _n);
        i += n_leaf;
        data[i] = val;
        for (i >>= 1; i > 0; i >>= 1) data[i] = Monoid::operation(data[i * 2], data[i * 2 + 1]);
    }

    value_type operator[](int i) const {
        assert(0 <= i && i < _n);
        return data[i + n_leaf];
    }

    // f(query(l, r)) == true となる最大のr
    template <class Lambda, class... Args>
    int bisect_from_left(int l, Lambda f, Args... args) const {
        static_assert(std::is_same_v<std::invoke_result_t<Lambda, value_type, Args...>, bool>,
                      "The function signature is invalid.");
        assert(0 <= l && l < _n);
        assert(f(Monoid::identity, args...));
        l += n_leaf;
        value_type sm = Monoid::identity;
        do {
            l /= l & -l;
            if (!f(Monoid::operation(sm, data[l]), args...)) {
                while (l < n_leaf) {
                    l *= 2;
                    if (value_type op = Monoid::operation(sm, data[l]); f(op, args...)) {
                        sm = op;
                        ++l;
                    }
                }
                return l - n_leaf;
            }
            sm = Monoid::operation(sm, data[l]);
            ++l;
        } while ((l & -l) != l);
        return _n;
    }

    // f(query(l, r)) == true となる最小のl
    template <class Lambda, class... Args>
    int bisect_from_right(int r, Lambda f, Args... args) const {
        static_assert(std::is_same_v<std::invoke_result_t<Lambda, value_type, Args...>, bool>,
                      "The function signature is invalid.");
        assert(0 <= r && r <= _n);
        assert(f(Monoid::identity, args...));
        if (r == 0) return 0;
        r += n_leaf;
        value_type sm = Monoid::identity;
        do {
            --r;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(Monoid::operation(data[r], sm))) {
                while (r < n_leaf) {
                    r = (2 * r + 1);
                    if (value_type op = Monoid::operation(data[r], sm); f(op, args...)) {
                        sm = op;
                        --r;
                    }
                }
                return r + 1 - n_leaf;
            }
            sm = op(data[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};
}  // namespace bys
