#include "usual.h"

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), nums(n);
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            nums[i] = fruits[i][1];
        }
        int j = lower_bound(pos.begin(), pos.end(), startPos) - pos.begin();
        int i = upper_bound(pos.begin(), pos.end(), startPos) - pos.begin() - 1;
        int ans = 0, cnt = 0;
        function<void(int, int, int, int, int)> dfs = [&](int x, int idx, int t, int l, int u)
        {
            if (t < 0)
            {
                ans = max(ans, cnt);
                return;
            }
            if (idx != -1)
                cnt += nums[idx];
            if (0 <= l && l < n)
                dfs(pos[l], l, t - (x - pos[l]), l - 1, u);
            if (0 <= u && u < n)
                dfs(pos[u], u, t - (pos[u] - x), l, u + 1);
            if (idx != -1)
                cnt -= nums[idx];
        };
        if (i == j) {
            cnt += nums[i];
            --i;
            ++j;
        } else {
            if (0 <= i && i < n && pos[i] == startPos) {
                cnt += nums[i];
                --i;
            } else if (0 <= j && j < n && pos[j] == startPos) {
                cnt += nums[j];
                ++j;
            }
        }
        ans = max(ans, cnt);
        dfs(startPos, -1, k, i, j);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> a{{200000,10000}};
    cout << Solution().maxTotalFruits(a, 0, 200000) << endl;
    return 0;
}
