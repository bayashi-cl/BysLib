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
    \ * @brief Ordered Set\n *\n * pb_ds\u306E\u30E9\u30C3\u30D1\n */\nnamespace bys\
    \ {\nnamespace pbds = __gnu_pbds;\ntemplate <class T, class Comp = std::less<T>>\n\
    using OrderdSet = pbds::tree<T, pbds::null_type, Comp, pbds::rb_tree_tag, pbds::tree_order_statistics_node_update>;\n\
    }  // namespace bys\n"
  code: "#pragma once\n#include <ext/pb_ds/assoc_container.hpp>\n/**\n * @file ordered_set.hpp\n\
    \ * @brief Ordered Set\n *\n * pb_ds\u306E\u30E9\u30C3\u30D1\n */\nnamespace bys\
    \ {\nnamespace pbds = __gnu_pbds;\ntemplate <class T, class Comp = std::less<T>>\n\
    using OrderdSet = pbds::tree<T, pbds::null_type, Comp, pbds::rb_tree_tag, pbds::tree_order_statistics_node_update>;\n\
    }  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/ds/ordered_set.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ds/ordered_set.hpp
layout: document
redirect_from:
- /library/byslib/ds/ordered_set.hpp
- /library/byslib/ds/ordered_set.hpp.html
title: Ordered Set
---
