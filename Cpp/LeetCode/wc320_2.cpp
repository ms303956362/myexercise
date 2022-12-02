#include "usual.h"

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> a;
        function<void(TreeNode*)> dfs = [&](TreeNode* p) {
            if (!p) {
                return;
            }
            dfs(p->left);
            a.push_back(p->val);
            dfs(p->right);
        };
        dfs(root);
        vector<vector<int>> ans;
        for (const auto& q : queries) {
            auto p1 = lower_bound(a.begin(), a.end(), q);
            auto p2 = upper_bound(a.begin(), a.end(), q);
            int max_num = -1, min_num = -1;
            if (p1 != a.end()) {
                max_num = *p1;
            }
            if (p2 != a.begin()) {
                min_num = *prev(p2);
            }
            ans.push_back(vector<int>{min_num, max_num});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
