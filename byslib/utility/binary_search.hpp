#pragma once
#include <cmath>
#include <type_traits>

#include "../core/alias.hpp"
/**
 * @file binary_search.hpp
 * @brief Binary Search
 *
 * 二分探索法
 */
namespace bys {
/**
 * @brief 抽象化めぐる式二分探索
 *
 * See: https://twitter.com/meguru_comp/status/697008509376835584
 *
 * @param ok is_okがTrueとなる初期値
 * @param ng is_okがFalseとなる初期値
 * @param is_ok 判定用関数
 * @param args is_okに追加で渡される引数 可変長
 * @return T is_okを満たす最大/小の整数
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
 * @brief 実数範囲の二分探索
 *
 * @param ok is_okがTrueとなる初期値
 * @param ng is_okがFalseとなる初期値
 * @param rep 繰り返し回数 100回程度?
 * @param is_ok 判定用関数
 * @param args is_okに追加で渡される引数 可変長
 * @return double is_okを満たす最大/小の実数
 */
template <class Lambda, class... Args>
f128 bisect_float(f128 ok, f128 ng, int rep, Lambda is_ok, Args... args) {
    static_assert(std::is_same_v<std::invoke_result_t<Lambda, f128, Args...>, bool>,
                  "The function signature is invalid.");
    assert(is_ok(ok, args...));
    assert(!is_ok(ng, args...));

    for (int i = 0; i < rep; i++) {
        auto mid = (ok + ng) / 2;
        if (is_ok(mid, args...)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}
}  // namespace bys
