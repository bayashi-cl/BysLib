#define PROBLEM "https://yukicoder.me/problems/no/117"

#include "../../math/combination.hpp"

#include "../../core/core.hpp"
#include "../../utility/range.hpp"

namespace bys {
std::tuple<char, int, int> parse(string s) {
    s.pop_back();
    std::replace(s.begin(), s.end(), ',', ' ');
    std::stringstream ss{s.substr(2)};
    int n, r;
    ss >> n >> r;
    return {s[0], n, r};
}

void Solver::solve() {
    auto t = scanner.read<int>();
    int MAX = 2'000'002;
    MultiComb mc(MAX, MOD7);
    for (UV : irange(t)) {
        auto [c, n, k] = parse(scanner.read<string>());
        if (c == 'C') {
            print(mc.comb(n, k));
        } else if (c == 'P') {
            print(mc.perm(n, k));
        } else if (c == 'H') {
            print(mc.hom(n, k));
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
