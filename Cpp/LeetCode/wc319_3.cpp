#include "usual.h"

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> idx(1e5 + 5);
        int ans = 0;
        while (!q.empty()) {
            int l = q.size();
            vector<int> a;
            for (int t = 0; t < l; ++t) {
                auto p = q.front();
                q.pop();
                a.push_back(p->val);
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            vector<int> b(a.begin(), a.end());
            sort(b.begin(), b.end());
            for (int i = 0; i < l; ++i) {
                idx[b[i]] = i;
            }
            for (int i = 0; i < l; ++i) {
                while (i != idx[a[i]]) {
                    int j = idx[a[i]];
                    swap(a[i], a[j]);
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
