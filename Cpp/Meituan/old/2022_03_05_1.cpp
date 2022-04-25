#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        s.insert(num);
    }
    vector<int> a(s.begin(), s.end());
    int m = a.size();
    vector<vector<int>> dp(m + 1, vector<int>(2));
    int ans = 0;
    for (int i = m - 1; i >= 0; --i) {
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
        if (i == m - 1 || a[i] + 1 != a[i + 1]) {
            dp[i][1] = dp[i][0] + 1;
        } else {
            dp[i][1] = dp[i + 1][0] + 1;
        }
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans << endl;
    return 0;
}
