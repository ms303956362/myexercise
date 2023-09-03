#include "usual.h"

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1), nxt(n + 1, n);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[nxt[nums[i]]] + 1;
            nxt[nums[i]] = i;
        }
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        vector<int> ptr(n + 1);
        for (int i = 0; i <= n; ++i) {
            if (pos[i].size() > 0) {
                ptr[i] = pos[i].size() - 1;
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (pos[nums[i]][ptr[nums[i]]] > i && (pos[nums[i]][ptr[nums[i]]] - i) - (pre[i] - pre[pos[nums[i]][ptr[nums[i]]]]) > k) {
                --ptr[nums[i]];
            }
            // cout << nums[i] << ": " << pos[nums[i]][ptr[nums[i]]] << endl;
            ans = max(ans, pre[i] - pre[pos[nums[i]][ptr[nums[i]]]] + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1};
    int k = 0;
    Solution().longestEqualSubarray(v, k);
    return 0;
}
