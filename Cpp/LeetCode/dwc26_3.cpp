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
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }

    int helper(TreeNode* r, int max_above) {
        int cnt = 0;
        if (r->val <= max_above) {
            ++cnt;
        } else {
            max_above = r->val;
        }
        if (r->left)
            cnt += helper(r->left, max_above);
        if (r->right)
            cnt += helper(r->right, max_above);
        return cnt;
    }
};