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
template<class T>void printvec(const vector<T>& v) { for (T i : v) cout << i << " "; cout << endl;}

struct pre_exec {pre_exec() {cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(11) << boolalpha; }; } pre_exec_t;
// clang-format on
#pragma endregion

int& lastvec(vector<int>& v, int i = -1) {
    assert(i < 0);
    return *(v.end() + i);
}

int main() {
    vector<int> vec = {3, 1, 4, 1, 5};
    auto&& b = lastvec(vec, -3);
    b = 7;
    printvec(vec);
}
