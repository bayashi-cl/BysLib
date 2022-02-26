---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/const.hpp
    title: core/const.hpp
  - icon: ':heavy_check_mark:'
    path: core/core.hpp
    title: core/core.hpp
  - icon: ':heavy_check_mark:'
    path: core/io.hpp
    title: core/io.hpp
  - icon: ':heavy_check_mark:'
    path: core/macro.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\
      \u3067\u306F\u4F55\u3082\u3057\u306A\u3044\u3002"
  - icon: ':heavy_check_mark:'
    path: core/printer.hpp
    title: core/printer.hpp
  - icon: ':heavy_check_mark:'
    path: core/scanner.hpp
    title: core/scanner.hpp
  - icon: ':heavy_check_mark:'
    path: core/solver.hpp
    title: core/solver.hpp
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: core/types.hpp
    title: core/types.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: "\u70B9/\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C
  bundledCode: "#line 1 \"test/geometry/cross_point.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C\"\n#define\
    \ ERROR 1e-8\n#line 2 \"core/stdlib.hpp\"\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n#line 3 \"core/const.hpp\"\n\nnamespace bys {\nconstexpr int MOD = 998244353;\n\
    constexpr int MOD7 = 1000000007;\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max() / 2;\n}  // namespace\
    \ bys\n#line 4 \"core/types.hpp\"\n#include <utility>\n\nnamespace bys {\ntemplate\
    \ <class, class = void>\nstruct has_lshift_to_ostream : std::false_type {};\n\
    template <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\n\ntemplate <class, class = void>\n\
    struct has_rshift_from_istream : std::false_type {};\ntemplate <class T>\nstruct\
    \ has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\n\ntemplate <class T, class =\
    \ void>\nstruct has_tuple_interface : std::false_type {};\ntemplate <class T>\n\
    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\n\ntemplate <class, class = void>\nstruct has_iterator : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_iterator<T, std::void_t<typename T::iterator>>\
    \ : std::true_type {};\n\nstruct Int1 {};\n}  // namespace bys\n#line 4 \"core/printer.hpp\"\
    \n\nnamespace bys {\nstruct Printer {\n    Printer(std::ostream& os_) : os(os_)\
    \ {}\n    ~Printer() { os << std::flush; }\n\n    template <class T>\n    void\
    \ cat(T&& v) {\n        if constexpr (has_lshift_to_ostream<std::decay_t<T>>::value)\
    \ {\n            os << v;\n        } else if constexpr (has_iterator<std::decay_t<T>>::value)\
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
    \ ...);\n    }\n};\n}  // namespace bys\n#line 4 \"core/scanner.hpp\"\n\nnamespace\
    \ bys {\nstruct Scanner {\n    Scanner(std::istream& is_) : is(is_){};\n\n   \
    \ template <class... Ts>\n    void scan(Ts&... args) {\n        (is >> ... >>\
    \ args);\n    }\n\n    template <class T, class... Us>\n    decltype(auto) read()\
    \ {\n        if constexpr (sizeof...(Us) == 0) {\n            if constexpr (has_rshift_from_istream<T>::value)\
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
    \ }\n};\n}  // namespace bys\n#line 5 \"core/io.hpp\"\n\nnamespace bys {\n__attribute__((constructor))\
    \ void setup_io() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::cout << std::fixed << std::setprecision(11);\n    std::cerr << std::fixed\
    \ << std::setprecision(11);\n    std::cerr << std::boolalpha;\n}\n\nPrinter print(std::cout),\
    \ debug(std::cerr);\nScanner scanner(std::cin);\n}  // namespace bys\n#line 2\
    \ \"core/macro.hpp\"\n// clang-format off\n#ifdef LOCAL\n//! @brief \u30C7\u30D0\
    \u30C3\u30B0\u7528\u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\u4F55\
    \u3082\u3057\u306A\u3044\u3002\n#define DEBUG(...) { std::cerr << \"[debug] line\"\
    \ << std::setw(4) << __LINE__ << \": \"; debug(__VA_ARGS__); }\n#else\n#define\
    \ DEBUG(...)\n#endif\n//! @brief print\u3057\u3066return\u3059\u308B\u3002\n#define\
    \ EXIT(...) { print(__VA_ARGS__); return; }\n#define CONCAT_IMPL(a, b) a##b\n\
    #define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\u5909\
    \u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"line: \" + std::to_string(__LINE__)\
    \ + \", func: \" + __func__)\n// clang-format on\n#line 2 \"core/solver.hpp\"\n\
    \nnamespace bys {\nstruct Solver {\n    int IT = 1;\n    Solver() {}\n    void\
    \ solve();\n    void solve(int rep) {\n        for (; IT <= rep; ++IT) solve();\n\
    \    }\n};\n}  // namespace bys\n#line 3 \"geometry/base.hpp\"\n\nnamespace bys::geo\
    \ {\nconst ld EPS = 1e-9;\nconst ld PI = std::acos(-1.0);\nconst ld TAU = PI *\
    \ 2;\nint sgn(ld a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }\nbool isclose(ld\
    \ a, ld b) { return sgn(a - b) == 0; }\nld radian(ld degree) { return degree *\
    \ (PI / 180.0); }\nld degree(ld theta) { return theta * (180.0 / PI); }\n}  //\
    \ namespace bys::geo\n#line 3 \"geometry/point.hpp\"\n\nnamespace bys::geo {\n\
    //! @brief \u70B9/\u30D9\u30AF\u30C8\u30EB\ntemplate <class T>\nstruct Point {\n\
    \    T x, y;\n    Point() : x(0.0), y(0.0) {}\n    Point(T x, T y) : x(x), y(y)\
    \ {}\n    // clang-format off\n    friend std::istream& operator>>(std::istream&\
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
    \ on\n\n    T norm2() const { return x * x + y * y; }\n    ld norm() const { return\
    \ std::sqrt(norm2()); }\n    Point normalized() const { return Point(x / norm(),\
    \ y / norm()); }\n    ld angle() const { return std::atan2(y, x); }\n    Point\
    \ rotate(ld theta) const {\n        ld ct = std::cos(theta), st = std::sin(theta);\n\
    \        return Point(x * ct - y * st, x * st + y * ct);\n    }\n    //! @brief\
    \ \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u7528\u300245\u5EA6\u56DE\u8EE2\
    \u3057\u3066\u221A2\u500D\u3059\u308B\n    Point manhattan_rotate() const { return\
    \ Point(x - y, x + y); }\n    T dot(const Point& rh) const { return x * rh.x +\
    \ y * rh.y; }\n    T det(const Point& rh) const { return x * rh.y - y * rh.x;\
    \ }\n    Point normal() const { return Point(-normalized().y, normalized().x);\
    \ }\n    Point projection(const Point& to) const { return to * (dot(to) / to.norm2());\
    \ }\n    int quadrant() const {\n        if (sgn(y) >= 0) return sgn(x) >= 0 ?\
    \ 1 : 2;\n        return sgn(x) >= 0 ? 4 : 3;\n    }\n    // \u504F\u89D2\u30BD\
    \u30FC\u30C8\u7528\n    bool operator<(const Point& rh) const {\n        int q\
    \ = quadrant(), rhq = rh.quadrant();\n        if (q != rhq) return q < rhq;\n\
    \        return sgn(det(rh)) > 0;\n    }\n    bool operator<=(const Point& rh)\
    \ const {\n        int q = quadrant(), rhq = rh.quadrant();\n        if (q !=\
    \ rhq) return q < rhq;\n        return sgn(det(rh)) >= 0;\n    }\n};\n\ntemplate\
    \ <class T>\nbool compx(Point<T>& a, Point<T>& b) {\n    return a.x < b.x;\n}\n\
    template <class T>\nbool compy(Point<T>& a, Point<T>& b) {\n    return a.y < b.y;\n\
    }\n\nenum class Turn { Back = -2, CW, Middle, CCW, Front };\n/**\n * @brief \u8FBA\
    \u306E\u66F2\u304C\u308B\u65B9\u5411\n * @return\n * +1: CCW ab->bc\u304C\u5DE6\
    \u306B\u66F2\u304C\u308B\n * -1: CW  ab->bc\u304C\u53F3\u306B\u66F2\u304C\u308B\
    \n * +2: Front  ab\u306E\u524D\u65B9\n * -2: Back   ab\u306E\u5F8C\u65B9\n * \
    \ 0: Middle ab\u4E0A\n */\ntemplate <class T>\nTurn iSP(const Point<T>& a, const\
    \ Point<T>& b, const Point<T>& c) {\n    int flg = sgn((b - a).det(c - a));\n\
    \    if (flg == 1) {\n        return Turn::CCW;\n    } else if (flg == -1) {\n\
    \        return Turn::CW;\n    } else {\n        if (sgn((b - a).dot(c - b)) >\
    \ 0) {\n            return Turn::Front;\n        } else if (sgn((a - b).dot(c\
    \ - a)) > 0) {\n            return Turn::Back;\n        } else {\n           \
    \ return Turn::Middle;\n        }\n    }\n}\n/**\n * -1: Obtuse \u920D\u89D2\n\
    \ *  0: Right \u76F4\u89D2\n * +1: Acute \u92ED\u89D2\n */\nenum class Angle {\
    \ Obtuse = -1, Right, Acute };\n/**\n * @brief \u89D2\u306E\u7A2E\u985E\n * @return\
    \ Angle\n * -1: Obtuse \u920D\u89D2\n *  0: Right \u76F4\u89D2\n * +1: Acute \u92ED\
    \u89D2\n */\ntemplate <class T>\nAngle angle_type(const Point<T>& a, const Point<T>&\
    \ b, const Point<T>& c) {\n    int t = sgn((a - b).dot(c - b));\n    if (t ==\
    \ -1) {\n        return Angle::Obtuse;\n    } else if (t == 0) {\n        return\
    \ Angle::Right;\n    } else {\n        return Angle::Acute;\n    }\n}\n}  // namespace\
    \ bys::geo\n#line 3 \"geometry/line.hpp\"\n\nnamespace bys::geo {\ntemplate <class\
    \ T>\n//! @brief \u76F4\u7DDA\nstruct Line {\n    Point<T> p, q;\n    Line(Point<T>\
    \ p, Point<T> q) : p(p), q(q) {}\n    Point<T> to_Point() const { return q - p;\
    \ }\n    Point<ld> to_unit_Point() const { return to_Point().normalized(); }\n\
    \    ld angle() const { return to_Point().angle(); }\n    bool operator==(const\
    \ Line& rh) const { return abs((int)iSP(p, q, rh.p)) != 1 && abs((int)iSP(p, q,\
    \ rh.q)) != 1; }\n    bool operator!=(const Line& rh) const { return !(*this ==\
    \ rh); }\n};\n//! @brief \u7DDA\u5206\ntemplate <class T>\nstruct Segment : Line<T>\
    \ {\n    Segment(Point<T>& p, Point<T>& q) : Line<T>::Line(p, q) {}\n    ld length()\
    \ const { return this->to_Point().norm(); }\n    Point<ld> internal_division(ld\
    \ m, ld n) const { return (this->p * n + this->q * m) / (m + n); }\n    bool operator==(const\
    \ Segment& rh) const {\n        return (this->p == rh.p && this->q == rh.q) ||\
    \ (this->p == rh.q && this->q == rh.p);\n    }\n    bool operator!=(const Segment&\
    \ rh) const { return !(*this == rh); }\n};\ntemplate <class T>\nTurn iSP(const\
    \ Point<T>& p, const Line<T>& l) {\n    return iSP(l.p, l.q, p);\n}\ntemplate\
    \ <class T>\nbool is_parallel(const Line<T>& a, const Line<T>& b) {\n    return\
    \ sgn(a.to_Point().det(b.to_Point())) == 0;\n}\ntemplate <class T>\nbool is_vertial(const\
    \ Line<T>& a, const Line<T>& b) {\n    return sgn(a.to_Point().dot(b.to_Point()))\
    \ == 0;\n}\ntemplate <class T>\nbool is_cross(const Line<T>& a, const Line<T>&\
    \ b) {\n    return sgn(a.to_Point().det(b.to_Point())) != 0 || sgn(a.to_Point().det(b.p\
    \ - a.p)) == 0;\n}\ntemplate <class T>\nbool is_cross(const Segment<T>& a, const\
    \ Segment<T>& b) {\n    return (int)iSP(b.p, a) * (int)iSP(b.q, a) <= 0 && (int)iSP(a.p,\
    \ b) * (int)iSP(a.q, b) <= 0;\n}\ntemplate <class T>\nld angle(const Line<T>&\
    \ a, const Line<T>& b) {\n    return std::atan2(a.to_Point().det(b.to_Point()),\
    \ a.to_Point().dot(b.to_Point()));\n}\n\ntemplate <class T>\nld distance(const\
    \ Point<T>& p, const Line<T>& l) {\n    return abs(l.to_Point().det(p - l.p) /\
    \ (l.q - l.p).norm());\n}\ntemplate <class T>\nld distance(const Point<T>& p,\
    \ const Segment<T>& s) {\n    if (angle_type(s.p, s.q, p) == Angle::Obtuse) {\n\
    \        return (p - s.q).norm();\n    } else if (angle_type(s.q, s.p, p) == Angle::Obtuse)\
    \ {\n        return (p - s.p).norm();\n    } else {\n        return distance(p,\
    \ Line(s.p, s.q));\n    }\n}\ntemplate <class T>\nld distance(const Segment<T>&\
    \ s, const Segment<T>& t) {\n    if (is_cross(s, t)) return 0;\n\n    return min({distance(s.p,\
    \ t), distance(s.q, t), distance(t.p, s), distance(t.q, s)});\n}\ntemplate <class\
    \ T>\n// std::pair<bool, Point<T>> cross_point(const Line<T>& a, const Line<T>&\
    \ b) {\nstd::optional<Point<T>> cross_point(const Line<T>& a, const Line<T>& b)\
    \ {\n    if (!is_cross(a, b)) return std::nullopt;\n    Point s = b.p - a.p;\n\
    \    return b.p + b.to_Point() * abs(a.to_Point().det(s) / a.to_Point().det(b.to_Point()));\n\
    }\ntemplate <class T>\n// std::pair<bool, Point<T>> cross_point(const Segment<T>&\
    \ a, const Segment<T>& b) {\nstd::optional<Point<T>> cross_point(const Segment<T>&\
    \ a, const Segment<T>& b) {\n    if (!is_cross(a, b)) return std::nullopt;\n \
    \   Point s = b.p - a.p;\n    return b.p + b.to_Point() * abs(a.to_Point().det(s)\
    \ / a.to_Point().det(b.to_Point()));\n}\ntemplate <class T>\nPoint<T> projection(const\
    \ Point<T>& p, const Line<T>& l) {\n    return (p - l.p).projection(l.to_Point())\
    \ + l.p;\n}\ntemplate <class T>\nPoint<T> reflection(const Point<T>& p, const\
    \ Line<T>& l) {\n    return p + (projection(p, l) - p) * 2;\n}\n}  // namespace\
    \ bys::geo\n\n/**\n * @todo \u534A\u76F4\u7DDA\u306E\u5B9F\u88C5\n *\n */\n#line\
    \ 5 \"test/geometry/cross_point.test.cpp\"\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto q = scanner.read<int>();\n    for (int i = 0; i < q; ++i) {\n  \
    \      auto [p0, p1, p2, p3] = scanner.read<geo::Point<ld>, 4>();\n        geo::Segment\
    \ s1(p0, p1), s2(p2, p3);\n        print(geo::cross_point(s1, s2).value());\n\
    \    }\n}\n}  // namespace bys\n\nint main() {\n    bys::Solver solver;\n    solver.solve(/*\
    \ bys::scanner.read<int>() */);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C\"\
    \n#define ERROR 1e-8\n#include \"../../core/core.hpp\"\n#include \"../../geometry/line.hpp\"\
    \n\nnamespace bys {\nvoid Solver::solve() {\n    auto q = scanner.read<int>();\n\
    \    for (int i = 0; i < q; ++i) {\n        auto [p0, p1, p2, p3] = scanner.read<geo::Point<ld>,\
    \ 4>();\n        geo::Segment s1(p0, p1), s2(p2, p3);\n        print(geo::cross_point(s1,\
    \ s2).value());\n    }\n}\n}  // namespace bys\n\nint main() {\n    bys::Solver\
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
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/base.hpp
  isVerificationFile: true
  path: test/geometry/cross_point.test.cpp
  requiredBy: []
  timestamp: '2022-02-09 20:18:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/cross_point.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/cross_point.test.cpp
- /verify/test/geometry/cross_point.test.cpp.html
title: test/geometry/cross_point.test.cpp
---
