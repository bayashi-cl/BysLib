---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/io.hpp
    title: core/io.hpp
  - icon: ':heavy_check_mark:'
    path: core/printer.hpp
    title: core/printer.hpp
  - icon: ':heavy_check_mark:'
    path: core/scanner.hpp
    title: core/scanner.hpp
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: core/types.hpp
    title: core/types.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/edge.hpp
    title: graphv2/edge.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <cmath>\n#include <complex>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n#include <utility>\n\nnamespace bys {\ntemplate <class, class = void>\n\
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
    \ debug(std::cerr);\nScanner scanner(std::cin);\n}  // namespace bys\nnamespace\
    \ bys {\nstruct Edge {\n    std::size_t src, dest;\n    ll weight;\n    Edge()\
    \ {}\n    Edge(std::size_t src, std::size_t dest, ll weight = 1) : src(src), dest(dest),\
    \ weight(weight) {}\n    bool operator<(const Edge& rh) const { return weight\
    \ < rh.weight; }\n    operator int() const { return dest; }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge& e) {\n        return os << \"{\" <<\
    \ e.src << \" -> \" << e.dest << \": \" << e.weight << \"}\";\n    }\n};\nstruct\
    \ DynamicAdjacencyList {\n    std::vector<std::vector<Edge>> data;\n    DynamicAdjacencyList(std::size_t\
    \ n) : data(n, vector<Edge>()), _n(n) {}\n    std::vector<vector<Edge>>::reference\
    \ operator[](std::size_t i) { return *(data.begin() + i); }\n    const std::vector<vector<Edge>>::const_reference\
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
    \ bys\nnamespace bys {\nAdjacencyList read_adj_uv(std::size_t n, std::size_t m,\
    \ bool directed = false, int index = 1) {\n    AdjacencyList graph(n, directed\
    \ ? m : 2 * m);\n    for (std::size_t i = 0; i < m; ++i) {\n        auto [u, v]\
    \ = scanner.read<int, 2>();\n        u -= index;\n        v -= index;\n      \
    \  graph.add_edge(u, v);\n        if (!directed) graph.add_edge(v, u);\n    }\n\
    \    return graph;\n}\nAdjacencyList read_adj_uvc(std::size_t n, std::size_t m,\
    \ bool directed = false, int index = 1) {\n    AdjacencyList graph(n, directed\
    \ ? m : 2 * m);\n    for (std::size_t i = 0; i < m; ++i) {\n        auto [u, v,\
    \ c] = scanner.read<int, int, ll>();\n        u -= index;\n        v -= index;\n\
    \        graph.add_edge(u, v, c);\n        if (!directed) graph.add_edge(v, u,\
    \ c);\n    }\n    return graph;\n}\nAdjacencyList read_tree_uv(std::size_t n,\
    \ bool directed = false, int index = 1) { return read_adj_uv(n, n - 1, directed,\
    \ index); }\nAdjacencyList read_tree_uvc(std::size_t n, bool directed = false,\
    \ int index = 1) {\n    return read_adj_uvc(n, n - 1, directed, index);\n}\nvector<Edge>\
    \ read_elist_uv(std::size_t m, int index = 1) {\n    vector<Edge> elist;\n   \
    \ elist.reserve(m);\n    for (std::size_t i = 0; i < m; ++i) {\n        auto [u,\
    \ v] = scanner.read<int, 2>();\n        u -= index;\n        v -= index;\n   \
    \     elist.emplace_back(Edge(u, v, 1));\n    }\n    return elist;\n}\nvector<Edge>\
    \ read_elist_uvc(std::size_t m, int index = 1) {\n    vector<Edge> elist;\n  \
    \  elist.reserve(m);\n    for (std::size_t i = 0; i < m; ++i) {\n        auto\
    \ [u, v, c] = scanner.read<int, int, ll>();\n        u -= index;\n        v -=\
    \ index;\n        elist.emplace_back(Edge(u, v, c));\n    }\n    return elist;\n\
    }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/io.hpp\"\n#include \"../core/stdlib.hpp\"\
    \n#include \"edge.hpp\"\nnamespace bys {\nAdjacencyList read_adj_uv(std::size_t\
    \ n, std::size_t m, bool directed = false, int index = 1) {\n    AdjacencyList\
    \ graph(n, directed ? m : 2 * m);\n    for (std::size_t i = 0; i < m; ++i) {\n\
    \        auto [u, v] = scanner.read<int, 2>();\n        u -= index;\n        v\
    \ -= index;\n        graph.add_edge(u, v);\n        if (!directed) graph.add_edge(v,\
    \ u);\n    }\n    return graph;\n}\nAdjacencyList read_adj_uvc(std::size_t n,\
    \ std::size_t m, bool directed = false, int index = 1) {\n    AdjacencyList graph(n,\
    \ directed ? m : 2 * m);\n    for (std::size_t i = 0; i < m; ++i) {\n        auto\
    \ [u, v, c] = scanner.read<int, int, ll>();\n        u -= index;\n        v -=\
    \ index;\n        graph.add_edge(u, v, c);\n        if (!directed) graph.add_edge(v,\
    \ u, c);\n    }\n    return graph;\n}\nAdjacencyList read_tree_uv(std::size_t\
    \ n, bool directed = false, int index = 1) { return read_adj_uv(n, n - 1, directed,\
    \ index); }\nAdjacencyList read_tree_uvc(std::size_t n, bool directed = false,\
    \ int index = 1) {\n    return read_adj_uvc(n, n - 1, directed, index);\n}\nvector<Edge>\
    \ read_elist_uv(std::size_t m, int index = 1) {\n    vector<Edge> elist;\n   \
    \ elist.reserve(m);\n    for (std::size_t i = 0; i < m; ++i) {\n        auto [u,\
    \ v] = scanner.read<int, 2>();\n        u -= index;\n        v -= index;\n   \
    \     elist.emplace_back(Edge(u, v, 1));\n    }\n    return elist;\n}\nvector<Edge>\
    \ read_elist_uvc(std::size_t m, int index = 1) {\n    vector<Edge> elist;\n  \
    \  elist.reserve(m);\n    for (std::size_t i = 0; i < m; ++i) {\n        auto\
    \ [u, v, c] = scanner.read<int, int, ll>();\n        u -= index;\n        v -=\
    \ index;\n        elist.emplace_back(Edge(u, v, c));\n    }\n    return elist;\n\
    }\n}  // namespace bys\n"
  dependsOn:
  - core/io.hpp
  - core/stdlib.hpp
  - core/printer.hpp
  - core/types.hpp
  - core/scanner.hpp
  - graphv2/edge.hpp
  isVerificationFile: false
  path: graphv2/reader.hpp
  requiredBy: []
  timestamp: '2022-02-26 15:09:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphv2/reader.hpp
layout: document
redirect_from:
- /library/graphv2/reader.hpp
- /library/graphv2/reader.hpp.html
title: graphv2/reader.hpp
---