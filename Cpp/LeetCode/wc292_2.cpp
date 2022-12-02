#include "usual.h"

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        function<pair<int, int>(TreeNode *)> dfs = [&](TreeNode *p)
        {
            if (!p) {
                return make_pair(0, 0);
            }
            auto [lsum, ln] = dfs(p->left);
            auto [rsum, rn] = dfs(p->right);
            int avg = (lsum + rsum + p->val) / (ln + rn + 1);
            if (avg == p->val) {
                ++ans;
            }
            return make_pair(lsum + rsum + p->val, ln + rn + 1);
        };
        dfs(root);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
