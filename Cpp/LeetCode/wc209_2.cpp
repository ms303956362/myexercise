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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int l = q.size();
            int last = (level % 2 ? INT_MAX : INT_MIN);
            for (int i = 0; i != l; ++i) {
                auto p = q.front();
                q.pop();
                if (level % 2) {
                    if (p->val % 2 == level % 2 && p->val >= last)
                        return false;
                } else {
                    if (p->val % 2 == level % 2 && p->val <= last)
                        return false;
                }
                last = p->val;
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            ++level;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
