#pragma once
#include <vector>

#include "point.hpp"
/**
 * @file polygon.hpp
 * @brief Polygon
 */
namespace bys::geo {
//! @brief 多角形
template <class T>
struct Polygon {
    int n_vertex;
    std::vector<Point<T>> vertex;
    Polygon(std::initializer_list<Point<T>> init) : n_vertex(init.size()), vertex(init.begin(), init.end()) {}
    Polygon(std::vector<Point<T>> vertex) : n_vertex(vertex.size()), vertex(vertex) {}
    //! @brief 面積*2
    T area2() const {
        if (n_vertex < 3) return 0;
        f128 s = 0.0;
        for (int i = 0; i < n_vertex; ++i) {
            s += vertex[i].det(vertex[(i + 1) % n_vertex]);
        }
        return s;
    };
    //! @brief 面積
    f128 area() const { return area2() * 0.5; }
    //! @brief 凸判定
    bool is_convex() const {
        int left = 0;
        int right = 0;
        for (int i = 0; i < n_vertex; ++i) {
            auto res = iSP(vertex[i], vertex[(i + 1) % n_vertex], vertex[(i + 2) % n_vertex]);
            if (res == Turn::CW) left++;
            if (res == Turn::CCW) right++;
        }
        return left == 0 || right == 0;
    }
};
}  // namespace bys::geo
