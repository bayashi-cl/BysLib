---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: deapth_first_search.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../../core/core.hpp\"\
    \n#include \"../../graphv2/lca.hpp\"\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto [n, q] = scanner.read<int, 2>();\n    auto p = scanner.readvec<int>(n\
    \ - 1);\n    AdjacencyList graph(n, (n - 1) * 2);\n    for (int i = 0; i < n -\
    \ 1; ++i) {\n        graph.add_edge(p[i], i + 1);\n        graph.add_edge(i +\
    \ 1, p[i]);\n    }\n    LowestCommonAncestor lca(graph, 0);\n    for (int i =\
    \ 0; i < q; ++i) {\n        auto [u, v] = scanner.read<int, 2>();\n        print(lca.lca(u,\
    \ v));\n    }\n}\n}  // namespace bys\n\nint main() {\n    bys::Solver solver;\n\
    \    solver.solve(/* bys::scanner.read<int>() */);\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graphv2/lca.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graphv2/lca.test.cpp
layout: document
redirect_from:
- /verify/test/graphv2/lca.test.cpp
- /verify/test/graphv2/lca.test.cpp.html
title: test/graphv2/lca.test.cpp
---
