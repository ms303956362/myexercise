#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int pos = s.find(',');
    string s1(s.begin(), s.begin() + pos), s2(s.begin() + pos + 1, s.end());
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n2; ++i) {
        dp[0][i] = i;
    }
    for (int i1 = 1; i1 <= n1; ++i1) {
        for (int i2 = 1; i2 <= n2; ++i2) {
            int d = (s1[i1 - 1] == s2[i2 - 1] ? 0 : 1);
            dp[i1][i2] = min({dp[i1 - 1][i2 - 1] + d, dp[i1 - 1][i2] + 1, dp[i1][i2 - 1] + 1});
        }
    }
    cout << dp[n1][n2] << endl;
    return 0;
}

/*
Traceback (most recent call last):
  File "Solution.py", line 1, in <module>
    s1,s2=map(str,input().split(','))
EOFError: EOF when reading a line

*/