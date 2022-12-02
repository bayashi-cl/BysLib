---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':question:'
    path: byslib/io/io.hpp
    title: I/O
  - icon: ':question:'
    path: byslib/io/printer.hpp
    title: Output
  - icon: ':question:'
    path: byslib/io/scanner.hpp
    title: Input
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <cassert>\n#include <vector>\n#include <cstdint>\nnamespace\
    \ bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\n\
    using i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128\
    \ = long double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    \n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n#include <iomanip>\n#include <iostream>\n\
    #include <string>\n#include <utility>\n\n#include <array>\n#include <type_traits>\n\
    /**\n * @file traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\n\
    namespace bys {\ntemplate <class, class = void> struct has_rshift_from_istream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_rshift_from_istream<T,\
    \ std::void_t<decltype(std::declval<std::istream&>() >> std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_rshift_from_istream_v\
    \ = has_rshift_from_istream<T>::value;\n\ntemplate <class, class = void> struct\
    \ has_lshift_to_ostream : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T,\
    \ std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_lshft_to_ostream_v\
    \ = has_lshift_to_ostream<T>::value;\n\ntemplate <class, class = void> struct\
    \ is_tuple_like : std::false_type {};\ntemplate <class T> struct is_tuple_like<T,\
    \ std::void_t<decltype(std::tuple_size<T>())>> : std::true_type {};\ntemplate\
    \ <class T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\n\ntemplate\
    \ <class, class = void> struct is_iterable : std::false_type {};\ntemplate <class\
    \ T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \ntemplate <class T> struct Indexed {\n    static_assert(std::is_integral_v<T>);\n\
    \    using resolve_to = T;\n};\nusing i32_1 = Indexed<i32>;\nusing i64_1 = Indexed<i64>;\n\
    \ntemplate <class, class = void> struct is_indexed : std::false_type {};\ntemplate\
    \ <class T> struct is_indexed<Indexed<T>> : std::true_type {};\ntemplate <class\
    \ T> constexpr bool is_indexed_v = is_indexed<T>::value;\n\ntemplate <class T,\
    \ class = void> struct resolve_type { using type = T; };\ntemplate <class T> struct\
    \ resolve_type<T, std::void_t<typename T::resolve_to>> { using type = typename\
    \ T::resolve_to; };\ntemplate <class T, std::size_t N> struct resolve_type<std::array<T,\
    \ N>> {\n    using type = std::array<typename resolve_type<T>::type, N>;\n};\n\
    template <class T, class U> struct resolve_type<std::pair<T, U>> {\n    using\
    \ type = std::pair<typename resolve_type<T>::type, typename resolve_type<U>::type>;\n\
    };\ntemplate <class... Args> struct resolve_type<std::tuple<Args...>> {\n    using\
    \ type = std::tuple<typename resolve_type<Args>::type...>;\n};\ntemplate <class\
    \ T> using resolve_type_t = typename resolve_type<T>::type;\n}  // namespace bys\n\
    /**\n * @file printer.hpp\n * @brief Output\n */\nnamespace bys {\nclass Printer\
    \ {\n    std::ostream& _os;\n    // sep1 \"\\n\"       : iterable<iterable>\n\
    \    // sep2 \" \" or \"\\n\": iterable, args\n    // sep3 \" \"        : tuple_like\n\
    \    std::string sep1 = \"\\n\", sep2 = \" \", sep3 = \" \", end = \"\\n\";\n\n\
    \    template <std::size_t I, class T> void print_tuple_element(T&& elem) {\n\
    \        if constexpr (I != 0) cat(sep3);\n        cat(std::forward<T>(elem));\n\
    \    }\n    template <class Tp, std::size_t... I> void print_tuple(Tp&& tp, std::index_sequence<I...>)\
    \ {\n        (print_tuple_element<I>(std::forward<std::tuple_element_t<I, std::decay_t<Tp>>>(std::get<I>(tp))),\
    \ ...);\n    }\n\n  public:\n    Printer() = delete;\n    Printer(std::ostream&\
    \ os) : _os(os) { _os << std::fixed << std::setprecision(11) << std::boolalpha;\
    \ }\n    ~Printer() { _os << std::flush; }\n\n    template <class T> void cat(T&&\
    \ v) {\n        if constexpr (has_lshft_to_ostream_v<std::decay_t<T>>) {\n   \
    \         _os << v;\n        } else if constexpr (is_iterable_v<std::decay_t<T>>)\
    \ {\n            std::string sep;\n            if constexpr (is_iterable_v<typename\
    \ std::decay_t<T>::value_type>) {\n                sep = sep1;\n            }\
    \ else {\n                sep = sep2;\n            }\n            bool top = true;\n\
    \            for (auto&& vi : v) {\n                top ? (void)(top = false)\
    \ : cat(sep);\n                cat(vi);\n            }\n        } else if constexpr\
    \ (is_tuple_like_v<std::decay_t<T>>) {\n            print_tuple(std::forward<T>(v),\
    \ std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>());\n        }\
    \ else {\n            static_assert([] { return false; }(), \"type error\");\n\
    \        }\n    }\n\n    void print() { cat(end); }\n    template <class T> void\
    \ print(T&& v) {\n        cat(std::forward<T>(v));\n        cat(end);\n    }\n\
    \    template <class T, class... Ts> void print(T&& top, Ts&&... args) {\n   \
    \     cat(std::forward<T>(top));\n        cat(sep2);\n        print(std::forward<Ts>(args)...);\n\
    \    }\n    template <class... Ts> void operator()(Ts&&... args) { print(std::forward<Ts>(args)...);\
    \ }\n\n    void flush() { _os << std::flush; }\n    template <class... Ts> void\
    \ send(Ts&&... args) {\n        print(std::forward<Ts>(args)...);\n        flush();\n\
    \    }\n\n    Printer set_sep(const std::string& sep_1, const std::string& sep_2,\
    \ const std::string& sep_3) {\n        sep1 = sep_1;\n        sep2 = sep_2;\n\
    \        sep3 = sep_3;\n        return *this;\n    }\n    Printer set_sep(const\
    \ std::string& sep_2) {\n        sep2 = sep_2;\n        return *this;\n    }\n\
    \    Printer set_end(const std::string& _end) {\n        end = _end;\n       \
    \ return *this;\n    }\n};\n}  // namespace bys\n#include <tuple>\n\n/**\n * @file\
    \ scanner.hpp\n * @brief Input\n */\nnamespace bys {\nclass Scanner {\n    std::istream&\
    \ _is;\n    template <class T, std::size_t... I> auto read_tuple(std::index_sequence<I...>)\
    \ {\n        return resolve_type_t<T>{read<typename std::tuple_element_t<I, T>>()...};\n\
    \    }\n\n  public:\n    Scanner() = delete;\n    Scanner(std::istream& is) :\
    \ _is(is) { _is.tie(nullptr); }\n\n    template <class T> auto read() {\n    \
    \    if constexpr (has_rshift_from_istream_v<T>) {\n            T res;\n     \
    \       _is >> res;\n            return res;\n        } else if constexpr (is_tuple_like_v<T>)\
    \ {\n            return read_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \        } else if constexpr (is_indexed_v<T>) {\n            typename T::resolve_to\
    \ n;\n            _is >> n;\n            return --n;\n        } else {\n     \
    \       static_assert([] { return false; }(), \"TypeError\");\n        }\n   \
    \ }\n    template <class... Ts, std::enable_if_t<(sizeof...(Ts) >= 2), std::nullptr_t>\
    \ = nullptr> auto read() {\n        return std::tuple{read<Ts>()...};\n    }\n\
    \    template <class T, std::size_t N> auto read() {\n        std::array<resolve_type_t<T>,\
    \ N> res;\n        for (auto&& e : res) e = read<T>();\n        return res;\n\
    \    }\n    template <class T> auto readvec(i32 n) {\n        std::vector<resolve_type_t<T>>\
    \ res(n);\n        for (auto&& e : res) e = read<T>();\n        return res;\n\
    \    }\n    template <class T> auto readvec(i32 n, i32 m) {\n        std::vector<std::vector<resolve_type_t<T>>>\
    \ res(n);\n        for (auto&& e : res) e = readvec<T>(m);\n        return res;\n\
    \    }\n};\n}  // namespace bys\n\n/**\n * @file io.hpp\n * @brief I/O\n */\n\
    namespace bys {\ntemplate <class... Args> std::string debugfmt(i32 line, Args&&...\
    \ args) {\n    std::stringstream ss;\n    Printer printer(ss);\n    ss << \"\U0001F4CC\
    \ line\" << std::setw(4) << line << \": \";\n    printer.set_sep(\"\\n       \
    \      \", \" \", \" \");\n    printer.print(std::forward<Args>(args)...);\n \
    \   return ss.str();\n}\n\nPrinter print(std::cout), debug(std::cerr);\nScanner\
    \ scanner(std::cin);\n\n#ifdef LOCAL\n//! @brief \u30C7\u30D0\u30C3\u30B0\u7528\
    \u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\u4F55\u3082\u3057\u306A\
    \u3044\u3002\n#define DEBUG(...)                                  \\\n    {  \
    \                                             \\\n        debug.cat(debugfmt(__LINE__,\
    \ __VA_ARGS__)); \\\n        debug.flush();                              \\\n\
    \    }\n#else\n#define DEBUG(...)\n#endif\n#define DEBUGCASE(casenum, ...) \\\n\
    \    if (TESTCASE == casenum) DEBUG(__VA_ARGS__)\n//! @brief print\u3057\u3066\
    return\u3059\u308B\u3002\n#define EXIT(...)           \\\n    {              \
    \         \\\n        print(__VA_ARGS__); \\\n        return;             \\\n\
    \    }\n}  // namespace bys\n\nnamespace bys {\ntemplate <class T> class CumulativeSum2D\
    \ {\n    std::vector<std::vector<T>> data;\n\n    void build() {\n        i32\
    \ n = data.size();\n        i32 m = data[0].size();\n        for (i32 i = 1; i\
    \ < n; ++i) {\n            for (i32 j = 1; j < m; ++j) {\n                data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n  \
    \      }\n    }\n\n  public:\n    CumulativeSum2D(std::vector<std::vector<T>>\
    \ const& v) : data(v.size() + 1, std::vector<T>(v[0].size() + 1)) {\n        i32\
    \ n = v.size();\n        for (i32 i = 0; i < n; ++i) {\n            std::copy(v[i].begin(),\
    \ v[i].end(), std::next(data[i + 1].begin()));\n        }\n        build();\n\
    \    };\n\n    T prefix_fold(i32 i, i32 j) const { return data[i][j]; }\n\n  \
    \  // [si, gi), [sj, gj)\n    T fold(i32 si, i32 sj, i32 gi, i32 gj) const {\n\
    \        return prefix_fold(gi, gj) - prefix_fold(si, gj) - prefix_fold(gi, sj)\
    \ + prefix_fold(si, sj);\n    }\n    T fold_close(i32 si, i32 sj, i32 gi, i32\
    \ gj) { return fold(si, sj, gi + 1, gj + 1); }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../core/int_alias.hpp\"\
    \n#include \"../io/io.hpp\"\n\nnamespace bys {\ntemplate <class T> class CumulativeSum2D\
    \ {\n    std::vector<std::vector<T>> data;\n\n    void build() {\n        i32\
    \ n = data.size();\n        i32 m = data[0].size();\n        for (i32 i = 1; i\
    \ < n; ++i) {\n            for (i32 j = 1; j < m; ++j) {\n                data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n  \
    \      }\n    }\n\n  public:\n    CumulativeSum2D(std::vector<std::vector<T>>\
    \ const& v) : data(v.size() + 1, std::vector<T>(v[0].size() + 1)) {\n        i32\
    \ n = v.size();\n        for (i32 i = 0; i < n; ++i) {\n            std::copy(v[i].begin(),\
    \ v[i].end(), std::next(data[i + 1].begin()));\n        }\n        build();\n\
    \    };\n\n    T prefix_fold(i32 i, i32 j) const { return data[i][j]; }\n\n  \
    \  // [si, gi), [sj, gj)\n    T fold(i32 si, i32 sj, i32 gi, i32 gj) const {\n\
    \        return prefix_fold(gi, gj) - prefix_fold(si, gj) - prefix_fold(gi, sj)\
    \ + prefix_fold(si, sj);\n    }\n    T fold_close(i32 si, i32 sj, i32 gi, i32\
    \ gj) { return fold(si, sj, gi + 1, gj + 1); }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/io/io.hpp
  - byslib/io/printer.hpp
  - byslib/core/traits.hpp
  - byslib/io/scanner.hpp
  isVerificationFile: false
  path: byslib/ds/cumulative_sum_2D.hpp
  requiredBy: []
  timestamp: '2022-12-02 16:15:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ds/cumulative_sum_2D.hpp
layout: document
redirect_from:
- /library/byslib/ds/cumulative_sum_2D.hpp
- /library/byslib/ds/cumulative_sum_2D.hpp.html
title: byslib/ds/cumulative_sum_2D.hpp
---
