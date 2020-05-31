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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10, 0);
        return helper(root, cnt);
    }

    int helper(TreeNode* r, vector<int> cnt) {
        if (!r)
            return 0;
        ++cnt[r->val - 1];
        if (!r->left && !r->right) {
            bool hasOdd = false;
            for (const auto& n : cnt) {
                if (n & 0x01) {
                    if (!hasOdd)
                        hasOdd = true;
                    else
                        return 0;
                }
            }
            return 1;
        }
        return helper(r->left, cnt) + helper(r->right, cnt);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
