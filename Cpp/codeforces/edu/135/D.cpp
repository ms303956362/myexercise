// IO
#include <iostream>
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] != s[i + 1]) {
                dp[i][i + 1] = 1;
            } else {
                dp[i][i + 1] = 2;
            }
            for (int j = i + 3; j < n; j += 2) {
                // if (dp[i + 1][j - 1] == 1 || (s[i] != s[j] && dp[i + 1][j - 1] == 2) || dp[i + 2][j] == 1 || (s[i] > s[i + 1] && dp[i + 2][j] == 2) 
                //     || dp[i][j - 2] == 1 || (s[j] > s[j - 1] && dp[i][j - 2] == 2)) {
                //     dp[i][j] = 1;
                // } else if (dp[i + 1][j - 1] == 0 && (dp[i + 2][j] == 0 || (s[i] < s[i + 1] && dp[i + 2][j] == 2)) 
                //     && (dp[i][j - 2] == 0 || (s[j] < s[j - 1] && dp[i][j - 2] == 2))) {
                //     dp[i][j] = 0;
                // } else {
                //     dp[i][j] = 2;
                // }
                if (((dp[i + 1][j - 1] == 1 || (s[i] > s[j] && dp[i + 1][j - 1] == 2)) && (dp[i + 2][j] == 1 || (s[i] > s[i + 1] && dp[i + 2][j] == 2))) ||
                    ((dp[i + 1][j - 1] == 1 || (s[i] < s[j] && dp[i + 1][j - 1] == 2)) && (dp[i][j - 2] == 1 || (s[j] > s[j - 1] && dp[i][j - 2] == 2)))) {
                    dp[i][j] = 1;
                } else if ((dp[i + 1][j - 1] == 0 || (s[i] < s[j] && dp[i + 1][j - 1] == 2) || dp[i + 2][j] == 0 || (s[i] < s[j] && dp[i + 2][j] == 2))
                        && (dp[i + 1][j - 1] == 0 || (s[i] > s[j] && dp[i + 1][j - 1] == 2) || dp[i][j - 2] == 0 || (s[i] > s[j] && dp[i][j - 2] == 2))) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 2;
                }
            }
        }
        if (dp[0][n - 1] == 1) {
            cout << "Alice" << endl;
        } else if (dp[0][n - 1] == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
    return 0;
}
