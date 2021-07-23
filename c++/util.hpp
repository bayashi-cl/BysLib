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

}  // namespace bys
