#pragma once
#include "io.hpp"

namespace bys {
struct Solver {
    int IT = 1;
    Solver() { fastio(); }
    void solve();
    void solve(int rep) {
        for (; IT <= rep; ++IT) solve();
    }
};
}  // namespace bys
