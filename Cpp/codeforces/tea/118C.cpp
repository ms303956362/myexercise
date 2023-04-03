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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(10);
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - '0'];
        if (cnt[s[i] - '0'] >= k) {
            ok = true;
        }
    }
    if (ok) {
        cout << 0 << '\n' << s << '\n';
        return;
    }
    int min_cost = INT_MAX;
    string ans(n, '9');
    for (char c = '0'; c <= '9'; ++c) {
        string t = s;
        int cntc = cnt[c - '0'], cost = 0;
        for (char d = 1; d <= max('9' - c, c - '0') && cntc < k; ++d) {
            for (int i = 0; i < n && c + d <= '9' && cntc < k; ++i) {
                if (c + d >= '0' && t[i] == c + d) {
                    t[i] = c;
                    ++cntc;
                    cost += d;
                }
            }
            for (int i = n - 1; i >= 0 && c - d >= '0' && cntc < k; --i) {
                if (c - d <= '9' && t[i] == c - d) {
                    t[i] = c;
                    ++cntc;
                    cost += d;
                }
            }
        }
        if (cost < min_cost) {
            min_cost = cost;
            ans = t;
        } else if (cost == min_cost && t < ans) {
            ans = t;
        }
    }
    cout << min_cost << '\n' << ans << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
