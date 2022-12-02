#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
        if (i < n - 1 && (s[i] == s[i + 1] + 1 || s[i] == s[i + 1] - 1 || s[i] == s[i + 1])) {
            dp[i][1] = dp[i + 1][0] + (s[i] - 'a' + 1) + (s[i + 1] - 'a' + 1);
        }
    }
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}
