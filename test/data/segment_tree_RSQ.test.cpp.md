---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: Monoid
  - icon: ':question:'
    path: core/const.hpp
    title: Const
  - icon: ':question:'
    path: core/core.hpp
    title: core/all
  - icon: ':question:'
    path: core/io.hpp
    title: I/O
  - icon: ':question:'
    path: core/macro.hpp
    title: Macro
  - icon: ':question:'
    path: core/printer.hpp
    title: Output
  - icon: ':question:'
    path: core/scanner.hpp
    title: Input
  - icon: ':question:'
    path: core/solver.hpp
    title: Solver
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':question:'
    path: core/types.hpp
    title: Types
  - icon: ':heavy_check_mark:'
    path: data/segment_tree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: math/bit.hpp
    title: Bit
  - icon: ':heavy_check_mark:'
    path: utility/change.hpp
    title: chmin/chmax
  - icon: ':question:'
    path: utility/range.hpp
    title: Python::range
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <optional>\n#include <utility>\n/**\n * @file monoid.hpp\n * @author\
    \ bayashi_cl\n * @brief Monoid\n *\n * \u30E2\u30CE\u30A4\u30C9\n */\nnamespace\
    \ bys {\ntemplate <class T>\nstruct Magma {\n    using set_type = T;\n    static\
    \ constexpr set_type operation(set_type a, set_type b);\n    static constexpr\
    \ bool commutative{false};\n};\ntemplate <class T>\nstruct Add : Magma<T> {\n\
    \    using typename Magma<T>::set_type;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return a + b; }\n    static constexpr set_type identity{0};\n\
    \    static constexpr bool commutative{true};\n};\ntemplate <class T>\nstruct\
    \ Min : Magma<T> {\n    using typename Magma<T>::set_type;\n    static constexpr\
    \ set_type operation(set_type a, set_type b) { return std::min(a, b); }\n    static\
    \ constexpr set_type identity{std::numeric_limits<set_type>::max()};\n};\ntemplate\
    \ <class T>\nstruct Max : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::max(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T>\nstruct Update : Magma<T> {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\ntemplate\
    \ <class T>\nstruct Affine : Magma<T> {\n    using set_type = std::pair<T, T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return {a.first\
    \ * b.first, a.second * b.first + b.second}; }\n    static constexpr set_type\
    \ identity{1, 0};\n};\n}  // namespace bys\n/**\n * @file core.hpp\n * @author\
    \ bayashi_cl\n * @brief core/all\n * \n * C++ library for competitive programming\
    \ by bayashi_cl\n * Repository: https://github.com/bayashi-cl/byslib\n * Document\
    \ : https://bayashi-cl.github.io/byslib/\n */\n/**\n * @file stdlib.hpp\n * @author\
    \ bayashi_cl\n * @brief STL Template\n */\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n/**\n * @file const.hpp\n * @author bayashi_cl\n * @brief Const\n */\n\
    namespace bys {\nconstexpr int MOD = 998244353;\nconstexpr int MOD7 = 1000000007;\n\
    constexpr int INF = std::numeric_limits<int>::max() / 2;\nconstexpr ll LINF =\
    \ std::numeric_limits<ll>::max() / 2;\n}  // namespace bys\n/**\n * @file types.hpp\n\
    \ * @author bayashi_cl\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\n\
    namespace bys {\ntemplate <class, class = void>\nstruct has_lshift_to_ostream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\n\ntemplate <class, class = void>\n\
    struct has_rshift_from_istream : std::false_type {};\ntemplate <class T>\nstruct\
    \ has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\n\ntemplate <class T, class =\
    \ void>\nstruct has_tuple_interface : std::false_type {};\ntemplate <class T>\n\
    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\n\ntemplate <class, class = void>\nstruct has_iterator : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_iterator<T, std::void_t<typename T::iterator>>\
    \ : std::true_type {};\n\nstruct Int1 {};\n}  // namespace bys\n/**\n * @file\
    \ printer.hpp\n * @author bayashi_cl\n * @brief Output\n */\nnamespace bys {\n\
    class Printer {\n    std::ostream& os;\n    std::string _sep = \" \", _end = \"\
    \\n\";\n    template <std::size_t I, class T>\n    inline void print_tuple_element(T&&\
    \ elem) {\n        if constexpr (I != 0) cat(_sep);\n        cat(std::forward<T>(elem));\n\
    \    }\n    template <class Tp, std::size_t... I>\n    inline void print_tuple(Tp&&\
    \ tp, std::index_sequence<I...>) {\n        (print_tuple_element<I>(std::forward<decltype(std::get<I>(tp))>(std::get<I>(tp))),\
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
    \ cat(_end); }\n};\n}  // namespace bys\n/**\n * @file scanner.hpp\n * @author\
    \ bayashi_cl\n * @brief Input\n */\nnamespace bys {\nclass Scanner {\n    std::istream&\
    \ is;\n    template <class Tp, std::size_t... I>\n    inline decltype(auto) read_tuple(std::index_sequence<I...>)\
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
    \ bys\n/**\n * @file io.hpp\n * @author bayashi_cl\n * @brief I/O\n */\nnamespace\
    \ bys {\n__attribute__((constructor)) void setup_io() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    std::cout << std::fixed << std::setprecision(11);\n\
    \    std::cerr << std::fixed << std::setprecision(11);\n    std::cerr << std::boolalpha;\n\
    }\n\nPrinter print(std::cout), debug(std::cerr);\nScanner scanner(std::cin);\n\
    }  // namespace bys\n/**\n * @file macro.hpp\n * @author bayashi_cl\n * @brief\
    \ Macro\n */\n// clang-format off\n#ifdef LOCAL\n//! @brief \u30C7\u30D0\u30C3\
    \u30B0\u7528\u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\u4F55\u3082\
    \u3057\u306A\u3044\u3002\n#define DEBUG(...) { std::cerr << \"[debug] line\" <<\
    \ std::setw(4) << __LINE__ << \": \"; debug(__VA_ARGS__); }\n#else\n#define DEBUG(...)\n\
    #endif\n//! @brief print\u3057\u3066return\u3059\u308B\u3002\n#define EXIT(...)\
    \ { print(__VA_ARGS__); return; }\n#define CONCAT_IMPL(a, b) a##b\n#define CONCAT(a,\
    \ b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\u5909\u6570\u3092\u751F\
    \u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_, __LINE__)\n\
    #define RE std::runtime_error(\"line: \" + std::to_string(__LINE__) + \", func:\
    \ \" + __func__)\n// clang-format on\n/**\n * @file solver.hpp\n * @author bayashi_cl\n\
    \ * @brief Solver\n */\nnamespace bys {\nstruct Solver {\n    int IT = 1;\n  \
    \  Solver() {}\n    void solve();\n    //! @brief \u30DE\u30EB\u30C1\u30C6\u30B9\
    \u30C8\u30B1\u30FC\u30B9\u7528\n    void solve(int rep) {\n        for (; IT <=\
    \ rep; ++IT) solve();\n    }\n};\n}  // namespace bys\n/**\n * @file bit.hpp\n\
    \ * @author bayashi_cl\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\
    \u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x)\
    \ - 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T>\nconstexpr int bit_width(T\
    \ x) {\n    int bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++)\
    \ x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\
    \ntemplate <class T>\nconstexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return\
    \ x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\
    \u4E0A\u3052\ntemplate <class T>\nconstexpr T bit_ceil(T x) {\n    assert(x >=\
    \ 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\
    \u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T>\nstd::string bin(T n)\
    \ {\n    assert(n > 0);\n    if (n == 0) return \"0\";\n    std::string res;\n\
    \    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>=\
    \ 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//!\
    \ @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class\
    \ T>\nconstexpr bool pop(T s, int d) {\n    return s & (T(1) << d);\n}\n}  //\
    \ namespace bys\n/**\n * @file segment_tree.hpp\n * @author bayashi_cl\n * @brief\
    \ Segment Tree\n */\nnamespace bys {\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n *\n * \u4E00\u70B9\u66F4\u65B0: O(logN)\n * \u533A\u9593\u53D6\u5F97\
    : O(logN)\n *\n * @tparam Monoid \u30E2\u30CE\u30A4\u30C9\n */\ntemplate <class\
    \ Monoid>\nclass SegmentTree {\n    using value_type = typename Monoid::set_type;\n\
    \    int _n, n_leaf;\n    std::vector<value_type> data;\n\n   public:\n    SegmentTree(int\
    \ n) : _n(n), n_leaf(bit_ceil(n)), data(n_leaf * 2, Monoid::identity) {}\n   \
    \ SegmentTree(const vector<value_type>& v) : _n(v.size()), n_leaf(bit_ceil(_n)),\
    \ data(n_leaf * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(),\
    \ data.begin() + n_leaf);\n        for (int i = n_leaf - 1; i > 0; --i) data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n    }\n\n    value_type\
    \ query(int l, int r) const {\n        assert(0 <= l && l < _n);\n        assert(l\
    \ <= r);\n        assert(r <= _n);\n\n        value_type left = Monoid::identity,\
    \ right = Monoid::identity;\n        for (l += n_leaf, r += n_leaf; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left, data[l++]);\n\
    \            if (r & 1) right = Monoid::operation(data[--r], right);\n       \
    \ }\n        return Monoid::operation(left, right);\n    }\n\n    value_type query_all()\
    \ const { return data[1]; }\n\n    void update(int i, value_type val) {\n    \
    \    assert(0 <= i && i < _n);\n        i += n_leaf;\n        data[i] = val;\n\
    \        for (i >>= 1; i > 0; i >>= 1) data[i] = Monoid::operation(data[i * 2],\
    \ data[i * 2 + 1]);\n    }\n\n    value_type operator[](int i) const {\n     \
    \   assert(0 <= i && i < _n);\n        return data[i + n_leaf];\n    }\n\n   \
    \ // f(query(l, r)) == true \u3068\u306A\u308B\u6700\u5927\u306Er\n    template\
    \ <class Lambda, class... Args>\n    int bisect_from_left(int l, Lambda f, Args...\
    \ args) const {\n        static_assert(std::is_same_v<std::invoke_result_t<Lambda,\
    \ value_type, Args...>, bool>,\n                      \"The function signature\
    \ is invalid.\");\n        assert(0 <= l && l < _n);\n        assert(f(Monoid::identity,\
    \ args...));\n        l += n_leaf;\n        value_type sm = Monoid::identity;\n\
    \        do {\n            l /= l & -l;\n            if (!f(Monoid::operation(sm,\
    \ data[l]), args...)) {\n                while (l < n_leaf) {\n              \
    \      l *= 2;\n                    if (value_type op = Monoid::operation(sm,\
    \ data[l]); f(op, args...)) {\n                        sm = op;\n            \
    \            ++l;\n                    }\n                }\n                return\
    \ l - n_leaf;\n            }\n            sm = Monoid::operation(sm, data[l]);\n\
    \            ++l;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    // f(query(l, r)) == true \u3068\u306A\u308B\u6700\u5C0F\u306El\n    template\
    \ <class Lambda, class... Args>\n    int bisect_from_right(int r, Lambda f, Args...\
    \ args) const {\n        static_assert(std::is_same_v<std::invoke_result_t<Lambda,\
    \ value_type, Args...>, bool>,\n                      \"The function signature\
    \ is invalid.\");\n        assert(0 <= r && r <= _n);\n        assert(f(Monoid::identity,\
    \ args...));\n        if (r == 0) return 0;\n        r += n_leaf;\n        value_type\
    \ sm = Monoid::identity;\n        do {\n            --r;\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\n            if (!f(Monoid::operation(data[r], sm)))\
    \ {\n                while (r < n_leaf) {\n                    r = (2 * r + 1);\n\
    \                    if (value_type op = Monoid::operation(data[r], sm); f(op,\
    \ args...)) {\n                        sm = op;\n                        --r;\n\
    \                    }\n                }\n                return r + 1 - n_leaf;\n\
    \            }\n            sm = op(data[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n}  // namespace bys\n/**\n * @file change.hpp\n\
    \ * @author bayashi_cl\n * @brief chmin/chmax\n */\nnamespace bys {\n/**\n * @brief\
    \ \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\u308C\
    \u305F\u3068\u304D\n */\ntemplate <class T>\ninline bool chmax(T& a, const T&\
    \ b) {\n    return a < b ? a = b, true : false;\n}\n/**\n * @brief \u6700\u5C0F\
    \u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\u308C\u305F\u3068\
    \u304D\n */\ntemplate <class T>\ninline bool chmin(T& a, const T& b) {\n    return\
    \ a > b ? a = b, true : false;\n}\n}  // namespace bys\n/**\n * @file range.hpp\n\
    \ * @author bayashi_cl\n * @brief Python::range\n *\n * Python\u518D\u73FE\u30B7\
    \u30EA\u30FC\u30BA range\u7DE8\n * See: https://docs.python.org/ja/3/library/stdtypes.html#range\n\
    \ */\nnamespace bys {\ntemplate <typename T>\nclass Range {\n    T it;\n    const\
    \ T stop, step;\n    const int dir;\n\n   public:\n    Range(T start, T stop,\
    \ T step = 1) : it(start), stop(stop), step(step), dir(step >= 0 ? 1 : -1) {}\n\
    \    Range(T stop) : it(0), stop(stop), step(1), dir(1) {}\n    Range<T> begin()\
    \ const { return *this; }\n    T end() const { return stop; }\n    bool operator!=(const\
    \ T val) const { return (val - it) * dir > 0; }\n    void operator++() { it +=\
    \ step; }\n    const T& operator*() const { return it; }\n\n    friend Range reversed(const\
    \ Range& r) {\n        auto new_start = (r.stop - r.dir - r.it) / r.step * r.step\
    \ + r.it;\n        return {new_start, r.it - r.dir, -r.step};\n    }\n};\n//!\
    \ @brief range(stop)\ntemplate <class T>\nRange<T> irange(T stop) {\n    return\
    \ Range(stop);\n}\n//! @brief range(start, stop[, step])\ntemplate <class T>\n\
    Range<T> irange(T start, T stop, T step = 1) {\n    return Range(start, stop,\
    \ step);\n}\n}  // namespace bys\n\nnamespace bys {\nvoid Solver::solve() {\n\
    \    auto [n, q] = scanner.read<int, 2>();\n    auto a = scanner.readvec<ll>(n);\n\
    \    SegmentTree<Add<ll>> seg(a);\n    for (UV : irange(q)) {\n        auto [t,\
    \ l, r] = scanner.read<int, 3>();\n        if (t == 0) {\n            seg.update(l,\
    \ seg[l] + r);\n\n        } else {\n            print(seg.query(l, r));\n    \
    \    }\n    }\n}\n}  // namespace bys\n\nint main() {\n    bys::Solver solver;\n\
    \    solver.solve(/* bys::scanner.read<int>() */);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../../algebra/monoid.hpp\"\n#include \"../../core/core.hpp\"\n#include\
    \ \"../../data/segment_tree.hpp\"\n#include \"../../utility/change.hpp\"\n#include\
    \ \"../../utility/range.hpp\"\n\nnamespace bys {\nvoid Solver::solve() {\n   \
    \ auto [n, q] = scanner.read<int, 2>();\n    auto a = scanner.readvec<ll>(n);\n\
    \    SegmentTree<Add<ll>> seg(a);\n    for (UV : irange(q)) {\n        auto [t,\
    \ l, r] = scanner.read<int, 3>();\n        if (t == 0) {\n            seg.update(l,\
    \ seg[l] + r);\n\n        } else {\n            print(seg.query(l, r));\n    \
    \    }\n    }\n}\n}  // namespace bys\n\nint main() {\n    bys::Solver solver;\n\
    \    solver.solve(/* bys::scanner.read<int>() */);\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid.hpp
  - core/core.hpp
  - core/stdlib.hpp
  - core/const.hpp
  - core/io.hpp
  - core/printer.hpp
  - core/types.hpp
  - core/scanner.hpp
  - core/macro.hpp
  - core/solver.hpp
  - data/segment_tree.hpp
  - math/bit.hpp
  - utility/change.hpp
  - utility/range.hpp
  isVerificationFile: true
  path: test/data/segment_tree_RSQ.test.cpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data/segment_tree_RSQ.test.cpp
layout: document
redirect_from:
- /verify/test/data/segment_tree_RSQ.test.cpp
- /verify/test/data/segment_tree_RSQ.test.cpp.html
title: test/data/segment_tree_RSQ.test.cpp
---
