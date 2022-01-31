#pragma once
#include "../core/stdlib.hpp"
namespace bys {
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
}  // namespace bys
