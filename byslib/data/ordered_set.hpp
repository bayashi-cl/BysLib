#pragma once
#include <ext/pb_ds/assoc_container.hpp>
/**
 * @file ordered_set.hpp
 * @brief Ordered Set
 *
 * pb_dsのラッパ
 */
namespace bys {
namespace pbds = __gnu_pbds;
template <class T, class Comp>
using Tree = pbds::
    tree<T, pbds::null_type, Comp, pbds::rb_tree_tag, pbds::tree_order_statistics_node_update>;

template <class T> using OrderdSet = Tree<T, std::less<T>>;
template <class T> using OrderdSetGt = Tree<T, std::greater<T>>;
}  // namespace bys
