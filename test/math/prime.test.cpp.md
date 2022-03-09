---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/const.hpp
    title: core/const.hpp
  - icon: ':heavy_check_mark:'
    path: core/core.hpp
    title: core/core.hpp
  - icon: ':heavy_check_mark:'
    path: core/io.hpp
    title: core/io.hpp
  - icon: ':heavy_check_mark:'
    path: core/macro.hpp
    title: "\u30DE\u30AF\u30ED"
  - icon: ':heavy_check_mark:'
    path: core/printer.hpp
    title: core/printer.hpp
  - icon: ':heavy_check_mark:'
    path: core/scanner.hpp
    title: core/scanner.hpp
  - icon: ':heavy_check_mark:'
    path: core/solver.hpp
    title: core/solver.hpp
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: core/types.hpp
    title: core/types.hpp
  - icon: ':heavy_check_mark:'
    path: math/bit.hpp
    title: math/bit.hpp
  - icon: ':heavy_check_mark:'
    path: math/numeric.hpp
    title: math/numeric.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: Miller-Rabin
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <iterator>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\nnamespace bys {\nusing std::array,\
    \ std::vector, std::string, std::set, std::map, std::pair;\nusing std::cin, std::cout,\
    \ std::endl;\nusing std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\
    \n// alias\nusing ll = long long int;\nusing ld = long double;\nusing Pa = pair<int,\
    \ int>;\nusing Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class\
    \ T>\nusing uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing\
    \ umap = std::unordered_map<S, T>;\n}  // namespace bys\n\nnamespace bys {\nconstexpr\
    \ int MOD = 998244353;\nconstexpr int MOD7 = 1000000007;\nconstexpr int INF =\
    \ std::numeric_limits<int>::max() / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max()\
    \ / 2;\n}  // namespace bys\n#include <utility>\n\nnamespace bys {\ntemplate <class,\
    \ class = void>\nstruct has_lshift_to_ostream : std::false_type {};\ntemplate\
    \ <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\n\ntemplate <class, class = void>\n\
    struct has_rshift_from_istream : std::false_type {};\ntemplate <class T>\nstruct\
    \ has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\n\ntemplate <class T, class =\
    \ void>\nstruct has_tuple_interface : std::false_type {};\ntemplate <class T>\n\
    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\n\ntemplate <class, class = void>\nstruct has_iterator : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_iterator<T, std::void_t<typename T::iterator>>\
    \ : std::true_type {};\n\nstruct Int1 {};\n}  // namespace bys\n\nnamespace bys\
    \ {\nstruct Printer {\n    Printer(std::ostream& os_) : os(os_) {}\n    ~Printer()\
    \ { os << std::flush; }\n\n    template <class T>\n    void cat(T&& v) {\n   \
    \     if constexpr (has_lshift_to_ostream<std::decay_t<T>>::value) {\n       \
    \     os << v;\n        } else if constexpr (has_iterator<std::decay_t<T>>::value)\
    \ {\n            string sep2;\n            if constexpr (has_iterator<std::decay_t<typename\
    \ std::decay_t<T>::value_type>>::value) {\n                sep2 = _end;\n    \
    \        } else {\n                sep2 = _sep;\n            }\n            for\
    \ (auto &&itr = std::begin(v), end = std::end(v); itr != end; ++itr) {\n     \
    \           cat(*itr);\n                if (std::next(itr) != end) cat(sep2);\n\
    \            }\n        } else if constexpr (has_tuple_interface<std::decay_t<T>>::value)\
    \ {\n            print_tuple(std::forward<T>(v), std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>());\n\
    \        } else {\n            static_assert([] { return false; }(), \"type error\"\
    );\n        }\n    }\n    void print() { cat(_end); }\n    template <class T>\n\
    \    void print(T&& top) {\n        cat(std::forward<T>(top));\n        cat(_end);\n\
    \    }\n    template <class T, class... Ts>\n    void print(T&& top, Ts&&... args)\
    \ {\n        cat(std::forward<T>(top));\n        cat(_sep);\n        print(std::forward<Ts>(args)...);\n\
    \    }\n    template <class... Ts>\n    void operator()(Ts&&... args) {\n    \
    \    print(std::forward<Ts>(args)...);\n    }\n\n    void flush() { os << std::flush;\
    \ }\n    template <class... Ts>\n    void send(Ts&&... args) {\n        print(std::forward<Ts>(args)...);\n\
    \        flush();\n    }\n\n    Printer set(string sep_ = \" \", string end_ =\
    \ \"\\n\") {\n        _sep = sep_;\n        _end = end_;\n        return *this;\n\
    \    }\n    void lf() { cat(_end); }\n\n   private:\n    std::ostream& os;\n \
    \   std::string _sep = \" \", _end = \"\\n\";\n    template <std::size_t I, class\
    \ T>\n    inline void print_tuple_element(T&& elem) {\n        if constexpr (I\
    \ != 0) cat(_sep);\n        cat(std::forward<T>(elem));\n    }\n    template <class\
    \ Tp, std::size_t... I>\n    inline void print_tuple(Tp&& tp, std::index_sequence<I...>)\
    \ {\n        (print_tuple_element<I>(std::forward<decltype(std::get<I>(tp))>(std::get<I>(tp))),\
    \ ...);\n    }\n};\n}  // namespace bys\n\nnamespace bys {\nstruct Scanner {\n\
    \    Scanner(std::istream& is_) : is(is_){};\n\n    template <class... Ts>\n \
    \   void scan(Ts&... args) {\n        (is >> ... >> args);\n    }\n\n    template\
    \ <class T, class... Us>\n    decltype(auto) read() {\n        if constexpr (sizeof...(Us)\
    \ == 0) {\n            if constexpr (has_rshift_from_istream<T>::value) {\n  \
    \              T res;\n                is >> res;\n                return res;\n\
    \            } else if constexpr (has_tuple_interface<T>::value) {\n         \
    \       auto res = read_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \                return res;\n            } else if constexpr (std::is_same_v<T,\
    \ Int1>) {\n                int res;\n                is >> res;\n           \
    \     --res;\n                return res;\n            } else if constexpr (has_iterator<T>::value)\
    \ {\n                //! TODO: \u4E00\u884C\u8AAD\u3093\u3067split\n         \
    \       static_assert([] { return false; }(), \"NotImplementedError\");\n    \
    \        } else {\n                static_assert([] { return false; }(), \"TypeError\"\
    );\n            }\n        } else {\n            return std::tuple{read<T>(),\
    \ read<Us>()...};\n        }\n    }\n\n    template <class T, std::size_t N, typename\
    \ R = std::conditional_t<std::is_same_v<T, Int1>, int, T>>\n    std::array<R,\
    \ N> read() {\n        std::array<R, N> res;\n        for (auto&& e : res) e =\
    \ read<T>();\n        return res;\n    }\n\n    template <class T, typename R\
    \ = std::conditional_t<std::is_same_v<T, Int1>, int, T>>\n    vector<R> readvec(int\
    \ n) {\n        vector<R> res(n);\n        for (auto&& e : res) e = read<T>();\n\
    \        return res;\n    }\n    template <class T, typename R = std::conditional_t<std::is_same_v<T,\
    \ Int1>, int, T>>\n    vector<vector<R>> readvec(int n, int m) {\n        vector<vector<R>>\
    \ res(n);\n        for (auto&& e : res) e = readvec<T>(m);\n        return res;\n\
    \    }\n\n    template <class Lambda = std::function<int(std::string)>,\n    \
    \          typename T = std::invoke_result_t<std::decay_t<Lambda>, std::string>>\n\
    \    std::vector<T> readln(\n        Lambda f = [](string x) { return std::stoi(x);\
    \ }, char sep = ' ') {\n        std::ws(is);\n        std::string elem;\n    \
    \    std::getline(is, elem);\n        std::stringstream ss{elem};\n        std::vector<T>\
    \ res;\n        while (std::getline(ss, elem, sep)) res.emplace_back(f(elem));\n\
    \        return res;\n    }\n    std::string getline(bool skip_ws = true) {\n\
    \        if (skip_ws) std::ws(is);\n        std::string res;\n        std::getline(is,\
    \ res);\n        return res;\n    }\n\n   private:\n    std::istream& is;\n  \
    \  template <class Tp, std::size_t... I>\n    inline decltype(auto) read_tuple(std::index_sequence<I...>)\
    \ {\n        return Tp{read<typename std::tuple_element_t<I, Tp>>()...};\n   \
    \ }\n};\n}  // namespace bys\n\nnamespace bys {\n__attribute__((constructor))\
    \ void setup_io() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::cout << std::fixed << std::setprecision(11);\n    std::cerr << std::fixed\
    \ << std::setprecision(11);\n    std::cerr << std::boolalpha;\n}\n\nPrinter print(std::cout),\
    \ debug(std::cerr);\nScanner scanner(std::cin);\n}  // namespace bys\n// clang-format\
    \ off\n/**\n * @brief \u30DE\u30AF\u30ED\n */\n#ifdef LOCAL\n//! @brief \u30C7\
    \u30D0\u30C3\u30B0\u7528\u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\
    \u4F55\u3082\u3057\u306A\u3044\u3002\n#define DEBUG(...) { std::cerr << \"[debug]\
    \ line\" << std::setw(4) << __LINE__ << \": \"; debug(__VA_ARGS__); }\n#else\n\
    #define DEBUG(...)\n#endif\n//! @brief print\u3057\u3066return\u3059\u308B\u3002\
    \n#define EXIT(...) { print(__VA_ARGS__); return; }\n#define CONCAT_IMPL(a, b)\
    \ a##b\n#define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\
    \u5909\u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"line: \" + std::to_string(__LINE__)\
    \ + \", func: \" + __func__)\n// clang-format on\n\nnamespace bys {\nstruct Solver\
    \ {\n    int IT = 1;\n    Solver() {}\n    void solve();\n    void solve(int rep)\
    \ {\n        for (; IT <= rep; ++IT) solve();\n    }\n};\n}  // namespace bys\n\
    \nnamespace bys {\ntemplate <class T>\nint bit_width(T x) {\n    int bits = 0;\n\
    \    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return\
    \ bits;\n}\ntemplate <class T>\nT bit_floor(T x) {\n    assert(x >= 0);\n    return\
    \ x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\ntemplate <class T>\nT bit_ceil(T\
    \ x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n\
    }\n\nstring bin(ll n) {\n    assert(n > 0);\n    if (n == 0) return \"0\";\n \
    \   string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n\
    \        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return\
    \ res;\n}\ninline bool pop(int s, int d) { return s & (1 << d); }\ninline bool\
    \ pop(ll s, int d) { return s & (1LL << d); }\n}  // namespace bys\n\nnamespace\
    \ bys {\nconstexpr ll int_pow(int a, int b) {\n    ll res = 1;\n    for (int i\
    \ = 0; i < b; ++i) res *= a;\n    return res;\n}\ntemplate <class T>\nT mod_pow(T\
    \ p, T q, T mod) {\n    T res = 1 % mod;\n    p %= mod;\n    for (; q; q >>= 1)\
    \ {\n        if (q & 1) res = res * p % mod;\n        p = p * p % mod;\n    }\n\
    \    return res;\n}\nll ceildiv(ll x, ll y) { return x > 0 ? (x + y - 1) / y :\
    \ x / y; }\nll floordiv(ll x, ll y) { return x > 0 ? x / y : (x - y + 1) / y;\
    \ }\npair<ll, ll> divmod(ll x, ll y) {\n    ll q = floordiv(x, y);\n    return\
    \ {q, x - q * y};\n}\n\nll isqrt_aux(ll c, ll n) {\n    if (c == 0) return 1;\n\
    \    ll k = (c - 1) / 2;\n    ll a = isqrt_aux(c / 2, n >> (2 * k + 2));\n   \
    \ return (a << k) + (n >> (k + 2)) / a;\n}\nll isqrt(ll n) {\n    assert(n >=\
    \ 0);\n    if (n == 0) return 0;\n    ll a = isqrt_aux((bit_width(n) - 1) / 2,\
    \ n);\n    return n < a * a ? a - 1 : a;\n}\ntemplate <class T, typename std::enable_if_t<std::is_floating_point_v<T>,\
    \ std::nullptr_t> = nullptr>\ninline bool isclose(T x, T y, T coef = 4.0) {\n\
    \    if (x == y) return true;\n    auto diff = std::abs(x - y);\n    return diff\
    \ <= std::numeric_limits<T>::epsilon() * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n\
    }\n}  // namespace bys\nnamespace bys {\ntemplate <typename T>\nvector<T> prime_factorize(T\
    \ n) {\n    vector<T> res;\n    while (n % 2 == 0) {\n        res.push_back(2);\n\
    \        n /= 2;\n    }\n    T f = 3;\n    while (f * f <= n) {\n        if (n\
    \ % f == 0) {\n            res.push_back(f);\n            n /= f;\n        } else\
    \ {\n            f += 2;\n        }\n    }\n    if (n != 1) res.push_back(n);\n\
    \    return res;\n}\n//! @brief Miller-Rabin\nbool is_prime(ll n) {\n    if (n\
    \ <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return\
    \ false;\n    std::array<ll, 7> prime = {2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022};\n    ll s = 0, d = n - 1;\n    while (d % 2 == 0) {\n        ++s;\n\
    \        d >>= 1;\n    }\n    for (auto p : prime) {\n        if (p % n == 0)\
    \ return true;\n        ll t, x = mod_pow<__int128_t>(p, d, n);\n        if (x\
    \ != 1) {\n            for (t = 0; t < s; ++t) {\n                if (x == n -\
    \ 1) break;\n                x = __int128_t(x) * x % n;\n            }\n     \
    \       if (t == s) return false;\n        }\n    }\n    return true;\n}\n}  //\
    \ namespace bys\n\nnamespace bys {\nvoid Solver::solve() {\n    auto n = scanner.read<int>();\n\
    \    cout << n << \": \";\n    print(prime_factorize(n));\n}\n}  // namespace\
    \ bys\n\nint main() {\n    bys::Solver solver;\n    solver.solve();\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include \"../../core/core.hpp\"\n#include \"../../math/prime.hpp\"\n\nnamespace\
    \ bys {\nvoid Solver::solve() {\n    auto n = scanner.read<int>();\n    cout <<\
    \ n << \": \";\n    print(prime_factorize(n));\n}\n}  // namespace bys\n\nint\
    \ main() {\n    bys::Solver solver;\n    solver.solve();\n    return 0;\n}\n"
  dependsOn:
  - core/core.hpp
  - core/stdlib.hpp
  - core/const.hpp
  - core/io.hpp
  - core/printer.hpp
  - core/types.hpp
  - core/scanner.hpp
  - core/macro.hpp
  - core/solver.hpp
  - math/prime.hpp
  - math/numeric.hpp
  - math/bit.hpp
  isVerificationFile: true
  path: test/math/prime.test.cpp
  requiredBy: []
  timestamp: '2022-03-02 03:13:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/prime.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime.test.cpp
- /verify/test/math/prime.test.cpp.html
title: test/math/prime.test.cpp
---