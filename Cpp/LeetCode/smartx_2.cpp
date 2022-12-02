#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solve(const string& s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
        }
    }
    int max_len = 0;
    string ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int len = min(dp[i][j], j - i);
            if (len > max_len) {
                max_len = len;
                ans = s.substr(i, len);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
