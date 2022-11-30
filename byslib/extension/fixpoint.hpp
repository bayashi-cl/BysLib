#pragma once
#include <map>
#include <utility>
/**
 * @file fixpoint.hpp
 * @brief FixPoint
 */
namespace bys {
/**
 * @brief ラムダ再帰
 *
 * @see: https://koturn.hatenablog.com/entry/2018/06/10/060000
 */
template <typename F> struct FixPoint : F {
    FixPoint(F&& f) : F{std::forward<F>(f)} {}
    template <typename... Args> decltype(auto) operator()(Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};

/**
 * @brief メモ化再帰
 *
 * @see ?
 */
template <class F> class Cache : F {
    template <class> struct get_signature {};

    template <class Fn, class R, class Self, class... Args> struct get_signature<R (Fn::*)(Self, Args...) const> {
        using result_type = R;
        using args_tuple = std::tuple<std::decay_t<Args>...>;
    };

    using signature = get_signature<decltype(&F::template operator()<Cache<F>&>)>;
    using args_tuple = typename signature::args_tuple;
    using result_type = typename signature::result_type;

    std::map<args_tuple, result_type> memo;

  public:
    Cache(F&& fn) : F{std::forward<F>(fn)} {}

    template <class... Args> result_type operator()(Args&&... args) {
        args_tuple key{std::forward<Args>(args)...};
        if (auto itr = memo.find(key); itr == memo.end()) {
            result_type res = F::operator()(*this, std::forward<Args>(args)...);
            memo.emplace(key, res);
            return res;
        } else {
            return itr->second;
        }
    }
};
}  // namespace bys
