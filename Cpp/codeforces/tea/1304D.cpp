// IO
#include <iostream>
#include <iomanip>      // std::setprecision
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v1, v2;
    for (int i = n; i > 0; --i) {
        v1.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        v2.push_back(i);
    }
    int i = 0;
    while (i < n - 1) {
        int j = i;
        while (j < n - 1 && s[j] == '<') {
            ++j;
        }
        reverse(v1.begin() + i, v1.begin() + j + 1);
        i = j + 1;
    }
    i = 0;
    while (i < n - 1) {
        int j = i;
        while (j < n - 1 && s[j] == '>') {
            ++j;
        }
        reverse(v2.begin() + i, v2.begin() + j + 1);
        i = j + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << v1[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        cout << v2[i] << ' ';
    }
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
