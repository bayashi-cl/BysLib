---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/constant.hpp
    title: Const
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':heavy_check_mark:'
    path: byslib/extension/change.hpp
    title: chmin/chmax
  - icon: ':heavy_check_mark:'
    path: byslib/extension/enumerate.hpp
    title: Python::enumerate
  - icon: ':heavy_check_mark:'
    path: byslib/extension/irange.hpp
    title: Python::range
  - icon: ':heavy_check_mark:'
    path: byslib/extension/macro.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: byslib/extension/subrange.hpp
    title: byslib/extension/subrange.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/bellman_ford.hpp
    title: Bellman Ford
  - icon: ':heavy_check_mark:'
    path: byslib/graph/edge.hpp
    title: byslib/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/graph.hpp
    title: byslib/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/io/io.hpp
    title: I/O
  - icon: ':heavy_check_mark:'
    path: byslib/io/printer.hpp
    title: Output
  - icon: ':heavy_check_mark:'
    path: byslib/io/scanner.hpp
    title: Input
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/coo.hpp
    title: byslib/linalg/coo.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/csr.hpp
    title: byslib/linalg/csr.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/sparsefwd.hpp
    title: byslib/linalg/sparsefwd.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/procon/solver.hpp
    title: Solver
  - icon: ':heavy_check_mark:'
    path: byslib/procon/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: byslib/template.hpp
    title: byslib/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\"\
    \n#include <cstddef>\n#include <limits>\n#include <tuple>\n#include <utility>\n\
    \n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    using u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\nusing u128 = __uint128_t;\nusing f32 = float;\nusing\
    \ f64 = double;\nusing f128 = long double;\n\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr\
    \ auto operator\"\" name(unsigned long long x) { return static_cast<type>(x);\
    \ }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16, std::int16_t);\n\
    DEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64, std::int64_t);\n\
    DEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8, std::uint8_t);\n\
    DEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32, std::uint32_t);\n\
    DEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128, __uint128_t);\n\
    DEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n}  // namespace\
    \ bys\n#include <array>\n#include <iostream>\n#include <type_traits>\n/**\n *\
    \ @file traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\nnamespace\
    \ bys {\ntemplate <class, class = void> struct has_rshift_from_istream : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\ntemplate <class T> constexpr\
    \ bool has_rshift_from_istream_v = has_rshift_from_istream<T>::value;\n\ntemplate\
    \ <class, class = void> struct has_lshift_to_ostream : std::false_type {};\ntemplate\
    \ <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\ntemplate <class T> constexpr\
    \ bool has_lshft_to_ostream_v = has_lshift_to_ostream<T>::value;\n\ntemplate <class,\
    \ class = void> struct is_tuple_like : std::false_type {};\ntemplate <class T>\
    \ struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\ntemplate <class T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\n\
    \ntemplate <class, class = void> struct is_iterable : std::false_type {};\ntemplate\
    \ <class T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>\
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
    \n/**\n * @file constant.hpp\n * @brief Const\n */\nnamespace bys {\nconstexpr\
    \ i32 MOD7 = 1000000007;\nconstexpr i32 MOD9 = 998244353;\nconstexpr i32 MOD =\
    \ MOD9;\n\ntemplate <class T> constexpr T get_inf();\nnamespace impl {\ntemplate\
    \ <class Tp, std::size_t... I> constexpr auto get_inf_tuple(std::index_sequence<I...>)\
    \ {\n    return Tp{get_inf<typename std::tuple_element_t<I, Tp>>()...};\n}\n}\
    \  // namespace impl\ntemplate <class T> constexpr T get_inf() {\n    if constexpr\
    \ (std::is_integral_v<T>) {\n        return std::numeric_limits<T>::max() / (T)2;\n\
    \    } else if constexpr (std::is_floating_point_v<T>) {\n        return std::numeric_limits<T>::infinity();\n\
    \    } else if constexpr (is_tuple_like_v<T>) {\n        return impl::get_inf_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \    } else {\n        static_assert([]() { return false; }, \"Type Error\");\n\
    \    }\n}\ntemplate <class T> constexpr bool is_inf(T x) { return x == get_inf<T>();\
    \ }\nconstexpr auto INF = get_inf<i32>();\nconstexpr auto LINF = get_inf<i64>();\n\
    }  // namespace bys\n/**\n * @file change.hpp\n * @brief chmin/chmax\n */\nnamespace\
    \ bys {\n/**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true\
    \ \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T> constexpr\
    \ bool chmax(T& a, T const& b) { return a < b ? a = b, true : false; }\n/**\n\
    \ * @brief \u6700\u5C0F\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\
    \u308C\u305F\u3068\u304D\n */\ntemplate <class T> constexpr bool chmin(T& a, T\
    \ const& b) { return a > b ? a = b, true : false; }\n}  // namespace bys\n\n\n\
    #include <numeric>\n#include <vector>\n\n#include <iterator>\n\n\nnamespace bys\
    \ {\ntemplate <class Iterator> class SubRange {\n  public:\n    using iterator\
    \ = Iterator;\n    using reverse_iterator = std::reverse_iterator<iterator>;\n\
    \    using value_type = typename iterator::value_type;\n\n    SubRange() = default;\n\
    \    SubRange(const SubRange& s) : _begin(s._begin), _end(s._end) {}\n    SubRange(const\
    \ iterator& begin, const iterator& end) : _begin(begin), _end(end) {}\n\n    iterator\
    \ begin() const noexcept { return _begin; }\n    iterator end() const noexcept\
    \ { return _end; }\n    reverse_iterator rbegin() const noexcept { return reverse_iterator{_end};\
    \ }\n    reverse_iterator rend() const { return reverse_iterator{_begin}; }\n\
    \    auto operator[](std::size_t i) const noexcept { return *(_begin + i); }\n\
    \    auto size() const noexcept { return _end - _begin; }\n    bool empty() const\
    \ noexcept { return _begin == _end; }\n\n    auto to_vec() const { return std::vector(_begin,\
    \ _end); }\n\n  private:\n    iterator _begin, _end;\n};\ntemplate <class Iterable>\
    \ auto reversed(Iterable&& iter) {\n    static_assert(is_iterable_v<Iterable>,\
    \ \"iter is not iterable\");\n    return SubRange(std::rbegin(std::forward<Iterable>(iter)),\
    \ std::rend(std::forward<Iterable>(iter)));\n}\n}  // namespace bys\n#include\
    \ <algorithm>\n#include <cassert>\n\nnamespace bys {\ntemplate <class T> struct\
    \ CSRMatrix;\n}\n\nnamespace bys {\ntemplate <class T> class COOMatrix {\n  public:\n\
    \    using value_type = T;\n    const std::pair<i32, i32> shape;\n\n  private:\n\
    \    std::vector<std::tuple<i32, i32, T>> _data;\n    std::vector<i32> _col_cnt;\n\
    \n  public:\n    COOMatrix(i32 n, i32 m = -1) : shape{n, m}, _col_cnt(n) {}\n\n\
    \    void set(i32 i, i32 j, const T& v) {\n        assert(0 <= i and i < shape.first);\n\
    \        ++_col_cnt[i];\n        _data.emplace_back(i, j, v);\n    }\n    void\
    \ push_back(i32 i, T&& v) { set(i, _col_cnt[i], std::forward<T>(v)); }\n    template\
    \ <class... Args> void emplace_back(i32 i, Args&&... args) { set(i, _col_cnt[i],\
    \ {std::forward<Args>(args)...}); }\n    auto begin() const { return _data.begin();\
    \ }\n    auto end() const { return _data.end(); }\n\n    void sort() {\n     \
    \   std::sort(_data.begin(), _data.end(), [](const std::tuple<i32, i32, T>& a,\
    \ const std::tuple<i32, i32, T>& b) {\n            return std::get<2>(a) < std::get<2>(b);\n\
    \        });\n    }\n    std::size_t size() const { return shape.first; }\n  \
    \  std::ptrdiff_t ssize() const { return shape.first; }\n    std::size_t nonzero()\
    \ const { return _data.size(); }\n\n    friend CSRMatrix<T>;\n};\n}  // namespace\
    \ bys\n\nnamespace bys {\ntemplate <class T> class CSRMatrix {\n  public:\n  \
    \  using value_type = T;\n    const std::pair<i32, i32> shape;\n\n  private:\n\
    \    std::vector<i32> _indptr, _indices;\n    std::vector<T> _data;\n\n  public:\n\
    \    CSRMatrix(const COOMatrix<T>& coo)\n        : shape(coo.shape), _indptr(coo._col_cnt),\
    \ _indices(coo._data.size()), _data(coo._data.size()) {\n        _indptr.push_back(0);\n\
    \n        std::partial_sum(_indptr.begin(), _indptr.end(), _indptr.begin());\n\
    \        for (auto&& [i, j, v] : coo._data) {\n            i32 index = --_indptr[i];\n\
    \            _indices[index] = j;\n            _data[index] = v;\n        }\n\
    \    }\n    CSRMatrix(std::pair<i32, i32> shape, const std::vector<std::vector<std::pair<i32,\
    \ T>>>& data)\n        : shape(shape), _indptr(shape.first + 1) {\n        for\
    \ (i32 i = 0; i < shape.first; ++i) {\n            for (auto&& [index, elem] :\
    \ data[i]) {\n                _indices.push_back(index);\n                _data.push_back(elem);\n\
    \            }\n            _indptr[i + 1] += _indptr[i] + data[i].size();\n \
    \       }\n    }\n    auto operator[](std::size_t i) const { return SubRange(_data.cbegin()\
    \ + _indptr[i], _data.cbegin() + _indptr[i + 1]); }\n    std::size_t size() const\
    \ { return shape.first; }\n    std::ptrdiff_t ssize() const { return shape.first;\
    \ }\n};\n}  // namespace bys\n\nnamespace bys {\nstruct EdgeBase {};\n\ntemplate\
    \ <class WeightType = i64, class VertexType = i32> struct Edge : EdgeBase {\n\
    \    using weight_type = WeightType;\n    using vertex_type = VertexType;\n  \
    \  vertex_type src, dest;\n    weight_type weight;\n\n    Edge() : src(-1), dest(-1),\
    \ weight(get_inf<weight_type>()) {}\n    Edge(vertex_type src_, vertex_type dest_,\
    \ weight_type weight_ = 1) : src(src_), dest(dest_), weight(weight_) {}\n\n  \
    \  bool operator<(const Edge& other) const { return weight < other.weight; }\n\
    \    friend std::ostream& operator<<(std::ostream& os, Edge const& e) {\n    \
    \    return os << '{' << e.src << \" -> \" << e.dest << \": \" << e.weight <<\
    \ '}';\n    }\n};\n\ntemplate <class InfoType, class WeightType = i64, class VertexType\
    \ = i32> struct InfoEdge : Edge<WeightType, VertexType> {\n    using info_type\
    \ = InfoType;\n    using super = Edge<WeightType, VertexType>;\n    using super::Edge;\n\
    \    using typename super::vertex_type;\n    using typename super::weight_type;\n\
    \n    info_type info;\n    InfoEdge(vertex_type src_, vertex_type dest_, weight_type\
    \ weight_ = 1, info_type info_ = info_type())\n        : super(src_, dest_, weight_),\
    \ info(info_) {}\n};\n\ntemplate <class E> constexpr bool is_edge_v = std::is_base_of_v<EdgeBase,\
    \ E>;\n}  // namespace bys\n\nnamespace bys {\nenum class Directed : bool { undirected,\
    \ directed };\nconstexpr auto directed = Directed::directed;\nconstexpr auto undirected\
    \ = Directed::undirected;\n\ntemplate <class E> class EdgesCSR;\n\ntemplate <class\
    \ E> class EdgesCOO {\n    COOMatrix<E> coo;\n\n  public:\n    using edge_type\
    \ = E;\n    using vertex_type = typename edge_type::vertex_type;\n    using weight_type\
    \ = typename edge_type::weight_type;\n    Directed directed_kind;\n\n    template\
    \ <class Itr> class EdgeIterator {\n        Itr coo_itr;\n\n      public:\n  \
    \      using difference_type = std::ptrdiff_t;\n        using value_type = edge_type;\n\
    \        using reference = edge_type&;\n        using pointer = edge_type*;\n\
    \        using iterator_category = std::bidirectional_iterator_tag;\n\n      \
    \  EdgeIterator(const Itr& itr) : coo_itr(itr) {}\n        auto operator*() {\
    \ return std::get<2>(*coo_itr); }\n        auto operator*() const { return std::get<2>(*coo_itr);\
    \ }\n\n        EdgeIterator& operator++() noexcept {\n            ++coo_itr;\n\
    \            return *this;\n        }\n        EdgeIterator& operator--() noexcept\
    \ {\n            --coo_itr;\n            return *this;\n        }\n        bool\
    \ operator==(EdgeIterator const& other) const { return coo_itr == other.coo_itr;\
    \ }\n        bool operator!=(EdgeIterator const& other) const { return coo_itr\
    \ != other.coo_itr; }\n    };\n\n    EdgesCOO(i32 n, Directed dir) : coo(n, -1),\
    \ directed_kind(dir) {}\n    std::size_t size() const { return coo.shape.first;\
    \ }\n    std::ptrdiff_t ssize() const { return coo.shape.first; }\n    std::size_t\
    \ n_edges() const { return coo.nonzero(); }\n    auto begin() const { return EdgeIterator(coo.begin());\
    \ }\n    auto end() const { return EdgeIterator(coo.end()); }\n    void sort()\
    \ { coo.sort(); }\n\n    void add(edge_type& e) { coo.push_back(e.src, e); }\n\
    \    void add_edge(vertex_type src, vertex_type dest, weight_type weight = 1)\
    \ {\n        coo.push_back(src, {src, dest, weight});\n        if (directed_kind\
    \ == Directed::undirected) coo.push_back(dest, {dest, src, weight});\n    }\n\n\
    \    auto build() const { return EdgesCSR<edge_type>(coo, directed_kind); }\n\
    };\ntemplate <class E> class EdgesCSR : public CSRMatrix<E> {\n  public:\n   \
    \ using edge_type = E;\n    using vertex_type = typename edge_type::vertex_type;\n\
    \    using weight_type = typename edge_type::weight_type;\n    Directed directed_kind;\n\
    \    EdgesCSR(const COOMatrix<E>& coo, Directed dir) : CSRMatrix<E>::CSRMatrix(coo),\
    \ directed_kind(dir) {}\n};\n\nusing EdgeList = EdgesCOO<Edge<>>;\nusing AdjList\
    \ = EdgesCSR<Edge<>>;\n}  // namespace bys\n/**\n * @file bellman_ford.hpp\n *\
    \ @brief Bellman Ford\n */\nnamespace bys {\n/**\n * @brief \u30D9\u30EB\u30DE\
    \u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\n *\n * O(VE)\n *\n * @param elist \u8FBA\
    \u30EA\u30B9\u30C8\n * @param n_node \u9802\u70B9\u6570\n * @param source \u59CB\
    \u70B9\n * @return inf -> \u5230\u9054\u4E0D\u53EF, -inf -> \u8CA0\u9589\u8DEF\
    \n */\ntemplate <class E> std::vector<typename E::weight_type> bellman_ford(EdgesCOO<E>\
    \ const& edges, typename E::vertex_type source) {\n    using W = typename E::weight_type;\n\
    \    std::vector cost(edges.size(), get_inf<W>());\n    i32 n = edges.size();\n\
    \    cost[source] = 0;\n    for (i32 i = 0; i < n - 1; ++i) {\n        for (auto&&\
    \ e : edges) {\n            if (is_inf(cost[e.src])) continue;\n            chmin(cost[e.dest],\
    \ cost[e.src] + e.weight);\n        }\n    }\n    std::vector<bool> neg_cycle(n);\n\
    \    for (i32 i = 0; i < n; ++i) {\n        for (auto&& e : edges) {\n       \
    \     if (is_inf(cost[e.src])) continue;\n            if (chmin(cost[e.dest],\
    \ cost[e.src] + e.weight) || neg_cycle[e.src]) neg_cycle[e.dest] = true;\n   \
    \     }\n    }\n    for (i32 i = 0; i < n; ++i) {\n        if (neg_cycle[i]) cost[i]\
    \ = -get_inf<W>();\n    }\n    return cost;\n}\n}  // namespace bys\n/**\n * @file\
    \ template.hpp\n * @author bayashi_cl\n *\n * C++ library for competitive programming\
    \ by bayashi_cl\n * Repository: https://github.com/bayashi-cl/byslib\n * Document\
    \  : https://bayashi-cl.github.io/byslib/\n */\n#ifndef LOCAL\n#define NDEBUG\n\
    #endif\n\n/**\n * @file enumerate.hpp\n * @brief Python::enumerate\n *\n * Python\u518D\
    \u73FE\u30B7\u30EA\u30FC\u30BA enumerate\u7DE8\n * See: https://docs.python.org/ja/3/library/functions.html#enumerate\n\
    \ */\nnamespace bys {\ntemplate <class Iterator> struct EnumerateIterator {\n\
    \  public:\n    using difference_type = typename Iterator::difference_type;\n\
    \    using value_type = std::tuple<i32, typename Iterator::value_type>;\n    //\
    \ using pointer = value_type*;\n    using reference = value_type&;\n    using\
    \ iterator_category = std::forward_iterator_tag;\n\n    EnumerateIterator(const\
    \ Iterator& iterator, i32 idx) : index(idx), value(iterator) {}\n\n    auto& operator++()\
    \ {\n        ++value;\n        ++index;\n        return *this;\n    }\n    bool\
    \ operator!=(const EnumerateIterator& other) const { return value != other.value;\
    \ }\n    auto operator*() const { return std::tie(index, *value); }\n\n  private:\n\
    \    i32 index;\n    Iterator value;\n};\n\n/**\n * @brief enumerate\n *\n * @param\
    \ iterable \u5BFE\u8C61\n * @param start index\u306E\u521D\u671F\u5024\n */\n\
    template <class Iterable> auto enumerate(Iterable& iterable, i32 start = 0) {\n\
    \    using iterator_t = EnumerateIterator<typename Iterable::iterator>;\n    i32\
    \ end = static_cast<i32>(iterable.size()) + start;\n    return SubRange(iterator_t(std::begin(iterable),\
    \ start), iterator_t(std::end(iterable), end));\n}\n/**\n * @brief const enumerate\n\
    \ *\n * @param iterable \u5BFE\u8C61\n * @param start index\u306E\u521D\u671F\u5024\
    \n */\ntemplate <class Iterable> auto cenumerate(Iterable& iterable, i32 start\
    \ = 0) {\n    using iterator_t = EnumerateIterator<typename Iterable::const_iterator>;\n\
    \    i32 end = static_cast<i32>(iterable.size()) + start;\n    return SubRange(iterator_t(std::cbegin(iterable),\
    \ start), iterator_t(std::cend(iterable), end));\n}\n}  // namespace bys\n/**\n\
    \ * @file irange.hpp\n * @brief Python::range\n *\n * Python\u518D\u73FE\u30B7\
    \u30EA\u30FC\u30BA range\u7DE8\n * See: https://docs.python.org/ja/3/library/stdtypes.html#range\n\
    \ */\nnamespace bys {\ntemplate <class T> class IntegerIncrementIterator {\n \
    \ public:\n    using difference_type = std::ptrdiff_t;\n    using value_type =\
    \ T;\n    using reference = T;\n    using pointer = T*;\n    using iterator_category\
    \ = std::bidirectional_iterator_tag;\n\n    explicit IntegerIncrementIterator(T\
    \ x) : value(x) {}\n\n    reference operator*() noexcept { return value; }\n \
    \   const reference operator*() const noexcept { return value; }\n\n    auto operator++()\
    \ noexcept {\n        ++value;\n        return *this;\n    }\n    auto operator++(int)\
    \ noexcept {\n        auto temp = *this;\n        ++*this;\n        return temp;\n\
    \    }\n    auto operator--() noexcept {\n        --value;\n        return *this;\n\
    \    }\n    auto operator--(int) {\n        auto temp = *this;\n        --*this;\n\
    \        return temp;\n    }\n\n    bool operator!=(IntegerIncrementIterator const&\
    \ other) const { return value != other.value; }\n    bool operator==(IntegerIncrementIterator\
    \ const& other) const { return value == other.value; }\n\n  private:\n    value_type\
    \ value;\n};\n\ntemplate <class T> class IntegerStepIterator {\n  public:\n  \
    \  using difference_type = std::ptrdiff_t;\n    using value_type = T;\n    using\
    \ reference = T;\n    using pointer = T*;\n    using iterator_category = std::bidirectional_iterator_tag;\n\
    \n    explicit IntegerStepIterator(T f, T x, T s) : start(f), value(x), step(s)\
    \ {}\n\n    reference operator*() noexcept { return start + value * step; }\n\
    \    const reference operator*() const noexcept { return start + value * step;\
    \ }\n\n    auto operator++() {\n        ++value;\n        return *this;\n    }\n\
    \    auto operator++(int) {\n        auto temp = *this;\n        ++*this;\n  \
    \      return temp;\n    }\n    auto operator--() {\n        --value;\n      \
    \  return *this;\n    }\n    auto operator--(int) {\n        auto temp = *this;\n\
    \        --*this;\n        return temp;\n    }\n\n    bool operator!=(IntegerStepIterator\
    \ const& other) const { return value != other.value; }\n    bool operator==(IntegerStepIterator\
    \ const& other) const { return value == other.value; }\n\n  private:\n    value_type\
    \ start, value, step;\n};\n\ntemplate <class T> SubRange<IntegerIncrementIterator<T>>\
    \ irange(T stop) {\n    static_assert(std::is_integral_v<T>, \"T is not integer.\"\
    );\n    using iterator_t = IntegerIncrementIterator<T>;\n    if (stop < static_cast<T>(0))\
    \ stop = static_cast<T>(0);\n    return SubRange(iterator_t(static_cast<T>(0)),\
    \ iterator_t(stop));\n}\ntemplate <class T> SubRange<IntegerIncrementIterator<T>>\
    \ irange(T start, T stop) {\n    static_assert(std::is_integral_v<T>, \"T is not\
    \ integer.\");\n    using iterator_t = IntegerIncrementIterator<T>;\n    if (stop\
    \ < start) stop = start;\n    return SubRange(iterator_t(start), iterator_t(stop));\n\
    }\ntemplate <class T> SubRange<IntegerStepIterator<T>> irange(T start, T stop,\
    \ T step) {\n    static_assert(std::is_integral_v<T>, \"T is not integer.\");\n\
    \    using iterator_t = IntegerStepIterator<T>;\n    assert(step != 0);\n    auto\
    \ w = step >= 0 ? stop - start : start - stop;\n    auto s = step >= 0 ? step\
    \ : -step;\n    if (w < 0) w = 0;\n    return SubRange(iterator_t(start, static_cast<T>(0),\
    \ step), iterator_t(start, (w + s - 1) / s, step));\n}\n}  // namespace bys\n\
    #include <string>\nusing std::literals::string_literals::operator\"\"s;\n/**\n\
    \ * @file macro.hpp\n * @brief Macro\n */\n// clang-format off\n#define CONCAT_IMPL(a,\
    \ b) a##b\n#define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\
    \u5909\u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"file: \"s + __FILE__ + \", line:\
    \ \"s + std::to_string(__LINE__) + \", func: \"s + __func__)\n#ifdef LOCAL\n#define\
    \ DEBUGBLOCK(block) block\n#else\n#define DEBUGBLOCK(block)\n#endif\n// clang-format\
    \ on\n#include <iomanip>\n\n/**\n * @file printer.hpp\n * @brief Output\n */\n\
    namespace bys {\nclass Printer {\n    std::ostream& _os;\n    // sep1 \"\\n\"\
    \       : iterable<iterable>\n    // sep2 \" \" or \"\\n\": iterable, args\n \
    \   // sep3 \" \"        : tuple_like\n    std::string sep1 = \"\\n\", sep2 =\
    \ \" \", sep3 = \" \", end = \"\\n\";\n\n    template <std::size_t I, class T>\
    \ void print_tuple_element(T&& elem) {\n        if constexpr (I != 0) cat(sep3);\n\
    \        cat(std::forward<T>(elem));\n    }\n    template <class Tp, std::size_t...\
    \ I> void print_tuple(Tp&& tp, std::index_sequence<I...>) {\n        (print_tuple_element<I>(std::forward<std::tuple_element_t<I,\
    \ std::decay_t<Tp>>>(std::get<I>(tp))), ...);\n    }\n\n  public:\n    Printer()\
    \ = delete;\n    Printer(std::ostream& os) : _os(os) { _os << std::fixed << std::setprecision(11)\
    \ << std::boolalpha; }\n    ~Printer() { _os << std::flush; }\n\n    template\
    \ <class T> void cat(T&& v) {\n        if constexpr (has_lshft_to_ostream_v<std::decay_t<T>>)\
    \ {\n            _os << v;\n        } else if constexpr (is_iterable_v<std::decay_t<T>>)\
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
    \ return *this;\n    }\n};\n}  // namespace bys\n\n/**\n * @file scanner.hpp\n\
    \ * @brief Input\n */\nnamespace bys {\nclass Scanner {\n    std::istream& _is;\n\
    \    template <class T, std::size_t... I> auto read_tuple(std::index_sequence<I...>)\
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
    \    }\n}  // namespace bys\n\n#include <unistd.h>\n\n\n\n/**\n * @file solver.hpp\n\
    \ * @brief Solver\n */\nnamespace bys {\nstruct Solver {\n    static inline i32\
    \ TESTCASE = 1;\n    static void solve();\n    static i32 main(i32 t = 1) {\n\
    \        std::ios::sync_with_stdio(false);\n\n        for (; TESTCASE <= t; ++TESTCASE)\
    \ solve();\n#ifdef LOCAL\n        if (not std::cin.good()) std::cerr << \"\U0001F7E1\
    \ Input failed.\" << std::endl;\n        if (not isatty(STDIN_FILENO) and not\
    \ std::ws(std::cin).eof()) std::cerr << \"\U0001F7E1 Unused input.\" << std::endl;\n\
    #endif\n        return 0;\n    }\n};\n}  // namespace bys\n/**\n * @file stdlib.hpp\n\
    \ * @brief STL Template\n */\n#include <bitset>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <map>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <unordered_map>\n#include <unordered_set>\n\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs;\n\n// alias\nusing Pa = std::pair<i32, i32>;\nusing Pa64 = std::pair<i64,\
    \ i64>;\ntemplate <class T> using uset = std::unordered_set<T>;\ntemplate <class\
    \ S, class T> using umap = std::unordered_map<S, T>;\n}  // namespace bys\n\n\
    namespace bys {\nvoid Solver::solve() {\n    auto [v, e, r] = scanner.read<i32,\
    \ 3>();\n\n    EdgeList edges(v, directed);\n    for (UV : irange(e)) {\n    \
    \    auto [s, t, d] = scanner.read<i32, i32, i64>();\n        edges.add_edge(s,\
    \ t, d);\n    }\n    auto res = bellman_ford(edges, r);\n    for (auto ans : res)\
    \ {\n        if (is_inf(-ans)) EXIT(\"NEGATIVE CYCLE\");\n    }\n    for (auto\
    \ ans : res) {\n        if (is_inf(ans)) {\n            print(\"INF\");\n    \
    \    } else {\n            print(ans);\n        }\n    }\n}\n}  // namespace bys\n\
    \nint main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\"\
    \n#include \"../../byslib/graph/bellman_ford.hpp\"\n#include \"../../byslib/template.hpp\"\
    \n\nnamespace bys {\nvoid Solver::solve() {\n    auto [v, e, r] = scanner.read<i32,\
    \ 3>();\n\n    EdgeList edges(v, directed);\n    for (UV : irange(e)) {\n    \
    \    auto [s, t, d] = scanner.read<i32, i32, i64>();\n        edges.add_edge(s,\
    \ t, d);\n    }\n    auto res = bellman_ford(edges, r);\n    for (auto ans : res)\
    \ {\n        if (is_inf(-ans)) EXIT(\"NEGATIVE CYCLE\");\n    }\n    for (auto\
    \ ans : res) {\n        if (is_inf(ans)) {\n            print(\"INF\");\n    \
    \    } else {\n            print(ans);\n        }\n    }\n}\n}  // namespace bys\n\
    \nint main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }\n"
  dependsOn:
  - byslib/graph/bellman_ford.hpp
  - byslib/core/constant.hpp
  - byslib/core/int_alias.hpp
  - byslib/core/traits.hpp
  - byslib/extension/change.hpp
  - byslib/graph/graph.hpp
  - byslib/graph/edge.hpp
  - byslib/linalg/csr.hpp
  - byslib/extension/subrange.hpp
  - byslib/linalg/coo.hpp
  - byslib/linalg/sparsefwd.hpp
  - byslib/template.hpp
  - byslib/extension/enumerate.hpp
  - byslib/extension/irange.hpp
  - byslib/extension/macro.hpp
  - byslib/io/io.hpp
  - byslib/io/printer.hpp
  - byslib/io/scanner.hpp
  - byslib/procon/solver.hpp
  - byslib/procon/stdlib.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-02 16:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_B.test.cpp
- /verify/test/AOJ/GRL_1_B.test.cpp.html
title: test/AOJ/GRL_1_B.test.cpp
---
