#pragma once
#include "../core/stdlib.hpp"
/**
 * @file fixpoint.hpp
 * @brief FixPoint
 */
namespace bys {
/**
 * @brief ラムダ再帰
 *
 * See: https://koturn.hatenablog.com/entry/2018/06/10/060000
 */
template <typename F>
struct FixPoint : F {
    FixPoint(F&& f) : F{std::forward<F>(f)} {}
    template <typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
}  // namespace bys
