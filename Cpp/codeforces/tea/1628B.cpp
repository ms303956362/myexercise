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
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    auto check = [](const string& s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    };
    vector<int> has2(26);
    vector<vector<int>> has3(26, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        if (check(v[i])) {
            cout << "YES" << '\n';
            return;
        }
        if (v[i].size() == 2) {
            int x = v[i][0] - 'a', y = v[i][1] - 'a';
            if ((has2[y] & (1 << x)) || has3[y][x] > 0) {
                cout << "YES" << '\n';
                return;
            }
            has2[x] |= (1 << y);
        } else {
            int x = v[i][0] - 'a', y = v[i][1] - 'a', z = v[i][2] - 'a';
            if ((has2[z] & (1 << y)) || (has3[z][y] & (1 << x))) {
                cout << "YES" << '\n';
                return;
            }
            has3[x][y] |= (1 << z);
        }
    }
    cout << "NO" << '\n';
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
