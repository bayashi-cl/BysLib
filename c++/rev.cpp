#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#include <boost/range/irange.hpp>
using boost::irange;
#include <boost/range/adaptor/reversed.hpp>
using boost::adaptors::reverse;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {
    vector<int> v = {0, 1, 5, 3, 4};
    // // nomal
    // for (int i = v.size() - 1; i >= 0; i--) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // // irange
    // for (int i : irange((int)v.size() - 1, -1, -1)) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // // for_each
    // for_each(v.rbegin(), v.rend(), [](int i) { cout << i << " "; });
    // cout << endl;

    // // itr
    // for (auto&& i = v.rbegin(); i < v.rend(); i++) {
    //     *i = 3;
    //     cout << *i << " ";
    // }
    // cout << endl;

    // boost
    for (auto&& i : reverse(v)) {
        cout << i << " ";
    }
    cout << endl;

    // // reverse
    // reverse(begin(v), end(v));
    // for (int i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
}
