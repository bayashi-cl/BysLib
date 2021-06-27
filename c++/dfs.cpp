#pragma region template
// clang-format off
// #include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#include <boost/range/irange.hpp>
using boost::irange;

using ll = long long;

const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const int MOD = 1e9 + 7;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>void printvec(vector<T>& v) { for (T i : v) cout << i << " "; cout << endl;}
struct pre_exec {pre_exec() {cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(11); }; } pre_exec_t;
// clang-format on
#pragma endregion

struct DFS {
    vector<vector<int>> graph;
    vector<int> first_order;
    vector<int> last_order;
    DFS(vector<vector<int>> graph, int start) : graph(graph) { search(start); }
    void search(int now, int from = -1) {
        first_order.push_back(now);
        for (int to : graph[now]) {
            if (to == from) continue;
            search(to, now);
        }
        last_order.push_back(now);
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> graph(K);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS d(graph, 0);
    printvec(d.last_order);
    return 0;
}
/*
in
12 13
0 1
0 2
0 3
1 4
1 5
2 6
2 7
6 10
6 11
3 8
3 9
9 12
->
out
4 5 1 10 11 6 7 2 8 12 9 3 0
*/
