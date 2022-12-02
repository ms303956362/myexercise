#include <iostream>

using namespace std;

int mod = 1e9 + 7;
int dp[100002][9][9];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 9 << endl;
        return 0;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            dp[2][i][j] = 1;
        }
    }
    dp[2][0][0] = 0;
    for (int l = 3; l <= n; ++l) {
        for (int i = 0; i < 9; ++i) {
            int j = 0;
            if (i == 0) {
                j = 1;
            }
            for (; j < 9; ++j) {
                int k = 0;
                if (i == 0) {
                    k = 1;
                }
                for (; k < 9; ++k) {
                    dp[l][i][j] = (dp[l][i][j] + dp[l - 1][j][k]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ans = (ans + dp[n][i][j]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
