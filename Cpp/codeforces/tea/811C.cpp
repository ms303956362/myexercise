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

// using ll = long long;

int a[5005], l[5005], r[5005], dp[5005], vst[5005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (l[a[i]] == 0) {
            l[a[i]] = i;
        }
        r[a[i]] = i;
    }
    // memset(vst, n, sizeof(int) * 5005);
    // for (int i = n - 1; i >= 0; --i) {
    //     dp[i] = dp[i + 1];
    //     int val = 0, end = i;
    //     for (int j = i; j < n; ++j) {
    //         if (vst[a[j]] > i) {
    //             if (l[a[j]] < j) {
    //                 break;
    //             }
    //             vst[a[j]] = i;
    //             val ^= a[j];
    //             end = max(end, r[a[j]]);
    //         }
    //         if (j == end) {
    //             dp[i] = max(dp[i], dp[j + 1] + val);
    //         }
    //     }
    // }
    // cout << dp[0] << endl;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int j = i, ll = l[a[i]], val = 0; j > 0; --j) {
            int v = a[j];
            if (vst[v] < i) {
                if (r[v] > j) {
                    break;
                }
                vst[v] = i;
                ll = min(ll, l[v]);
                val ^= v;
            }
            if (ll == j) {
                dp[i] = max(dp[i], dp[j - 1] + val);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
