#include "usual.h"
int pre[10001][26];

class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        // vector<vector<int>> pre(n + 1, vector<int>(26));
        memset(pre, 0, 10001 * 26 * sizeof(int));
        vector<vector<pair<int, int>>> idx(26, vector<pair<int, int>>(26, {n, n}));
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int a = 0; a < 26; ++a) {
                pre[i][a] = pre[i + 1][a];
            }
            ++pre[i][s[i] - 'a'];
            for (int a = 0; a < 26; ++a) {
                for (int b = 0; b < 26; ++b) {
                    auto [j1, j2] = idx[a][b];
                    if (pre[i][a] - pre[j1][a] != 0 && pre[i][b] - pre[j1][b] != 0) {
                        ans = max(ans, pre[i][a] - pre[j1][a] - (pre[i][b] - pre[j1][b]));
                    }
                    if (pre[i][a] - pre[j2][a] != 0 && pre[i][b] - pre[j2][b] != 0) {
                        ans = max(ans, pre[i][a] - pre[j2][a] - (pre[i][b] - pre[j2][b]));
                    }
                    if (pre[i][a] - pre[i][b] < pre[j1][a] - pre[j1][b]) {
                        idx[a][b] = make_pair(i, j1);
                    } else if (pre[i][a] - pre[i][b] < pre[j2][a] - pre[j2][b]) {
                        idx[a][b] = make_pair(j1, i);
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().largestVariance("baaabbbaaaaaab");
    return 0;
}
