---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/const.hpp
    title: Const
  - icon: ':heavy_check_mark:'
    path: core/core.hpp
    title: core/all
  - icon: ':heavy_check_mark:'
    path: core/io.hpp
    title: I/O
  - icon: ':heavy_check_mark:'
    path: core/macro.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: core/printer.hpp
    title: Output
  - icon: ':heavy_check_mark:'
    path: core/scanner.hpp
    title: Input
  - icon: ':heavy_check_mark:'
    path: core/solver.hpp
    title: Solver
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: core/types.hpp
    title: Types
  - icon: ':heavy_check_mark:'
    path: math/bit.hpp
    title: Bit
  - icon: ':heavy_check_mark:'
    path: math/numeric.hpp
    title: Numeric
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: Prime
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
    \n/**\n * @file core.hpp\n * @author bayashi_cl\n * @brief core/all\n *\n * C++\
    \ library for competitive programming by bayashi_cl\n * Repository: https://github.com/bayashi-cl/byslib\n\
    \ * Document : https://bayashi-cl.github.io/byslib/\n */\n#ifndef LOCAL\n#define\
    \ NDEBUG\n#endif\n/**\n * @file stdlib.hpp\n * @brief STL Template\n */\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string, std::set,\
    \ std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing std::min,\
    \ std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\nusing ll\
    \ = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\nusing\
    \ Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\n/**\n * @file const.hpp\n * @brief Const\n */\nnamespace\
    \ bys {\nconstexpr int MOD = 998244353;\nconstexpr int MOD7 = 1000000007;\nconstexpr\
    \ int INF = std::numeric_limits<int>::max() / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max()\
    \ / 2;\n}  // namespace bys\n/**\n * @file types.hpp\n * @brief Types\n *\n *\
    \ type_traits\u62E1\u5F35\n */\nnamespace bys {\ntemplate <class, class = void>\n\
    struct has_lshift_to_ostream : std::false_type {};\ntemplate <class T>\nstruct\
    \ has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\n\ntemplate <class, class = void>\n\
    struct has_rshift_from_istream : std::false_type {};\ntemplate <class T>\nstruct\
    \ has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\n\ntemplate <class T, class =\
    \ void>\nstruct has_tuple_interface : std::false_type {};\ntemplate <class T>\n\
    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\n\ntemplate <class, class = void>\nstruct has_iterator : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_iterator<T, std::void_t<typename T::iterator>>\
    \ : std::true_type {};\n\nstruct Int1 {};\n}  // namespace bys\n/**\n * @file\
    \ printer.hpp\n * @brief Output\n */\nnamespace bys {\nclass Printer {\n    std::ostream&\
    \ os;\n    std::string _sep = \" \", _end = \"\\n\";\n    template <std::size_t\
    \ I, class T>\n    inline void print_tuple_element(T&& elem) {\n        if constexpr\
    \ (I != 0) cat(_sep);\n        cat(std::forward<T>(elem));\n    }\n    template\
    \ <class Tp, std::size_t... I>\n    inline void print_tuple(Tp&& tp, std::index_sequence<I...>)\
    \ {\n        (print_tuple_element<I>(std::forward<decltype(std::get<I>(tp))>(std::get<I>(tp))),\
    \ ...);\n    }\n\n   public:\n    Printer(std::ostream& os_) : os(os_) {}\n  \
    \  ~Printer() { os << std::flush; }\n\n    template <class T>\n    void cat(T&&\
    \ v) {\n        if constexpr (has_lshift_to_ostream<std::decay_t<T>>::value) {\n\
    \            os << v;\n        } else if constexpr (has_iterator<std::decay_t<T>>::value)\
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
    \    }\n    //! @brief \u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\n    template\
    \ <class... Ts>\n    void operator()(Ts&&... args) {\n        print(std::forward<Ts>(args)...);\n\
    \    }\n\n    void flush() { os << std::flush; }\n    //! @brief \u51FA\u529B\u5F8C\
    \u306Bflush\n    template <class... Ts>\n    void send(Ts&&... args) {\n     \
    \   print(std::forward<Ts>(args)...);\n        flush();\n    }\n\n    //! @brief\
    \ \u533A\u5207\u308A\u6587\u5B57\u3068\u7D42\u7AEF\u6587\u5B57\u3092\u8A2D\u5B9A\
    \n    Printer set(string sep_ = \" \", string end_ = \"\\n\") {\n        _sep\
    \ = sep_;\n        _end = end_;\n        return *this;\n    }\n    void lf() {\
    \ cat(_end); }\n};\n}  // namespace bys\n/**\n * @file scanner.hpp\n * @brief\
    \ Input\n */\nnamespace bys {\nclass Scanner {\n    std::istream& is;\n    template\
    \ <class Tp, std::size_t... I>\n    inline decltype(auto) read_tuple(std::index_sequence<I...>)\
    \ {\n        return Tp{read<typename std::tuple_element_t<I, Tp>>()...};\n   \
    \ }\n\n   public:\n    Scanner(std::istream& is_) : is(is_){};\n\n    template\
    \ <class... Ts>\n    void scan(Ts&... args) {\n        (is >> ... >> args);\n\
    \    }\n\n    /**\n     * @brief 2\u3064\u4EE5\u4E0A\u306E\u7570\u306A\u308B\u578B\
    \n     *\n     * \u53D7\u3051\u53D6\u308A\u306F\u69CB\u9020\u5316\u675F\u7E1B\u3067\
    \n     */\n    template <class T, class... Us>\n    decltype(auto) read() {\n\
    \        if constexpr (sizeof...(Us) == 0) {\n            if constexpr (has_rshift_from_istream<T>::value)\
    \ {\n                T res;\n                is >> res;\n                return\
    \ res;\n            } else if constexpr (has_tuple_interface<T>::value) {\n  \
    \              auto res = read_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \                return res;\n            } else if constexpr (std::is_same_v<T,\
    \ Int1>) {\n                int res;\n                is >> res;\n           \
    \     --res;\n                return res;\n            } else if constexpr (has_iterator<T>::value)\
    \ {\n                //! TODO: \u4E00\u884C\u8AAD\u3093\u3067split\n         \
    \       static_assert([] { return false; }(), \"NotImplementedError\");\n    \
    \        } else {\n                static_assert([] { return false; }(), \"TypeError\"\
    );\n            }\n        } else {\n            return std::tuple{read<T>(),\
    \ read<Us>()...};\n        }\n    }\n    /**\n     * @brief \u578BT\u3092N\u500B\
    \n     *\n     * \u53D7\u3051\u53D6\u308A\u306F\u69CB\u9020\u5316\u675F\u7E1B\u3067\
    \n     */\n    template <class T, std::size_t N, typename R = std::conditional_t<std::is_same_v<T,\
    \ Int1>, int, T>>\n    std::array<R, N> read() {\n        std::array<R, N> res;\n\
    \        for (auto&& e : res) e = read<T>();\n        return res;\n    }\n   \
    \ //! @brief n\u8981\u7D20\u306Evector\n    template <class T, typename R = std::conditional_t<std::is_same_v<T,\
    \ Int1>, int, T>>\n    vector<R> readvec(int n) {\n        vector<R> res(n);\n\
    \        for (auto&& e : res) e = read<T>();\n        return res;\n    }\n   \
    \ //! @brief n*m\u8981\u7D20\u306E2\u6B21\u5143vector\n    template <class T,\
    \ typename R = std::conditional_t<std::is_same_v<T, Int1>, int, T>>\n    vector<vector<R>>\
    \ readvec(int n, int m) {\n        vector<vector<R>> res(n);\n        for (auto&&\
    \ e : res) e = readvec<T>(m);\n        return res;\n    }\n\n    /**\n     * @brief\
    \ 1\u884C\u3092\u8AAD\u307F\u53D6\u308A\u305D\u308C\u3092\u8981\u7D20\u3054\u3068\
    \u306B\u5909\u63DB\n     * @param f \u6587\u5B57\u5217\u304B\u3089\u306E\u5909\
    \u63DB\u95A2\u6570\n     * @param sep \u533A\u5207\u308A\u6587\u5B57\n     */\n\
    \    template <class Lambda = std::function<int(std::string)>,\n             \
    \ typename T = std::invoke_result_t<std::decay_t<Lambda>, std::string>>\n    std::vector<T>\
    \ readln(\n        Lambda f = [](string x) { return std::stoi(x); }, char sep\
    \ = ' ') {\n        std::ws(is);\n        std::string elem;\n        std::getline(is,\
    \ elem);\n        std::stringstream ss{elem};\n        std::vector<T> res;\n \
    \       while (std::getline(ss, elem, sep)) res.emplace_back(f(elem));\n     \
    \   return res;\n    }\n    /**\n     * @brief 1\u884C\u3092\u6587\u5B57\u5217\
    \u3067\u53D6\u5F97\n     * @param skip_ws \u5148\u982D\u306E\u7A7A\u767D\u30FB\
    \u6539\u884C\u3092\u8AAD\u307F\u98DB\u3070\u3059\n     */\n    std::string getline(bool\
    \ skip_ws = true) {\n        if (skip_ws) std::ws(is);\n        std::string res;\n\
    \        std::getline(is, res);\n        return res;\n    }\n};\n}  // namespace\
    \ bys\n/**\n * @file io.hpp\n * @brief I/O\n */\nnamespace bys {\n__attribute__((constructor))\
    \ void setup_io() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::cout << std::fixed << std::setprecision(11);\n    std::cerr << std::fixed\
    \ << std::setprecision(11);\n    std::cerr << std::boolalpha;\n}\n\nPrinter print(std::cout),\
    \ debug(std::cerr);\nScanner scanner(std::cin);\n}  // namespace bys\n/**\n *\
    \ @file macro.hpp\n * @brief Macro\n */\n// clang-format off\n#ifdef LOCAL\n//!\
    \ @brief \u30C7\u30D0\u30C3\u30B0\u7528\u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\
    \u3067\u306F\u4F55\u3082\u3057\u306A\u3044\u3002\n#define DEBUG(...) { std::cerr\
    \ << \"[debug] line\" << std::setw(4) << __LINE__ << \": \"; debug(__VA_ARGS__);\
    \ }\n#else\n#define DEBUG(...)\n#endif\n//! @brief print\u3057\u3066return\u3059\
    \u308B\u3002\n#define EXIT(...) { print(__VA_ARGS__); return; }\n#define CONCAT_IMPL(a,\
    \ b) a##b\n#define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\
    \u5909\u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"line: \" + std::to_string(__LINE__)\
    \ + \", func: \" + __func__)\n// clang-format on\n/**\n * @file solver.hpp\n *\
    \ @brief Solver\n */\nnamespace bys {\nstruct Solver {\n    int IT = 1;\n    Solver()\
    \ {}\n    void solve();\n    //! @brief \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\
    \u30FC\u30B9\u7528\n    void solve(int rep) {\n        for (; IT <= rep; ++IT)\
    \ solve();\n    }\n};\n}  // namespace bys\n/**\n * @file bit.hpp\n * @brief Bit\n\
    \ * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\u3055\u308C\u308B\n */\nnamespace\
    \ bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x) - 1  < log2(x) <= bit_width(x)\n\
    \ */\ntemplate <class T>\nconstexpr int bit_width(T x) {\n    int bits = 0;\n\
    \    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return\
    \ bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\ntemplate <class\
    \ T>\nconstexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return x == 0 ? 0\
    \ : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0A\
    \u3052\ntemplate <class T>\nconstexpr T bit_ceil(T x) {\n    assert(x >= 0);\n\
    \    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\u6587\
    \u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T>\nstd::string bin(T n) {\n \
    \   assert(n > 0);\n    if (n == 0) return \"0\";\n    std::string res;\n    while\
    \ (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>= 1;\n   \
    \ }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//! @brief\
    \ d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class T>\n\
    constexpr bool pop(T s, int d) {\n    return s & (T(1) << d);\n}\n}  // namespace\
    \ bys\n/**\n * @file numeric.hpp\n * @brief Numeric\n *\n * \u6570\u5024\u8A08\
    \u7B97\u8A70\u3081\u5408\u308F\u305B\n */\nnamespace bys {\n//! @brief \u6574\u6570\
    \u306E\u7D2F\u4E57\nconstexpr ll int_pow(int a, int b) {\n    ll res = 1;\n  \
    \  for (int i = 0; i < b; ++i) res *= a;\n    return res;\n}\n/**\n * @brief \u7E70\
    \u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n *\n * O(log q)\n */\ntemplate <class T>\n\
    constexpr T mod_pow(T p, T q, T mod) {\n    T res = 1 % mod;\n    p %= mod;\n\
    \    for (; q; q >>= 1) {\n        if (q & 1) res = res * p % mod;\n        p\
    \ = p * p % mod;\n    }\n    return res;\n}\n//! @brief ceil(x / y)\ntemplate\
    \ <class T>\nconstexpr T ceildiv(T x, T y) {\n    return x > T(0) ? (x + y - 1)\
    \ / y : x / y;\n}\n//! @brief floor(x / y)\ntemplate <class T>\nconstexpr T floordiv(T\
    \ x, T y) {\n    return x > T(0) ? x / y : (x - y + 1) / y;\n}\n/**\n * @brief\
    \ Python::divmod\n *\n * See: https://docs.python.org/ja/3/library/functions.html#divmod\n\
    \ */\ntemplate <class T>\nconstexpr std::pair<T, T> divmod(T x, T y) {\n    auto\
    \ q = floordiv(x, y);\n    return {q, x - q * y};\n}\n\n/**\n * @brief Python::%\n\
    \ *\n * See: https://docs.python.org/ja/3/reference/expressions.html#index-68\n\
    \ */\ntemplate <class T, class S>\nconstexpr T floormod(T x, S mod) {\n    x %=\
    \ mod;\n    if (x < 0) x += mod;\n    return x;\n}\n\nconstexpr ll isqrt_aux(ll\
    \ c, ll n) {\n    if (c == 0) return 1;\n    ll k = (c - 1) / 2;\n    ll a = isqrt_aux(c\
    \ / 2, n >> (2 * k + 2));\n    return (a << k) + (n >> (k + 2)) / a;\n}\n/**\n\
    \ * @brief Python::math.isqrt\n *\n * floor(sqrt(n))\n * See: https://docs.python.org/ja/3/library/math.html#math.isqrt\n\
    \ */\ntemplate <class T>\nconstexpr T isqrt(T n) {\n    assert(n >= 0);\n    if\
    \ (n == T(0)) return T(0);\n    ll a = isqrt_aux((bit_width(n) - 1) / 2, n);\n\
    \    return n < a * a ? a - 1 : a;\n}\n/**\n * @brief Nim::math::almostEqual\n\
    \ *\n * See: https://nim-lang.org/docs/math.html#almostEqual,T,T,Natural\n */\n\
    template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t>\
    \ = nullptr>\nconstexpr bool isclose(T x, T y, T coef = 4.0) {\n    if (x == y)\
    \ return true;\n    auto diff = std::abs(x - y);\n    return diff <= std::numeric_limits<T>::epsilon()\
    \ * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n}\n\nconstexpr\
    \ std::pair<long long, long long> inv_gcd(long long a, long long b) {\n    a =\
    \ floormod(a, b);\n    if (a == 0) return {b, 0};\n    long long s = b, t = a;\n\
    \    long long m0 = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n\
    \        s -= t * u;\n        m0 -= m1 * u;\n        auto tmp = s;\n        s\
    \ = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n\
    \    }\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n}  // namespace\
    \ bys\n/**\n * @file prime.hpp\n * @brief Prime\n */\nnamespace bys {\n\n/**\n\
    \ * @brief \u7D20\u56E0\u6570\u5206\u89E3\n *\n * \u8A66\u3057\u5272\u308A\u6CD5\
    \n * O(\u221An)\n */\ntemplate <typename T>\nvector<T> prime_factorize(T n) {\n\
    \    vector<T> res;\n    while (n % 2 == 0) {\n        res.push_back(2);\n   \
    \     n /= 2;\n    }\n    T f = 3;\n    while (f * f <= n) {\n        if (n %\
    \ f == 0) {\n            res.push_back(f);\n            n /= f;\n        } else\
    \ {\n            f += 2;\n        }\n    }\n    if (n != 1) res.push_back(n);\n\
    \    return res;\n}\n\n/**\n * @brief Miller-Rabin\u7D20\u6570\u5224\u5B9A\n *\n\
    \ * 2^64\u4EE5\u4E0B\u306A\u3089\u6B63\u78BA\u306B\u5224\u5B9A\u3067\u304D\u308B\
    \n * See: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test\n\
    \ * See: https://miller-rabin.appspot.com\n */\nconstexpr bool is_prime(long long\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d >>= 1;\n    constexpr std::array<ll, 7> prime = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n    for (long long p : prime) {\n    \
    \    long long t = d;\n        long long y = mod_pow(p, t, n);\n        while\
    \ (t != n - 1 && y != 1 && y != n - 1) {\n            y = y * y % n;\n       \
    \     t <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n         \
    \   return false;\n        }\n    }\n    return true;\n}\n}  // namespace bys\n\
    \nnamespace bys {\nvoid Solver::solve() {\n    auto n = scanner.read<int>();\n\
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
  - core/const.hpp
  - core/stdlib.hpp
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
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/prime.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime.test.cpp
- /verify/test/math/prime.test.cpp.html
title: test/math/prime.test.cpp
---
