#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<char, char>> combination(const string& vec) {
    vector<pair<char, char>> res;
    int len = (int)vec.size();
    assert(len > 1);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            pair<char, char> p = {vec[i], vec[j]};
            res.push_back(p);
        }
    }
    return res;
}

template <class T>
vector<pair<T, T>> combination(const vector<T>& vec) {
    vector<pair<T, T>> res;
    int len = (int)vec.size();
    assert(len > 1);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            pair<T, T> p = {vec[i], vec[j]};
            res.push_back(p);
        }
    }
    return res;
}

template <class T>
void print_pair(const pair<T, T>& p) {
    cout << p.first << " " << p.second << endl;
}

int main() {
    vector<int> v = {3, 1, 4, 1, 5};
    for (auto&& p : combination(v)) {
        print_pair(p);
    }
    string s = "3i415";
    for (auto&& p : combination(s)) {
        print_pair(p);
    }

    return 0;
}
