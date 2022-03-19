#pragma once
#include <vector>

#include "../math/bit.hpp"
#include "../monoid/mapping.hpp"
namespace bys {
template <class T, class ActMonoid, class Action = MappingToSet<T, ActMonoid>>
struct DualSegmentTree {
    int _n, n_leaf, logsize;
    std::vector<typename ActMonoid::set_type> lazy;
    std::vector<T> data;

    void push(int p) {
        for (int i = logsize; i > 0; --i) {
            int a = p >> i;
            if (lazy[a] == ActMonoid::identity) continue;
            if (a * 2 < n_leaf) {
                lazy[a * 2] = ActMonoid::operation(lazy[a * 2], lazy[a]);
                lazy[a * 2 + 1] = ActMonoid::operation(lazy[a * 2 + 1], lazy[a]);
            } else {
                int t = a * 2 - n_leaf;
                Action::mapping(data[t], lazy[a]);
                Action::mapping(data[t + 1], lazy[a]);
            }
            lazy[a] = ActMonoid::identity;
        }
    }

   public:
    DualSegmentTree(int n, T ident)
        : _n(n), n_leaf(bit_ceil(_n)), logsize(bit_width(n - 1)), lazy(n_leaf, ActMonoid::identity), data(n_leaf, ident) {}
    DualSegmentTree(const std::vector<T>& v)
        : _n(v.size()), n_leaf(bit_ceil(_n)), logsize(bit_width(_n - 1)), lazy(n_leaf, ActMonoid::identity), data(n_leaf) {
        std::copy(v.begin(), v.end(), data.begin());
    }

    T operator[](int i) const {
        T res = data[i];
        for (i = (i + n_leaf) >> 1; i > 0; i >>= 1) {
            Action::mapping(res, lazy[i]);
        }
        return res;
    }
    void update(int i, T val) {
        if constexpr (!ActMonoid::commutative) {
            push(i + n_leaf);
        }
        data[i] = val;
    }
    void apply(int l, int r, T val) {
        assert(l < r);
        l += n_leaf;
        r += n_leaf;
        if constexpr (!ActMonoid::commutative) {
            push(l);
            push(r - 1);
        }
        if (l & 1) Action::mapping(data[l++ - n_leaf], val);
        if (r & 1) Action::mapping(data[--r - n_leaf], val);
        for (l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                lazy[l] = ActMonoid::operation(lazy[l], val);
                ++l;
            }
            if (r & 1) {
                --r;
                lazy[r] = ActMonoid::operation(lazy[r], val);
            }
        }
    }
};
}  // namespace bys
