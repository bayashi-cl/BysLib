#pragma once
#include <string>
using std::literals::string_literals::operator""s;
/**
 * @file macro.hpp
 * @brief Macro
 */
// clang-format off
#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)
//! @brief [[maybe_unused]]な変数を生成。
#define UV [[maybe_unused]] auto CONCAT(unused_val_, __LINE__)
#define RE std::runtime_error("file: "s + __FILE__ + ", line: "s + std::to_string(__LINE__) + ", func: "s + __func__)
#ifdef LOCAL
#define DEBUGBLOCK(block) block
#else
#define DEBUGBLOCK(block)
#endif
// clang-format on
