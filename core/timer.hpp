#pragma once
#include <chrono>

namespace bys {
struct Timer {
    std::chrono::time_point<std::chrono::system_clock> end;
    Timer(int ms) {
        end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms);
    }
    inline bool counting() const {
        return std::chrono::system_clock::now() <= end;
    }
};
}  // namespace bys
