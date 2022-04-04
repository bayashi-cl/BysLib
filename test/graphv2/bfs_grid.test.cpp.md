---
data:
  _extendedDependsOn:
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
  - icon: ':x:'
    path: graphv2/breadth_first_search.hpp
    title: Breadth First Search
  - icon: ':question:'
    path: graphv2/edge.hpp
    title: Edge
  - icon: ':question:'
    path: graphv2/result.hpp
    title: Shortest Path Result
  - icon: ':question:'
    path: utility/change.hpp
    title: chmin/chmax
  - icon: ':question:'
    path: utility/grid.hpp
    title: Grid Manager
  - icon: ':question:'
    path: utility/range.hpp
    title: Python::range
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc232/tasks/abc232_d
    links:
    - https://atcoder.jp/contests/abc232/tasks/abc232_d
  bundledCode: "#define PROBLEM \"https://atcoder.jp/contests/abc232/tasks/abc232_d\"\
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
    \ solve();\n    }\n};\n}  // namespace bys\n/**\n * @file edge.hpp\n * @brief\
    \ Edge\n * @todo concept\n */\nnamespace bys {\n//! @brief \u8FBA\nstruct Edge\
    \ {\n    std::size_t src, dest;\n    ll weight;\n    Edge() {}\n    Edge(std::size_t\
    \ src, std::size_t dest, ll weight = 1) : src(src), dest(dest), weight(weight)\
    \ {}\n    bool operator<(const Edge& rh) const { return weight < rh.weight; }\n\
    \    operator int() const { return dest; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge& e) {\n        return os << \"{\" << e.src << \" -> \" << e.dest\
    \ << \": \" << e.weight << \"}\";\n    }\n};\n//! @brief \u96A3\u63A5\u30EA\u30B9\
    \u30C8\nstruct DynamicAdjacencyList {\n    std::vector<std::vector<Edge>> data;\n\
    \    DynamicAdjacencyList(std::size_t n) : data(n, vector<Edge>()), _n(n) {}\n\
    \    std::vector<vector<Edge>>::reference operator[](std::size_t i) { return *(data.begin()\
    \ + i); }\n    const std::vector<vector<Edge>>::const_reference operator[](std::size_t\
    \ i) const { return *(data.cbegin() + i); }\n    void add_edge(const Edge& e)\
    \ { data[e.src].push_back(e); }\n    void add_edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }\n    std::size_t\
    \ size() const { return _n; }\n\n   private:\n    std::size_t _n;\n};\n/**\n *\
    \ @brief \u96A3\u63A5\u30EA\u30B9\u30C8\n *\n * CSR\u5F62\u5F0F\n * See: https://qiita.com/Nachia/items/d420c08b333296f54526\n\
    \ */\nstruct AdjacencyList {\n    AdjacencyList(std::size_t n, std::size_t m =\
    \ UINT64_MAX) : _n(n), _m(m), index(n + 1), _build_flg(m == 0) {}\n\n    struct\
    \ AdjacencyRange {\n        using iterator = std::vector<Edge>::const_iterator;\n\
    \        using reference = std::vector<Edge>::const_reference;\n        using\
    \ value_type = Edge;\n        iterator _begin, _end;\n        iterator begin()\
    \ const { return _begin; }\n        iterator end() const { return _end; }\n  \
    \      reference operator[](std::size_t i) const { return *(_begin + i); }\n \
    \       std::size_t size() const { return std::distance(_begin, _end); }\n   \
    \     bool empty() const { return size() == 0; }\n    };\n    AdjacencyRange operator[](std::size_t\
    \ i) const {\n        return AdjacencyRange{data.begin() + index[i], data.begin()\
    \ + index[i + 1]};\n    }\n\n    void build() {\n        std::partial_sum(index.begin(),\
    \ index.end(), index.begin());\n        data.resize(buf.size());\n        for\
    \ (auto&& e : buf) data[--index[e.src]] = e;\n        _build_flg = true;\n   \
    \ }\n    void add_edge(const Edge& e) {\n        ++index[e.src];\n        buf.emplace_back(e);\n\
    \        if (buf.size() == _m) build();\n    }\n    void add_edge(std::size_t\
    \ src, std::size_t dest, ll weight = 1) { add_edge(Edge(src, dest, weight)); }\n\
    \    std::size_t size() const { return _n; }\n    std::size_t n_edge() const {\
    \ return buf.size(); }\n    bool build_flg() const { return _build_flg; }\n\n\
    \   private:\n    std::size_t _n, _m;\n    std::vector<Edge> buf, data;\n    std::vector<std::size_t>\
    \ index;\n    bool _build_flg;\n};\n}  // namespace bys\n/**\n * @file result.hpp\n\
    \ * @brief Shortest Path Result\n */\nnamespace bys {\n/**\n * @brief \u5358\u4E00\
    \u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\n *\n * \u7D4C\u8DEF\u5FA9\u5143\u3082\u3067\
    \u304D\u308B\n */\nstruct SSSPResult {\n    std::size_t source;\n    std::vector<ll>\
    \ cost;\n    std::vector<int> prev;\n\n    SSSPResult(std::size_t _n, std::size_t\
    \ _source) : source(_source), cost(_n, LINF), prev(_n, -1) {}\n    vector<std::size_t>\
    \ path(int to) const {\n        vector<std::size_t> res;\n        while (to !=\
    \ -1) {\n            res.push_back(to);\n            to = prev[to];\n        }\n\
    \        std::reverse(res.begin(), res.end());\n        return res;\n    }\n};\n\
    /**\n * @brief \u5168\u9802\u70B9\u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF\n *\n *\
    \ \u7D4C\u8DEF\u5FA9\u5143\u3082\u3067\u304D\u308B\n */\nstruct APSPResult {\n\
    \    std::vector<std::vector<ll>> cost;\n    std::vector<std::vector<int>> prev;\n\
    \    APSPResult(std::size_t _n) : cost(_n, vector(_n, LINF)), prev(_n, vector(_n,\
    \ -1)) {}\n    std::vector<std::size_t> path(int from, int to) {\n        vector<std::size_t>\
    \ res;\n        for (int now = to; now != from; now = prev[from][now]) {\n   \
    \         res.push_back(now);\n        }\n        res.push_back(from);\n     \
    \   std::reverse(res.begin(), res.end());\n        return res;\n    }\n};\n} \
    \ // namespace bys\n/**\n * @file breadth_first_search.hpp\n * @brief Breadth\
    \ First Search\n *\n * \u5E45\u512A\u5148\u63A2\u7D22\n */\nnamespace bys {\n\
    /**\n * @brief \u5E45\u512A\u5148\u63A2\u7D22\n *\n * O(V + E)\n *\n * @param\
    \ graph AdjacencyList or DynamicAdjacencyList\n * @param source \u59CB\u70B9\n\
    \ * @return SSSPResult\n * @todo \u591A\u59CB\u70B9\u5BFE\u5FDC\n */\ntemplate\
    \ <class Adj>\nSSSPResult breadth_first_search(const Adj& graph, std::size_t source)\
    \ {\n    std::size_t n = graph.size();\n    SSSPResult res(n, source);\n    std::queue<std::size_t>\
    \ que;\n    que.emplace(source);\n    res.cost[source] = 0;\n    while (!que.empty())\
    \ {\n        auto top = que.front();\n        que.pop();\n        for (auto&&\
    \ next : graph[top]) {\n            if (res.cost[next] == LINF) {\n          \
    \      res.prev[next] = top;\n                res.cost[next] = res.cost[top] +\
    \ 1;\n                que.emplace(next.dest);\n            }\n        }\n    }\n\
    \    return res;\n}\n/**\n * @brief 01BFS\n *\n * O(V + E)\n *\n * @param graph\
    \ AdjacencyList or DynamicAdjacencyList\n * @param source \u59CB\u70B9\n * @return\
    \ SSSPResult\n */\ntemplate <class Adj>\nSSSPResult zero_one_bfs(const Adj& graph,\
    \ std::size_t source) {\n    std::size_t n = graph.size();\n    SSSPResult res(n,\
    \ source);\n    std::deque<std::size_t> que;\n    que.emplace_back(source);\n\
    \    res.cost[source] = 0;\n    while (!que.empty()) {\n        auto top = que.front();\n\
    \        que.pop_front();\n        for (auto&& next : graph[top]) {\n        \
    \    ll next_cost = res.cost[top] + next.weight;\n            if (next_cost >=\
    \ res.cost[next]) continue;\n            res.cost[next] = next_cost;\n       \
    \     res.prev[next] = top;\n            if (next.weight == 0) {\n           \
    \     que.emplace_front(next.dest);\n            } else if (next.weight == 1)\
    \ {\n                que.emplace_back(next.dest);\n            } else {\n    \
    \            throw RE;\n            }\n        }\n    }\n    return res;\n}\n\
    }  // namespace bys\n/**\n * @file change.hpp\n * @brief chmin/chmax\n */\nnamespace\
    \ bys {\n/**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true\
    \ \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T>\ninline\
    \ bool chmax(T& a, const T& b) {\n    return a < b ? a = b, true : false;\n}\n\
    /**\n * @brief \u6700\u5C0F\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\
    \u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T>\ninline bool chmin(T&\
    \ a, const T& b) {\n    return a > b ? a = b, true : false;\n}\n}  // namespace\
    \ bys\n/**\n * @file grid.hpp\n * @brief Grid Manager\n */\nnamespace bys {\n\
    //! @brief \u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u88DC\u52A9\u30C4\u30FC\u30EB\u8A70\
    \u3081\u5408\u308F\u305B\nstruct Grid {\n    int h, w;\n    //! @brief row*col\u306E\
    \u30B0\u30EA\u30C3\u30C9\n    Grid(int row, int col) : h(row), w(col) {}\n\n \
    \   //! @brief \u30B0\u30EA\u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u304B\u5224\
    \u5B9A\n    bool contain(int row, int col) const { return 0 <= row && row < h\
    \ && 0 <= col && col < w; }\n    //! @brief \u30B0\u30EA\u30C3\u30C9\u306E\u9762\
    \u7A4D\n    int area() const { return h * w; }\n    //! @brief \u4E00\u6B21\u5143\
    \u5316\u3057\u305F\u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n   \
    \ int index(int row, int col) const {\n        assert(contain(row, col));\n  \
    \      return row * w + col;\n    }\n    int index(std::pair<int, int> p) const\
    \ { return index(p.first, p.second); }\n    //! @brief \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u304B\u3089\u5FA9\u5143\n    std::pair<int, int> coord(int idx) const\
    \ {\n        assert(0 <= idx && idx < area());\n        return {idx / w, idx %\
    \ w};\n    }\n    //! \u5468\u56F2\u306E\u30DE\u30B9\u306E\u3046\u3061\u30B0\u30EA\
    \u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u3082\u306E\n    auto next(int row,\
    \ int col, const vector<pair<int, int>> delta) const {\n        assert(contain(row,\
    \ col));\n        std::vector<std::pair<int, int>> res;\n        for (auto [di,\
    \ dj] : delta) {\n            int ni = row + di;\n            int nj = col + dj;\n\
    \            if (contain(ni, nj)) res.push_back({ni, nj});\n        }\n      \
    \  return res;\n    }\n    //! @brief \u53F3\u30FB\u4E0B\n    auto next2(int row,\
    \ int col) const { return next(row, col, {{1, 0}, {0, 1}}); }\n    //! @brief\
    \ \u4E0A\u4E0B\u5DE6\u53F3\n    auto next4(int row, int col) const { return next(row,\
    \ col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }\n    //! @brief 8\u65B9\u5411\n\
    \    auto next8(int row, int col) const {\n        vector<pair<int, int>> delta;\n\
    \        for (int di = -1; di <= 1; ++di) {\n            for (int dj = -1; dj\
    \ <= 1; ++dj) {\n                if (di == 0 && dj == 0) continue;\n         \
    \       delta.push_back({di, dj});\n            }\n        }\n        return next(row,\
    \ col, delta);\n    }\n};\n}  // namespace bys\n/**\n * @file range.hpp\n * @brief\
    \ Python::range\n *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA range\u7DE8\
    \n * See: https://docs.python.org/ja/3/library/stdtypes.html#range\n */\nnamespace\
    \ bys {\ntemplate <typename T>\nclass Range {\n    T it;\n    const T stop, step;\n\
    \    const int dir;\n\n   public:\n    Range(T start, T stop, T step = 1) : it(start),\
    \ stop(stop), step(step), dir(step >= 0 ? 1 : -1) {}\n    Range(T stop) : it(0),\
    \ stop(stop), step(1), dir(1) {}\n    Range<T> begin() const { return *this; }\n\
    \    T end() const { return stop; }\n    bool operator!=(const T val) const {\
    \ return (val - it) * dir > 0; }\n    void operator++() { it += step; }\n    const\
    \ T& operator*() const { return it; }\n\n    friend Range reversed(const Range&\
    \ r) {\n        auto new_start = (r.stop - r.dir - r.it) / r.step * r.step + r.it;\n\
    \        return {new_start, r.it - r.dir, -r.step};\n    }\n};\n//! @brief range(stop)\n\
    template <class T>\nRange<T> irange(T stop) {\n    return Range(stop);\n}\n//!\
    \ @brief range(start, stop[, step])\ntemplate <class T>\nRange<T> irange(T start,\
    \ T stop, T step = 1) {\n    return Range(start, stop, step);\n}\n}  // namespace\
    \ bys\n\nnamespace bys {\nvoid Solver::solve() {\n    auto [h, w] = scanner.read<int,\
    \ 2>();\n    auto c = scanner.readvec<string>(h);\n    Grid grid(h, w);\n\n  \
    \  DynamicAdjacencyList graph(grid.area());\n    for (int i : Range(h)) {\n  \
    \      for (int j : Range(w)) {\n            if (c[i][j] == '#') continue;\n \
    \           for (auto [ni, nj] : grid.next2(i, j)) {\n                if (c[ni][nj]\
    \ == '.') graph.add_edge(grid.index(i, j), grid.index(ni, nj));\n            }\n\
    \        }\n    }\n    auto res = breadth_first_search(graph, 0);\n    ll ans\
    \ = 0;\n    for (const auto d : res.cost) {\n        if (d != LINF) chmax(ans,\
    \ d);\n    }\n    print(ans + 1);\n}\n}  // namespace bys\n\nint main() {\n  \
    \  bys::Solver solver;\n    solver.solve(/* bys::scanner.read<int>() */);\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc232/tasks/abc232_d\"\n#include\
    \ \"../../core/core.hpp\"\n#include \"../../graphv2/breadth_first_search.hpp\"\
    \n#include \"../../utility/change.hpp\"\n#include \"../../utility/grid.hpp\"\n\
    #include \"../../utility/range.hpp\"\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto [h, w] = scanner.read<int, 2>();\n    auto c = scanner.readvec<string>(h);\n\
    \    Grid grid(h, w);\n\n    DynamicAdjacencyList graph(grid.area());\n    for\
    \ (int i : Range(h)) {\n        for (int j : Range(w)) {\n            if (c[i][j]\
    \ == '#') continue;\n            for (auto [ni, nj] : grid.next2(i, j)) {\n  \
    \              if (c[ni][nj] == '.') graph.add_edge(grid.index(i, j), grid.index(ni,\
    \ nj));\n            }\n        }\n    }\n    auto res = breadth_first_search(graph,\
    \ 0);\n    ll ans = 0;\n    for (const auto d : res.cost) {\n        if (d !=\
    \ LINF) chmax(ans, d);\n    }\n    print(ans + 1);\n}\n}  // namespace bys\n\n\
    int main() {\n    bys::Solver solver;\n    solver.solve(/* bys::scanner.read<int>()\
    \ */);\n    return 0;\n}\n"
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
  - graphv2/breadth_first_search.hpp
  - graphv2/edge.hpp
  - graphv2/result.hpp
  - utility/change.hpp
  - utility/grid.hpp
  - utility/range.hpp
  isVerificationFile: true
  path: test/graphv2/bfs_grid.test.cpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graphv2/bfs_grid.test.cpp
layout: document
redirect_from:
- /verify/test/graphv2/bfs_grid.test.cpp
- /verify/test/graphv2/bfs_grid.test.cpp.html
title: test/graphv2/bfs_grid.test.cpp
---
