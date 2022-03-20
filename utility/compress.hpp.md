---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\nnamespace bys {\n/**\n * @brief  \u5EA7\u6A19\u5727\u7E2E\n * @details\
    \ \u4F7F\u3046\u524D\u306Bconstruct()\n */\ntemplate <class T>\nstruct Compress\
    \ {\n    Compress() {}\n    Compress(std::vector<T>& vec) : cp(vec) {}\n    void\
    \ add(T v) {\n        assert(!build);\n        cp.push_back(v);\n    }\n    void\
    \ construct() {\n        assert(!build);\n        sort(std::begin(cp), std::end(cp));\n\
    \        cp.erase(std::unique(std::begin(cp), std::end(cp)), cp.end());\n    \
    \    build = true;\n    }\n    //! @brief \u5727\u7E2E\u3055\u308C\u305F\u5024\
    \u3092\u53D6\u5F97 O(log N)\n    int get(T v) const {\n        assert(build);\n\
    \        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);\n     \
    \   assert(*itr == v);\n        return std::distance(cp.begin(), itr);\n    }\n\
    \    //! @brief \u89E3\u51CD\u3055\u308C\u305F\u5024\u3092\u53D6\u5F97 O(1)\n\
    \    T unzip(int i) {\n        assert(build);\n        return cp[i];\n    }\n\
    \    int size() const { return cp.size(); }\n\n   private:\n    std::vector<T>\
    \ cp;\n    bool build = false;\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\nnamespace bys {\n/**\n * @brief\
    \  \u5EA7\u6A19\u5727\u7E2E\n * @details \u4F7F\u3046\u524D\u306Bconstruct()\n\
    \ */\ntemplate <class T>\nstruct Compress {\n    Compress() {}\n    Compress(std::vector<T>&\
    \ vec) : cp(vec) {}\n    void add(T v) {\n        assert(!build);\n        cp.push_back(v);\n\
    \    }\n    void construct() {\n        assert(!build);\n        sort(std::begin(cp),\
    \ std::end(cp));\n        cp.erase(std::unique(std::begin(cp), std::end(cp)),\
    \ cp.end());\n        build = true;\n    }\n    //! @brief \u5727\u7E2E\u3055\u308C\
    \u305F\u5024\u3092\u53D6\u5F97 O(log N)\n    int get(T v) const {\n        assert(build);\n\
    \        auto itr = std::lower_bound(std::begin(cp), std::end(cp), v);\n     \
    \   assert(*itr == v);\n        return std::distance(cp.begin(), itr);\n    }\n\
    \    //! @brief \u89E3\u51CD\u3055\u308C\u305F\u5024\u3092\u53D6\u5F97 O(1)\n\
    \    T unzip(int i) {\n        assert(build);\n        return cp[i];\n    }\n\
    \    int size() const { return cp.size(); }\n\n   private:\n    std::vector<T>\
    \ cp;\n    bool build = false;\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/compress.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/compress.hpp
layout: document
redirect_from:
- /library/utility/compress.hpp
- /library/utility/compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
