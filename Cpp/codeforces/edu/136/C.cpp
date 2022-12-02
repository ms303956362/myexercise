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
const int N = 70;

long long C[N][N], MOD = 998244353;

void get_C(int maxn)
{
    C[0][0] = 1;
    for(int i=1;i<=maxn;i++)
    {
        C[i][0] = 1;
        for(int j=1;j<=i;j++)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    get_C(65);
    int t;
    cin >> t;
    vector<vector<int>> dp(66, vector<int>(3));
    dp[2][0] = 1;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i = 4; i <= 60; i += 2) {
        dp[i][0] = (C[i - 1][i / 2 - 1] + dp[i - 2][1]) % MOD;
        dp[i][1] = (C[i - 2][i / 2 - 2] + dp[i - 2][0]) % MOD;
        dp[i][2] = dp[i - 2][2];
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl;
    }
    return 0;
}
