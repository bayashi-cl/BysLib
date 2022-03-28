---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Python::enumerate
    links:
    - https://docs.python.org/ja/3/library/functions.html#enumerate
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
    \ T>;\n}  // namespace bys\n/**\n * @file enumerate.hpp\n * @author bayashi_cl\n\
    \ * @brief Python::enumerate\n *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA\
    \ enumerate\u7DE8\n * See: https://docs.python.org/ja/3/library/functions.html#enumerate\n\
    \ */\nnamespace bys {\ntemplate <class Iterator>\nclass Enumerate {\n    Iterator\
    \ _begin, _end;\n    int _idx;\n\n   public:\n    class EnumerateIterator {\n\
    \        Iterator _iter;\n        int _id;\n\n       public:\n        EnumerateIterator(Iterator\
    \ iter, int id) : _iter(iter), _id(id) {}\n        void operator++() { ++_iter,\
    \ ++_id; }\n        bool operator!=(const EnumerateIterator& other) const { return\
    \ _iter != other._iter; }\n        auto operator*() { return std::tie(_id, *_iter);\
    \ }\n    };\n\n    Enumerate(Iterator from, Iterator to, int start) : _begin(from),\
    \ _end(to), _idx(start) {}\n    auto begin() const { return EnumerateIterator(_begin,\
    \ _idx); }\n    auto end() const { return EnumerateIterator(_end, _idx + std::distance(_begin,\
    \ _end)); }\n};\n/**\n * @brief enumerate\n *\n * @param iterable \u5BFE\u8C61\
    \n * @param start index\u306E\u521D\u671F\u5024\n */\ntemplate <class Iterable>\n\
    auto enumerate(Iterable& iterable, int start = 0) {\n    return Enumerate(std::begin(iterable),\
    \ std::end(iterable), start);\n}\n/**\n * @brief const enumerate\n *\n * @param\
    \ iterable \u5BFE\u8C61\n * @param start index\u306E\u521D\u671F\u5024\n */\n\
    template <class Iterable>\nauto cenumerate(Iterable& iterable, int start = 0)\
    \ {\n    return Enumerate(std::cbegin(iterable), std::cend(iterable), start);\n\
    }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file enumerate.hpp\n\
    \ * @author bayashi_cl\n * @brief Python::enumerate\n *\n * Python\u518D\u73FE\
    \u30B7\u30EA\u30FC\u30BA enumerate\u7DE8\n * See: https://docs.python.org/ja/3/library/functions.html#enumerate\n\
    \ */\nnamespace bys {\ntemplate <class Iterator>\nclass Enumerate {\n    Iterator\
    \ _begin, _end;\n    int _idx;\n\n   public:\n    class EnumerateIterator {\n\
    \        Iterator _iter;\n        int _id;\n\n       public:\n        EnumerateIterator(Iterator\
    \ iter, int id) : _iter(iter), _id(id) {}\n        void operator++() { ++_iter,\
    \ ++_id; }\n        bool operator!=(const EnumerateIterator& other) const { return\
    \ _iter != other._iter; }\n        auto operator*() { return std::tie(_id, *_iter);\
    \ }\n    };\n\n    Enumerate(Iterator from, Iterator to, int start) : _begin(from),\
    \ _end(to), _idx(start) {}\n    auto begin() const { return EnumerateIterator(_begin,\
    \ _idx); }\n    auto end() const { return EnumerateIterator(_end, _idx + std::distance(_begin,\
    \ _end)); }\n};\n/**\n * @brief enumerate\n *\n * @param iterable \u5BFE\u8C61\
    \n * @param start index\u306E\u521D\u671F\u5024\n */\ntemplate <class Iterable>\n\
    auto enumerate(Iterable& iterable, int start = 0) {\n    return Enumerate(std::begin(iterable),\
    \ std::end(iterable), start);\n}\n/**\n * @brief const enumerate\n *\n * @param\
    \ iterable \u5BFE\u8C61\n * @param start index\u306E\u521D\u671F\u5024\n */\n\
    template <class Iterable>\nauto cenumerate(Iterable& iterable, int start = 0)\
    \ {\n    return Enumerate(std::cbegin(iterable), std::cend(iterable), start);\n\
    }\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/enumerate.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/enumerate.hpp
layout: document
redirect_from:
- /library/utility/enumerate.hpp
- /library/utility/enumerate.hpp.html
title: Python::enumerate
---
