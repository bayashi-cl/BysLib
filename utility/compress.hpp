#pragma once
#include "byslib/core/stdlib.hpp"

namespace bys {
template <class T>
struct Compress {
    vector<T> cp;
    bool build = false;
    Compress() {}
    Compress(vector<T>& vec) : cp(vec) {}
    void add(T v) {
        assert(!build);
        cp.push_back(v);
    }
    void construct() {
        assert(!build);
        sort(std::begin(cp), std::end(cp));
        cp.erase(std::unique(std::begin(cp), std::end(cp)), cp.end());
        build = true;
    }
    int get(T v) const {
        assert(build);
        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);
        assert(*itr == v);
        return std::distance(cp.begin(), itr);
    }
    int size() const { return cp.size(); }
    T unzip(int i) {
        assert(build);
        return cp[i];
    }
};
}  // namespace bys
