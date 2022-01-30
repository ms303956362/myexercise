#include "usual.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int l = q.size();
            ++level;
            for (int i = 0; i < l; ++i) {
                auto p = q.front();
                q.pop();
                if (level == depth - 1) {
                    p->left = new TreeNode(val, p->left, nullptr);
                    p->right = new TreeNode(val, nullptr, p->right);
                } else {
                    if (p->left)
                        q.push(p->left);
                    if (p->right)
                        q.push(p->right);
                }
            }
            if (level == depth - 1)
                break;
        }
        return root;
    }
};


int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    Solution().addOneRow(root, 1, 2);
    return 0;
}
