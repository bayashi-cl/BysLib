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
    path: graphv2/dijkstra.hpp
    title: graphv2/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/edge.hpp
    title: graphv2/edge.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/result.hpp
    title: Single Source Shortest Path Result
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\
    #ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include <array>\n\
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
    namespace bys {\nstruct Edge {\n    std::size_t src, dest;\n    ll weight;\n \
    \   Edge() {}\n    Edge(std::size_t src, std::size_t dest, ll weight = 1) : src(src),\
    \ dest(dest), weight(weight) {}\n    bool operator<(const Edge& rh) const { return\
    \ weight < rh.weight; }\n    operator int() const { return dest; }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Edge& e) {\n        return\
    \ os << \"{\" << e.src << \" -> \" << e.dest << \": \" << e.weight << \"}\";\n\
    \    }\n};\nstruct DynamicAdjacencyList {\n    std::vector<std::vector<Edge>>\
    \ data;\n    DynamicAdjacencyList(std::size_t n) : data(n, vector<Edge>()), _n(n)\
    \ {}\n    std::vector<vector<Edge>>::reference operator[](std::size_t i) { return\
    \ *(data.begin() + i); }\n    const std::vector<vector<Edge>>::const_reference\
    \ operator[](std::size_t i) const { return *(data.cbegin() + i); }\n    void add_edge(const\
    \ Edge& e) { data[e.src].push_back(e); }\n    void add_edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }\n    std::size_t\
    \ size() const { return _n; }\n\n   private:\n    std::size_t _n;\n};\nstruct\
    \ AdjacencyList {\n    AdjacencyList(std::size_t n, std::size_t m) : _n(n), _m(m),\
    \ index(n + 1), _build_flg(m == 0) { buf.reserve(m); }\n\n    struct AdjacencyRange\
    \ {\n        using iterator = std::vector<Edge>::const_iterator;\n        using\
    \ reference = std::vector<Edge>::const_reference;\n        iterator _begin, _end;\n\
    \        iterator begin() const { return _begin; }\n        iterator end() const\
    \ { return _end; }\n        reference operator[](std::size_t i) const { return\
    \ *(_begin + i); }\n        std::size_t size() const { return std::distance(_begin,\
    \ _end); }\n        bool empty() const { return size() == 0; }\n    };\n    AdjacencyRange\
    \ operator[](std::size_t i) const {\n        return AdjacencyRange{data.begin()\
    \ + index[i], data.begin() + index[i + 1]};\n    }\n\n    void build() {\n   \
    \     std::partial_sum(index.begin(), index.end(), index.begin());\n        data.resize(_m);\n\
    \        for (auto&& e : buf) data[--index[e.src]] = e;\n        _build_flg =\
    \ true;\n    }\n    void add_edge(const Edge& e) {\n        ++index[e.src];\n\
    \        buf.emplace_back(e);\n        if (buf.size() == _m) build();\n    }\n\
    \    void add_edge(std::size_t src, std::size_t dest, ll weight = 1) { add_edge(Edge(src,\
    \ dest, weight)); }\n    std::size_t size() const { return _n; }\n    std::size_t\
    \ n_edge() const { return _m; }\n    bool build_flg() const { return _build_flg;\
    \ }\n\n   private:\n    std::size_t _n, _m;\n    std::vector<Edge> buf, data;\n\
    \    std::vector<std::size_t> index;\n    bool _build_flg;\n};\n}  // namespace\
    \ bys\nnamespace bys {\n/**\n * @brief Single Source Shortest Path Result\n *\
    \ \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\u306E\u7B54\u3048\
    \n * \u7D4C\u8DEF\u5FA9\u5143\u3082\u3067\u304D\u308B\n */\nstruct SSSPResult\
    \ {\n    std::size_t source;\n    std::vector<ll> cost;\n    std::vector<int>\
    \ prev;\n\n    SSSPResult(std::size_t _n, std::size_t _source) : source(_source),\
    \ cost(_n, LINF), prev(_n, -1) {}\n    vector<std::size_t> path(int to) const\
    \ {\n        vector<std::size_t> res;\n        while (to != -1) {\n          \
    \  res.push_back(to);\n            to = prev[to];\n        }\n        std::reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n};\nstruct APSPResult {\n    std::vector<std::vector<ll>>\
    \ cost;\n    std::vector<std::vector<int>> prev;\n    APSPResult(std::size_t _n)\
    \ : cost(_n, vector(_n, LINF)), prev(_n, vector(_n, -1)) {}\n    std::vector<std::size_t>\
    \ path(int from, int to) {\n        vector<std::size_t> res;\n        for (int\
    \ now = to; now != from; now = prev[from][now]) {\n            res.push_back(now);\n\
    \        }\n        res.push_back(from);\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n\nnamespace bys {\nSSSPResult\
    \ dijkstra(const AdjacencyList& graph, int source) {\n    using Node = std::pair<ll,\
    \ std::size_t>;\n    std::size_t n = graph.size();\n    SSSPResult res(n, source);\n\
    \    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> que;\n \
    \   res.cost[source] = 0;\n    que.push({0, source});\n\n    while (!que.empty())\
    \ {\n        auto [top_cost, top] = que.top();\n        que.pop();\n        if\
    \ (res.cost[top] < top_cost) continue;\n        for (auto&& next : graph[top])\
    \ {\n            ll next_cost = res.cost[top] + next.weight;\n            if (next_cost\
    \ < res.cost[next]) {\n                res.cost[next] = next_cost;\n         \
    \       res.prev[next] = top;\n                que.push({next_cost, next});\n\
    \            }\n        }\n    }\n    return res;\n}\n}  // namespace bys\n\n\
    namespace bys {\nvoid Solver::solve() {\n    auto [n, m, s, t] = scanner.read<int,\
    \ 4>();\n    AdjacencyList graph(n, m);\n    for (int i = 0; i < m; ++i) {\n \
    \       auto [s, t, d] = scanner.read<int, 3>();\n        graph.add_edge(s, t,\
    \ d);\n    }\n    auto res = dijkstra(graph, s);\n    if (res.cost[t] == LINF)\
    \ {\n        print(-1);\n    } else {\n        auto path = res.path(t);\n    \
    \    int y = path.size();\n        print(res.cost[t], y - 1);\n        for (int\
    \ i = 0; i < y - 1; ++i) print(path[i], path[i + 1]);\n    }\n}\n}  // namespace\
    \ bys\n\nint main() {\n    bys::Solver solver;\n    solver.solve(/* bys::scanner.read<int>()\
    \ */);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../../core/core.hpp\"\n#include \"../../graphv2/dijkstra.hpp\"\n\nnamespace\
    \ bys {\nvoid Solver::solve() {\n    auto [n, m, s, t] = scanner.read<int, 4>();\n\
    \    AdjacencyList graph(n, m);\n    for (int i = 0; i < m; ++i) {\n        auto\
    \ [s, t, d] = scanner.read<int, 3>();\n        graph.add_edge(s, t, d);\n    }\n\
    \    auto res = dijkstra(graph, s);\n    if (res.cost[t] == LINF) {\n        print(-1);\n\
    \    } else {\n        auto path = res.path(t);\n        int y = path.size();\n\
    \        print(res.cost[t], y - 1);\n        for (int i = 0; i < y - 1; ++i) print(path[i],\
    \ path[i + 1]);\n    }\n}\n}  // namespace bys\n\nint main() {\n    bys::Solver\
    \ solver;\n    solver.solve(/* bys::scanner.read<int>() */);\n    return 0;\n\
    }\n"
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
  - graphv2/dijkstra.hpp
  - graphv2/edge.hpp
  - graphv2/result.hpp
  isVerificationFile: true
  path: test/graphv2/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graphv2/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graphv2/dijkstra.test.cpp
- /verify/test/graphv2/dijkstra.test.cpp.html
title: test/graphv2/dijkstra.test.cpp
---
