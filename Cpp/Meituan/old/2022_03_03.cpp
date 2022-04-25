#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(2));
    function<void(long long, long long)> dfs = [&](int u, int f)
    {
        dp[u][0].second = 1e9 + 5;
        dp[u][1].first = a[u];
        dp[u][1].second = a[u];
        for (const auto& v : g[u])
        {
            if (v == f)
                continue;
            dfs(v, u);
            // dp[u][0]
            if (dp[v][0].first > dp[v][1].first)
            {
                dp[u][0].first += dp[v][0].first;
                dp[u][0].second = min(dp[u][0].second, dp[v][0].second);
            }
            else if (dp[v][0].first < dp[v][1].first)
            {
                dp[u][0].first += dp[v][1].first;
                dp[u][0].second = min(dp[u][0].second, dp[v][1].second);
            }
            else
            {
                dp[u][0].first += dp[v][0].first;
                dp[u][0].second = min(dp[u][0].second, max(dp[v][0].second, dp[v][1].second));
            }
            // dp[u][1]
            dp[u][1].first += dp[v][0].first;
            dp[u][1].second = min(dp[u][1].second, dp[v][0].second);
        }
        if (dp[u][0].second >= 1e9 + 5) {
            dp[u][0].second = 0;
        }
    };
    dfs(0, -1);
    if (dp[0][0].first > dp[0][1].first) {
        cout << dp[0][0].first << " " << dp[0][0].second << endl;
    } else if (dp[0][0].first < dp[0][1].first) {
        cout << dp[0][1].first << " " << dp[0][1].second << endl;
    } else {
        cout << dp[0][0].first << " " << max(dp[0][0].second, dp[0][1].second) << endl;
    }
    return 0;
}
