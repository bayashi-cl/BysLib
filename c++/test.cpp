#include "bys.hpp"
#include "geo.hpp"

using namespace bys;
void solve() {
    using V = geo::Vec2d;
    V a(0, 0);
    V b(3, 0);
    V c(5, 2);
    V d(2, 2);

    geo::Polygon tri = {a, b, c, d};
    print(tri.area());
}

int main() {
    bys::init();
    solve();
    return 0;
}
