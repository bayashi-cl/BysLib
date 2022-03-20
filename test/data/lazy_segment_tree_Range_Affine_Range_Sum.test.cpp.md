---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: acl/acl.hpp
    title: acl/acl.hpp
  - icon: ':question:'
    path: core/const.hpp
    title: core/const.hpp
  - icon: ':question:'
    path: core/core.hpp
    title: core/core.hpp
  - icon: ':question:'
    path: core/io.hpp
    title: core/io.hpp
  - icon: ':question:'
    path: core/macro.hpp
    title: "\u30DE\u30AF\u30ED"
  - icon: ':question:'
    path: core/printer.hpp
    title: core/printer.hpp
  - icon: ':question:'
    path: core/scanner.hpp
    title: core/scanner.hpp
  - icon: ':question:'
    path: core/solver.hpp
    title: core/solver.hpp
  - icon: ':question:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':question:'
    path: core/types.hpp
    title: core/types.hpp
  - icon: ':question:'
    path: data/lazy_segment_tree.hpp
    title: data/lazy_segment_tree.hpp
  - icon: ':question:'
    path: math/bit.hpp
    title: math/bit.hpp
  - icon: ':question:'
    path: monoid/mapping.hpp
    title: monoid/mapping.hpp
  - icon: ':x:'
    path: monoid/mapping_modint.hpp
    title: monoid/mapping_modint.hpp
  - icon: ':question:'
    path: monoid/monoid.hpp
    title: monoid/monoid.hpp
  - icon: ':x:'
    path: monoid/monoid_modint.hpp
    title: monoid/monoid_modint.hpp
  - icon: ':question:'
    path: utility/change.hpp
    title: utility/change.hpp
  - icon: ':question:'
    path: utility/range.hpp
    title: "Python\u306Erange"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <iostream>\n#include <atcoder/math>\n#include <atcoder/modint>\n\n\
    namespace bys {\nusing atcoder::pow_mod, atcoder::inv_mod;\nusing mint = atcoder::modint998244353;\n\
    using mint7 = atcoder::modint1000000007;\ntemplate <int MOD>\ninline std::istream&\
    \ operator>>(std::istream& is, atcoder::static_modint<MOD>& m) {\n    long long\
    \ int n;\n    is >> n;\n    m = n;\n    return is;\n}\ntemplate <typename T, typename\
    \ std::enable_if_t<atcoder::internal::is_modint<T>::value, std::nullptr_t> = nullptr>\n\
    std::ostream& operator<<(std::ostream& os, const T& m) {\n    return os << m.val();\n\
    }\n}  // namespace bys\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <functional>\n#include <iomanip>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n\nnamespace bys {\nconstexpr int MOD = 998244353;\nconstexpr int MOD7 =\
    \ 1000000007;\nconstexpr int INF = std::numeric_limits<int>::max() / 2;\nconstexpr\
    \ ll LINF = std::numeric_limits<ll>::max() / 2;\n}  // namespace bys\n#include\
    \ <utility>\n\nnamespace bys {\ntemplate <class, class = void>\nstruct has_lshift_to_ostream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
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
    \n\nnamespace bys {\ntemplate <class T>\nint bit_width(T x) {\n    int bits =\
    \ 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return\
    \ bits;\n}\ntemplate <class T>\nT bit_floor(T x) {\n    assert(x >= 0);\n    return\
    \ x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\ntemplate <class T>\nT bit_ceil(T\
    \ x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n\
    }\n\nstring bin(ll n) {\n    assert(n > 0);\n    if (n == 0) return \"0\";\n \
    \   string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n\
    \        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return\
    \ res;\n}\ninline bool pop(int s, int d) { return s & (1 << d); }\ninline bool\
    \ pop(ll s, int d) { return s & (1LL << d); }\n}  // namespace bys\n#include <optional>\n\
    namespace bys {\ntemplate <class T>\nstruct Magma {\n    using set_type = T;\n\
    \    static constexpr set_type operation(set_type a, set_type b);\n    static\
    \ constexpr bool commutative{false};\n};\ntemplate <class T>\nstruct Add : Magma<T>\
    \ {\n    using typename Magma<T>::set_type;\n    static constexpr set_type operation(set_type\
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
    \ identity{1, 0};\n};\n}  // namespace bys\nnamespace bys {\ntemplate <class T,\
    \ class ActMonoid>\nstruct MappingToSet {\n    static constexpr void mapping(T&,\
    \ typename ActMonoid::set_type) {\n        static_assert([] { return false; }(),\
    \ \"mapping function does not defined.\");\n    }\n};\ntemplate <class T, class\
    \ S>\nstruct MappingToSet<T, Add<S>> {\n    static constexpr void mapping(T& t,\
    \ typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class T, class S>\n\
    struct MappingToSet<T, Update<S>> {\n    static constexpr void mapping(T& t, typename\
    \ Update<S>::set_type u) {\n        if (u.has_value()) t = u.value();\n    }\n\
    };\ntemplate <class Monoid, class ActMonoid>\nstruct Mapping {\n    static constexpr\
    \ void mapping(typename Monoid::set_type&, typename ActMonoid::set_type, int)\
    \ {\n        static_assert([] { return false; }(), \"mapping function does not\
    \ defined.\");\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Min<T>,\
    \ Update<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t,\
    \ typename Update<S>::set_type s, int) {\n        if (s.has_value()) t = s.value();\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>, Add<S>> {\n  \
    \  static constexpr void mapping(typename Add<T>::set_type& t, typename Add<S>::set_type\
    \ s, int w) { t += s * w; }\n};\ntemplate <class T, class S>\nstruct Mapping<Min<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t, typename\
    \ Add<S>::set_type s, int) { t += s; }\n};\ntemplate <class T, class S>\nstruct\
    \ Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename Add<T>::set_type&\
    \ t, typename Update<S>::set_type s, int w) {\n        if (s.has_value()) t =\
    \ s.value() * w;\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, int w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\n}  // namespace bys\nnamespace bys {\ntemplate <class Monoid, class\
    \ ActMonoid, class Action = Mapping<Monoid, ActMonoid>>\nclass LazySegmentTree\
    \ {\n    using value_type = typename Monoid::set_type;\n    using act_type = typename\
    \ ActMonoid::set_type;\n    int _n, n_leaf, logsize;\n    std::vector<act_type>\
    \ lazy;\n    std::vector<value_type> data;\n\n    void reload(int p) { data[p]\
    \ = Monoid::operation(data[p * 2], data[p * 2 + 1]); }\n    void push(const int\
    \ p) {\n        int w = n_leaf >> bit_width(p);\n        apply_segment(p * 2,\
    \ lazy[p], w);\n        apply_segment(p * 2 + 1, lazy[p], w);\n        lazy[p]\
    \ = ActMonoid::identity;\n    }\n    void apply_segment(const int p, act_type\
    \ f, int w) {\n        Action::mapping(data[p], f, w);\n        if (p < n_leaf)\
    \ lazy[p] = ActMonoid::operation(lazy[p], f);\n    }\n\n   public:\n    LazySegmentTree(int\
    \ n)\n        : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {}\n    LazySegmentTree(std::vector<value_type> v)\n\
    \        : _n(v.size()),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + n_leaf);\n        for (int i = n_leaf - 1; i > 0; --i) {\n            data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n        }\n    }\n    value_type\
    \ operator[](int p) {\n        assert(0 <= p && p < _n);\n        p += n_leaf;\n\
    \        for (int i = logsize; i > 0; --i) push(p >> i);\n        return data[p];\n\
    \    }\n    void update(int p, const value_type& x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += n_leaf;\n        for (int i = logsize; i > 0; --i) push(p\
    \ >> i);\n        data[p] = x;\n        for (int i = 1; i <= logsize; ++i) reload(p\
    \ >> i);\n    }\n    value_type query(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r <= _n);\n        if (l == r) return\
    \ Monoid::identity;\n\n        l += n_leaf;\n        r += n_leaf;\n\n        for\
    \ (int i = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        value_type left = Monoid::identity, right = Monoid::identity;\n    \
    \    for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left,\
    \ data[l++]);\n            if (r & 1) right = Monoid::operation(data[--r], right);\n\
    \        }\n        return Monoid::operation(left, right);\n    }\n\n    // value_type\
    \ query_all() { return data[1]; }\n    // void apply(int i, act_type f) { apply(i,\
    \ i + 1, f); }\n\n    void apply(int l, int r, act_type f) {\n        assert(0\
    \ <= l);\n        assert(l <= r);\n        assert(r <= _n);\n        if (l ==\
    \ r) return;\n        l += n_leaf;\n        r += n_leaf;\n\n        for (int i\
    \ = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    int l2 = l, r2 = r;\n        int w = 1;\n        while (l2 < r2) {\n    \
    \        if (l2 & 1) apply_segment(l2++, f, w);\n            if (r2 & 1) apply_segment(--r2,\
    \ f, w);\n            l2 >>= 1;\n            r2 >>= 1;\n            w <<= 1;\n\
    \        }\n\n        for (int i = 1; i <= logsize; i++) {\n            if (((l\
    \ >> i) << i) != l) reload(l >> i);\n            if (((r >> i) << i) != r) reload((r\
    \ - 1) >> i);\n        }\n    }\n};\n}  // namespace bys\nnamespace bys {\ntemplate\
    \ <class T>\nstruct AddModint : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return a +\
    \ b; }\n    static inline const set_type identity = {0};\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T>\nstruct AffineModint : Magma<T>\
    \ {\n    using set_type = std::pair<T, T>;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return {a.first * b.first, a.second * b.first + b.second};\
    \ }\n    static inline const set_type identity = {1, 0};\n};\n}  // namespace\
    \ bys\nnamespace bys {\ntemplate <class T, class S>\nstruct Mapping<AddModint<T>,\
    \ AffineModint<S>> {\n    static void mapping(typename AddModint<T>::set_type&\
    \ t, typename AffineModint<S>::set_type s, int w) {\n        t = t * s.first +\
    \ w * s.second;\n    }\n};\n}  // namespace bys\nnamespace bys {\ntemplate <class\
    \ T>\ninline bool chmax(T& a, const T& b) {\n    if (a < b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\ntemplate <class T>\ninline bool chmin(T&\
    \ a, const T& b) {\n    if (b < a) {\n        a = b;\n        return 1;\n    }\n\
    \    return 0;\n}\n}  // namespace bys\n\nnamespace bys {\n//! @brief Python\u306E\
    range\ntemplate <typename T>\nstruct Range {\n    Range(T start, T stop, T step\
    \ = 1) : it(start), stop(stop), step(step), dir(step >= 0 ? 1 : -1) {}\n    Range(T\
    \ stop) : it(0), stop(stop), step(1), dir(1) {}\n    Range<T> begin() const {\
    \ return *this; }\n    T end() const { return stop; }\n    bool operator!=(const\
    \ T val) const { return (val - it) * dir > 0; }\n    void operator++() { it +=\
    \ step; }\n    const T& operator*() const { return it; }\n\n   private:\n    T\
    \ it;\n    const T stop, step;\n    const int dir;\n\n    friend Range reversed(const\
    \ Range& r) {\n        auto new_start = (r.stop - r.dir - r.it) / r.step * r.step\
    \ + r.it;\n        return {new_start, r.it - r.dir, -r.step};\n    }\n};\ntemplate\
    \ <class T>\nRange<T> irange(T stop) {\n    return Range(stop);\n}\ntemplate <class\
    \ T>\nRange<T> irange(T start, T stop, T step = 1) {\n    return Range(start,\
    \ stop, step);\n}\n}  // namespace bys\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto [n, q] = scanner.read<int, 2>();\n    auto a = scanner.readvec<mint>(n);\n\
    \    LazySegmentTree<AddModint<mint>, AffineModint<mint>, Mapping<AddModint<mint>,\
    \ AffineModint<mint>>> seg(a);\n    for (UV : irange(q)) {\n        auto t = scanner.read<int>();\n\
    \        if (t == 0) {\n            auto [l, r] = scanner.read<int, 2>();\n  \
    \          auto [b, c] = scanner.read<mint, 2>();\n            seg.apply(l, r,\
    \ {b, c});\n        } else {\n            auto [l, r] = scanner.read<int, 2>();\n\
    \            print(seg.query(l, r));\n        }\n    }\n}\n}  // namespace bys\n\
    \nint main() {\n    bys::Solver solver;\n    solver.solve(/* bys::scanner.read<int>()\
    \ */);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../acl/acl.hpp\"\n#include \"../../core/core.hpp\"\n#include \"\
    ../../data/lazy_segment_tree.hpp\"\n#include \"../../monoid/mapping_modint.hpp\"\
    \n#include \"../../monoid/monoid_modint.hpp\"\n#include \"../../utility/change.hpp\"\
    \n#include \"../../utility/range.hpp\"\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto [n, q] = scanner.read<int, 2>();\n    auto a = scanner.readvec<mint>(n);\n\
    \    LazySegmentTree<AddModint<mint>, AffineModint<mint>, Mapping<AddModint<mint>,\
    \ AffineModint<mint>>> seg(a);\n    for (UV : irange(q)) {\n        auto t = scanner.read<int>();\n\
    \        if (t == 0) {\n            auto [l, r] = scanner.read<int, 2>();\n  \
    \          auto [b, c] = scanner.read<mint, 2>();\n            seg.apply(l, r,\
    \ {b, c});\n        } else {\n            auto [l, r] = scanner.read<int, 2>();\n\
    \            print(seg.query(l, r));\n        }\n    }\n}\n}  // namespace bys\n\
    \nint main() {\n    bys::Solver solver;\n    solver.solve(/* bys::scanner.read<int>()\
    \ */);\n    return 0;\n}\n"
  dependsOn:
  - acl/acl.hpp
  - core/core.hpp
  - core/stdlib.hpp
  - core/const.hpp
  - core/io.hpp
  - core/printer.hpp
  - core/types.hpp
  - core/scanner.hpp
  - core/macro.hpp
  - core/solver.hpp
  - data/lazy_segment_tree.hpp
  - math/bit.hpp
  - monoid/mapping.hpp
  - monoid/monoid.hpp
  - monoid/mapping_modint.hpp
  - monoid/monoid_modint.hpp
  - utility/change.hpp
  - utility/range.hpp
  isVerificationFile: true
  path: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2022-03-20 20:42:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
- /verify/test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp.html
title: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
---
