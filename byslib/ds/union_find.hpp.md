---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/graph/kruskal.hpp
    title: byslib/graph/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union Find Tree
    links: []
  bundledCode: "#include <cassert>\n#include <map>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\n\
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
    }  // namespace bys\n/**\n * @file union_find.hpp\n * @brief Union Find Tree\n\
    \ */\nnamespace bys {\n//! @brief Union Find Tree\nstruct UnionFindTree {\n  \
    \  UnionFindTree() : _n(0) {}\n    UnionFindTree(i32 n) : _n(n), _n_tree(_n),\
    \ parent(_n, -1) {}\n\n    i32 find(i32 a) {\n        assert(a < _n);\n      \
    \  std::vector<i32> path;\n        while (parent[a] >= 0) {\n            path.emplace_back(a);\n\
    \            a = parent[a];\n        }\n        for (auto&& p : path) parent[p]\
    \ = a;\n        return a;\n    }\n    bool same(i32 a, i32 b) {\n        assert(a\
    \ < _n);\n        assert(b < _n);\n        return find(a) == find(b);\n    }\n\
    \    /**\n     * @brief \u30DE\u30FC\u30B8\n     *\n     * a, b\u304C\u5225\u306E\
    \u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\u305F\u5834\u5408true\n\
    \     */\n    bool unite(i32 a, i32 b) {\n        assert(a < _n);\n        assert(b\
    \ < _n);\n        a = find(a);\n        b = find(b);\n        if (a == b) return\
    \ false;\n        --_n_tree;\n        if (-parent[a] < -parent[b]) std::swap(a,\
    \ b);\n        parent[a] += parent[b];\n        parent[b] = a;\n        return\
    \ true;\n    }\n    std::map<i32, std::vector<i32>> groups() {\n        std::map<i32,\
    \ std::vector<i32>> res;\n        for (i32 i = 0; i < _n; ++i) res[find(i)].emplace_back(i);\n\
    \        return res;\n    };\n    i32 size(i32 a) { return -parent[find(a)]; }\n\
    \    i32 n_tree() { return _n_tree; }\n\n  private:\n    i32 _n, _n_tree;\n  \
    \  std::vector<i32> parent;  // \u8CA0\u306A\u3089\u89AA\u3067\u3042\u308A\u305D\
    \u306E\u5024\u306F(-\u5B50\u306E\u6570)\n};\ntemplate <class T, class Lambda>\
    \ struct UnionFindTreeWithData : UnionFindTree {\n    std::vector<T> _data;\n\
    \    Lambda _mearge;\n\n    UnionFindTreeWithData(i32 n, const std::vector<T>&\
    \ data, Lambda mearge)\n        : UnionFindTree::UnionFindTree(n), _data(data),\
    \ _mearge(mearge) {}\n\n    bool unite(i32 a, i32 b) {\n        auto leader_a\
    \ = find(a), leader_b = find(b);\n        if (UnionFindTree::unite(a, b)) {\n\
    \            auto new_leader = find(a);\n            _data[new_leader] = _mearge(_data[leader_a],\
    \ _data[leader_b]);\n            return true;\n        } else {\n            return\
    \ false;\n        }\n    }\n    T get(i32 i) { return _data[find(i)]; }\n};\n\n\
    struct LinkedUnionFindTree : UnionFindTree {\n    std::vector<i32> _link;\n  \
    \  LinkedUnionFindTree(i32 n) : UnionFindTree::UnionFindTree(n), _link(n) { std::iota(_link.begin(),\
    \ _link.end(), 0); }\n\n    bool unite(i32 a, i32 b) {\n        if (UnionFindTree::unite(a,\
    \ b)) {\n            std::swap(_link[a], _link[b]);\n            return true;\n\
    \        } else {\n            return false;\n        }\n    }\n    std::vector<i32>\
    \ connect(i32 x) const {\n        std::vector<i32> res = {x};\n        for (i32\
    \ y = _link[x]; y != x; y = _link[y]) res.push_back(y);\n        return res;\n\
    \    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <cassert>\n#include <map>\n#include <numeric>\n#include\
    \ <utility>\n#include <vector>\n#include \"../core/int_alias.hpp\"\n/**\n * @file\
    \ union_find.hpp\n * @brief Union Find Tree\n */\nnamespace bys {\n//! @brief\
    \ Union Find Tree\nstruct UnionFindTree {\n    UnionFindTree() : _n(0) {}\n  \
    \  UnionFindTree(i32 n) : _n(n), _n_tree(_n), parent(_n, -1) {}\n\n    i32 find(i32\
    \ a) {\n        assert(a < _n);\n        std::vector<i32> path;\n        while\
    \ (parent[a] >= 0) {\n            path.emplace_back(a);\n            a = parent[a];\n\
    \        }\n        for (auto&& p : path) parent[p] = a;\n        return a;\n\
    \    }\n    bool same(i32 a, i32 b) {\n        assert(a < _n);\n        assert(b\
    \ < _n);\n        return find(a) == find(b);\n    }\n    /**\n     * @brief \u30DE\
    \u30FC\u30B8\n     *\n     * a, b\u304C\u5225\u306E\u9023\u7D50\u6210\u5206\u306B\
    \u5C5E\u3057\u3066\u3044\u305F\u5834\u5408true\n     */\n    bool unite(i32 a,\
    \ i32 b) {\n        assert(a < _n);\n        assert(b < _n);\n        a = find(a);\n\
    \        b = find(b);\n        if (a == b) return false;\n        --_n_tree;\n\
    \        if (-parent[a] < -parent[b]) std::swap(a, b);\n        parent[a] += parent[b];\n\
    \        parent[b] = a;\n        return true;\n    }\n    std::map<i32, std::vector<i32>>\
    \ groups() {\n        std::map<i32, std::vector<i32>> res;\n        for (i32 i\
    \ = 0; i < _n; ++i) res[find(i)].emplace_back(i);\n        return res;\n    };\n\
    \    i32 size(i32 a) { return -parent[find(a)]; }\n    i32 n_tree() { return _n_tree;\
    \ }\n\n  private:\n    i32 _n, _n_tree;\n    std::vector<i32> parent;  // \u8CA0\
    \u306A\u3089\u89AA\u3067\u3042\u308A\u305D\u306E\u5024\u306F(-\u5B50\u306E\u6570\
    )\n};\ntemplate <class T, class Lambda> struct UnionFindTreeWithData : UnionFindTree\
    \ {\n    std::vector<T> _data;\n    Lambda _mearge;\n\n    UnionFindTreeWithData(i32\
    \ n, const std::vector<T>& data, Lambda mearge)\n        : UnionFindTree::UnionFindTree(n),\
    \ _data(data), _mearge(mearge) {}\n\n    bool unite(i32 a, i32 b) {\n        auto\
    \ leader_a = find(a), leader_b = find(b);\n        if (UnionFindTree::unite(a,\
    \ b)) {\n            auto new_leader = find(a);\n            _data[new_leader]\
    \ = _mearge(_data[leader_a], _data[leader_b]);\n            return true;\n   \
    \     } else {\n            return false;\n        }\n    }\n    T get(i32 i)\
    \ { return _data[find(i)]; }\n};\n\nstruct LinkedUnionFindTree : UnionFindTree\
    \ {\n    std::vector<i32> _link;\n    LinkedUnionFindTree(i32 n) : UnionFindTree::UnionFindTree(n),\
    \ _link(n) { std::iota(_link.begin(), _link.end(), 0); }\n\n    bool unite(i32\
    \ a, i32 b) {\n        if (UnionFindTree::unite(a, b)) {\n            std::swap(_link[a],\
    \ _link[b]);\n            return true;\n        } else {\n            return false;\n\
    \        }\n    }\n    std::vector<i32> connect(i32 x) const {\n        std::vector<i32>\
    \ res = {x};\n        for (i32 y = _link[x]; y != x; y = _link[y]) res.push_back(y);\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ds/union_find.hpp
  requiredBy:
  - byslib/graph/kruskal.hpp
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_1_A.test.cpp
  - test/yosupo/unionfind.test.cpp
documentation_of: byslib/ds/union_find.hpp
layout: document
redirect_from:
- /library/byslib/ds/union_find.hpp
- /library/byslib/ds/union_find.hpp.html
title: Union Find Tree
---
