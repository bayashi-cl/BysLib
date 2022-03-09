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
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <cmath>\n#include <complex>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\nnamespace bys {\ntemplate <class Iterator>\nclass Enumerate {\n    Iterator\
    \ _begin, _end;\n    int _idx;\n\n   public:\n    class EnumerateIterator {\n\
    \        Iterator _iter;\n        int _id;\n\n       public:\n        EnumerateIterator(Iterator\
    \ iter, int id) : _iter(iter), _id(id) {}\n        void operator++() { ++_iter,\
    \ ++_id; }\n        bool operator!=(const EnumerateIterator& other) const { return\
    \ _iter != other._iter; }\n        auto operator*() { return std::tie(_id, *_iter);\
    \ }\n    };\n\n    Enumerate(Iterator from, Iterator to, int start) : _begin(from),\
    \ _end(to), _idx(start) {}\n    auto begin() const { return EnumerateIterator(_begin,\
    \ _idx); }\n    auto end() const { return EnumerateIterator(_end, _idx + std::distance(_begin,\
    \ _end)); }\n};\n\ntemplate <class Iterable>\nauto enumerate(Iterable& iterable,\
    \ int start = 0) {\n    return Enumerate(std::begin(iterable), std::end(iterable),\
    \ start);\n}\ntemplate <class Iterable>\nauto cenumerate(Iterable& iterable, int\
    \ start = 0) {\n    return Enumerate(std::cbegin(iterable), std::cend(iterable),\
    \ start);\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\nnamespace bys {\ntemplate\
    \ <class Iterator>\nclass Enumerate {\n    Iterator _begin, _end;\n    int _idx;\n\
    \n   public:\n    class EnumerateIterator {\n        Iterator _iter;\n       \
    \ int _id;\n\n       public:\n        EnumerateIterator(Iterator iter, int id)\
    \ : _iter(iter), _id(id) {}\n        void operator++() { ++_iter, ++_id; }\n \
    \       bool operator!=(const EnumerateIterator& other) const { return _iter !=\
    \ other._iter; }\n        auto operator*() { return std::tie(_id, *_iter); }\n\
    \    };\n\n    Enumerate(Iterator from, Iterator to, int start) : _begin(from),\
    \ _end(to), _idx(start) {}\n    auto begin() const { return EnumerateIterator(_begin,\
    \ _idx); }\n    auto end() const { return EnumerateIterator(_end, _idx + std::distance(_begin,\
    \ _end)); }\n};\n\ntemplate <class Iterable>\nauto enumerate(Iterable& iterable,\
    \ int start = 0) {\n    return Enumerate(std::begin(iterable), std::end(iterable),\
    \ start);\n}\ntemplate <class Iterable>\nauto cenumerate(Iterable& iterable, int\
    \ start = 0) {\n    return Enumerate(std::cbegin(iterable), std::cend(iterable),\
    \ start);\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/enumerate.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:17:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/enumerate.hpp
layout: document
redirect_from:
- /library/utility/enumerate.hpp
- /library/utility/enumerate.hpp.html
title: utility/enumerate.hpp
---