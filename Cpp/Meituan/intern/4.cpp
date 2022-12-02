#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> bombs(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> bombs[i];
        --bombs[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n));
    dp[m][bombs[m]] = 0x3f3f3f3f;
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0x3f3f3f3f;
            for (int k = 0; k < n; ++k) {
                if (k == bombs[i + 1])
                    continue;
                dp[i][j] = min(dp[i][j], dp[i + 1][k] + (j != k));
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
