#pragma once

#include "bys.hpp"

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
    Compress() {}
    Compress(vector<T>& vec) : cp(vec) {}
    void add(T v) { cp.push_back(v); }
    void construct() {
        sort(std::begin(cp), std::end(cp));
        cp.erase(std::unique(std::begin(cp), std::end(cp)), cp.end());
    }
    int get(T v) {
        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);
        assert(*itr == v);
        return std::distance(cp.begin(), itr);
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

struct Board {
    int h, w;
    Board(int row, int col) : h(row), w(col) {}

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

}  // namespace bys
