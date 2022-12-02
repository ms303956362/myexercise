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
int INF = 1e9 + 7;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        s.push_back(s[i]);
    }
    int j = INF, ans = 0;
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (s[i] == 'g') {
            j = i;
        }
        if (s[i] == c) {
            if (j < INF) {
                ans = max(ans, j - i);
            }
        }
    }
    cout << ans << endl;
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
