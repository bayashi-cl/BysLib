---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Coordinate Compression
    links: []
  bundledCode: "/**\n * @file stdlib.hpp\n * @author bayashi_cl\n * @brief STL Template\n\
    \ */\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\n\
    using ll = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\n\
    using Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\n/**\n * @file compress.hpp\n * @author bayashi_cl\n\
    \ * @brief Coordinate Compression\n *\n * \u5EA7\u6A19\u5727\u7E2E\n */\nnamespace\
    \ bys {\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n */\ntemplate <class T>\nclass\
    \ Compress {\n    std::vector<T> cp;\n    bool build = false;\n\n   public:\n\
    \    Compress() {}\n    Compress(const std::vector<T>& vec) : cp(vec) { construct();\
    \ }\n    void add(T v) {\n        assert(!build);\n        cp.emplace_back(v);\n\
    \    }\n    void construct() {\n        assert(!build);\n        sort(std::begin(cp),\
    \ std::end(cp));\n        cp.erase(std::unique(std::begin(cp), std::end(cp)),\
    \ cp.end());\n        build = true;\n    }\n    //! @brief \u5727\u7E2E\u3055\u308C\
    \u305F\u5024\u3092\u53D6\u5F97 O(log N)\n    int get(T v) const {\n        assert(build);\n\
    \        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);\n     \
    \   assert(*itr == v);\n        return std::distance(cp.begin(), itr);\n    }\n\
    \    //! @brief \u89E3\u51CD\u3055\u308C\u305F\u5024\u3092\u53D6\u5F97 O(1)\n\
    \    T unzip(int i) const {\n        assert(build);\n        return cp[i];\n \
    \   }\n    std::size_t size() const { return cp.size(); }\n};\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file compress.hpp\n\
    \ * @author bayashi_cl\n * @brief Coordinate Compression\n *\n * \u5EA7\u6A19\u5727\
    \u7E2E\n */\nnamespace bys {\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n */\ntemplate\
    \ <class T>\nclass Compress {\n    std::vector<T> cp;\n    bool build = false;\n\
    \n   public:\n    Compress() {}\n    Compress(const std::vector<T>& vec) : cp(vec)\
    \ { construct(); }\n    void add(T v) {\n        assert(!build);\n        cp.emplace_back(v);\n\
    \    }\n    void construct() {\n        assert(!build);\n        sort(std::begin(cp),\
    \ std::end(cp));\n        cp.erase(std::unique(std::begin(cp), std::end(cp)),\
    \ cp.end());\n        build = true;\n    }\n    //! @brief \u5727\u7E2E\u3055\u308C\
    \u305F\u5024\u3092\u53D6\u5F97 O(log N)\n    int get(T v) const {\n        assert(build);\n\
    \        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);\n     \
    \   assert(*itr == v);\n        return std::distance(cp.begin(), itr);\n    }\n\
    \    //! @brief \u89E3\u51CD\u3055\u308C\u305F\u5024\u3092\u53D6\u5F97 O(1)\n\
    \    T unzip(int i) const {\n        assert(build);\n        return cp[i];\n \
    \   }\n    std::size_t size() const { return cp.size(); }\n};\n}  // namespace\
    \ bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/compress.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/compress.hpp
layout: document
redirect_from:
- /library/utility/compress.hpp
- /library/utility/compress.hpp.html
title: Coordinate Compression
---
