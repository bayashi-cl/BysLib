#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../core/core.hpp"
#include "../../data/binary_indexed_tree.hpp"

using namespace bys;
int main() {
    const int N = 10;
    vector<int> v(N);
    std::iota(v.begin(), v.end(), 0);
    BinaryIndexedTree bit(v);
    for (int i = 0; i < N; ++i) assert(bit.get(i) == i);

    print("Hello World");
    return 0;
}
