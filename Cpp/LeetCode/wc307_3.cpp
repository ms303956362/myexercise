#include "usual.h"

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, int> parent;
        parent[root->val] = -1;
        function<void(TreeNode*)> dfs = [&](TreeNode* p) {
            if (!p) {
                return;
            }
            if (p->left) {
                parent[p->left->val] = p->val;
                dfs(p->left);
            }
            if (p->right) {
                parent[p->right->val] = p->val;
                dfs(p->right);
            }
        };
        dfs(root);
        unordered_map<int, unordered_set<int>> g;
        for (const auto& [son, father] : parent) {
            if (father != -1) {
                g[son].insert(father);
                g[father].insert(son);
            }
        }
        unordered_set<int> vst;
        queue<int> q;
        q.push(start);
        vst.insert(start);
        int ans = -1;
        while (!q.empty()) {
            int l = q.size();
            ++ans;
            for (int i = 0; i < l; ++i) {
                int u = q.front();
                q.pop();
                for (const auto& v : g[u]) {
                    if (!vst.count(v)) {
                        vst.insert(v);
                        q.push(v);
                    }
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
