#pragma once
#include "core/io.hpp"
// clang-format off
#ifdef LOCAL
#define DEBUG(...) debug("[debug] line:", __LINE__, "\t", __VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define EXIT(...) { print(__VA_ARGS__); return; }
// clang-format on
