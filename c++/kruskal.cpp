#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
// #include <boost/range/irange.hpp>
// using boost::irange;

using ll = long long;
using P = pair<int, int>;
const int INF = (1 << 30) - 1;
const int MOD = 1e9 + 7;
const ll LINF = 1LL << 60;

struct Edge {
    int from;
    int to;
    ll cost;
    Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
    bool operator<(const Edge& right) const { return cost < right.cost; }
};
class Kruskal {
   public:
    atcoder::dsu dsu;
    vector<Edge> graph;
    vector<Edge> mst;
    ll cost;
    Kruskal(int n) : dsu(n), cost(0) {}

    void from_matrix(vector<vector<int>> mat) {
        for (int i = 1; i < mat.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (mat[i][j] != -1) graph.push_back(Edge(i, j, mat[i][j]));
            }
        }
    }
    void add_edge(Edge e) { graph.push_back(e); }
    void add_edge(int from, int to, ll cost) {
        graph.push_back(Edge(from, to, cost));
    }
    ll calc() {
        sort(graph.begin(), graph.end());
        for (Edge e : graph) {
            if (dsu.same(e.from, e.to)) continue;
            dsu.merge(e.from, e.to);
            mst.push_back(e);
            cost += e.cost;
        }
        return cost;
    }
};

int main() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N, vector<int>(N));
    for (auto&& row : adj) {
        for (auto&& i : row) cin >> i;
    }
    Kruskal k(N);
    k.from_matrix(adj);
    ll cost = k.calc();
    cout << cost << endl;
    return 0;
}
