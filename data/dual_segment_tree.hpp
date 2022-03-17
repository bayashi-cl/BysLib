#pragma once
#include <vector>

#include "../math/bit.hpp"
namespace bys {
template <class T, class A>
class DualSegmentTree {
    using L = typename A::value_type;
    int _n, n_leaf, logsize;
    std::vector<L> lazy;
    std::vector<T> data;
    void push(int p) {
        for (int i = logsize; i > 0; --i) {
            int a = p >> i;
            if (lazy[a] == A::id) continue;
            if (a * 2 < n_leaf) {
                lazy[a * 2] = A::composition(lazy[a], lazy[a * 2]);
                lazy[a * 2 + 1] = A::composition(lazy[a], lazy[a * 2 + 1]);

            } else {
                int t = a * 2 - n_leaf;
                data[t] = A::mapping(lazy[a], data[t]);
                data[t + 1] = A::mapping(lazy[a], data[t + 1]);
            }
            lazy[a] = A::id;
        }
    }

   public:
    DualSegmentTree(int n, T ident)
        : _n(n), n_leaf(bit_ceil(_n)), logsize(bit_width(n - 1)), lazy(n_leaf, A::id), data(n_leaf, ident) {}
    DualSegmentTree(const std::vector<T>& v)
        : _n(v.size()), n_leaf(bit_ceil(_n)), logsize(bit_width(_n - 1)), lazy(n_leaf, A::id), data(n_leaf) {
        std::copy(v.begin(), v.end(), data.begin());
    }

    T operator[](int i) const {
        T res = data[i];
        for (i = (i + n_leaf) >> 1; i > 0; i >>= 1) {
            res = A::mapping(lazy[i], res);
        }
        return res;
    }
    void update(int i, T val) {
        push(i + n_leaf);
        data[i] = val;
    }
    void apply(int l, int r, T val) {
        assert(l < r);
        l += n_leaf;
        r += n_leaf;
        push(l);
        push(r - 1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (l < n_leaf) {
                    lazy[l] = A::composition(val, lazy[l]);
                } else {
                    data[l - n_leaf] = A::mapping(val, data[l - n_leaf]);
                }
                ++l;
            }
            if (r & 1) {
                --r;
                if (r < n_leaf) {
                    lazy[r] = A::composition(val, lazy[r]);
                } else {
                    data[r - n_leaf] = A::mapping(val, data[r - n_leaf]);
                }
            }
        }
    }
};
}  // namespace bys
