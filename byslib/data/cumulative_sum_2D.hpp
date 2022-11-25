#pragma once
#include <cassert>
#include <vector>
#include "../core/alias.hpp"

namespace bys {
template <class T> struct CumulativeSum2D {
  private:
    bool build;

  public:
    std::vector<std::vector<T>> data;
    CumulativeSum2D(i32 n, i32 m) : build(false), data(n + 1, std::vector<T>(m + 1)){};
    CumulativeSum2D(std::vector<std::vector<T>> const& v)
        : build(false), data(v.size() + 1, std::vector<T>(v[0].size() + 1)) {
        i32 n = v.size();
        for (i32 i = 0; i < n; ++i) {
            std::copy(v[i].begin(), v[i].end(), std::next(data[i + 1].begin()));
        }
        construct();
    };
    void set(i32 i, i32 j, i32 x) {
        assert(!build);
        data[i + 1][j + 1] = x;
    }
    void add(i32 i, i32 j, i32 x) {
        assert(!build);
        data[i + 1][j + 1] += x;
    }
    T get(i32 i, i32 j) const { return data[i + 1][j + 1]; }
    void construct() {
        assert(!build);
        i32 n = data.size();
        i32 m = data[0].size();
        for (i32 i = 1; i < n; ++i) {
            for (i32 j = 1; j < m; ++j) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
        build = true;
    }
    // [si, gi), [sj, gj)
    T sum(i32 si, i32 sj, i32 gi, i32 gj) {
        assert(build);
        return (data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj]);
    }
    // [s, g)
    T sum(std::pair<i32, i32> s, std::pair<i32, i32> g) {
        return sum(s.first, s.second, g.first, g.second);
    }
};
}  // namespace bys
