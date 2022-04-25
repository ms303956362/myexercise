#include "usual.h"

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode *> mp;
        unordered_map<int, int> cnt;
        for (const auto& d : descriptions) {
            if (!mp.count(d[0])) {
                mp[d[0]] = new TreeNode(d[0]);
                cnt[d[0]] = 0;
            }
            if (!mp.count(d[1])) {
                mp[d[1]] = new TreeNode(d[1]);
                cnt[d[1]] = 0;
            }
            auto parent = mp[d[0]], child = mp[d[1]];
            ++cnt[d[1]];
            if (d[2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        for (const auto& [id, c] : cnt) {
            if (c == 0) {
                return mp[id];
            }
        }
        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> d{{1, 2, 1 }, { 2, 3, 0 }, { 3, 4, 1 }};
    Solution().createBinaryTree(d);
    return 0;
}
