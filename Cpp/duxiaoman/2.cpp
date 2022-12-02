#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// void solve() {
//     int n, m, k, x;
//     cin >> n >> m >> k >> x;
//     vector<vector<int>> a(n, vector<int>(m));
//     vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(305)));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> a[i][j];
//         }
//     }
//     dp[n - 1][m - 1][a[n - 1][m - 1] + 140] = true;
//     for (int i = n - 1; i >= 0; --i) {
//         for (int j = m - 1; j >= 0; --j) {
//             if (j + 1 < m) {
//                 for (int s = 0; s < 300; ++s) {
//                     if (0 <= s + a[i][j] && s + a[i][j] < 300 && dp[i][j + 1][s + a[i][j]]) {
//                         dp[i][j][s] = true;
//                     }
//                 }
//             }
//             if (i + 1 < n) {
//                 for (int s = 0; s < 300; ++s) {
//                     if (0 <= s + a[i][j] && s + a[i][j] < 300 && dp[i + 1][j][s + a[i][j]]) {
//                         dp[i][j][s] = true;
//                     }
//                 }
//             }
//         }
//     }
//     if (dp[0][0][x + 140]) {
//         cout << "yes" << endl;
//     } else {
//         cout << "no" << endl;
//     }
// }

void solve() {
    int m, n, k, x;
    cin >> m >> n >> k >> x;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
    dp[m - 1][n - 1].insert(a[m - 1][n - 1]);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (j + 1 < n) {
                for (const auto& s : dp[i][j + 1]) {
                    dp[i][j].insert(s + a[i][j]);
                }
            }
            if (i + 1 < m) {
                for (const auto& s : dp[i + 1][j]) {
                    dp[i][j].insert(s + a[i][j]);
                }
            }
        }
    }
    if (dp[0][0].count(x)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
