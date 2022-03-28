---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Ordered Set
    links: []
  bundledCode: "#include <ext/pb_ds/assoc_container.hpp>\n/**\n * @file ordered_set.hpp\n\
    \ * @author bayashi_cl\n * @brief Ordered Set\n *\n * pb_ds\u306E\u30E9\u30C3\u30D1\
    \n */\nnamespace bys {\nusing namespace __gnu_pbds;\ntemplate <typename T>\nusing\
    \ OrderedSet = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    template <typename T>\nusing OrderedSetGT = tree<T, null_type, std::greater<T>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n}  // namespace bys\n"
  code: "#pragma once\n#include <ext/pb_ds/assoc_container.hpp>\n/**\n * @file ordered_set.hpp\n\
    \ * @author bayashi_cl\n * @brief Ordered Set\n *\n * pb_ds\u306E\u30E9\u30C3\u30D1\
    \n */\nnamespace bys {\nusing namespace __gnu_pbds;\ntemplate <typename T>\nusing\
    \ OrderedSet = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    template <typename T>\nusing OrderedSetGT = tree<T, null_type, std::greater<T>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: data/ordered_set.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data/ordered_set.hpp
layout: document
redirect_from:
- /library/data/ordered_set.hpp
- /library/data/ordered_set.hpp.html
title: Ordered Set
---
