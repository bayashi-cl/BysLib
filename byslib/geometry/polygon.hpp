#pragma once
#include "byslib/geometry/point.hpp"

namespace bys::geo {
template <class T>
struct Polygon {
    int n_vertex;
    std::vector<Point<T>> vertex;
    Polygon(std::initializer_list<Point<T>> init)
        : n_vertex(init.size()), vertex(init.begin(), init.end()) {}
    Polygon(std::vector<Point<T>> vertex)
        : n_vertex(vertex.size()), vertex(vertex) {}
    T area2() const {
        if (n_vertex < 3) return 0;
        ld s = 0.0;
        for (int i = 0; i < n_vertex; ++i) {
            s += vertex[i].det(vertex[(i + 1) % n_vertex]);
        }
        return s * 0.5;
    };
    ld area() const { return area2() * 0.5; }
    bool is_convex() const {
        int left = 0;
        int right = 0;
        for (int i = 0; i < n_vertex; ++i) {
            int res = iSP(vertex[i], vertex[(i + 1) % n_vertex],
                          vertex[(i + 2) % n_vertex]);
            if (res == -1) left++;
            if (res == 1) right++;
        }
        return left == 0 || right == 0;
    }
};
}  // namespace bys::geo
