---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/constant.hpp
    title: Const
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':question:'
    path: byslib/extension/subrange.hpp
    title: byslib/extension/subrange.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/edge.hpp
    title: byslib/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/graph.hpp
    title: byslib/graph/graph.hpp
  - icon: ':question:'
    path: byslib/io/io.hpp
    title: I/O
  - icon: ':question:'
    path: byslib/io/printer.hpp
    title: Output
  - icon: ':question:'
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Reader
    links: []
  bundledCode: "#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
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
    }  // namespace bys\n#include <iomanip>\n#include <iostream>\n#include <string>\n\
    #include <utility>\n\n#include <array>\n#include <type_traits>\n/**\n * @file\
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
    /**\n * @file printer.hpp\n * @brief Output\n */\nnamespace bys {\nclass Printer\
    \ {\n    std::ostream& _os;\n    // sep1 \"\\n\"       : iterable<iterable>\n\
    \    // sep2 \" \" or \"\\n\": iterable, args\n    // sep3 \" \"        : tuple_like\n\
    \    std::string sep1 = \"\\n\", sep2 = \" \", sep3 = \" \", end = \"\\n\";\n\n\
    \    template <std::size_t I, class T> void print_tuple_element(T&& elem) {\n\
    \        if constexpr (I != 0) cat(sep3);\n        cat(std::forward<T>(elem));\n\
    \    }\n    template <class Tp, std::size_t... I> void print_tuple(Tp&& tp, std::index_sequence<I...>)\
    \ {\n        (print_tuple_element<I>(std::forward<std::tuple_element_t<I, std::decay_t<Tp>>>(std::get<I>(tp))),\
    \ ...);\n    }\n\n  public:\n    Printer() = delete;\n    Printer(std::ostream&\
    \ os) : _os(os) { _os << std::fixed << std::setprecision(11) << std::boolalpha;\
    \ }\n    ~Printer() { _os << std::flush; }\n\n    template <class T> void cat(T&&\
    \ v) {\n        if constexpr (has_lshft_to_ostream_v<std::decay_t<T>>) {\n   \
    \         _os << v;\n        } else if constexpr (is_iterable_v<std::decay_t<T>>)\
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
    \ return *this;\n    }\n};\n}  // namespace bys\n#include <tuple>\n#include <vector>\n\
    \n/**\n * @file scanner.hpp\n * @brief Input\n */\nnamespace bys {\nclass Scanner\
    \ {\n    std::istream& _is;\n    template <class T, std::size_t... I> auto read_tuple(std::index_sequence<I...>)\
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
    \    }\n}  // namespace bys\n\n#include <cstddef>\n\n#include <limits>\n\n\n/**\n\
    \ * @file constant.hpp\n * @brief Const\n */\nnamespace bys {\nconstexpr i32 MOD7\
    \ = 1000000007;\nconstexpr i32 MOD9 = 998244353;\nconstexpr i32 MOD = MOD9;\n\n\
    template <class T> constexpr T get_inf();\nnamespace impl {\ntemplate <class Tp,\
    \ std::size_t... I> constexpr auto get_inf_tuple(std::index_sequence<I...>) {\n\
    \    return Tp{get_inf<typename std::tuple_element_t<I, Tp>>()...};\n}\n}  //\
    \ namespace impl\ntemplate <class T> constexpr T get_inf() {\n    if constexpr\
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
    \ = EdgesCSR<Edge<>>;\n}  // namespace bys\n\n/**\n * @file reader.hpp\n * @brief\
    \ Reader\n *\n * \u30B0\u30E9\u30D5\u5165\u529B\n */\nnamespace bys {\n//! @brief\
    \ \u91CD\u307F\u306A\u3057\u96A3\u63A5\u30EA\u30B9\u30C8\nauto read_adj_uv(i32\
    \ n, i32 m, bool directed = false, i32 index = 1) {\n    EdgesCOO<Edge<i32>> edges(n);\n\
    \    for (i32 i = 0; i < m; ++i) {\n        auto [u, v] = scanner.read<i32, 2>();\n\
    \        u -= index;\n        v -= index;\n        if (directed) {\n         \
    \   edges.add_edge(u, v);\n        } else {\n            edges.add_undirected_edge(u,\
    \ v);\n        }\n    }\n    return edges.adj();\n}\n//! @brief \u91CD\u307F\u3064\
    \u304D\u96A3\u63A5\u30EA\u30B9\u30C8\nauto read_adj_uvc(i32 n, i32 m, bool directed\
    \ = false, i32 index = 1) {\n    EdgesCOO<Edge<i64>> edges(n);\n    for (i32 i\
    \ = 0; i < m; ++i) {\n        auto [u, v, c] = scanner.read<i32, i32, i64>();\n\
    \        u -= index;\n        v -= index;\n        if (directed) {\n         \
    \   edges.add_edge(u, v, c);\n        } else {\n            edges.add_undirected_edge(u,\
    \ v, c);\n        }\n    }\n    return edges.adj();\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/int_alias.hpp\"\n#include \"../io/io.hpp\"\
    \n#include \"graph.hpp\"\n\n/**\n * @file reader.hpp\n * @brief Reader\n *\n *\
    \ \u30B0\u30E9\u30D5\u5165\u529B\n */\nnamespace bys {\n//! @brief \u91CD\u307F\
    \u306A\u3057\u96A3\u63A5\u30EA\u30B9\u30C8\nauto read_adj_uv(i32 n, i32 m, bool\
    \ directed = false, i32 index = 1) {\n    EdgesCOO<Edge<i32>> edges(n);\n    for\
    \ (i32 i = 0; i < m; ++i) {\n        auto [u, v] = scanner.read<i32, 2>();\n \
    \       u -= index;\n        v -= index;\n        if (directed) {\n          \
    \  edges.add_edge(u, v);\n        } else {\n            edges.add_undirected_edge(u,\
    \ v);\n        }\n    }\n    return edges.adj();\n}\n//! @brief \u91CD\u307F\u3064\
    \u304D\u96A3\u63A5\u30EA\u30B9\u30C8\nauto read_adj_uvc(i32 n, i32 m, bool directed\
    \ = false, i32 index = 1) {\n    EdgesCOO<Edge<i64>> edges(n);\n    for (i32 i\
    \ = 0; i < m; ++i) {\n        auto [u, v, c] = scanner.read<i32, i32, i64>();\n\
    \        u -= index;\n        v -= index;\n        if (directed) {\n         \
    \   edges.add_edge(u, v, c);\n        } else {\n            edges.add_undirected_edge(u,\
    \ v, c);\n        }\n    }\n    return edges.adj();\n}\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/io/io.hpp
  - byslib/io/printer.hpp
  - byslib/core/traits.hpp
  - byslib/io/scanner.hpp
  - byslib/graph/graph.hpp
  - byslib/graph/edge.hpp
  - byslib/core/constant.hpp
  - byslib/linalg/csr.hpp
  - byslib/extension/subrange.hpp
  - byslib/linalg/coo.hpp
  - byslib/linalg/sparsefwd.hpp
  isVerificationFile: false
  path: byslib/graph/reader.hpp
  requiredBy: []
  timestamp: '2022-12-02 16:15:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/graph/reader.hpp
layout: document
redirect_from:
- /library/byslib/graph/reader.hpp
- /library/byslib/graph/reader.hpp.html
title: Reader
---
