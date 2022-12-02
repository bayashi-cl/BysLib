#pragma once
#include <cstdint>
namespace bys {
using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using i128 = __int128_t;
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using u128 = __uint128_t;
using f32 = float;
using f64 = double;
using f128 = long double;

using isize = std::ptrdiff_t;
using usize = std::size_t;

#define DEFINE_NUM_LITERAL(name, type) \
    constexpr auto operator"" name(unsigned long long x) { return static_cast<type>(x); }

DEFINE_NUM_LITERAL(_i8, std::int8_t);
DEFINE_NUM_LITERAL(_i16, std::int16_t);
DEFINE_NUM_LITERAL(_i32, std::int32_t);
DEFINE_NUM_LITERAL(_i64, std::int64_t);
DEFINE_NUM_LITERAL(_i128, __int128_t);
DEFINE_NUM_LITERAL(_u8, std::uint8_t);
DEFINE_NUM_LITERAL(_u16, std::uint16_t);
DEFINE_NUM_LITERAL(_u32, std::uint32_t);
DEFINE_NUM_LITERAL(_u64, std::uint64_t);
DEFINE_NUM_LITERAL(_u128, __uint128_t);
DEFINE_NUM_LITERAL(_z, std::size_t);
#undef DEFINE_NUM_LITERAL
}  // namespace bys
