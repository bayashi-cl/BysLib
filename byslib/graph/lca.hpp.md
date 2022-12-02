---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/algebra/monoid.hpp
    title: Monoid
  - icon: ':question:'
    path: byslib/core/constant.hpp
    title: Const
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':x:'
    path: byslib/ds/sparse_table.hpp
    title: Sparse Table
  - icon: ':warning:'
    path: byslib/extension/fixpoint.hpp
    title: FixPoint
  - icon: ':question:'
    path: byslib/extension/subrange.hpp
    title: byslib/extension/subrange.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/edge.hpp
    title: byslib/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/graph.hpp
    title: byslib/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/coo.hpp
    title: byslib/linalg/coo.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/csr.hpp
    title: byslib/linalg/csr.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/sparsefwd.hpp
    title: byslib/linalg/sparsefwd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Lowest Common Ancestor
    links: []
  bundledCode: "/**\n * @file lca.hpp\n * @brief Lowest Common Ancestor\n *\n * \u6700\
    \u8FD1\u5171\u901A\u7956\u5148\n */\n#include <array>\n#include <optional>\n#include\
    \ <utility>\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
    \ i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
    using i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\n\
    using u32 = std::uint32_t;\nusing u64 = std::uint64_t;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\n\nusing isize\
    \ = std::ptrdiff_t;\nusing usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name,\
    \ type) \\\n    constexpr auto operator\"\" name(unsigned long long x) { return\
    \ static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16,\
    \ std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64,\
    \ std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8,\
    \ std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32,\
    \ std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128,\
    \ __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n\
    }  // namespace bys\n\n/**\n * @file monoid.hpp\n * @brief Monoid\n *\n * \u30E2\
    \u30CE\u30A4\u30C9\n */\nnamespace bys {\nstruct Magma {\n    using set_type =\
    \ std::nullptr_t;\n    static constexpr set_type operation(set_type, set_type);\n\
    \    static constexpr set_type inverse(set_type);\n    static constexpr set_type\
    \ identity{nullptr};\n    static constexpr bool commutative{false};\n};\ntemplate\
    \ <class T> struct Add : Magma {\n    using set_type = T;\n    static constexpr\
    \ set_type operation(set_type a, set_type b) { return a + b; }\n    static constexpr\
    \ set_type inverse(set_type a) { return -a; }\n    static constexpr set_type identity{0};\n\
    \    static constexpr bool commutative{true};\n};\ntemplate <class T> struct Min\
    \ : Magma {\n    using set_type = T;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T> struct Max : Magma {\n    using set_type = T;\n    static\
    \ constexpr set_type operation(set_type a, set_type b) { return std::max(a, b);\
    \ }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T> struct Update : Magma {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\ntemplate\
    \ <class T> struct Affine : Magma {\n    using set_type = std::pair<T, T>;\n \
    \   static constexpr set_type operation(set_type a, set_type b) { return {a.first\
    \ * b.first, a.second * b.first + b.second}; }\n    static constexpr set_type\
    \ identity{1, 0};\n};\ntemplate <class Modint> struct ModMul : Magma {\n    using\
    \ set_type = Modint;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return a * b; }\n    static constexpr set_type inverse(set_type a) { return\
    \ a.inv(); }\n    static constexpr set_type identity{1};\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T> struct Xor : Magma {\n    using\
    \ set_type = T;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return a ^ b; }\n    static constexpr set_type inverse(set_type a) { return\
    \ a; }\n    static constexpr set_type identity{0};\n    static constexpr bool\
    \ commutative{true};\n};\ntemplate <std::size_t N> struct Perm : Magma {\n   \
    \ using set_type = std::array<i32, N>;\n    static constexpr set_type operation(const\
    \ set_type& a, const set_type& b) {\n        set_type res = {};\n        for (auto\
    \ i = 0UL; i < N; ++i) res[i] = b[a[i]];\n        return res;\n    }\n    static\
    \ constexpr set_type inverse(const set_type& a) {\n        set_type res = {};\n\
    \        for (auto i = 0UL; i < N; ++i) res[a[i]] = i;\n        return res;\n\
    \    }\n    static constexpr set_type identity = []() {\n        set_type res\
    \ = {};\n        for (auto i = 0UL; i < N; ++i) res[i] = i;\n        return res;\n\
    \    }();\n};\n}  // namespace bys\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\n/**\n * @file sparse_table.hpp\n * @brief Sparse Table\n\
    \ */\nnamespace bys {\n/**\n * @brief Sparse Table\n *\n * \u69CB\u7BC9: O(NlogN)\n\
    \ * \u30AF\u30A8\u30EA: O(1)\n * See:\n * https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table\n\
    \ *\n * @tparam Band \u30E2\u30CE\u30A4\u30C9\u3067\u51AA\u7B49\u6027\u304C\u3042\
    \u308B\u3082\u306E\n */\ntemplate <class Band> class SparseTable {\n    using\
    \ T = typename Band::set_type;\n    i32 n;\n    std::vector<i32> lookup;\n   \
    \ std::vector<std::vector<T>> table;\n\n  public:\n    SparseTable() {}\n    SparseTable(const\
    \ std::vector<T>& v) { build(v); }\n\n    void build(const std::vector<T>& v)\
    \ {\n        n = v.size();\n        lookup.resize(n + 1);\n\n        for (i32\
    \ i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;\n        i32 max_k =\
    \ lookup.back();\n        table.assign(max_k + 1, std::vector<T>(n));\n      \
    \  std::copy(v.begin(), v.end(), table[0].begin());\n        for (i32 i = 1; i\
    \ <= max_k; ++i) {\n            for (i32 j = 0; j <= n - (1 << i); ++j) {\n  \
    \              table[i][j] = Band::operation(table[i - 1][j], table[i - 1][j +\
    \ (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T fold(i32 l, i32\
    \ r) {\n        assert(0 <= l && l <= n);\n        assert(0 <= r && r <= n);\n\
    \        if (l >= r) return Band::identity;\n        i32 w = r - l;\n        return\
    \ Band::operation(table[lookup[w]][l], table[lookup[w]][r - (1 << lookup[w])]);\n\
    \    }\n};\n}  // namespace bys\n#include <map>\n/**\n * @file fixpoint.hpp\n\
    \ * @brief FixPoint\n */\nnamespace bys {\n/**\n * @brief \u30E9\u30E0\u30C0\u518D\
    \u5E30\n *\n * @see: https://koturn.hatenablog.com/entry/2018/06/10/060000\n */\n\
    template <typename F> struct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args> decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\n/**\n * @brief \u30E1\u30E2\u5316\u518D\u5E30\n *\n * @see ?\n */\n\
    template <class F> class Cache : F {\n    template <class> struct get_signature\
    \ {};\n\n    template <class Fn, class R, class Self, class... Args> struct get_signature<R\
    \ (Fn::*)(Self, Args...) const> {\n        using result_type = R;\n        using\
    \ args_tuple = std::tuple<std::decay_t<Args>...>;\n    };\n\n    using signature\
    \ = get_signature<decltype(&F::template operator()<Cache<F>&>)>;\n    using args_tuple\
    \ = typename signature::args_tuple;\n    using result_type = typename signature::result_type;\n\
    \n    std::map<args_tuple, result_type> memo;\n\n  public:\n    Cache(F&& fn)\
    \ : F{std::forward<F>(fn)} {}\n\n    template <class... Args> result_type operator()(Args&&...\
    \ args) {\n        args_tuple key{std::forward<Args>(args)...};\n        if (auto\
    \ itr = memo.find(key); itr == memo.end()) {\n            result_type res = F::operator()(*this,\
    \ std::forward<Args>(args)...);\n            memo.emplace(key, res);\n       \
    \     return res;\n        } else {\n            return itr->second;\n       \
    \ }\n    }\n};\n}  // namespace bys\n\n#include <cstddef>\n#include <iostream>\n\
    \n#include <limits>\n#include <tuple>\n\n#include <type_traits>\n/**\n * @file\
    \ traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\nnamespace\
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
    }  // namespace bys\n#include <numeric>\n\n#include <iterator>\n\n\nnamespace\
    \ bys {\ntemplate <class Iterator> class SubRange {\n  public:\n    using iterator\
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
    \ std::rend(std::forward<Iterable>(iter)));\n}\n}  // namespace bys\n\nnamespace\
    \ bys {\ntemplate <class T> struct CSRMatrix;\n}\n\nnamespace bys {\ntemplate\
    \ <class T> class COOMatrix {\n  public:\n    using value_type = T;\n    const\
    \ std::pair<i32, i32> shape;\n\n  private:\n    std::vector<std::tuple<i32, i32,\
    \ T>> _data;\n    std::vector<i32> _col_cnt;\n\n  public:\n    COOMatrix(i32 n,\
    \ i32 m = -1) : shape{n, m}, _col_cnt(n) {}\n\n    void set(i32 i, i32 j, const\
    \ T& v) {\n        assert(0 <= i and i < shape.first);\n        ++_col_cnt[i];\n\
    \        _data.emplace_back(i, j, v);\n    }\n    void push_back(i32 i, T&& v)\
    \ { set(i, _col_cnt[i], std::forward<T>(v)); }\n    template <class... Args> void\
    \ emplace_back(i32 i, Args&&... args) { set(i, _col_cnt[i], {std::forward<Args>(args)...});\
    \ }\n    auto begin() const { return _data.begin(); }\n    auto end() const {\
    \ return _data.end(); }\n\n    void sort() {\n        std::sort(_data.begin(),\
    \ _data.end(), [](const std::tuple<i32, i32, T>& a, const std::tuple<i32, i32,\
    \ T>& b) {\n            return std::get<2>(a) < std::get<2>(b);\n        });\n\
    \    }\n    std::size_t size() const { return shape.first; }\n    std::ptrdiff_t\
    \ ssize() const { return shape.first; }\n    std::size_t nonzero() const { return\
    \ _data.size(); }\n\n    friend CSRMatrix<T>;\n};\n}  // namespace bys\n\nnamespace\
    \ bys {\ntemplate <class T> class CSRMatrix {\n  public:\n    using value_type\
    \ = T;\n    const std::pair<i32, i32> shape;\n\n  private:\n    std::vector<i32>\
    \ _indptr, _indices;\n    std::vector<T> _data;\n\n  public:\n    CSRMatrix(const\
    \ COOMatrix<T>& coo)\n        : shape(coo.shape), _indptr(coo._col_cnt), _indices(coo._data.size()),\
    \ _data(coo._data.size()) {\n        _indptr.push_back(0);\n\n        std::partial_sum(_indptr.begin(),\
    \ _indptr.end(), _indptr.begin());\n        for (auto&& [i, j, v] : coo._data)\
    \ {\n            i32 index = --_indptr[i];\n            _indices[index] = j;\n\
    \            _data[index] = v;\n        }\n    }\n    CSRMatrix(std::pair<i32,\
    \ i32> shape, const std::vector<std::vector<std::pair<i32, T>>>& data)\n     \
    \   : shape(shape), _indptr(shape.first + 1) {\n        for (i32 i = 0; i < shape.first;\
    \ ++i) {\n            for (auto&& [index, elem] : data[i]) {\n               \
    \ _indices.push_back(index);\n                _data.push_back(elem);\n       \
    \     }\n            _indptr[i + 1] += _indptr[i] + data[i].size();\n        }\n\
    \    }\n    auto operator[](std::size_t i) const { return SubRange(_data.cbegin()\
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
    \ = EdgesCSR<Edge<>>;\n}  // namespace bys\nnamespace bys {\n/**\n * @brief \u6700\
    \u8FD1\u5171\u901A\u7956\u5148\n *\n * Sparse Table\u306B\u3088\u308BEulerTour\
    \ + RmQ\n * \u69CB\u7BC9   O(N logN)\n * \u30AF\u30A8\u30EA O(1)\n */\ntemplate\
    \ <class E> class LowestCommonAncestor {\n    struct Vertex {\n        i32 id,\
    \ depath;\n        bool operator<(const Vertex& rh) const { return depath < rh.depath;\
    \ }\n    };\n    i32 n;\n    SparseTable<Min<Vertex>> st;\n    std::vector<i32>\
    \ pos;\n\n  public:\n    LowestCommonAncestor(EdgesCSR<E> const& graph, i32 root)\
    \ : n(graph.size()), pos(n) {\n        std::vector<Vertex> euler_tour;\n     \
    \   euler_tour.reserve(2 * n - 1);\n        FixPoint([&](auto&& self, i32 now,\
    \ i32 prev, i32 deapth) -> void {\n            pos[now] = euler_tour.size();\n\
    \            euler_tour.push_back({now, deapth});\n\n            for (auto&& nxt\
    \ : graph[now]) {\n                if (i32(nxt.dest) == prev) continue;\n    \
    \            self(nxt.dest, now, deapth + 1);\n                euler_tour.push_back({now,\
    \ deapth});\n            }\n        })(root, -1, 0);\n        st.build(euler_tour);\n\
    \    }\n    i32 lca(i32 a, i32 b) {\n        assert(a < n);\n        assert(b\
    \ < n);\n        if (a == b) return a;\n        if (pos[a] > pos[b]) std::swap(a,\
    \ b);\n        return st.fold(pos[a], pos[b]).id;\n    }\n};\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n/**\n * @file lca.hpp\n * @brief Lowest Common Ancestor\n *\n\
    \ * \u6700\u8FD1\u5171\u901A\u7956\u5148\n */\n#include \"../algebra/monoid.hpp\"\
    \n#include \"../core/int_alias.hpp\"\n#include \"../ds/sparse_table.hpp\"\n#include\
    \ \"../extension/fixpoint.hpp\"\n#include \"graph.hpp\"\nnamespace bys {\n/**\n\
    \ * @brief \u6700\u8FD1\u5171\u901A\u7956\u5148\n *\n * Sparse Table\u306B\u3088\
    \u308BEulerTour + RmQ\n * \u69CB\u7BC9   O(N logN)\n * \u30AF\u30A8\u30EA O(1)\n\
    \ */\ntemplate <class E> class LowestCommonAncestor {\n    struct Vertex {\n \
    \       i32 id, depath;\n        bool operator<(const Vertex& rh) const { return\
    \ depath < rh.depath; }\n    };\n    i32 n;\n    SparseTable<Min<Vertex>> st;\n\
    \    std::vector<i32> pos;\n\n  public:\n    LowestCommonAncestor(EdgesCSR<E>\
    \ const& graph, i32 root) : n(graph.size()), pos(n) {\n        std::vector<Vertex>\
    \ euler_tour;\n        euler_tour.reserve(2 * n - 1);\n        FixPoint([&](auto&&\
    \ self, i32 now, i32 prev, i32 deapth) -> void {\n            pos[now] = euler_tour.size();\n\
    \            euler_tour.push_back({now, deapth});\n\n            for (auto&& nxt\
    \ : graph[now]) {\n                if (i32(nxt.dest) == prev) continue;\n    \
    \            self(nxt.dest, now, deapth + 1);\n                euler_tour.push_back({now,\
    \ deapth});\n            }\n        })(root, -1, 0);\n        st.build(euler_tour);\n\
    \    }\n    i32 lca(i32 a, i32 b) {\n        assert(a < n);\n        assert(b\
    \ < n);\n        if (a == b) return a;\n        if (pos[a] > pos[b]) std::swap(a,\
    \ b);\n        return st.fold(pos[a], pos[b]).id;\n    }\n};\n}  // namespace\
    \ bys\n"
  dependsOn:
  - byslib/algebra/monoid.hpp
  - byslib/core/int_alias.hpp
  - byslib/ds/sparse_table.hpp
  - byslib/extension/fixpoint.hpp
  - byslib/graph/graph.hpp
  - byslib/graph/edge.hpp
  - byslib/core/constant.hpp
  - byslib/core/traits.hpp
  - byslib/linalg/csr.hpp
  - byslib/extension/subrange.hpp
  - byslib/linalg/coo.hpp
  - byslib/linalg/sparsefwd.hpp
  isVerificationFile: false
  path: byslib/graph/lca.hpp
  requiredBy: []
  timestamp: '2022-12-02 16:15:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/graph/lca.hpp
layout: document
redirect_from:
- /library/byslib/graph/lca.hpp
- /library/byslib/graph/lca.hpp.html
title: Lowest Common Ancestor
---
