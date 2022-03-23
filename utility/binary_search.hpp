#pragma once
#include "../core/stdlib.hpp"

namespace bys {
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
    static_assert(std::is_same_v<std::invoke_result_t<Lambda, T, Args...>, bool>, "The function signature is invalid.");
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
/**
 * @brief 実数の二分探索
 *
 * @tparam Lambda
 * @tparam Args
 * @param ok is_okを満たす初期値
 * @param ng is_okを満たさない初期値
 * @param rep エポック
 * @param is_ok 判定用ラムダ式 bool(long double, Args...)
 * @param args is_okに渡される追加引数
 * @return double
 */
template <class Lambda, class... Args>
double bisect_float(ld ok, ld ng, int rep, Lambda is_ok, Args... args) {
    assert(is_ok(ok, args...));
    assert(!is_ok(ng, args...));

    for (int i = 0; i < rep; i++) {
        ld mid = (ok + ng) / 2;
        if (is_ok(mid, args...)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}
}  // namespace bys
