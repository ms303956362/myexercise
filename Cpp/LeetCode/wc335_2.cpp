#include "usual.h"

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> v;
        while (!q.empty()) {
            int l = q.size();
            long long sum = 0;
            for (int i = 0; i < l; ++i) {
                auto p = q.front();
                q.pop();
                sum += p->val;
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            v.push_back(sum);
        }
        sort(v.rbegin(), v.rend());
        return v.size() >= k ? v[k - 1] : -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
