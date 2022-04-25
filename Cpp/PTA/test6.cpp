#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sum = 0;
    for (const auto& num : a) {
        sum += num;
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    vector<int> curr1, curr2, a1, a2;
    int min_diff = sum + 1, s1 = 0, s2 = 0;
    function<void(int, int)> dfs = [&](int i, int s) {
        if (dp[i][s] != -1) {
            return;
        }
        if (i == n) {
            int t = sum - s;
            if (abs(t - s) < min_diff) {
                min_diff = abs(t - s);
                a1 = curr1;
                a2 = curr2;
                s1 = s;
                s2 = t;
            }
            dp[i][s] = abs(t - s);
            return;
        }
        curr1.push_back(a[i]);
        dfs(i + 1, s + a[i]);
        curr1.pop_back();
        curr2.push_back(a[i]);
        dfs(i + 1, s);
        curr2.pop_back();
        dp[i][s] = min(dp[i + 1][s + a[i]], dp[i + 1][s]);
    };
    dfs(0, 0);
    cout << s1 << endl;
    for (const auto& num : a1) {
        cout << num << " ";
    }
    cout << endl;
    cout << s2 << endl;
    for (const auto& num : a2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
