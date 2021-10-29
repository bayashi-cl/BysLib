#include "bys.hpp"
#include "geo.hpp"
// #include "linalg.hpp"

using namespace bys;
int main() {
    geo::Vec2d a(0, 0);
    geo::Vec2d b(1, 1);
    geo::Segment s(a, b);
    geo::Segment t(b, a);
    print(s == t);
    // print(s.length());
    return 0;
}
