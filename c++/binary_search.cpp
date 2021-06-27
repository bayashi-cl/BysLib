#pragma region template
#include <atcoder/modint>
#include <boost/range/irange.hpp>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iomanip>
#include <iostream>
// #include <iterator>
#include <limits>
// #include <map>
// #include <numeric>
// #include <queue>
// #include <set>
// #include <stack>
#include <string>
#include <valarray>
#include <vector>

namespace mine {
using std::cin, std::cout, std::endl, std::vector, std::string, boost::irange;
using ll = long long int;
using mint = atcoder::modint1000000007;
using Vec = std::vector<int>;
using VecVec = std::vector<std::vector<int>>;
using Pa = std::pair<int, int>;
constexpr int MOD = 1'000'000'007;
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
inline void init() {cin.tie(nullptr); std::ios::sync_with_stdio(false); cout << std::fixed << std::setprecision(11) << std::boolalpha;}
// clang-format on
#pragma endregion

/**
 * @brief 二分探索法
 * https://atcoder.jp/contests/abc205/submissions/23500985
 * @tparam T 初期値と返り値、is_okの第一引数 int or long long intを想定
 * @param ok (T): is_okを満たす初期値
 * @param ng (T): is_okを満たさない初期値
 * @param is_ok (bool()): 判定用ラムダ式
 * @param args... (Args...): is_okに渡される引数 可変長
 * @return (T): is_okを満たす最大/小の整数
 */
template <typename T, class Lambda, class... Args>
T meguru_bisect(T ok, T ng, Lambda is_ok, Args... args) {
    assert(is_ok(ok, args...));
    assert(!is_ok(ng, args...));

    while (std::abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        if (is_ok(mid, args...)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

void main() {}

}  // namespace mine

int main() {
    mine::init();
    mine::main();
    std::cout << std::flush;
    return 0;
}
