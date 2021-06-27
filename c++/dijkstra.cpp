#pragma region template
#include <atcoder/math>
#include <atcoder/modint>
#include <boost/range/irange.hpp>
// #include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

namespace mine {
using atcoder::pow_mod, atcoder::inv_mod;
using boost::irange;
using std::cin, std::cout, std::endl;
using std::min, std::max, std::sort, std::abs, std::pow;
using std::vector, std::string, std::set, std::map;
using mint = atcoder::modint1000000007;
using ll = long long int;
using Pa = std::pair<int, int>;
using Vec = std::vector<int>;
using VecVec = std::vector<std::vector<int>>;
constexpr int MOD = 1000000007;
constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr ll LINF = std::numeric_limits<ll>::max() / 2;
// clang-format off
template <class T> inline bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, const T& b) {if (b < a) {a = b; return 1;} return 0;}
template <class T> std::istream& operator>>(std::istream& is, vector<T>& vec) {for (auto&& v : vec) is >> v; return is;}
template <class T> std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {for (std::size_t i = 0; i < vec.size(); i++) {if (i) os << " "; os << vec[i];} return os;}
template <class T> std::istream& operator>>(std::istream& is, std::valarray<T>& arr) {for (auto&& a : arr) is >> a; return is;}
template <class T> std::ostream& operator<<(std::ostream& os, const std::valarray<T>& arr) {for (std::size_t i = 0; i < arr.size(); i++) {if (i) os << " "; os << arr[i];} return os;}
template <class S, class T> std::istream& operator>>(std::istream& is, std::pair<S, T>& p) {is >> p.first >> p.second; return is;}
template <class S, class T> std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) {os << p.first << " " << p.second; return os;}
template <class Tail> void print(Tail&& tail) {cout << tail << "\n";}
template <class Head, class... Body> void print(Head&& head, Body&&... tail) {cout << head << " "; print(std::forward<Body>(tail)...);}
template <class Tail> void debug(Tail&& tail) {std::clog << tail << endl;}
template <class Head, class... Body> void debug(Head&& head, Body&&... tail) {std::clog << head << " "; print(std::forward<Body>(tail)...);}
inline void init() {cin.tie(nullptr); std::ios::sync_with_stdio(false); cout << std::fixed << std::setprecision(11) << std::boolalpha;}
// clang-format on
#pragma endregion

/**
 * @brief ダイクストラ法による最短経路探索
 * 構築後にDijkstra.search()を実行する
 * O(|E| log|N|)
 * @param graph 隣接グラフ
 */
template <class T>
struct Dijkstra {
    using Edge = std::pair<T, int>;  // (cost, node)
    using Adj = vector<vector<Edge>>;
    Adj graph;
    vector<T> cost;
    vector<int> prev;
    int n_node;

    Dijkstra(const Adj& graph) : graph(graph) {
        n_node = graph.size();
        cost.resize(n_node, LINF);
        prev.resize(n_node, -1);
    }

    /**
     * @brief 探索
     * コストはself.costに格納される。
     * @param start 探索開始点
     */
    void search(int start) {
        std::priority_queue<Edge, vector<Edge>, std::greater<Edge>> que;
        cost[start] = 0;
        que.push(Edge(0, start));

        while (!que.empty()) {
            auto [top_cost, top_node] = que.top();
            que.pop();
            if (cost[top_node] < top_cost) continue;
            for (auto [adj_cost, adj_node] : graph[top_node]) {
                T temp_cost = cost[top_node] + adj_cost;
                if (temp_cost < cost[adj_node]) {
                    cost[adj_node] = temp_cost;
                    prev[adj_node] = top_node;
                    que.push(Edge(temp_cost, adj_node));
                }
            }
        }
    }

    /**
     * @brief 経路復元
     * @param to
     * @return vector<int>
     */
    vector<int> path_finder(int to) {
        assert(to <= n_node);
        vector<int> path;
        while (to != -1) {
            path.push_back(to);
            to = prev[to];
        }
        std::reverse(std::begin(path), std::end(path));
        return path;
    }

    T get_cost(int i) {
        T res = cost[i];
        if (res == LINF) res = -1;
        return res;
    }
};

void main() {
    // https://judge.yosupo.jp/problem/shortest_path
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Dijkstra<ll>::Adj adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(Dijkstra<ll>::Edge(c, b));
    }
    auto dij = Dijkstra(adj);
    dij.search(s);
    ll cost = dij.get_cost(t);
    if (cost == -1) {
        print(-1);
        return;
    }
    auto path = dij.path_finder(t);
    print(cost, path.size() - 1);
    for (int i = 0; i < (int)path.size() - 1; ++i) print(path[i], path[i + 1]);
}

}  // namespace mine

int main() {
    mine::init();
    mine::main();
    std::cout << std::flush;
    return 0;
}
