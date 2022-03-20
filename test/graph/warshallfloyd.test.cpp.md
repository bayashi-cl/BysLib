---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/reader.hpp
    title: graph/reader.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  - icon: ':question:'
    path: utility/change.hpp
    title: utility/change.hpp
  - icon: ':question:'
    path: utility/range.hpp
    title: "Python\u306Erange"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
    \n#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include <array>\n\
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
    \nnamespace bys {\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n */\nstruct Edge {\n    int from, to;\n    ll cost;\n\n    //! @brief\
    \ \u91CD\u307F\u306A\u3057\u5358\u9802\u70B9\n    Edge(int to) : from(-1), to(to),\
    \ cost(1) {}\n    //! @brief \u91CD\u307F\u4ED8\u304D\u5358\u9802\u70B9\n    Edge(int\
    \ to, ll cost) : from(-1), to(to), cost(cost) {}\n    //! @brief \u91CD\u307F\u4ED8\
    \u304D\u4E21\u9802\u70B9\n    Edge(int from, int to, ll cost) : from(from), to(to),\
    \ cost(cost) {}\n    bool operator<(const Edge& rh) const { return cost < rh.cost;\
    \ }\n    operator std::size_t() const { return to; }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge& e) {\n        return os << \"{\" <<\
    \ e.from << \" -> \" << e.to << \": \" << e.cost << \"}\";\n    }\n};\nusing Adj\
    \ = vector<vector<Edge>>;\nusing EdgeList = vector<Edge>;\n}  // namespace bys\n\
    namespace bys {\ntemplate <class T>\ninline bool chmax(T& a, const T& b) {\n \
    \   if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n\
    template <class T>\ninline bool chmin(T& a, const T& b) {\n    if (b < a) {\n\
    \        a = b;\n        return 1;\n    }\n    return 0;\n}\n}  // namespace bys\n\
    \nnamespace bys {\nstruct WarshallFloyd {\n    int n_node;\n    vector<vector<ll>>\
    \ cost;\n    vector<vector<int>> prev;\n\n    WarshallFloyd(const EdgeList& graph,\
    \ int n_node)\n        : n_node(n_node), cost(n_node, vector(n_node, LINF)), prev(n_node,\
    \ vector(n_node, -1)) {\n        for (auto&& e : graph) cost[e.from][e.to] = e.cost;\n\
    \        for (int i = 0; i < n_node; ++i) cost[i][i] = 0;\n        for (int i\
    \ = 0; i < n_node; ++i) {\n            for (int j = 0; j < n_node; ++j) {\n  \
    \              prev[i][j] = i;\n            }\n        }\n        search();\n\
    \    }\n\n    void search() {\n        for (int k = 0; k < n_node; k++) {\n  \
    \          for (int i = 0; i < n_node; i++) {\n                for (int j = 0;\
    \ j < n_node; j++) {\n                    if (chmin(cost[i][j], cost[i][k] + cost[k][j]))\
    \ {\n                        prev[i][j] = prev[k][j];\n                    }\n\
    \                }\n            }\n        }\n    }\n    vector<int> path(int\
    \ from, int to) {\n        vector<int> res;\n        for (int now = to; now !=\
    \ from; now = prev[from][now]) {\n            res.push_back(now);\n        }\n\
    \        res.push_back(from);\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n\nnamespace bys {\nAdj read_adj_uv(int\
    \ n, int m, bool directed = false, int index = 1) {\n    Adj graph(n);\n    for\
    \ (int i = 0; i < m; ++i) {\n        auto [u, v] = scanner.read<int, 2>();\n \
    \       u -= index;\n        v -= index;\n        graph[u].push_back({v});\n \
    \       if (!directed) graph[v].push_back({u});\n    }\n    return graph;\n}\n\
    Adj read_adj_uvc(int n, int m, bool directed = false, int index = 1) {\n    Adj\
    \ graph(n);\n    for (int i = 0; i < m; ++i) {\n        auto [u, v, c] = scanner.read<int,\
    \ int, ll>();\n        u -= index;\n        v -= index;\n        graph[u].push_back({v,\
    \ c});\n        if (!directed) graph[v].push_back({u, c});\n    }\n    return\
    \ graph;\n}\nEdgeList read_elist_uv(int m, int index = 1) {\n    EdgeList elist;\n\
    \    elist.reserve(m);\n    for (int i = 0; i < m; ++i) {\n        auto [u, v]\
    \ = scanner.read<int, 2>();\n        u -= index;\n        v -= index;\n      \
    \  elist.push_back({u, v, 1});\n    }\n    return elist;\n}\nEdgeList read_elist_uvc(int\
    \ m, int index = 1) {\n    EdgeList elist;\n    elist.reserve(m);\n    for (int\
    \ i = 0; i < m; ++i) {\n        auto [u, v, c] = scanner.read<int, int, ll>();\n\
    \        u -= index;\n        v -= index;\n        elist.push_back({u, v, c});\n\
    \    }\n    return elist;\n}\n}  // namespace bys\n\nnamespace bys {\n//! @brief\
    \ Python\u306Erange\ntemplate <typename T>\nstruct Range {\n    Range(T start,\
    \ T stop, T step = 1) : it(start), stop(stop), step(step), dir(step >= 0 ? 1 :\
    \ -1) {}\n    Range(T stop) : it(0), stop(stop), step(1), dir(1) {}\n    Range<T>\
    \ begin() const { return *this; }\n    T end() const { return stop; }\n    bool\
    \ operator!=(const T val) const { return (val - it) * dir > 0; }\n    void operator++()\
    \ { it += step; }\n    const T& operator*() const { return it; }\n\n   private:\n\
    \    T it;\n    const T stop, step;\n    const int dir;\n\n    friend Range reversed(const\
    \ Range& r) {\n        auto new_start = (r.stop - r.dir - r.it) / r.step * r.step\
    \ + r.it;\n        return {new_start, r.it - r.dir, -r.step};\n    }\n};\ntemplate\
    \ <class T>\nRange<T> irange(T stop) {\n    return Range(stop);\n}\ntemplate <class\
    \ T>\nRange<T> irange(T start, T stop, T step = 1) {\n    return Range(start,\
    \ stop, step);\n}\n}  // namespace bys\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto [v, e] = scanner.read<int, 2>();\n    auto graph = read_elist_uvc(e,\
    \ 0);\n    WarshallFloyd wf(graph, v);\n    for (int i : Range(v)) {\n       \
    \ if (wf.cost[i][i] < 0) EXIT(\"NEGATIVE CYCLE\");\n    }\n    auto dump = [&](ll\
    \ x) -> string { return x >= (ll)INF * 100 ? \"INF\" : std::to_string(x); };\n\
    \n    for (auto&& e : wf.cost) {\n        std::for_each(e.begin(), std::prev(e.end()),\
    \ [&](ll x) { cout << dump(x) << \" \"; });\n        cout << dump(e.back()) <<\
    \ endl;\n    }\n}\n}  // namespace bys\nint main() {\n    bys::Solver solver;\n\
    \    solver.solve(/* bys::scanner.read<int>() */);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
    \n#include \"../../core/core.hpp\"\n#include \"../../graph/warshall_floyd.hpp\"\
    \n#include \"../../graph/reader.hpp\"\n#include \"../../utility/range.hpp\"\n\n\
    namespace bys {\nvoid Solver::solve() {\n    auto [v, e] = scanner.read<int, 2>();\n\
    \    auto graph = read_elist_uvc(e, 0);\n    WarshallFloyd wf(graph, v);\n   \
    \ for (int i : Range(v)) {\n        if (wf.cost[i][i] < 0) EXIT(\"NEGATIVE CYCLE\"\
    );\n    }\n    auto dump = [&](ll x) -> string { return x >= (ll)INF * 100 ? \"\
    INF\" : std::to_string(x); };\n\n    for (auto&& e : wf.cost) {\n        std::for_each(e.begin(),\
    \ std::prev(e.end()), [&](ll x) { cout << dump(x) << \" \"; });\n        cout\
    \ << dump(e.back()) << endl;\n    }\n}\n}  // namespace bys\nint main() {\n  \
    \  bys::Solver solver;\n    solver.solve(/* bys::scanner.read<int>() */);\n  \
    \  return 0;\n}\n"
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
  - graph/warshall_floyd.hpp
  - graph/edge.hpp
  - utility/change.hpp
  - graph/reader.hpp
  - utility/range.hpp
  isVerificationFile: true
  path: test/graph/warshallfloyd.test.cpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/warshallfloyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/warshallfloyd.test.cpp
- /verify/test/graph/warshallfloyd.test.cpp.html
title: test/graph/warshallfloyd.test.cpp
---
