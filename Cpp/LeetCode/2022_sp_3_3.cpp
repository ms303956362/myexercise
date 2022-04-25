#include "usual.h"

class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        vector<int> nums;
        function<void(TreeNode *)> dfs = [&](TreeNode *r) {
            if (!r) {
                return;
            }
            dfs(r->left);
            nums.push_back(r->val);
            dfs(r->right);
        };
        dfs(root);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> p(n + 1);
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
        function<int(int)> find = [&](int i) {
            return p[i] == i ? i : (p[i] = find(p[i]));
        };
        vector<int> color(n);
        reverse(ops.begin(), ops.end());
        for (const auto& op : ops) {
            int l = lower_bound(nums.begin(), nums.end(), op[1]) - nums.begin();
            int r = lower_bound(nums.begin(), nums.end(), op[2]) - nums.begin();
            for(int j = find(l); j <= r; j = find(j)) {
                color[j] = op[0] + 1;
                p[j] = j + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 2) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 4, 5};
    vector<vector<int>> ops{{ 1, 2, 4 }, { 1, 1, 3 }, { 0, 3, 5 }};
    cout << Solution().getNumber(nums, ops) << endl;
    return 0;
}