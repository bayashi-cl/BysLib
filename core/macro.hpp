#pragma once
/**
 * @file macro.hpp
 * @brief Macro
 */
// clang-format off
#ifdef LOCAL
//! @brief デバッグ用出力 ジャッジ上では何もしない。
#define DEBUG(...) debug(debugfmt(__LINE__, __VA_ARGS__));
#else
#define DEBUG(...)
#endif
#define DEBUGCASE(casenum, ...) if (TESTCASE == casenum) DEBUG(__VA_ARGS__);
//! @brief printしてreturnする。
#define EXIT(...) { print(__VA_ARGS__); return; }
#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)
//! @brief [[maybe_unused]]な変数を生成。
#define UV [[maybe_unused]] auto CONCAT(unused_val_, __LINE__)
#define RE std::runtime_error("line: " + std::to_string(__LINE__) + ", func: " + __func__)
// clang-format on
