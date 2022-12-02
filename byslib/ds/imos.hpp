#pragma once
#include <numeric>
#include <vector>

#include "../core/int_alias.hpp"

namespace bys {
template <class T> class Imos {
    const i32 _n;
    std::vector<T> vec;

  public:
    Imos(i32 n) : _n(n), vec(_n) {}
    void add(i32 l, i32 r, T v) {
        vec[l] += v;
        if (r < _n) vec[r] -= v;
    }
    std::vector<T> build() const {
        std::vector<T> res;
        res.reserve(_n);
        std::partial_sum(vec.begin(), vec.end(), std::back_inserter(res));
        return res;
    }
};
template <class T> class Imos2D {
    const i32 _h, _w;
    std::vector<std::vector<T>> vec;

  public:
    Imos2D(i32 h, i32 w) : _h(h), _w(w), vec(_h, std::vector<T>(w)) {}
    void add(i32 si, i32 sj, i32 ti, i32 tj, T v) {
        ++ti, ++tj;
        vec[si][sj] += v;
        if (tj < _w) vec[si][tj] -= v;
        if (ti < _h) vec[ti][sj] -= v;
        if (ti < _h and tj < _w) vec[ti][tj] += v;
    }
    std::vector<std::vector<T>> build() const {
        auto res = vec;
        for (i32 i = 0; i < _h; ++i) {
            for (i32 j = 0; j < _w; ++j) {
                if (i != 0) res[i][j] += res[i - 1][j];
                if (j != 0) res[i][j] += res[i][j - 1];
                if (i != 0 and j != 0) res[i][j] -= res[i - 1][j - 1];
            }
        }
        return res;
    }
};
}  // namespace bys
