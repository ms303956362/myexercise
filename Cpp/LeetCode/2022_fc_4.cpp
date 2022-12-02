#include "usual.h"

class Solution {
public:
    int closeLampInTree(TreeNode* root) {
        auto ans = dfs(root);
        return ans[3];
    }

    vector<int> dfs(TreeNode* p) {
        if (!p) {
            return {0, 0, 0, 0};
        }
        auto dpl = dfs(p->left), dpr = dfs(p->right);
        vector<int> dp(4);
        if (p->val == 1) {
            dp[0] = min({
                1 + dpl[0] + dpr[0],
                3 + dpl[1] + dpr[1],
                1 + dpl[2] + dpr[2],
                1 + dpl[3] + dpr[3]
            });
            dp[1] = min({
                2 + dpl[0] + dpr[0],
                2 + dpl[1] + dpr[1],
                2 + dpl[2] + dpr[2],
                0 + dpl[3] + dpr[3]
            });
            dp[2] = min({
                2 + dpl[0] + dpr[0],
                2 + dpl[1] + dpr[1],
                0 + dpl[2] + dpr[2],
                2 + dpl[3] + dpr[3]
            });
            dp[3] = min({
                3 + dpl[0] + dpr[0],
                1 + dpl[1] + dpr[1],
                1 + dpl[2] + dpr[2],
                1 + dpl[3] + dpr[3]
            });
        } else {
            dp[0] = min({
                2 + dpl[0] + dpr[0],
                2 + dpl[1] + dpr[1],
                0 + dpl[2] + dpr[2],
                2 + dpl[3] + dpr[3]
            });
            dp[1] = min({
                3 + dpl[0] + dpr[0],
                1 + dpl[1] + dpr[1],
                1 + dpl[2] + dpr[2],
                1 + dpl[3] + dpr[3]
            });
            dp[2] = min({
                1 + dpl[0] + dpr[0],
                3 + dpl[1] + dpr[1],
                1 + dpl[2] + dpr[2],
                1 + dpl[3] + dpr[3]
            });
            dp[3] = min({
                2 + dpl[0] + dpr[0],
                2 + dpl[1] + dpr[1],
                2 + dpl[2] + dpr[2],
                0 + dpl[3] + dpr[3]
            });
        }
        return dp;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
