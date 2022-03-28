#pragma once
#include "../core/stdlib.hpp"
/**
 * @file compress.hpp
 * @author bayashi_cl
 * @brief Coordinate Compression
 *
 * 座標圧縮
 */
namespace bys {
/**
 * @brief 座標圧縮
 */
template <class T>
class Compress {
    std::vector<T> cp;
    bool build = false;

   public:
    Compress() {}
    Compress(const std::vector<T>& vec) : cp(vec) { construct(); }
    void add(T v) {
        assert(!build);
        cp.emplace_back(v);
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
    T unzip(int i) const {
        assert(build);
        return cp[i];
    }
    std::size_t size() const { return cp.size(); }
};
}  // namespace bys
