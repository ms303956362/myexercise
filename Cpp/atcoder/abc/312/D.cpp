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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n + 1));
    if (s[0] == '(' || s[0] == '?') {
        dp[0][1] = 1;
    }
    int mod = 998244353;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (s[i] == '(') {
                if (j > 0) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            } else if (s[i] == ')') {
                if (j < n) {
                    dp[i][j] = dp[i - 1][j + 1];
                }
            } else {
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (j < n) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
    }
    cout << dp[n - 1][0] << '\n';
    return 0;
}
