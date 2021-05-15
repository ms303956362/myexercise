#include "usual.h"

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<vector<int>> cnt(n + 1, vector<int>(128, 0));
        for (int i = 1; i <= n; ++i) {
            for (int c = 'a'; c <= 'z'; ++c)
                cnt[i][c] = cnt[i - 1][c];
            ++cnt[i][s[i - 1]];
        }
        int ans = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = i + 1; j != n + 1; ++j) {
                int max_cnt = 0, min_cnt = INT_MAX;
                for (int c = 'a'; c <= 'z'; ++c) {
                    if (cnt[j][c] <= cnt[i][c])
                        continue;
                    max_cnt = max(max_cnt, cnt[j][c] - cnt[i][c]);
                    min_cnt = min(min_cnt, cnt[j][c] - cnt[i][c]);
                }
                if (max_cnt > min_cnt)
                    ans += max_cnt - min_cnt;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("aabcb");
    cout << Solution().beautySum(s) << endl;
    return 0;
}
