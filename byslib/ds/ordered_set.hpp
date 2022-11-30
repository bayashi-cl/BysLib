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
template <class T, class Comp = std::less<T>>
using OrderdSet = pbds::
    tree<T, pbds::null_type, Comp, pbds::rb_tree_tag, pbds::tree_order_statistics_node_update>;
}  // namespace bys
