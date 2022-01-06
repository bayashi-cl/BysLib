#pragma once
#include "../core/stdlib.hpp"

namespace bys {
//! @brief 座標圧縮 使う前にconstruct()
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
    //! @brief 圧縮された値を取得 O(log N)
    int get(T v) const {
        assert(build);
        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);
        assert(*itr == v);
        return std::distance(cp.begin(), itr);
    }
    //! @brief 解凍された値を取得 O(1)
    T unzip(int i) {
        assert(build);
        return cp[i];
    }
    int size() const { return cp.size(); }
};
}  // namespace bys
