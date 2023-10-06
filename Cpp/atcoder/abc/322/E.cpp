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

ll dp[101][6][6][6][6][6], a[101][6], c[101];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, 0x3f3f3f3f, sizeof(ll) * 101 * 6 * 6 * 6 * 6 * 6);
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }
    function<void(int, int, vector<int>&)> dfs = [&](int i, int l, vector<int>& cnt) {
        if (l == 5) {
            vector<int> s(5), t(5);
            s = cnt;
            bool neg = false;
            for (int j = 0; j < k; ++j) {
                t[j] -= a[i][j];
                if (t[j] < 0) {
                    neg = true;
                }
            }
            if (neg) {
                dp[i][s[0]][s[1]][s[2]][s[3]][s[4]] = dp[i + 1][s[0]][s[1]][s[2]][s[3]][s[4]];
            } else {
                dp[i][s[0]][s[1]][s[2]][s[3]][s[4]] = min(dp[i + 1][s[0]][s[1]][s[2]][s[3]][s[4]], dp[i + 1][t[0]][t[1]][t[2]][t[3]][t[4]] + c[i]);
            }
            return;
        }
        if (l < n) {
            for (int j = 0; j <= p; ++j) {
                cnt[l] = j;
                dfs(i, l + 1, cnt);
            }
        } else {
            dfs(i, l + 1, cnt);
        }
    };
    memset(dp[n], 0, sizeof(ll) * 6 * 6 * 6 * 6 * 6);
    for (int i = n - 1; i >= 0; --i) {
        vector<int> cnt(5);
        dfs(i, 0, cnt);
    }
    return 0;
}
