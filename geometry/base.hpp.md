---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: Polygon
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/counter_clockwise.test.cpp
    title: test/geometry/counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_point.test.cpp
    title: test/geometry/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection.test.cpp
    title: test/geometry/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/parallel_orthogonal.test.cpp
    title: test/geometry/parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/projection.test.cpp
    title: test/geometry/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Base
    links: []
  bundledCode: "/**\n * @file stdlib.hpp\n * @brief STL Template\n */\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n/**\n * @file base.hpp\n * @brief Base\n */\n//! @brief \u5E7E\u4F55\n\
    namespace bys::geo {\nconst ld EPS = 1e-9;\nconst ld PI = std::acos(-1.0);\nconst\
    \ ld TAU = PI * 2;\nint sgn(ld a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0;\
    \ }\nbool isclose(ld a, ld b) { return sgn(a - b) == 0; }\n//! @brief \u5EA6\u6570\
    \u6CD5 -> \u5F27\u5EA6\u6CD5\nld radian(ld degree) { return degree * (PI / 180.0);\
    \ }\n//! @brief \u5F27\u5EA6\u6CD5 -> \u5EA6\u6570\u6CD5\nld degree(ld theta)\
    \ { return theta * (180.0 / PI); }\n}  // namespace bys::geo\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file base.hpp\n *\
    \ @brief Base\n */\n//! @brief \u5E7E\u4F55\nnamespace bys::geo {\nconst ld EPS\
    \ = 1e-9;\nconst ld PI = std::acos(-1.0);\nconst ld TAU = PI * 2;\nint sgn(ld\
    \ a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }\nbool isclose(ld a, ld b)\
    \ { return sgn(a - b) == 0; }\n//! @brief \u5EA6\u6570\u6CD5 -> \u5F27\u5EA6\u6CD5\
    \nld radian(ld degree) { return degree * (PI / 180.0); }\n//! @brief \u5F27\u5EA6\
    \u6CD5 -> \u5EA6\u6570\u6CD5\nld degree(ld theta) { return theta * (180.0 / PI);\
    \ }\n}  // namespace bys::geo\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: geometry/base.hpp
  requiredBy:
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/line.hpp
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/area.test.cpp
  - test/geometry/parallel_orthogonal.test.cpp
  - test/geometry/counter_clockwise.test.cpp
  - test/geometry/is_convex.test.cpp
  - test/geometry/cross_point.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/distance.test.cpp
  - test/geometry/projection.test.cpp
  - test/geometry/intersection.test.cpp
documentation_of: geometry/base.hpp
layout: document
redirect_from:
- /library/geometry/base.hpp
- /library/geometry/base.hpp.html
title: Base
---
