#pragma once
#include <tuple>
#include <utility>

namespace bys {
template <class... Args>
auto make_optuple(Args&&... args);

template <class... Args>
class operative_tuple : public std::tuple<Args...> {
   public:
    using std::tuple<Args...>::tuple;

   private:
    template <class T, std::size_t... I>
    void fill(T const& v, std::index_sequence<I...>) noexcept {
        ((std::get<I>(*this) = v), ...);
    }

   public:
    template <class T>
    operative_tuple(T const& v) noexcept {
        fill(v, std::make_index_sequence<sizeof...(Args)>());
    }

#define DEFINE_BINOP(op, iop, name)                                               \
   private:                                                                       \
    template <std::size_t... I>                                                   \
    void name(operative_tuple const& other, std::index_sequence<I...>) noexcept { \
        ((std::get<I>(*this) iop std::get<I>(other)), ...);                       \
    }                                                                             \
                                                                                  \
   public:                                                                        \
    operative_tuple& operator iop(const operative_tuple& other) noexcept {        \
        name(other, std::make_index_sequence<sizeof...(Args)>());                 \
        return *this;                                                             \
    }                                                                             \
    friend operative_tuple operator op(operative_tuple const& a, operative_tuple const& b) { return operative_tuple(a) iop b; }

    DEFINE_BINOP(+, +=, iadd);
    DEFINE_BINOP(-, -=, isub);
    DEFINE_BINOP(*, *=, imul);
    DEFINE_BINOP(/, /=, idiv);
    DEFINE_BINOP(%, %=, imod);
    DEFINE_BINOP(&, &=, iand);
    DEFINE_BINOP(|, |=, ior);
    DEFINE_BINOP(^, ^=, ixor);
#undef DEFINE_BINOP

#define DEFINE_MONOOP(op, name)                        \
   private:                                            \
    template <std::size_t... I>                        \
    auto name(std::index_sequence<I...>) noexcept {    \
        return make_optuple(op std::get<I>(*this)...); \
    }                                                  \
                                                       \
   public:                                             \
    auto operator op() const noexcept { return name(std::make_index_sequence<sizeof...(Args)>()); }

    DEFINE_MONOOP(+, plus);
    DEFINE_MONOOP(-, minus);
    DEFINE_MONOOP(~, flip);
    DEFINE_MONOOP(!, notop);
    DEFINE_MONOOP(*, deref);
#undef DEFINE_MONOOP

#define DEFINE_INCL(op, name)                              \
   private:                                                \
    template <std::size_t... I>                            \
    void name(std::index_sequence<I...>) noexcept {        \
        (op std::get<I>(*this), ...);                      \
    }                                                      \
                                                           \
   public:                                                 \
    operative_tuple& operator op() noexcept {              \
        name(std::make_index_sequence<sizeof...(Args)>()); \
        return *this;                                      \
    }                                                      \
    operative_tuple operator op(int) noexcept {            \
        operative_tuple res = *this;                       \
        op* this;                                          \
        return res;                                        \
    }

    DEFINE_INCL(++, incl);
    DEFINE_INCL(--, decl);
#undef DEFINE_INCL

#define DEFINE_BITSHIFT(op, iop, name)                             \
   private:                                                        \
    template <std::size_t... I>                                    \
    void name(std::size_t x, std::index_sequence<I...>) noexcept { \
        ((std::get<I>(*this) iop x), ...);                         \
    }                                                              \
                                                                   \
   public:                                                         \
    operative_tuple& operator iop(std::size_t x) noexcept {        \
        name(x, std::make_index_sequence<sizeof...(Args)>());      \
        return *this;                                              \
    }                                                              \
    friend operative_tuple operator op(operative_tuple const& tp, std::size_t x) { return operative_tuple(tp) iop x; }

    DEFINE_BITSHIFT(<<, <<=, lshift);
    DEFINE_BITSHIFT(>>, >>=, rshift);
#undef DEFINE_BITSHFT
};

template <class... Args>
operative_tuple(Args...) -> operative_tuple<Args...>;

template <class... Args>
using optuple = operative_tuple<Args...>;

template <class... Args>
auto make_optuple(Args&&... args) {
    return operative_tuple<Args...>(std::forward<Args>(args)...);
}
}  // namespace bys

template <class... Types>
class std::tuple_size<bys::operative_tuple<Types...>> : public std::integral_constant<std::size_t, sizeof...(Types)> {};

template <std::size_t I, class... Types>
struct std::tuple_element<I, bys::operative_tuple<Types...>> {
    using type = std::tuple_element_t<I, std::tuple<Types...>>;
};
