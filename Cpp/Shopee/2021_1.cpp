#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> premax(n, vector<int>(2)), dp(n + 1, vector<int>(2));
    vector<int> sum(n);
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < m; ++j) {
            s += a[i][j];
            premax[i][0] = max(premax[i][0], s);
        }
        s = 0;
        for (int j = m - 1; j >= 0; --j) {
            s += a[i][j];
            premax[i][1] = max(premax[i][1], s);
        }
        sum[i] = s;
    }
    for (int i = n - 1; i >= 0; --i) {
        dp[i][0] = max(dp[i + 1][0] + premax[i][0], sum[i] + dp[i + 1][1]);
        dp[i][1] = max(dp[i + 1][1] + premax[i][1], sum[i] + dp[i + 1][0]);
    }
    cout << dp[0][0] << endl;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++t) {
        solve();
    }
    return 0;
}
