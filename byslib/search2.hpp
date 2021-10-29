#pragma once

#include "bys.hpp"

namespace bys {
struct BreadthFirstSearch {
    using MakeAdjFunc = std::function<vector<int>(int)>;
    using ManpFunc = std::function<void(int, int, map<int, int>&)>;

    map<int, int> result;
    MakeAdjFunc make_adj;
    ManpFunc manip;
    int err_val = -1;

    BreadthFirstSearch(vector<pair<int, int>> init, MakeAdjFunc adj,
                       ManpFunc mani)
        : make_adj(adj), manip(mani) {
        std::queue<int> que;
        for (auto& [node, val] : init) {
            que.push(node);
            result[node] = val;
        }
        while (!que.empty()) {
            int top = que.front();
            que.pop();
            for (auto&& nx : make_adj(top)) {
                if (result.find(nx) != result.end()) continue;
                manip(nx, top, result);
                que.push(nx);
            }
        }
    }
    int get_result(int x) {
        if (result.find(x) == result.end()) {
            return err_val;
        } else {
            return result[x];
        }
    }
};
}  // namespace bys
