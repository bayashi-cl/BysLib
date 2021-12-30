#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../core/core.hpp"
#include "../utility/range.hpp"

namespace bys {
vector<int> range2vec(int stop) {
    vector<int> res;
    for (auto&& i : Range(stop)) res.push_back(i);
    return res;
}
vector<int> range2vec(int start, int stop) {
    vector<int> res;
    for (auto&& i : Range(start, stop)) res.push_back(i);
    return res;
}
vector<int> range2vec(int start, int stop, int step) {
    vector<int> res;
    for (auto&& i : Range(start, stop, step)) res.push_back(i);
    return res;
}
vector<int> range2vec_rev(int stop) {
    vector<int> res;
    for (auto&& i : reversed(Range(stop))) res.push_back(i);
    return res;
}
vector<int> range2vec_rev(int start, int stop) {
    vector<int> res;
    for (auto&& i : reversed(Range(start, stop))) res.push_back(i);
    return res;
}
vector<int> range2vec_rev(int start, int stop, int step) {
    vector<int> res;
    for (auto&& i : reversed(Range(start, stop, step))) res.push_back(i);
    return res;
}
void Solver::solve() {
    vector<int> v5 = {0, 1, 2, 3, 4};
    assert(range2vec(5) == v5);
    vector<int> ve;
    assert(range2vec(-1) == ve);
    vector<int> v35 = {3, 4};
    assert(range2vec(3, 5) == v35);
    vector<int> v_22 = {-2, -1, 0, 1};
    assert(range2vec(-2, 2) == v_22);
    vector<int> v282 = {2, 4, 6};
    assert(range2vec(2, 8, 2) == v282);

    vector<int> vr5 = {4, 3, 2, 1, 0};
    assert(range2vec_rev(5) == vr5);
    vector<int> vre;
    assert(range2vec_rev(-1) == vre);
    vector<int> vr35 = {4, 3};
    assert(range2vec_rev(3, 5) == vr35);
    vector<int> vr_22 = {1, 0, -1, -2};
    assert(range2vec_rev(-2, 2) == vr_22);
    vector<int> vr282 = {6, 4, 2};
    assert(range2vec_rev(2, 8, 2) == vr282);
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve();
    return 0;
}
