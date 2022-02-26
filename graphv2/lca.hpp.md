---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: deapth_first_search.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"edge.hpp\"\n#include \"deapth_first_search.hpp\"\
    \n#include \"../data/sparse_table.hpp\"\n#include \"../utility/fixpoint.hpp\"\n\
    #include \"../math/algebra.hpp\"\n\nnamespace bys {\nclass LowestCommonAncestor\
    \ {\n    struct Vertex {\n        int id, depath;\n        bool operator<(const\
    \ Vertex& rh) const { return depath < rh.depath; }\n    };\n    std::size_t n;\n\
    \    SparseTable<Min<Vertex>> st;\n    std::vector<int> pos;\n\n   public:\n \
    \   LowestCommonAncestor(const AdjacencyList& graph, int root) : n(graph.size()),\
    \ pos(n) {\n        std::vector<Vertex> euler_tour;\n        euler_tour.reserve(2\
    \ * n - 1);\n        FixPoint([&](auto&& self, int now, int prev, int deapth)\
    \ -> void {\n            pos[now] = euler_tour.size();\n            euler_tour.push_back({now,\
    \ deapth});\n\n            for (auto&& nxt : graph[now]) {\n                if\
    \ (int(nxt.dest) == prev) continue;\n                self(nxt.dest, now, deapth\
    \ + 1);\n                euler_tour.push_back({now, deapth});\n            }\n\
    \        })(root, -1, 0);\n        st.build(euler_tour);\n    }\n    int lca(std::size_t\
    \ a, std::size_t b) {\n        assert(a < n);\n        assert(b < n);\n      \
    \  if (pos[a] > pos[b]) std::swap(a, b);\n        return st.query(pos[a], pos[b]).id;\n\
    \    }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: graphv2/lca.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphv2/lca.hpp
layout: document
redirect_from:
- /library/graphv2/lca.hpp
- /library/graphv2/lca.hpp.html
title: graphv2/lca.hpp
---
