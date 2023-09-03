#include "usual.h"

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> fa;
        unordered_map<TreeNode*, int> sum_son;
        root->val = 0;
        while (!q.empty()) {
            int l = q.size();
            map<int, int> mp;
            vector<TreeNode*> v;
            int sum = 0;
            while (l--) {
                auto p = q.front();
                q.pop();
                if (p->left) {
                    sum += p->left->val;
                    sum_son[p] += p->left->val;
                    fa[p->left] = p;
                    q.push(p->left);
                    v.push_back(p->left);
                }
                if (p->right) {
                    sum += p->right->val;
                    sum_son[p] += p->right->val;
                    fa[p->right] = p;
                    q.push(p->right);
                    v.push_back(p->right);
                }
            }
            for (const auto& p : v) {
                p->val = sum - sum_son[fa[p]];
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
