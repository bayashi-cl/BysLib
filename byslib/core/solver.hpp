#pragma once
#include <unistd.h>

#include <cstddef>
#include <iostream>

#include "alias.hpp"

/**
 * @file solver.hpp
 * @brief Solver
 */
namespace bys {
struct Solver {
    static inline i32 TESTCASE = 1;
    static void solve();
    static i32 main(i32 t = 1) {
        std::ios::sync_with_stdio(false);

        for (; TESTCASE <= t; ++TESTCASE) solve();
#ifdef LOCAL
        if (not std::cin.good()) std::cerr << "🟡 Input failed." << std::endl;
        if (not isatty(STDIN_FILENO) and not std::ws(std::cin).eof())
            std::cerr << "🟡 Unused input." << std::endl;
#endif
        return 0;
    }
};
}  // namespace bys
