#include "usual.h"

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        for (int i = 0; i < n; ++i) {
            if (lcp[i][i] != n - i) {
                return "";
            }
            for (int j = i + 1; j < n; ++j) {
                if (lcp[i][j] != lcp[j][i]) {
                    return "";
                }
                if (lcp[i][j] > n - i || lcp[i][j] > n - j) {
                    return "";
                }
            }
        }
        char c = 'a';
        string ans(n, 'A');
        for (int i = 0; i < n; ++i) {
            if (ans[i] != 'A') {
                continue;
            }
            if (c > 'z') {
                return "";
            }
            ans[i] = c;
            for (int j = i + 1; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    if (ans[j] != 'A') {
                        return "";
                    }
                    ans[j] = c;
                }
            }
            ++c;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (ans[i] == ans[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
            }
        }
        dp.pop_back();
        for (int i = n - 1; i >= 0; --i) {
            dp[i].pop_back();
        }
        return dp == lcp ? ans : "";
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
