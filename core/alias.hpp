#pragma once
#include <cstdint>
namespace bys {
// numpy style number types
using i1 = std::int8_t;
using i2 = std::int16_t;
using i4 = std::int32_t;
using i8 = std::int64_t;
using i16 = __int128_t;
using u1 = std::uint8_t;
using u2 = std::uint16_t;
using u4 = std::uint32_t;
using u8 = std::uint64_t;
using u16 = __uint128_t;
using f4 = float;
using f8 = double;
using f16 = long double;
}  // namespace bys
