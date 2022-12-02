---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/graph/dfs.hpp
    title: byslib/graph/dfs.hpp
  - icon: ':warning:'
    path: byslib/graph/lca.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: FixPoint
    links:
    - https://koturn.hatenablog.com/entry/2018/06/10/060000
  bundledCode: "#include <map>\n#include <utility>\n/**\n * @file fixpoint.hpp\n *\
    \ @brief FixPoint\n */\nnamespace bys {\n/**\n * @brief \u30E9\u30E0\u30C0\u518D\
    \u5E30\n *\n * @see: https://koturn.hatenablog.com/entry/2018/06/10/060000\n */\n\
    template <typename F> struct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args> decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\n/**\n * @brief \u30E1\u30E2\u5316\u518D\u5E30\n *\n * @see ?\n */\n\
    template <class F> class Cache : F {\n    template <class> struct get_signature\
    \ {};\n\n    template <class Fn, class R, class Self, class... Args> struct get_signature<R\
    \ (Fn::*)(Self, Args...) const> {\n        using result_type = R;\n        using\
    \ args_tuple = std::tuple<std::decay_t<Args>...>;\n    };\n\n    using signature\
    \ = get_signature<decltype(&F::template operator()<Cache<F>&>)>;\n    using args_tuple\
    \ = typename signature::args_tuple;\n    using result_type = typename signature::result_type;\n\
    \n    std::map<args_tuple, result_type> memo;\n\n  public:\n    Cache(F&& fn)\
    \ : F{std::forward<F>(fn)} {}\n\n    template <class... Args> result_type operator()(Args&&...\
    \ args) {\n        args_tuple key{std::forward<Args>(args)...};\n        if (auto\
    \ itr = memo.find(key); itr == memo.end()) {\n            result_type res = F::operator()(*this,\
    \ std::forward<Args>(args)...);\n            memo.emplace(key, res);\n       \
    \     return res;\n        } else {\n            return itr->second;\n       \
    \ }\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <map>\n#include <utility>\n/**\n * @file fixpoint.hpp\n\
    \ * @brief FixPoint\n */\nnamespace bys {\n/**\n * @brief \u30E9\u30E0\u30C0\u518D\
    \u5E30\n *\n * @see: https://koturn.hatenablog.com/entry/2018/06/10/060000\n */\n\
    template <typename F> struct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args> decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\n/**\n * @brief \u30E1\u30E2\u5316\u518D\u5E30\n *\n * @see ?\n */\n\
    template <class F> class Cache : F {\n    template <class> struct get_signature\
    \ {};\n\n    template <class Fn, class R, class Self, class... Args> struct get_signature<R\
    \ (Fn::*)(Self, Args...) const> {\n        using result_type = R;\n        using\
    \ args_tuple = std::tuple<std::decay_t<Args>...>;\n    };\n\n    using signature\
    \ = get_signature<decltype(&F::template operator()<Cache<F>&>)>;\n    using args_tuple\
    \ = typename signature::args_tuple;\n    using result_type = typename signature::result_type;\n\
    \n    std::map<args_tuple, result_type> memo;\n\n  public:\n    Cache(F&& fn)\
    \ : F{std::forward<F>(fn)} {}\n\n    template <class... Args> result_type operator()(Args&&...\
    \ args) {\n        args_tuple key{std::forward<Args>(args)...};\n        if (auto\
    \ itr = memo.find(key); itr == memo.end()) {\n            result_type res = F::operator()(*this,\
    \ std::forward<Args>(args)...);\n            memo.emplace(key, res);\n       \
    \     return res;\n        } else {\n            return itr->second;\n       \
    \ }\n    }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/fixpoint.hpp
  requiredBy:
  - byslib/graph/lca.hpp
  - byslib/graph/dfs.hpp
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/fixpoint.hpp
layout: document
redirect_from:
- /library/byslib/extension/fixpoint.hpp
- /library/byslib/extension/fixpoint.hpp.html
title: FixPoint
---
