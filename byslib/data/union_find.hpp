#pragma once
#include <cassert>
#include <map>
#include <numeric>
#include <utility>
#include <vector>
/**
 * @file union_find.hpp
 * @brief Union Find Tree
 */
namespace bys {
//! @brief Union Find Tree
struct UnionFindTree {
    UnionFindTree() : _n(0) {}
    UnionFindTree(std::size_t n) : _n(n), _n_tree(_n), parent(_n, -1) {}

    std::size_t find(std::size_t a) {
        assert(a < _n);
        std::vector<std::size_t> path;
        while (parent[a] >= 0) {
            path.emplace_back(a);
            a = parent[a];
        }
        for (auto&& p : path) parent[p] = a;
        return a;
    }
    bool same(std::size_t a, std::size_t b) {
        assert(a < _n);
        assert(b < _n);
        return find(a) == find(b);
    }
    /**
     * @brief マージ
     *
     * a, bが別の連結成分に属していた場合true
     */
    bool unite(std::size_t a, std::size_t b) {
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
    std::map<std::size_t, std::vector<std::size_t>> groups() {
        std::map<std::size_t, std::vector<std::size_t>> res;
        for (std::size_t i = 0; i < _n; ++i) res[find(i)].emplace_back(i);
        return res;
    };
    std::size_t size(std::size_t a) { return -parent[find(a)]; }
    std::size_t n_tree() { return _n_tree; }

   private:
    std::size_t _n, _n_tree;
    std::vector<int> parent;  // 負なら親でありその値は(-子の数)
};
template <class T, class Lambda>
struct UnionFindTreeWithData : UnionFindTree {
    std::vector<T> _data;
    Lambda _mearge;

    UnionFindTreeWithData(std::size_t n, const std::vector<T>& data, Lambda mearge)
        : UnionFindTree::UnionFindTree(n), _data(data), _mearge(mearge) {}

    bool unite(std::size_t a, std::size_t b) {
        auto leader_a = find(a), leader_b = find(b);
        if (UnionFindTree::unite(a, b)) {
            auto new_leader = find(a);
            _data[new_leader] = _mearge(_data[leader_a], _data[leader_b]);
            return true;
        } else {
            return false;
        }
    }
    T get(std::size_t i) { return _data[find(i)]; }
};

struct LinkedUnionFindTree : UnionFindTree {
    std::vector<int> _link;
    LinkedUnionFindTree(int n) : UnionFindTree::UnionFindTree(n), _link(n) { std::iota(_link.begin(), _link.end(), 0); }

    bool unite(std::size_t a, std::size_t b) {
        if (UnionFindTree::unite(a, b)) {
            std::swap(_link[a], _link[b]);
            return true;
        } else {
            return false;
        }
    }
    std::vector<int> connect(int x) const {
        std::vector<int> res = {x};
        for (int y = _link[x]; y != x; y = _link[y]) res.push_back(y);
        return res;
    }
};
}  // namespace bys
