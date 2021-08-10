// #include "geometry.hpp"
#include "geometry.hpp"

using namespace bys;

int main() {
    init();
    geo::Point a(3, 4);
    geo::Point b(2, 1);
    print(geo::len(a));
}
