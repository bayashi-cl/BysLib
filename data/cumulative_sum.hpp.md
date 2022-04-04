---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/cumulative_sum.test.cpp
    title: test/data/cumulative_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/cumulative_sum_2D.test.cpp
    title: test/data/cumulative_sum_2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Cumulative Sum
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
    \ bys\n/**\n * @file cumulative_sum.hpp\n * @brief Cumulative Sum\n *\n * \u7D2F\
    \u7A4D\u548C\n */\nnamespace bys {\ntemplate <class T>\nstruct CumulativeSum {\n\
    \    std::vector<T> data;\n    CumulativeSum(int n) : data(n + 1){};\n    CumulativeSum(const\
    \ vector<T>& v) : data(v.size() + 1) { std::copy(v.begin(), v.end(), std::next(data.begin()));\
    \ };\n    void set(int i, int x) {\n        assert(!build);\n        data[i +\
    \ 1] = x;\n    }\n    void add(int i, int x) {\n        assert(!build);\n    \
    \    data[i + 1] += x;\n    }\n    void construct() {\n        assert(!build);\n\
    \        std::partial_sum(data.begin(), data.end(), data.begin());\n        build\
    \ = true;\n    }\n    T operator[](int p) const { return data[p + 1]; }\n    //\
    \ [l, r)\n    T sum(int l, int r) const {\n        assert(build);\n        if\
    \ (l > r) return 0;\n        return data[r] - data[l];\n    }\n\n   private:\n\
    \    bool build = false;\n};\ntemplate <class T>\nstruct CumulativeSum2D {\n \
    \   std::vector<std::vector<T>> data;\n    CumulativeSum2D(int n, int m) : data(n\
    \ + 1, vector<T>(m + 1)){};\n    CumulativeSum2D(const vector<vector<T>>& v) :\
    \ data(v.size() + 1, vector<T>(v[0].size() + 1)) {\n        int n = v.size();\n\
    \        for (int i = 0; i < n; ++i) {\n            std::copy(v[i].begin(), v[i].end(),\
    \ std::next(data[i + 1].begin()));\n        }\n    };\n    void set(int i, int\
    \ j, int x) {\n        assert(!build);\n        data[i + 1][j + 1] = x;\n    }\n\
    \    void add(int i, int j, int x) {\n        assert(!build);\n        data[i\
    \ + 1][j + 1] += x;\n    }\n    T get(int i, int j) const { return data[i + 1][j\
    \ + 1]; }\n    void construct() {\n        assert(!build);\n        int n = data.size();\n\
    \        int m = data[0].size();\n        for (int i = 1; i < n; ++i) {\n    \
    \        for (int j = 1; j < m; ++j) {\n                data[i][j] += data[i][j\
    \ - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n        }\n    \
    \    build = true;\n    }\n    // [si, gi), [sj, gj)\n    T sum(int si, int sj,\
    \ int gi, int gj) {\n        assert(build);\n        return (data[gi][gj] - data[si][gj]\
    \ - data[gi][sj] + data[si][sj]);\n    }\n    // [s, g)\n    T sum(pair<int, int>\
    \ s, pair<int, int> g) { return sum(s.first, s.second, g.first, g.second); }\n\
    \n   private:\n    bool build = false;\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file cumulative_sum.hpp\n\
    \ * @brief Cumulative Sum\n *\n * \u7D2F\u7A4D\u548C\n */\nnamespace bys {\ntemplate\
    \ <class T>\nstruct CumulativeSum {\n    std::vector<T> data;\n    CumulativeSum(int\
    \ n) : data(n + 1){};\n    CumulativeSum(const vector<T>& v) : data(v.size() +\
    \ 1) { std::copy(v.begin(), v.end(), std::next(data.begin())); };\n    void set(int\
    \ i, int x) {\n        assert(!build);\n        data[i + 1] = x;\n    }\n    void\
    \ add(int i, int x) {\n        assert(!build);\n        data[i + 1] += x;\n  \
    \  }\n    void construct() {\n        assert(!build);\n        std::partial_sum(data.begin(),\
    \ data.end(), data.begin());\n        build = true;\n    }\n    T operator[](int\
    \ p) const { return data[p + 1]; }\n    // [l, r)\n    T sum(int l, int r) const\
    \ {\n        assert(build);\n        if (l > r) return 0;\n        return data[r]\
    \ - data[l];\n    }\n\n   private:\n    bool build = false;\n};\ntemplate <class\
    \ T>\nstruct CumulativeSum2D {\n    std::vector<std::vector<T>> data;\n    CumulativeSum2D(int\
    \ n, int m) : data(n + 1, vector<T>(m + 1)){};\n    CumulativeSum2D(const vector<vector<T>>&\
    \ v) : data(v.size() + 1, vector<T>(v[0].size() + 1)) {\n        int n = v.size();\n\
    \        for (int i = 0; i < n; ++i) {\n            std::copy(v[i].begin(), v[i].end(),\
    \ std::next(data[i + 1].begin()));\n        }\n    };\n    void set(int i, int\
    \ j, int x) {\n        assert(!build);\n        data[i + 1][j + 1] = x;\n    }\n\
    \    void add(int i, int j, int x) {\n        assert(!build);\n        data[i\
    \ + 1][j + 1] += x;\n    }\n    T get(int i, int j) const { return data[i + 1][j\
    \ + 1]; }\n    void construct() {\n        assert(!build);\n        int n = data.size();\n\
    \        int m = data[0].size();\n        for (int i = 1; i < n; ++i) {\n    \
    \        for (int j = 1; j < m; ++j) {\n                data[i][j] += data[i][j\
    \ - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n        }\n    \
    \    build = true;\n    }\n    // [si, gi), [sj, gj)\n    T sum(int si, int sj,\
    \ int gi, int gj) {\n        assert(build);\n        return (data[gi][gj] - data[si][gj]\
    \ - data[gi][sj] + data[si][sj]);\n    }\n    // [s, g)\n    T sum(pair<int, int>\
    \ s, pair<int, int> g) { return sum(s.first, s.second, g.first, g.second); }\n\
    \n   private:\n    bool build = false;\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: data/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/cumulative_sum_2D.test.cpp
  - test/data/cumulative_sum.test.cpp
documentation_of: data/cumulative_sum.hpp
layout: document
redirect_from:
- /library/data/cumulative_sum.hpp
- /library/data/cumulative_sum.hpp.html
title: Cumulative Sum
---
