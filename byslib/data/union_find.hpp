#pragma once
#include <cassert>
#include <map>
#include <numeric>
#include <utility>
#include <vector>
#include "../core/alias.hpp"
/**
 * @file union_find.hpp
 * @brief Union Find Tree
 */
namespace bys {
//! @brief Union Find Tree
struct UnionFindTree {
    UnionFindTree() : _n(0) {}
    UnionFindTree(i32 n) : _n(n), _n_tree(_n), parent(_n, -1) {}

    i32 find(i32 a) {
        assert(a < _n);
        std::vector<i32> path;
        while (parent[a] >= 0) {
            path.emplace_back(a);
            a = parent[a];
        }
        for (auto&& p : path) parent[p] = a;
        return a;
    }
    bool same(i32 a, i32 b) {
        assert(a < _n);
        assert(b < _n);
        return find(a) == find(b);
    }
    /**
     * @brief マージ
     *
     * a, bが別の連結成分に属していた場合true
     */
    bool unite(i32 a, i32 b) {
        assert(a < _n);
        assert(b < _n);
        a = find(a);
        b = find(b);
        if (a == b) return false;
        --_n_tree;
        if (-parent[a] < -parent[b]) std::swap(a, b);
        parent[a] += parent[b];
        parent[b] = a;
        return true;
    }
    std::map<i32, std::vector<i32>> groups() {
        std::map<i32, std::vector<i32>> res;
        for (i32 i = 0; i < _n; ++i) res[find(i)].emplace_back(i);
        return res;
    };
    i32 size(i32 a) { return -parent[find(a)]; }
    i32 n_tree() { return _n_tree; }

  private:
    i32 _n, _n_tree;
    std::vector<i32> parent;  // 負なら親でありその値は(-子の数)
};
template <class T, class Lambda> struct UnionFindTreeWithData : UnionFindTree {
    std::vector<T> _data;
    Lambda _mearge;

    UnionFindTreeWithData(i32 n, const std::vector<T>& data, Lambda mearge)
        : UnionFindTree::UnionFindTree(n), _data(data), _mearge(mearge) {}

    bool unite(i32 a, i32 b) {
        auto leader_a = find(a), leader_b = find(b);
        if (UnionFindTree::unite(a, b)) {
            auto new_leader = find(a);
            _data[new_leader] = _mearge(_data[leader_a], _data[leader_b]);
            return true;
        } else {
            return false;
        }
    }
    T get(i32 i) { return _data[find(i)]; }
};

struct LinkedUnionFindTree : UnionFindTree {
    std::vector<i32> _link;
    LinkedUnionFindTree(i32 n) : UnionFindTree::UnionFindTree(n), _link(n) {
        std::iota(_link.begin(), _link.end(), 0);
    }

    bool unite(i32 a, i32 b) {
        if (UnionFindTree::unite(a, b)) {
            std::swap(_link[a], _link[b]);
            return true;
        } else {
            return false;
        }
    }
    std::vector<i32> connect(i32 x) const {
        std::vector<i32> res = {x};
        for (i32 y = _link[x]; y != x; y = _link[y]) res.push_back(y);
        return res;
    }
};
}  // namespace bys
