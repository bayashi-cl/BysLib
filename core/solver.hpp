#pragma once
#include "stdlib.hpp"
/**
 * @file solver.hpp
 * @brief Solver
 */
namespace bys {
struct Solver {
    static inline int TESTCASE = 1;
    static void solve();
    static int main(int t = 1) {
        std::ios::sync_with_stdio(false);

        for (; TESTCASE <= t; ++TESTCASE) solve();

        if (not std::cin.good()) std::cerr << "🟡 Input failed." << std::endl;
        if (not std::ws(std::cin).eof()) std::cerr << "🟡 Unused input." << std::endl;
        return 0;
    }
};
}  // namespace bys
