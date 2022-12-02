#include "usual.h"

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->val < 2) {
            return root->val;
        }
        bool l = evaluateTree(root->left), r = evaluateTree(root->right);
        return root->val == 2 ? (l || r) : (l && r);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
