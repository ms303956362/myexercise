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
#include <numeric>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        if (s[0] == '?') {
            cout << "0" << '\n';
        } else {
            cout << s << '\n';
        }
        return;
    }
    vector<int> dp1(n), dp2(n);
    auto calc = [](int n, const string &s, vector<int>& dp) {
        bool has0 = true;
        int last1 = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                dp[i] = (last1 == -1 ? 0 : dp[last1]) + has0;
                has0 = false;
                last1 = i;
            } else {
                dp[i] = (last1 == -1 ? 0 : dp[last1]);
                if (s[i] == '0') {
                    has0 = true;
                }
            }
        }
    };
    calc(n, s, dp1);
    string t(s.rbegin(), s.rend());
    for (int i = 0; i < n; ++i) {
        if (t[i] == '1') {
            t[i] = '0';
        } else if (t[i] == '0') {
            t[i] = '1';
        }
    }
    calc(n, t, dp2);
    reverse(dp2.begin(), dp2.end());
    dp2.push_back(0);
    int idx = 0, min_op = dp1[0] + dp2[1];
    for (int i = 0; i < n; ++i) {
        if (dp1[i] + dp2[i + 1] < min_op) {
            min_op = dp1[i] + dp2[i + 1];
            idx = i;
        }
    }
    for (int i = 0; i <= idx; ++i) {
        if (s[i] == '?') {
            s[i] = (i > 0 ? s[i - 1] : '0');
        }
    }
    for (int i = n - 1; i > idx; --i) {
        if (s[i] == '?') {
            s[i] = (i < n - 1 ? s[i + 1] : '1');
        }
    }
    cout << s << '\n';
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
