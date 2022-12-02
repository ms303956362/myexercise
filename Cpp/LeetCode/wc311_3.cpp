#include "usual.h"

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int l = q.size();
            vector<TreeNode*> v;
            for (int i = 0; i < l; ++i) {
                auto p = q.front();
                q.pop();
                v.push_back(p);
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            if (level % 2) {
                int m = v.size(), i = 0, j = m - 1;
                while (i < j) {
                    swap(v[i]->val, v[j]->val);
                    ++i;
                    --j;
                }
            }
            ++level;
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
