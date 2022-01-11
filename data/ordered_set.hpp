#pragma once
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
namespace bys {
template <typename T>
using OrderedSet = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using OrderedSetGT = tree<T, null_type, std::greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
}  // namespace bys
