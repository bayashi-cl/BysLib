---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4EFB\u610F\u306E\u578B\u30921\u3064"
    links: []
  bundledCode: "#line 2 \"core/stdlib.hpp\"\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\
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
    \ bys\n#line 3 \"core/io_old.hpp\"\n\nnamespace bys {\n// pair\ntemplate <class\
    \ T, class U>\nstd::istream& operator>>(std::istream& is, std::pair<T, U>& p)\
    \ {\n    return is >> p.first >> p.second;\n}\ntemplate <typename T, typename\
    \ U>\nstd::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {\n\
    \    return os << p.first << \" \" << p.second;\n}\n\n// STL container\nstruct\
    \ is_container_impl {\n    template <typename T>\n    static auto check(T&& obj)\
    \ -> decltype(obj.begin(), obj.end(), std::true_type{});\n    template <typename\
    \ T>\n    static auto check(...) -> std::false_type;\n};\ntemplate <typename T>\n\
    class is_container : public decltype(is_container_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename C, typename std::enable_if<is_container<C>::value\
    \ && !std::is_same<C, std::string>::value &&\n                               \
    \                   !std::is_same<C, std::wstring>::value,\n                 \
    \                             std::nullptr_t>::type = nullptr>\nstd::ostream&\
    \ operator<<(std::ostream& os, const C& container) noexcept {\n    if (container.empty())\
    \ return os;\n    std::for_each(std::begin(container), std::prev(std::end(container)),\
    \ [&](auto e) { os << e << ' '; });\n    return os << *std::prev(std::end(container));\n\
    }\n\ntemplate <typename C, typename std::enable_if<is_container<C>::value && !std::is_same<C,\
    \ std::string>::value &&\n                                                  !std::is_same<C,\
    \ std::wstring>::value,\n                                              std::nullptr_t>::type\
    \ = nullptr>\nstd::istream& operator>>(std::istream& is, C& container) {\n   \
    \ std::for_each(std::begin(container), std::end(container), [&](auto&& e) { is\
    \ >> e; });\n    return is;\n}\n\n// I/O helper\n//! @brief \u4EFB\u610F\u306E\
    \u578B\u30921\u3064\ntemplate <class T>\ninline T input() {\n    T n;\n    cin\
    \ >> n;\n    return n;\n}\n//! @brief \u4EFB\u610F\u306E\u578B\u304Cn\u8981\u7D20\
    \u306Evector\ntemplate <class T>\ninline vector<T> input(int n) {\n    vector<T>\
    \ res(n);\n    cin >> res;\n    return res;\n}\n//! @brief \u4EFB\u610F\u306E\u578B\
    \u304Cn\u884Cm\u5217\u306Evector\ntemplate <class T>\ninline vector<vector<T>>\
    \ input(int n, int m) {\n    vector res(n, vector<T>(m));\n    cin >> res;\n \
    \   return res;\n}\n\n//! @brief \u4EFB\u610F\u306E\u578B\u3092N\u500B \u53D7\u3051\
    \u53D6\u308A\u306F\u69CB\u9020\u5316\u675F\u7E1B\u3067\ntemplate <class T, size_t\
    \ N>\ninline std::array<T, N> input() {\n    std::array<T, N> res;\n    cin >>\
    \ res;\n    return res;\n}\n//! @brief 2\u3064\u4EE5\u4E0A\u306E\u7570\u306A\u308B\
    \u578B \u53D7\u3051\u53D6\u308A\u306F\u69CB\u9020\u5316\u675F\u7E1B\u3067\ntemplate\
    \ <class S, class T, class... Us>\nstd::tuple<S, T, Us...> input() {\n    std::tuple<S,\
    \ T, Us...> res;\n    std::apply([](auto&... e) { (cin >> ... >> e); }, res);\n\
    \    return res;\n}\n//! @brief \u6A19\u6E96\u5165\u529B\u304B\u3089\u4EE3\u5165\
    \ntemplate <class... Ts>\nvoid cinto(Ts&... args) {\n    (cin >> ... >> args);\n\
    }\n//! @brief python\u306Eprint\u3063\u307D\u3044\u6319\u52D5\u3092\u3059\u308B\
    \nstruct Print {\n    std::ostream& os;\n    string sep = \" \", end = \"\\n\"\
    ;\n    Print(std::ostream& os) : os(os) {}\n    ~Print() { os << std::flush; }\n\
    \    void operator()() { os << end; }\n    template <class T>\n    void operator()(const\
    \ T& a) {\n        os << a << end;\n    }\n    //! @brief \u7A7A\u767D\u533A\u5207\
    \u308A\u3067\u51FA\u529B\n    template <class T, class... Ts>\n    void operator()(const\
    \ T& a, const Ts&... b) {\n        os << a;\n        (os << ... << (os << sep,\
    \ b));\n        os << end;\n    }\n    //! @brief \u51FA\u529B\u5F8Cflush \u30A4\
    \u30F3\u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\u554F\u984C\u7528\n    template <class...\
    \ Ts>\n    void send(const Ts&... a) {\n        operator()(a...);\n        os\
    \ << std::flush;\n    }\n} print(std::cout), debug(std::cerr);\n\n//! @brief cin\u9AD8\
    \u901F\u5316\u306A\u3069\ninline void fastio() {\n    cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    cout << std::fixed << std::setprecision(11);\n    std::cerr << std::boolalpha;\n\
    }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"stdlib.hpp\"\n\nnamespace bys {\n// pair\ntemplate\
    \ <class T, class U>\nstd::istream& operator>>(std::istream& is, std::pair<T,\
    \ U>& p) {\n    return is >> p.first >> p.second;\n}\ntemplate <typename T, typename\
    \ U>\nstd::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {\n\
    \    return os << p.first << \" \" << p.second;\n}\n\n// STL container\nstruct\
    \ is_container_impl {\n    template <typename T>\n    static auto check(T&& obj)\
    \ -> decltype(obj.begin(), obj.end(), std::true_type{});\n    template <typename\
    \ T>\n    static auto check(...) -> std::false_type;\n};\ntemplate <typename T>\n\
    class is_container : public decltype(is_container_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename C, typename std::enable_if<is_container<C>::value\
    \ && !std::is_same<C, std::string>::value &&\n                               \
    \                   !std::is_same<C, std::wstring>::value,\n                 \
    \                             std::nullptr_t>::type = nullptr>\nstd::ostream&\
    \ operator<<(std::ostream& os, const C& container) noexcept {\n    if (container.empty())\
    \ return os;\n    std::for_each(std::begin(container), std::prev(std::end(container)),\
    \ [&](auto e) { os << e << ' '; });\n    return os << *std::prev(std::end(container));\n\
    }\n\ntemplate <typename C, typename std::enable_if<is_container<C>::value && !std::is_same<C,\
    \ std::string>::value &&\n                                                  !std::is_same<C,\
    \ std::wstring>::value,\n                                              std::nullptr_t>::type\
    \ = nullptr>\nstd::istream& operator>>(std::istream& is, C& container) {\n   \
    \ std::for_each(std::begin(container), std::end(container), [&](auto&& e) { is\
    \ >> e; });\n    return is;\n}\n\n// I/O helper\n//! @brief \u4EFB\u610F\u306E\
    \u578B\u30921\u3064\ntemplate <class T>\ninline T input() {\n    T n;\n    cin\
    \ >> n;\n    return n;\n}\n//! @brief \u4EFB\u610F\u306E\u578B\u304Cn\u8981\u7D20\
    \u306Evector\ntemplate <class T>\ninline vector<T> input(int n) {\n    vector<T>\
    \ res(n);\n    cin >> res;\n    return res;\n}\n//! @brief \u4EFB\u610F\u306E\u578B\
    \u304Cn\u884Cm\u5217\u306Evector\ntemplate <class T>\ninline vector<vector<T>>\
    \ input(int n, int m) {\n    vector res(n, vector<T>(m));\n    cin >> res;\n \
    \   return res;\n}\n\n//! @brief \u4EFB\u610F\u306E\u578B\u3092N\u500B \u53D7\u3051\
    \u53D6\u308A\u306F\u69CB\u9020\u5316\u675F\u7E1B\u3067\ntemplate <class T, size_t\
    \ N>\ninline std::array<T, N> input() {\n    std::array<T, N> res;\n    cin >>\
    \ res;\n    return res;\n}\n//! @brief 2\u3064\u4EE5\u4E0A\u306E\u7570\u306A\u308B\
    \u578B \u53D7\u3051\u53D6\u308A\u306F\u69CB\u9020\u5316\u675F\u7E1B\u3067\ntemplate\
    \ <class S, class T, class... Us>\nstd::tuple<S, T, Us...> input() {\n    std::tuple<S,\
    \ T, Us...> res;\n    std::apply([](auto&... e) { (cin >> ... >> e); }, res);\n\
    \    return res;\n}\n//! @brief \u6A19\u6E96\u5165\u529B\u304B\u3089\u4EE3\u5165\
    \ntemplate <class... Ts>\nvoid cinto(Ts&... args) {\n    (cin >> ... >> args);\n\
    }\n//! @brief python\u306Eprint\u3063\u307D\u3044\u6319\u52D5\u3092\u3059\u308B\
    \nstruct Print {\n    std::ostream& os;\n    string sep = \" \", end = \"\\n\"\
    ;\n    Print(std::ostream& os) : os(os) {}\n    ~Print() { os << std::flush; }\n\
    \    void operator()() { os << end; }\n    template <class T>\n    void operator()(const\
    \ T& a) {\n        os << a << end;\n    }\n    //! @brief \u7A7A\u767D\u533A\u5207\
    \u308A\u3067\u51FA\u529B\n    template <class T, class... Ts>\n    void operator()(const\
    \ T& a, const Ts&... b) {\n        os << a;\n        (os << ... << (os << sep,\
    \ b));\n        os << end;\n    }\n    //! @brief \u51FA\u529B\u5F8Cflush \u30A4\
    \u30F3\u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\u554F\u984C\u7528\n    template <class...\
    \ Ts>\n    void send(const Ts&... a) {\n        operator()(a...);\n        os\
    \ << std::flush;\n    }\n} print(std::cout), debug(std::cerr);\n\n//! @brief cin\u9AD8\
    \u901F\u5316\u306A\u3069\ninline void fastio() {\n    cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    cout << std::fixed << std::setprecision(11);\n    std::cerr << std::boolalpha;\n\
    }\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: core/io_old.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:16:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: core/io_old.hpp
layout: document
redirect_from:
- /library/core/io_old.hpp
- /library/core/io_old.hpp.html
title: "\u4EFB\u610F\u306E\u578B\u30921\u3064"
---
