#pragma once
/**
 * @file stdlib.hpp
 * @brief STL Template
 */
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../core/int_alias.hpp"

namespace bys {
using std::array, std::vector, std::string, std::set, std::map, std::pair;
using std::cin, std::cout, std::endl;
using std::min, std::max, std::sort, std::reverse, std::abs;

// alias
using Pa = std::pair<i32, i32>;
using Pa64 = std::pair<i64, i64>;
template <class T> using uset = std::unordered_set<T>;
template <class S, class T> using umap = std::unordered_map<S, T>;
}  // namespace bys
