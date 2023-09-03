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

int dp[64][2][2][2][11][11][11];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    int a1, a2, a3;
    cin >> n >> a1 >> a2 >> a3;
    memset(dp, -1, 64 * 8 * 11 * 11 * 11 * sizeof(int));
    ll mod = 998244353;
    function<int(int, int, int, int, int, int, int)> dfs = [&](int i, int limit1, int limit2, int limit3, int r1, int r2, int r3) {
        if (dp[i][limit1][limit2][limit3][r1][r2][r3] != -1) {
            return dp[i][limit1][limit2][limit3][r1][r2][r3];
        }
        if (i == 0) {
            if (r1 == 0 && r2 == 0 && r3 == 0) {
                dp[i][limit1][limit2][limit3][r1][r2][r3] = 1;
                return 1;
            }
            return 0;
        }
        int dn = ((n >> (i - 1)) & 1);
        int up1 = limit1 ? dn : 1, up2 = limit2 ? dn : 1, up3 = limit3 ? dn : 1;
        int res = 0;
        for (int d1 = 0; d1 <= up1; ++d1) {
            int t1 = (d1 << (i - 1)) % a1, r11 = ((r1 - t1) % a1 + a1) % a1;
            for (int d2 = 0; d2 <= up2; ++d2) {
                int t2 = (d2 << (i - 1)) % a2, r22 = ((r2 - t2) % a2 + a2) % a2;
                for (int d3 = 0; d3 <= up3; ++d3) {
                    int t3 = (d3 << (i - 1)) % a3, r33 = ((r3 - t3) % a3 + a3) % a3;
                    if (((d1 + d2 + d3) & 1) != 0) {
                        continue;
                    }
                    res = (res + dfs(i - 1, limit1 && d1 == up1, limit2 && d2 == up2, limit3 && d3 == up3, r11, r22, r33)) % mod;
                }
            }
        }
        dp[i][limit1][limit2][limit3][r1][r2][r3] = res;
        return res;
    };
    dfs(62, 1, 1, 1, 0, 0, 0);
    cout << dp[62][1][1][1][0][0][0] << '\n';
    return 0;
}
