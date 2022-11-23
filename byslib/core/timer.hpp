#pragma once
#include <chrono>

#include "alias.hpp"
/**
 * @file timer.hpp
 * @brief Timer
 */
namespace bys {
struct Timer {
    std::chrono::time_point<std::chrono::system_clock> end;
    Timer(i32 ms) { end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms); }
    inline bool counting() const { return std::chrono::system_clock::now() <= end; }
};
}  // namespace bys
