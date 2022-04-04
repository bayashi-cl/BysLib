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
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: Base
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: Polygon
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\
    \n#define ERROR 1e-8\n/**\n * @file core.hpp\n * @author bayashi_cl\n * @brief\
    \ core/all\n *\n * C++ library for competitive programming by bayashi_cl\n * Repository:\
    \ https://github.com/bayashi-cl/byslib\n * Document : https://bayashi-cl.github.io/byslib/\n\
    \ */\n#ifndef LOCAL\n#define NDEBUG\n#endif\n/**\n * @file stdlib.hpp\n * @brief\
    \ STL Template\n */\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <iterator>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\nnamespace bys {\nusing std::array,\
    \ std::vector, std::string, std::set, std::map, std::pair;\nusing std::cin, std::cout,\
    \ std::endl;\nusing std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\
    \n// alias\nusing ll = long long int;\nusing ld = long double;\nusing Pa = pair<int,\
    \ int>;\nusing Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class\
    \ T>\nusing uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing\
    \ umap = std::unordered_map<S, T>;\n}  // namespace bys\n/**\n * @file const.hpp\n\
    \ * @brief Const\n */\nnamespace bys {\nconstexpr int MOD = 998244353;\nconstexpr\
    \ int MOD7 = 1000000007;\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max() / 2;\n}  // namespace\
    \ bys\n/**\n * @file types.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\
    \n */\nnamespace bys {\ntemplate <class, class = void>\nstruct has_lshift_to_ostream\
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
    \ solve();\n    }\n};\n}  // namespace bys\n/**\n * @file base.hpp\n * @brief\
    \ Base\n */\n//! @brief \u5E7E\u4F55\nnamespace bys::geo {\nconst ld EPS = 1e-9;\n\
    const ld PI = std::acos(-1.0);\nconst ld TAU = PI * 2;\nint sgn(ld a) { return\
    \ (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }\nbool isclose(ld a, ld b) { return sgn(a\
    \ - b) == 0; }\n//! @brief \u5EA6\u6570\u6CD5 -> \u5F27\u5EA6\u6CD5\nld radian(ld\
    \ degree) { return degree * (PI / 180.0); }\n//! @brief \u5F27\u5EA6\u6CD5 ->\
    \ \u5EA6\u6570\u6CD5\nld degree(ld theta) { return theta * (180.0 / PI); }\n}\
    \  // namespace bys::geo\n/**\n * @file point.hpp\n * @brief Point\n */\nnamespace\
    \ bys::geo {\n//! @brief \u70B9/\u30D9\u30AF\u30C8\u30EB\ntemplate <class T>\n\
    struct Point {\n    T x, y;\n    Point() : x(0.0), y(0.0) {}\n    Point(T x, T\
    \ y) : x(x), y(y) {}\n    // clang-format off\n    friend std::istream& operator>>(std::istream&\
    \ is, Point& v) { return is >> v.x >> v.y; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point& v) { return os << v.x << ' ' << v.y; }\n    Point operator+()\
    \ const { return *this; }\n    Point operator-() const { return Point(-x, -y);\
    \ }\n    Point operator+(const Point& rh) const { return Point(x + rh.x, y + rh.y);\
    \ }\n    Point operator-(const Point& rh) const { return Point(x - rh.x, y - rh.y);\
    \ }\n    Point operator*(const T rh) const { return Point(x * rh, y * rh); }\n\
    \    Point operator/(const T rh) const { return Point(x / rh, y / rh); }\n   \
    \ Point operator+=(const Point& rh) { x += rh.x; y += rh.y; return *this; }\n\
    \    Point operator-=(const Point& rh) { x -= rh.x; y -= rh.y; return *this; }\n\
    \    Point operator*=(const T rh) { x *= rh; y *= rh; return *this; }\n    Point\
    \ operator/=(const T rh) { x /= rh; y /= rh; return *this; }\n    bool operator==(const\
    \ Point& rh) const { return isclose(x, rh.x) && isclose(y, rh.y); }\n    bool\
    \ operator!=(const Point& rh) const { return !(*this == rh); }\n    // clang-format\
    \ on\n\n    //! @brief \u30CE\u30EB\u30E0^2\n    T norm2() const { return x *\
    \ x + y * y; }\n    //! @brief \u30CE\u30EB\u30E0\n    ld norm() const { return\
    \ std::sqrt(norm2()); }\n    //! @brief \u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\n\
    \    Point normalized() const { return Point(x / norm(), y / norm()); }\n    //!\
    \ @brief \u504F\u89D2\n    ld angle() const { return std::atan2(y, x); }\n   \
    \ //! @brief \u56DE\u8EE2\n    Point rotate(ld theta) const {\n        ld ct =\
    \ std::cos(theta), st = std::sin(theta);\n        return Point(x * ct - y * st,\
    \ x * st + y * ct);\n    }\n    Point rotate90() const { return Point(-y, x);\
    \ }\n    //! @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u7528\u3002\
    45\u5EA6\u56DE\u8EE2\u3057\u3066\u221A2\u500D\u3059\u308B\n    Point manhattan_rotate()\
    \ const { return Point(x - y, x + y); }\n    //! @brief \u5185\u7A4D\n    T dot(const\
    \ Point& rh) const { return x * rh.x + y * rh.y; }\n    //! @brief \u5916\u7A4D\
    \n    T det(const Point& rh) const { return x * rh.y - y * rh.x; }\n    //! @brief\
    \ \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB\n    Point normal() const { return Point(-normalized().y,\
    \ normalized().x); }\n    //! @brief \u6B63\u5C04\u5F71\u30D9\u30AF\u30C8\u30EB\
    \n    Point projection(const Point& to) const { return to * (dot(to) / to.norm2());\
    \ }\n    //! @brief \u8C61\u9650\n    int quadrant() const {\n        if (sgn(y)\
    \ >= 0) return sgn(x) >= 0 ? 1 : 2;\n        return sgn(x) >= 0 ? 4 : 3;\n   \
    \ }\n    //! @brief \u504F\u89D2\u30BD\u30FC\u30C8\u7528\n    bool operator<(const\
    \ Point& rh) const {\n        int q = quadrant(), rhq = rh.quadrant();\n     \
    \   if (q != rhq) return q < rhq;\n        return sgn(det(rh)) > 0;\n    }\n \
    \   bool operator<=(const Point& rh) const {\n        int q = quadrant(), rhq\
    \ = rh.quadrant();\n        if (q != rhq) return q < rhq;\n        return sgn(det(rh))\
    \ >= 0;\n    }\n};\n\ntemplate <class T>\nbool compx(Point<T>& a, Point<T>& b)\
    \ {\n    return a.x < b.x;\n}\ntemplate <class T>\nbool compy(Point<T>& a, Point<T>&\
    \ b) {\n    return a.y < b.y;\n}\n//! @brief \u66F2\u304C\u308B\u65B9\u5411\n\
    enum class Turn {\n    //! ab\u306E\u5F8C\u65B9\n    Back = -2,\n    //! ab->bc\u304C\
    \u53F3\u306B\u66F2\u304C\u308B\n    CW = -1,\n    //! ab\u4E0A\n    Middle = 0,\n\
    \    //! ab->bc\u304C\u5DE6\u306B\u66F2\u304C\u308B\n    CCW = 1,\n    //! ab\u306E\
    \u524D\u65B9\n    Front = 2,\n};\n//! @brief \u8FBA\u306E\u66F2\u304C\u308B\u65B9\
    \u5411\ntemplate <class T>\nTurn iSP(const Point<T>& a, const Point<T>& b, const\
    \ Point<T>& c) {\n    int flg = sgn((b - a).det(c - a));\n    if (flg == 1) {\n\
    \        return Turn::CCW;\n    } else if (flg == -1) {\n        return Turn::CW;\n\
    \    } else {\n        if (sgn((b - a).dot(c - b)) > 0) {\n            return\
    \ Turn::Front;\n        } else if (sgn((a - b).dot(c - a)) > 0) {\n          \
    \  return Turn::Back;\n        } else {\n            return Turn::Middle;\n  \
    \      }\n    }\n}\nenum class Angle {\n    //! \u920D\u89D2\n    Obtuse = -1,\n\
    \    //! \u76F4\u89D2\n    Right = 0,\n    //! \u92ED\u89D2\n    Acute = 1,\n\
    };\n\n//! @brief \u89D2\u306E\u7A2E\u985E\ntemplate <class T>\nAngle angle_type(const\
    \ Point<T>& a, const Point<T>& b, const Point<T>& c) {\n    int t = sgn((a - b).dot(c\
    \ - b));\n    if (t == -1) {\n        return Angle::Obtuse;\n    } else if (t\
    \ == 0) {\n        return Angle::Right;\n    } else {\n        return Angle::Acute;\n\
    \    }\n}\n}  // namespace bys::geo\n/**\n * @file polygon.hpp\n * @brief Polygon\n\
    \ */\nnamespace bys::geo {\n//! @brief \u591A\u89D2\u5F62\ntemplate <class T>\n\
    struct Polygon {\n    int n_vertex;\n    std::vector<Point<T>> vertex;\n    Polygon(std::initializer_list<Point<T>>\
    \ init) : n_vertex(init.size()), vertex(init.begin(), init.end()) {}\n    Polygon(std::vector<Point<T>>\
    \ vertex) : n_vertex(vertex.size()), vertex(vertex) {}\n    //! @brief \u9762\u7A4D\
    *2\n    T area2() const {\n        if (n_vertex < 3) return 0;\n        ld s =\
    \ 0.0;\n        for (int i = 0; i < n_vertex; ++i) {\n            s += vertex[i].det(vertex[(i\
    \ + 1) % n_vertex]);\n        }\n        return s;\n    };\n    //! @brief \u9762\
    \u7A4D\n    ld area() const { return area2() * 0.5; }\n    //! @brief \u51F8\u5224\
    \u5B9A\n    bool is_convex() const {\n        int left = 0;\n        int right\
    \ = 0;\n        for (int i = 0; i < n_vertex; ++i) {\n            auto res = iSP(vertex[i],\
    \ vertex[(i + 1) % n_vertex], vertex[(i + 2) % n_vertex]);\n            if (res\
    \ == Turn::CW) left++;\n            if (res == Turn::CCW) right++;\n        }\n\
    \        return left == 0 || right == 0;\n    }\n};\n}  // namespace bys::geo\n\
    \nnamespace bys {\nvoid Solver::solve() {\n    auto n = scanner.read<int>();\n\
    \    geo::Polygon p(scanner.readvec<geo::Point<ld>>(n));\n    print(p.area());\n\
    }\n}  // namespace bys\n\nint main() {\n    bys::Solver solver;\n    solver.solve(/*\
    \ bys::scanner.read<int>() */);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\
    \n#define ERROR 1e-8\n#include \"../../core/core.hpp\"\n#include \"../../geometry/polygon.hpp\"\
    \n\nnamespace bys {\nvoid Solver::solve() {\n    auto n = scanner.read<int>();\n\
    \    geo::Polygon p(scanner.readvec<geo::Point<ld>>(n));\n    print(p.area());\n\
    }\n}  // namespace bys\n\nint main() {\n    bys::Solver solver;\n    solver.solve(/*\
    \ bys::scanner.read<int>() */);\n    return 0;\n}\n"
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
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/base.hpp
  isVerificationFile: true
  path: test/geometry/area.test.cpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/area.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/area.test.cpp
- /verify/test/geometry/area.test.cpp.html
title: test/geometry/area.test.cpp
---
