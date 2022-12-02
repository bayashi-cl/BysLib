---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <tuple>\n#include <utility>\n\nnamespace bys {\ntemplate\
    \ <class... Args> auto make_optuple(Args&&... args);\n\ntemplate <class... Args>\
    \ class operative_tuple : public std::tuple<Args...> {\n  public:\n    using std::tuple<Args...>::tuple;\n\
    \n  private:\n    template <class T, std::size_t... I> void fill(T const& v, std::index_sequence<I...>)\
    \ noexcept {\n        ((std::get<I>(*this) = v), ...);\n    }\n\n  public:\n \
    \   template <class T> operative_tuple(T const& v) noexcept { fill(v, std::make_index_sequence<sizeof...(Args)>());\
    \ }\n\n#define DEFINE_BINOP(op, iop, name)                                   \
    \                                        \\\n  private:                      \
    \                                                                            \
    \  \\\n    template <std::size_t... I> void name(operative_tuple const& other,\
    \ std::index_sequence<I...>) noexcept { \\\n        ((std::get<I>(*this) iop std::get<I>(other)),\
    \ ...);                                                   \\\n    }          \
    \                                                                            \
    \                   \\\n                                                     \
    \                                                         \\\n  public:      \
    \                                                                            \
    \                   \\\n    operative_tuple& operator iop(const operative_tuple&\
    \ other) noexcept {                                    \\\n        name(other,\
    \ std::make_index_sequence<sizeof...(Args)>());                              \
    \               \\\n        return *this;                                    \
    \                                                     \\\n    }              \
    \                                                                            \
    \               \\\n    friend operative_tuple operator op(operative_tuple const&\
    \ a, operative_tuple const& b) { return operative_tuple(a) iop b; }\n\n    DEFINE_BINOP(+,\
    \ +=, iadd);\n    DEFINE_BINOP(-, -=, isub);\n    DEFINE_BINOP(*, *=, imul);\n\
    \    DEFINE_BINOP(/, /=, idiv);\n    DEFINE_BINOP(%, %=, imod);\n    DEFINE_BINOP(&,\
    \ &=, iand);\n    DEFINE_BINOP(|, |=, ior);\n    DEFINE_BINOP(^, ^=, ixor);\n\
    #undef DEFINE_BINOP\n\n#define DEFINE_MONOOP(op, name)                       \
    \                                                                           \\\
    \n  private:                                                                 \
    \                                                      \\\n    template <std::size_t...\
    \ I> auto name(std::index_sequence<I...>) noexcept { return make_optuple(op std::get<I>(*this)...);\
    \ } \\\n                                                                     \
    \                                                            \\\n  public:   \
    \                                                                            \
    \                                         \\\n    auto operator op() const noexcept\
    \ { return name(std::make_index_sequence<sizeof...(Args)>()); }\n\n    DEFINE_MONOOP(+,\
    \ plus);\n    DEFINE_MONOOP(-, minus);\n    DEFINE_MONOOP(~, flip);\n    DEFINE_MONOOP(!,\
    \ notop);\n    DEFINE_MONOOP(*, deref);\n#undef DEFINE_MONOOP\n\n#define DEFINE_INCL(op,\
    \ name)                                                                      \
    \             \\\n  private:                                                 \
    \                                                     \\\n    template <std::size_t...\
    \ I> void name(std::index_sequence<I...>) noexcept { (op std::get<I>(*this), ...);\
    \ } \\\n                                                                     \
    \                                           \\\n  public:                    \
    \                                                                            \
    \       \\\n    operative_tuple& operator op() noexcept {                    \
    \                                               \\\n        name(std::make_index_sequence<sizeof...(Args)>());\
    \                                                      \\\n        return *this;\
    \                                                                            \
    \               \\\n    }                                                    \
    \                                                       \\\n    operative_tuple\
    \ operator op(int) noexcept {                                                \
    \                 \\\n        operative_tuple res = *this;                   \
    \                                                         \\\n        op* this;\
    \                                                                            \
    \                   \\\n        return res;                                  \
    \                                                           \\\n    }\n\n    DEFINE_INCL(++,\
    \ incl);\n    DEFINE_INCL(--, decl);\n#undef DEFINE_INCL\n\n#define DEFINE_BITSHIFT(op,\
    \ iop, name)                                                         \\\n  private:\
    \                                                                            \
    \         \\\n    template <std::size_t... I> void name(std::size_t x, std::index_sequence<I...>)\
    \ noexcept { \\\n        ((std::get<I>(*this) iop x), ...);                  \
    \                                   \\\n    }                                \
    \                                                          \\\n              \
    \                                                                            \
    \     \\\n  public:                                                          \
    \                            \\\n    operative_tuple& operator iop(std::size_t\
    \ x) noexcept {                                    \\\n        name(x, std::make_index_sequence<sizeof...(Args)>());\
    \                                  \\\n        return *this;                 \
    \                                                         \\\n    }          \
    \                                                                            \
    \    \\\n    friend operative_tuple operator op(operative_tuple const& tp, std::size_t\
    \ x) { return operative_tuple(tp) iop x; }\n\n    DEFINE_BITSHIFT(<<, <<=, lshift);\n\
    \    DEFINE_BITSHIFT(>>, >>=, rshift);\n#undef DEFINE_BITSHFT\n};\n\ntemplate\
    \ <class... Args> operative_tuple(Args...) -> operative_tuple<Args...>;\n\ntemplate\
    \ <class... Args> using optuple = operative_tuple<Args...>;\n\ntemplate <class...\
    \ Args> auto make_optuple(Args&&... args) { return operative_tuple<Args...>(std::forward<Args>(args)...);\
    \ }\n}  // namespace bys\n\ntemplate <class... Types>\nclass std::tuple_size<bys::operative_tuple<Types...>>\
    \ : public std::integral_constant<std::size_t, sizeof...(Types)> {};\n\ntemplate\
    \ <std::size_t I, class... Types> struct std::tuple_element<I, bys::operative_tuple<Types...>>\
    \ {\n    using type = std::tuple_element_t<I, std::tuple<Types...>>;\n};\n"
  code: "#pragma once\n#include <tuple>\n#include <utility>\n\nnamespace bys {\ntemplate\
    \ <class... Args> auto make_optuple(Args&&... args);\n\ntemplate <class... Args>\
    \ class operative_tuple : public std::tuple<Args...> {\n  public:\n    using std::tuple<Args...>::tuple;\n\
    \n  private:\n    template <class T, std::size_t... I> void fill(T const& v, std::index_sequence<I...>)\
    \ noexcept {\n        ((std::get<I>(*this) = v), ...);\n    }\n\n  public:\n \
    \   template <class T> operative_tuple(T const& v) noexcept { fill(v, std::make_index_sequence<sizeof...(Args)>());\
    \ }\n\n#define DEFINE_BINOP(op, iop, name)                                   \
    \                                        \\\n  private:                      \
    \                                                                            \
    \  \\\n    template <std::size_t... I> void name(operative_tuple const& other,\
    \ std::index_sequence<I...>) noexcept { \\\n        ((std::get<I>(*this) iop std::get<I>(other)),\
    \ ...);                                                   \\\n    }          \
    \                                                                            \
    \                   \\\n                                                     \
    \                                                         \\\n  public:      \
    \                                                                            \
    \                   \\\n    operative_tuple& operator iop(const operative_tuple&\
    \ other) noexcept {                                    \\\n        name(other,\
    \ std::make_index_sequence<sizeof...(Args)>());                              \
    \               \\\n        return *this;                                    \
    \                                                     \\\n    }              \
    \                                                                            \
    \               \\\n    friend operative_tuple operator op(operative_tuple const&\
    \ a, operative_tuple const& b) { return operative_tuple(a) iop b; }\n\n    DEFINE_BINOP(+,\
    \ +=, iadd);\n    DEFINE_BINOP(-, -=, isub);\n    DEFINE_BINOP(*, *=, imul);\n\
    \    DEFINE_BINOP(/, /=, idiv);\n    DEFINE_BINOP(%, %=, imod);\n    DEFINE_BINOP(&,\
    \ &=, iand);\n    DEFINE_BINOP(|, |=, ior);\n    DEFINE_BINOP(^, ^=, ixor);\n\
    #undef DEFINE_BINOP\n\n#define DEFINE_MONOOP(op, name)                       \
    \                                                                           \\\
    \n  private:                                                                 \
    \                                                      \\\n    template <std::size_t...\
    \ I> auto name(std::index_sequence<I...>) noexcept { return make_optuple(op std::get<I>(*this)...);\
    \ } \\\n                                                                     \
    \                                                            \\\n  public:   \
    \                                                                            \
    \                                         \\\n    auto operator op() const noexcept\
    \ { return name(std::make_index_sequence<sizeof...(Args)>()); }\n\n    DEFINE_MONOOP(+,\
    \ plus);\n    DEFINE_MONOOP(-, minus);\n    DEFINE_MONOOP(~, flip);\n    DEFINE_MONOOP(!,\
    \ notop);\n    DEFINE_MONOOP(*, deref);\n#undef DEFINE_MONOOP\n\n#define DEFINE_INCL(op,\
    \ name)                                                                      \
    \             \\\n  private:                                                 \
    \                                                     \\\n    template <std::size_t...\
    \ I> void name(std::index_sequence<I...>) noexcept { (op std::get<I>(*this), ...);\
    \ } \\\n                                                                     \
    \                                           \\\n  public:                    \
    \                                                                            \
    \       \\\n    operative_tuple& operator op() noexcept {                    \
    \                                               \\\n        name(std::make_index_sequence<sizeof...(Args)>());\
    \                                                      \\\n        return *this;\
    \                                                                            \
    \               \\\n    }                                                    \
    \                                                       \\\n    operative_tuple\
    \ operator op(int) noexcept {                                                \
    \                 \\\n        operative_tuple res = *this;                   \
    \                                                         \\\n        op* this;\
    \                                                                            \
    \                   \\\n        return res;                                  \
    \                                                           \\\n    }\n\n    DEFINE_INCL(++,\
    \ incl);\n    DEFINE_INCL(--, decl);\n#undef DEFINE_INCL\n\n#define DEFINE_BITSHIFT(op,\
    \ iop, name)                                                         \\\n  private:\
    \                                                                            \
    \         \\\n    template <std::size_t... I> void name(std::size_t x, std::index_sequence<I...>)\
    \ noexcept { \\\n        ((std::get<I>(*this) iop x), ...);                  \
    \                                   \\\n    }                                \
    \                                                          \\\n              \
    \                                                                            \
    \     \\\n  public:                                                          \
    \                            \\\n    operative_tuple& operator iop(std::size_t\
    \ x) noexcept {                                    \\\n        name(x, std::make_index_sequence<sizeof...(Args)>());\
    \                                  \\\n        return *this;                 \
    \                                                         \\\n    }          \
    \                                                                            \
    \    \\\n    friend operative_tuple operator op(operative_tuple const& tp, std::size_t\
    \ x) { return operative_tuple(tp) iop x; }\n\n    DEFINE_BITSHIFT(<<, <<=, lshift);\n\
    \    DEFINE_BITSHIFT(>>, >>=, rshift);\n#undef DEFINE_BITSHFT\n};\n\ntemplate\
    \ <class... Args> operative_tuple(Args...) -> operative_tuple<Args...>;\n\ntemplate\
    \ <class... Args> using optuple = operative_tuple<Args...>;\n\ntemplate <class...\
    \ Args> auto make_optuple(Args&&... args) { return operative_tuple<Args...>(std::forward<Args>(args)...);\
    \ }\n}  // namespace bys\n\ntemplate <class... Types>\nclass std::tuple_size<bys::operative_tuple<Types...>>\
    \ : public std::integral_constant<std::size_t, sizeof...(Types)> {};\n\ntemplate\
    \ <std::size_t I, class... Types> struct std::tuple_element<I, bys::operative_tuple<Types...>>\
    \ {\n    using type = std::tuple_element_t<I, std::tuple<Types...>>;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/operative_tuple.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/operative_tuple.hpp
layout: document
redirect_from:
- /library/byslib/extension/operative_tuple.hpp
- /library/byslib/extension/operative_tuple.hpp.html
title: byslib/extension/operative_tuple.hpp
---
