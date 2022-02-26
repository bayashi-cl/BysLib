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
  bundledCode: '#line 2 "data/ordered_set.hpp"

    #include <ext/pb_ds/assoc_container.hpp>

    using namespace __gnu_pbds;

    namespace bys {

    template <typename T>

    using OrderedSet = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    template <typename T>

    using OrderedSetGT = tree<T, null_type, std::greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

    }  // namespace bys

    '
  code: '#pragma once

    #include <ext/pb_ds/assoc_container.hpp>

    using namespace __gnu_pbds;

    namespace bys {

    template <typename T>

    using OrderedSet = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    template <typename T>

    using OrderedSetGT = tree<T, null_type, std::greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

    }  // namespace bys

    '
  dependsOn: []
  isVerificationFile: false
  path: data/ordered_set.hpp
  requiredBy: []
  timestamp: '2022-01-12 08:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data/ordered_set.hpp
layout: document
redirect_from:
- /library/data/ordered_set.hpp
- /library/data/ordered_set.hpp.html
title: data/ordered_set.hpp
---
