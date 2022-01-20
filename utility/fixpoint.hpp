#pragma once
#include <utility>
namespace bys {
template <typename F>
struct FixPoint : F {
    FixPoint(F&& f) : F{std::forward<F>(f)} {}
    template <typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
template <typename F>
inline FixPoint<std::decay_t<F>> fix(F&& f) {
    return std::forward<std::decay_t<F>>(f);
}
}  // namespace bys
