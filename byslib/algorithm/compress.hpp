#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>
#include <vector>
#include "../core/int_alias.hpp"
/**
 * @file compress.hpp
 * @brief Coordinate Compression
 *
 * 座標圧縮
 */
namespace bys {
/**
 * @brief 座標圧縮
 */
template <class T> class Compress {
    std::vector<T> cp;
    Compress(std::vector<T> const& v) : cp(v) {
        sort(std::begin(cp), std::end(cp));
        cp.erase(std::unique(std::begin(cp), std::end(cp)), cp.end());
    }
    //! @brief 圧縮された値を取得 O(log N)
    i32 get(T v) const {
        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);
        assert(*itr == v);
        return std::distance(cp.begin(), itr);
    }

    //! @brief 解凍された値を取得 O(1)
    T unzip(i32 i) const { return cp[i]; }
    std::size_t size() const { return cp.size(); }
    std::ptrdiff_t ssize() const { return cp.size(); }
};
}  // namespace bys
