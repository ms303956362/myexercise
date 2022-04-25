#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j <= n && j <= (i + a[i]); ++j) {
            if (dp[j] == -1) {
                continue;
            }
            if (dp[i] == -1 || (dp[j] < k && dp[j] < dp[i])) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}
