#pragma once
#include "../core/stdlib.hpp"
/**
 * @file cumulative_sum.hpp
 * @author bayashi_cl
 * @brief Cumulative Sum
 *
 * 累積和
 */
namespace bys {
template <class T>
struct CumulativeSum {
    std::vector<T> data;
    CumulativeSum(int n) : data(n + 1){};
    CumulativeSum(const vector<T>& v) : data(v.size() + 1) { std::copy(v.begin(), v.end(), std::next(data.begin())); };
    void set(int i, int x) {
        assert(!build);
        data[i + 1] = x;
    }
    void add(int i, int x) {
        assert(!build);
        data[i + 1] += x;
    }
    void construct() {
        assert(!build);
        std::partial_sum(data.begin(), data.end(), data.begin());
        build = true;
    }
    T operator[](int p) const { return data[p + 1]; }
    // [l, r)
    T sum(int l, int r) const {
        assert(build);
        if (l > r) return 0;
        return data[r] - data[l];
    }

   private:
    bool build = false;
};
template <class T>
struct CumulativeSum2D {
    std::vector<std::vector<T>> data;
    CumulativeSum2D(int n, int m) : data(n + 1, vector<T>(m + 1)){};
    CumulativeSum2D(const vector<vector<T>>& v) : data(v.size() + 1, vector<T>(v[0].size() + 1)) {
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            std::copy(v[i].begin(), v[i].end(), std::next(data[i + 1].begin()));
        }
    };
    void set(int i, int j, int x) {
        assert(!build);
        data[i + 1][j + 1] = x;
    }
    void add(int i, int j, int x) {
        assert(!build);
        data[i + 1][j + 1] += x;
    }
    T get(int i, int j) const { return data[i + 1][j + 1]; }
    void construct() {
        assert(!build);
        int n = data.size();
        int m = data[0].size();
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
        build = true;
    }
    // [si, gi), [sj, gj)
    T sum(int si, int sj, int gi, int gj) {
        assert(build);
        return (data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj]);
    }
    // [s, g)
    T sum(pair<int, int> s, pair<int, int> g) { return sum(s.first, s.second, g.first, g.second); }

   private:
    bool build = false;
};
}  // namespace bys
