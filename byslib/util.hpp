#pragma once
#include "byslib/template/bys.hpp"

namespace bys {
template <class T, std::size_t I>
struct ItemGetter {
    bool operator()(const T& lh, const T& rh) { return lh[I] < rh[I]; }
};

/**
 * @brief 二分探索法
 * https://atcoder.jp/contests/abc205/submissions/23500985
 * @tparam T 初期値と返り値、is_okの第一引数 int or long long intを想定
 * @param ok (T): is_okを満たす初期値
 * @param ng (T): is_okを満たさない初期値
 * @param is_ok (bool()): 判定用ラムダ式
 * @param args... (Args...): is_okに渡される引数 可変長
 * @return (T): is_okを満たす最大/小の整数
 */
template <typename T, class Lambda, class... Args>
T meguru_bisect(T ok, T ng, Lambda is_ok, Args... args) {
    assert(is_ok(ok, args...));
    assert(!is_ok(ng, args...));

    while (std::abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        if (is_ok(mid, args...)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

template <class Lambda, class... Args>
double bisect_float(double ok, double ng, int rep, Lambda is_ok, Args... args) {
    assert(is_ok(ok, args...));
    assert(!is_ok(ng, args...));

    for (int i = 0; i < rep; i++) {
        double mid = (ok + ng) / 2;
        if (is_ok(mid, args...)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

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

template <class T>
T cumulate(vector<T>& vec, T init = 0) {
    T sum = init;
    for (auto&& i : vec) {
        sum += i;
        i = sum;
    }
    return sum;
}

template <class T, class BinOp>
T cumulate(vector<T>& vec, BinOp op, T init = 0) {
    T sum = init;
    for (auto&& i : vec) {
        sum = op(sum, i);
        i = sum;
    }
    return sum;
}

struct Grid {
    int h, w;
    Grid(int row, int col) : h(row), w(col) {}

    bool contain(int row, int col) {
        return 0 <= row && row < h && 0 <= col && col < w;
    }
    vector<pair<int, int>> next(int i, int j,
                                const vector<pair<int, int>> delta = {
                                    {1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
        vector<pair<int, int>> res;
        for (auto [di, dj] : delta) {
            int ni = i + di;
            int nj = j + dj;
            if (contain(ni, nj)) res.push_back({ni, nj});
        }
        return res;
    }
    int index(int i, int j) { return i * w + j; }
    int area() { return h * w; }
};

template <class T>
struct CumulativeSum {
    vector<T> data;
    CumulativeSum(int n) : data(n + 1){};
    CumulativeSum(const vector<T>& v) : data(v.size() + 1) {
        std::copy(v.begin(), v.end(), std::next(data.begin()));
    };
    void set(int i, int x) {
        assert(!build);
        data[i + 1] = x;
    }
    void construct() {
        assert(!build);
        std::partial_sum(data.begin(), data.end(), data.begin());
        build = true;
    }
    // [l, r)
    T sum(int l, int r) {
        assert(build);
        if (l > r) return 0;
        return data[r] - data[l];
    }

   private:
    bool build = false;
};
template <class T>
struct CumulativeSum2D {
    vector<vector<T>> data;
    CumulativeSum2D(int n, int m) : data(n + 1, vector<T>(m + 1)){};
    CumulativeSum2D(const vector<vector<T>>& v)
        : data(v.size() + 1, vector<T>(v[0].size() + 1)) {
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            std::copy(v[i].begin(), v[i].end(), std::next(data[i + 1].begin()));
        }
    };
    void set(int i, int j, int x) {
        assert(!build);
        data[i + 1][j + 1] = x;
    }
    T get(int i, int j) const { return data[i + 1][j + 1]; }
    void construct() {
        assert(!build);
        int n = data.size();
        int m = data[0].size();
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                data[i][j] +=
                    data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
        build = true;
    }
    // [si, gi), [sj, gj)
    T sum(int si, int sj, int gi, int gj) {
        assert(build);
        return (data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj]);
    }

   private:
    bool build = false;
};
}  // namespace bys
