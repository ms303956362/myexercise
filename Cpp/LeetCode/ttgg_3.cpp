#include "usual.h"

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (!root) {
        return "";
    }
    string data;
    queue<TreeNode*> q;
    q.push(root);
    data += to_string(root->val);
    data.push_back('#');
    while (!q.empty()) {
        int l = q.size();
        for (int i = 0; i < l; ++i) {
            auto p = q.front();
            q.pop();
            if (p->left) {
                data += to_string(p->left->val);
                q.push(p->left);
                data.push_back('#');
            } else {
                data.push_back('n');
            }
            if (p->right) {
                data += to_string(p->right->val);
                q.push(p->right);
                data.push_back('#');
            } else {
                data.push_back('n');
            }
        }
    }
    return data;
}

class Solution {
public:
    vector<TreeNode*> lightDistribution(TreeNode* root) {
        unordered_map<string, int> cnt;
        vector<TreeNode*> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* p) {
            if (!p) {
                return;
            }
            dfs(p->left);
            dfs(p->right);
            string s = serialize(p);
            if (!cnt.count(s)) {
                cnt[s] = 1;
            } else {
                if (cnt[s] == 1) {
                    ans.push_back(p);
                }
                ++cnt[s];
            }
        };
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
