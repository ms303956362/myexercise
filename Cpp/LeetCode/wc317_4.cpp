#include "usual.h"

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> res;
        function<int(TreeNode*, int)> dfs = [&](TreeNode* p, int depth) {
            if (!p) {
                return 0;
            }
            int lh = dfs(p->left, depth + 1);
            int rh = dfs(p->right, depth + 1);
            if (p->left) {
                res[p->left->val] = depth + rh;
            }
            if (p->right) {
                res[p->right->val] = depth + lh;
            }
            return max(lh, rh) + 1;
        };
        dfs(root, 0);
        vector<int> ans;
        for (const auto& q : queries) {
            ans.push_back(res[q]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
