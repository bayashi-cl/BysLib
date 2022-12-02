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
    path: byslib/geometry/base.hpp
    title: Base
  - icon: ':heavy_check_mark:'
    path: byslib/geometry/line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: byslib/geometry/point.hpp
    title: Point
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
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A\"\
    \n#define ERROR 1e-8\n#include <algorithm>\n#include <optional>\n\n#include <iostream>\n\
    \n#include <cmath>\n\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\n\
    using i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
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
    }  // namespace bys\n/**\n * @file base.hpp\n * @brief Base\n */\n//! @brief \u5E7E\
    \u4F55\nnamespace bys::geo {\nconstexpr f128 EPS = 1e-9;\nconst f128 PI = std::acos(-1.0);\n\
    const f128 TAU = PI * 2;\ni32 sgn(f128 a) { return (a < -EPS) ? -1 : (a > EPS)\
    \ ? 1 : 0; }\nbool isclose(f128 a, f128 b) { return sgn(a - b) == 0; }\n//! @brief\
    \ \u5EA6\u6570\u6CD5 -> \u5F27\u5EA6\u6CD5\nf128 radian(f128 degree) { return\
    \ degree * (PI / 180.0); }\n//! @brief \u5F27\u5EA6\u6CD5 -> \u5EA6\u6570\u6CD5\
    \nf128 degree(f128 theta) { return theta * (180.0 / PI); }\n}  // namespace bys::geo\n\
    /**\n * @file point.hpp\n * @brief Point\n */\nnamespace bys::geo {\n//! @brief\
    \ \u70B9/\u30D9\u30AF\u30C8\u30EB\ntemplate <class T> struct Point {\n    T x,\
    \ y;\n    Point() : x(0.0), y(0.0) {}\n    Point(T x, T y) : x(x), y(y) {}\n \
    \   // clang-format off\n    friend std::istream& operator>>(std::istream& is,\
    \ Point& v) { return is >> v.x >> v.y; }\n    friend std::ostream& operator<<(std::ostream&\
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
    \ x + y * y; }\n    //! @brief \u30CE\u30EB\u30E0\n    f128 norm() const { return\
    \ std::sqrt(norm2()); }\n    //! @brief \u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\n\
    \    Point normalized() const { return Point(x / norm(), y / norm()); }\n    //!\
    \ @brief \u504F\u89D2\n    f128 angle() const { return std::atan2(y, x); }\n \
    \   //! @brief \u56DE\u8EE2\n    Point rotate(f128 theta) const {\n        f128\
    \ ct = std::cos(theta), st = std::sin(theta);\n        return Point(x * ct - y\
    \ * st, x * st + y * ct);\n    }\n    Point rotate90() const { return Point(-y,\
    \ x); }\n    //! @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u7528\
    \u300245\u5EA6\u56DE\u8EE2\u3057\u3066\u221A2\u500D\u3059\u308B\n    Point manhattan_rotate()\
    \ const { return Point(x - y, x + y); }\n    //! @brief \u5185\u7A4D\n    T dot(const\
    \ Point& rh) const { return x * rh.x + y * rh.y; }\n    //! @brief \u5916\u7A4D\
    \n    T det(const Point& rh) const { return x * rh.y - y * rh.x; }\n    //! @brief\
    \ \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB\n    Point normal() const { return Point(-normalized().y,\
    \ normalized().x); }\n    //! @brief \u6B63\u5C04\u5F71\u30D9\u30AF\u30C8\u30EB\
    \n    Point projection(const Point& to) const { return to * (dot(to) / to.norm2());\
    \ }\n    //! @brief \u8C61\u9650\n    i32 quadrant() const {\n        if (sgn(y)\
    \ >= 0) return sgn(x) >= 0 ? 1 : 2;\n        return sgn(x) >= 0 ? 4 : 3;\n   \
    \ }\n    //! @brief \u504F\u89D2\u30BD\u30FC\u30C8\u7528\n    bool operator<(const\
    \ Point& rh) const {\n        i32 q = quadrant(), rhq = rh.quadrant();\n     \
    \   if (q != rhq) return q < rhq;\n        return sgn(det(rh)) > 0;\n    }\n \
    \   bool operator<=(const Point& rh) const {\n        i32 q = quadrant(), rhq\
    \ = rh.quadrant();\n        if (q != rhq) return q < rhq;\n        return sgn(det(rh))\
    \ >= 0;\n    }\n};\n\ntemplate <class T> bool compx(Point<T>& a, Point<T>& b)\
    \ { return a.x < b.x; }\ntemplate <class T> bool compy(Point<T>& a, Point<T>&\
    \ b) { return a.y < b.y; }\n//! @brief \u66F2\u304C\u308B\u65B9\u5411\nenum class\
    \ Turn {\n    //! ab\u306E\u5F8C\u65B9\n    Back = -2,\n    //! ab->bc\u304C\u53F3\
    \u306B\u66F2\u304C\u308B\n    CW = -1,\n    //! ab\u4E0A\n    Middle = 0,\n  \
    \  //! ab->bc\u304C\u5DE6\u306B\u66F2\u304C\u308B\n    CCW = 1,\n    //! ab\u306E\
    \u524D\u65B9\n    Front = 2,\n};\n//! @brief \u8FBA\u306E\u66F2\u304C\u308B\u65B9\
    \u5411\ntemplate <class T> Turn iSP(const Point<T>& a, const Point<T>& b, const\
    \ Point<T>& c) {\n    i32 flg = sgn((b - a).det(c - a));\n    if (flg == 1) {\n\
    \        return Turn::CCW;\n    } else if (flg == -1) {\n        return Turn::CW;\n\
    \    } else {\n        if (sgn((b - a).dot(c - b)) > 0) {\n            return\
    \ Turn::Front;\n        } else if (sgn((a - b).dot(c - a)) > 0) {\n          \
    \  return Turn::Back;\n        } else {\n            return Turn::Middle;\n  \
    \      }\n    }\n}\nenum class Angle {\n    //! \u920D\u89D2\n    Obtuse = -1,\n\
    \    //! \u76F4\u89D2\n    Right = 0,\n    //! \u92ED\u89D2\n    Acute = 1,\n\
    };\n\n//! @brief \u89D2\u306E\u7A2E\u985E\ntemplate <class T> Angle angle_type(const\
    \ Point<T>& a, const Point<T>& b, const Point<T>& c) {\n    i32 t = sgn((a - b).dot(c\
    \ - b));\n    if (t == -1) {\n        return Angle::Obtuse;\n    } else if (t\
    \ == 0) {\n        return Angle::Right;\n    } else {\n        return Angle::Acute;\n\
    \    }\n}\ntemplate <class T> T distance2(const Point<T>& a, const Point<T>& b)\
    \ {\n    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);\n}\ntemplate\
    \ <class T> T distance(const Point<T>& a, const Point<T>& b) { return sqrt(distance2(a,\
    \ b)); }\n}  // namespace bys::geo\n\n/**\n * @file line.hpp\n * @brief Line\n\
    \ * @todo \u534A\u76F4\u7DDA\u306E\u5B9F\u88C5\n */\nnamespace bys::geo {\ntemplate\
    \ <class T>\n//! @brief \u76F4\u7DDA\nstruct Line {\n    Point<T> p, q;\n    Line(Point<T>\
    \ p, Point<T> q) : p(p), q(q) {}\n    Point<T> to_Point() const { return q - p;\
    \ }\n    Point<f128> to_unit_Point() const { return to_Point().normalized(); }\n\
    \    f128 angle() const { return to_Point().angle(); }\n    bool operator==(const\
    \ Line& rh) const { return abs((i32)iSP(p, q, rh.p)) != 1 && abs((i32)iSP(p, q,\
    \ rh.q)) != 1; }\n    bool operator!=(const Line& rh) const { return !(*this ==\
    \ rh); }\n};\n//! @brief \u7DDA\u5206\ntemplate <class T> struct Segment : Line<T>\
    \ {\n    Segment(Point<T>& p, Point<T>& q) : Line<T>::Line(p, q) {}\n    f128\
    \ length() const { return this->to_Point().norm(); }\n    Point<f128> internal_division(f128\
    \ m, f128 n) const { return (this->p * n + this->q * m) / (m + n); }\n    bool\
    \ operator==(const Segment& rh) const {\n        return (this->p == rh.p && this->q\
    \ == rh.q) || (this->p == rh.q && this->q == rh.p);\n    }\n    bool operator!=(const\
    \ Segment& rh) const { return !(*this == rh); }\n};\ntemplate <class T> Turn iSP(const\
    \ Point<T>& p, const Line<T>& l) { return iSP(l.p, l.q, p); }\ntemplate <class\
    \ T> bool is_parallel(const Line<T>& a, const Line<T>& b) { return sgn(a.to_Point().det(b.to_Point()))\
    \ == 0; }\ntemplate <class T> bool is_vertial(const Line<T>& a, const Line<T>&\
    \ b) { return sgn(a.to_Point().dot(b.to_Point())) == 0; }\ntemplate <class T>\
    \ bool is_cross(const Line<T>& a, const Line<T>& b) {\n    return sgn(a.to_Point().det(b.to_Point()))\
    \ != 0 || sgn(a.to_Point().det(b.p - a.p)) == 0;\n}\ntemplate <class T> bool is_cross(const\
    \ Segment<T>& a, const Segment<T>& b) {\n    return (i32)iSP(b.p, a) * (i32)iSP(b.q,\
    \ a) <= 0 && (i32)iSP(a.p, b) * (i32)iSP(a.q, b) <= 0;\n}\ntemplate <class T>\
    \ f128 angle(const Line<T>& a, const Line<T>& b) {\n    return std::atan2(a.to_Point().det(b.to_Point()),\
    \ a.to_Point().dot(b.to_Point()));\n}\n\ntemplate <class T> f128 distance(const\
    \ Point<T>& p, const Line<T>& l) {\n    return std::abs(l.to_Point().det(p - l.p)\
    \ / (l.q - l.p).norm());\n}\ntemplate <class T> f128 distance(const Point<T>&\
    \ p, const Segment<T>& s) {\n    if (angle_type(s.p, s.q, p) == Angle::Obtuse)\
    \ {\n        return (p - s.q).norm();\n    } else if (angle_type(s.q, s.p, p)\
    \ == Angle::Obtuse) {\n        return (p - s.p).norm();\n    } else {\n      \
    \  return distance(p, Line(s.p, s.q));\n    }\n}\ntemplate <class T> f128 distance(const\
    \ Segment<T>& s, const Segment<T>& t) {\n    if (is_cross(s, t)) return 0;\n \
    \   return std::min({distance(s.p, t), distance(s.q, t), distance(t.p, s), distance(t.q,\
    \ s)});\n}\ntemplate <class T> std::optional<Point<T>> cross_point(const Line<T>&\
    \ a, const Line<T>& b) {\n    if (!is_cross(a, b)) return std::nullopt;\n    return\
    \ a.p + a.to_Point() * (b.p - a.p).det(b.to_Point()) / a.to_Point().det(b.to_Point());\n\
    }\n//! @brief \u5782\u7DDA\u306E\u8DB3\ntemplate <class T> Point<T> projection(const\
    \ Point<T>& p, const Line<T>& l) { return (p - l.p).projection(l.to_Point()) +\
    \ l.p; }\n//! @brief \u7DDA\u5BFE\u79F0\u306E\u70B9\ntemplate <class T> Point<T>\
    \ reflection(const Point<T>& p, const Line<T>& l) { return p + (projection(p,\
    \ l) - p) * 2; }\n}  // namespace bys::geo\n/**\n * @file template.hpp\n * @author\
    \ bayashi_cl\n *\n * C++ library for competitive programming by bayashi_cl\n *\
    \ Repository: https://github.com/bayashi-cl/byslib\n * Document  : https://bayashi-cl.github.io/byslib/\n\
    \ */\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <cstddef>\n#include <limits>\n\
    #include <tuple>\n#include <utility>\n\n#include <array>\n#include <type_traits>\n\
    /**\n * @file traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\n\
    namespace bys {\ntemplate <class, class = void> struct has_rshift_from_istream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_rshift_from_istream<T,\
    \ std::void_t<decltype(std::declval<std::istream&>() >> std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_rshift_from_istream_v\
    \ = has_rshift_from_istream<T>::value;\n\ntemplate <class, class = void> struct\
    \ has_lshift_to_ostream : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T,\
    \ std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_lshft_to_ostream_v\
    \ = has_lshift_to_ostream<T>::value;\n\ntemplate <class, class = void> struct\
    \ is_tuple_like : std::false_type {};\ntemplate <class T> struct is_tuple_like<T,\
    \ std::void_t<decltype(std::tuple_size<T>())>> : std::true_type {};\ntemplate\
    \ <class T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\n\ntemplate\
    \ <class, class = void> struct is_iterable : std::false_type {};\ntemplate <class\
    \ T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>\
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
    \ const& b) { return a > b ? a = b, true : false; }\n}  // namespace bys\n#include\
    \ <iterator>\n#include <vector>\n\n\nnamespace bys {\ntemplate <class Iterator>\
    \ class SubRange {\n  public:\n    using iterator = Iterator;\n    using reverse_iterator\
    \ = std::reverse_iterator<iterator>;\n    using value_type = typename iterator::value_type;\n\
    \n    SubRange() = default;\n    SubRange(const SubRange& s) : _begin(s._begin),\
    \ _end(s._end) {}\n    SubRange(const iterator& begin, const iterator& end) :\
    \ _begin(begin), _end(end) {}\n\n    iterator begin() const noexcept { return\
    \ _begin; }\n    iterator end() const noexcept { return _end; }\n    reverse_iterator\
    \ rbegin() const noexcept { return reverse_iterator{_end}; }\n    reverse_iterator\
    \ rend() const { return reverse_iterator{_begin}; }\n    auto operator[](std::size_t\
    \ i) const noexcept { return *(_begin + i); }\n    auto size() const noexcept\
    \ { return _end - _begin; }\n    bool empty() const noexcept { return _begin ==\
    \ _end; }\n\n    auto to_vec() const { return std::vector(_begin, _end); }\n\n\
    \  private:\n    iterator _begin, _end;\n};\ntemplate <class Iterable> auto reversed(Iterable&&\
    \ iter) {\n    static_assert(is_iterable_v<Iterable>, \"iter is not iterable\"\
    );\n    return SubRange(std::rbegin(std::forward<Iterable>(iter)), std::rend(std::forward<Iterable>(iter)));\n\
    }\n}  // namespace bys\n/**\n * @file enumerate.hpp\n * @brief Python::enumerate\n\
    \ *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA enumerate\u7DE8\n * See: https://docs.python.org/ja/3/library/functions.html#enumerate\n\
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
    \ * @brief STL Template\n */\n#include <bitset>\n#include <cassert>\n#include\
    \ <complex>\n#include <functional>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs;\n\n// alias\nusing Pa\
    \ = std::pair<i32, i32>;\nusing Pa64 = std::pair<i64, i64>;\ntemplate <class T>\
    \ using uset = std::unordered_set<T>;\ntemplate <class S, class T> using umap\
    \ = std::unordered_map<S, T>;\n}  // namespace bys\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto [p1, p2] = scanner.read<geo::Point<f128>, 2>();\n    geo::Line l(p1,\
    \ p2);\n    auto q = scanner.read<i32>();\n    for (int i = 0; i < q; ++i) {\n\
    \        auto p = scanner.read<geo::Point<f128>>();\n        print(geo::projection(p,\
    \ l));\n    }\n}\n}  // namespace bys\n\nint main() { return bys::Solver::main(/*\
    \ bys::scanner.read<int>() */); }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A\"\
    \n#define ERROR 1e-8\n#include \"../../byslib/geometry/line.hpp\"\n#include \"\
    ../../byslib/template.hpp\"\n\nnamespace bys {\nvoid Solver::solve() {\n    auto\
    \ [p1, p2] = scanner.read<geo::Point<f128>, 2>();\n    geo::Line l(p1, p2);\n\
    \    auto q = scanner.read<i32>();\n    for (int i = 0; i < q; ++i) {\n      \
    \  auto p = scanner.read<geo::Point<f128>>();\n        print(geo::projection(p,\
    \ l));\n    }\n}\n}  // namespace bys\n\nint main() { return bys::Solver::main(/*\
    \ bys::scanner.read<int>() */); }\n"
  dependsOn:
  - byslib/geometry/line.hpp
  - byslib/geometry/point.hpp
  - byslib/geometry/base.hpp
  - byslib/core/int_alias.hpp
  - byslib/template.hpp
  - byslib/core/constant.hpp
  - byslib/core/traits.hpp
  - byslib/extension/change.hpp
  - byslib/extension/enumerate.hpp
  - byslib/extension/subrange.hpp
  - byslib/extension/irange.hpp
  - byslib/extension/macro.hpp
  - byslib/io/io.hpp
  - byslib/io/printer.hpp
  - byslib/io/scanner.hpp
  - byslib/procon/solver.hpp
  - byslib/procon/stdlib.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_1_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-02 16:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_1_A.test.cpp
- /verify/test/AOJ/CGL_1_A.test.cpp.html
title: test/AOJ/CGL_1_A.test.cpp
---