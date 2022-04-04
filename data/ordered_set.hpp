#pragma once
#include <ext/pb_ds/assoc_container.hpp>
/**
 * @file ordered_set.hpp
 * @brief Ordered Set
 *
 * pb_dsのラッパ
 */
namespace bys {
using namespace __gnu_pbds;
template <typename T>
using OrderedSet = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using OrderedSetGT = tree<T, null_type, std::greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
}  // namespace bys
