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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<pair<int, char>> ps, pe;
        dfs(root, ps, startValue);
        dfs(root, pe, destValue);
        int i = 0, n = ps.size(), m = pe.size();
        while (i < n && i < m && ps[i].first == pe[i].first) {
            ++i;
        }
        string ans(n - i, 'U');
        for (int j = i; j < m; ++j) {
            ans.push_back(pe[j].second);
        }
        return ans;
    }

    bool dfs(TreeNode* r, vector<pair<int, char>>& p, int target) {
        if (r->val == target)
            return true;
        if (r->left) {
            p.emplace_back(r->left->val, 'L');
            if (dfs(r->left, p, target))
                return true;
            p.pop_back();
        }
        if (r->right) {
            p.emplace_back(r->right->val, 'R');
            if (dfs(r->right, p, target))
                return true;
            p.pop_back();
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
