#include "usual.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* expandBinaryTree(TreeNode* root) {
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* p) {
            if (p->left) {
                p->left = new TreeNode(-1, dfs(p->left), nullptr);
            }
            if (p->right) {
                p->right = new TreeNode(-1, nullptr, dfs(p->right));
            }
            return p;
        };
        return dfs(root);
    }
};