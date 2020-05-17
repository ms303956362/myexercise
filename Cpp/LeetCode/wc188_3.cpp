#include "usual.h"

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> canGoIn(n, false);
        vector<vector<int>> tree(n, vector<int>());
        for (int i = 0; i != edges.size(); ++i) {
            tree[edges[i][0]].push_back(edges[i][1]);
        }
        int cnt = 0;
        dfs2(0, hasApple, tree, canGoIn);
        dfs(0, cnt, tree, canGoIn);
        return cnt;
    }

    void dfs(int i, int& cnt, vector<vector<int>> &tree, vector<bool>& canGoIn) {
        for (int j = 0; j != tree[i].size(); ++j) {
            int c = tree[i][j];
            if (canGoIn[c]) {
                cnt += 2;
                dfs(c, cnt, tree, canGoIn);
            }
        }
    }

    void dfs2(int i, vector<bool>& hasApple, vector<vector<int>> &tree, vector<bool>& canGoIn) {
        bool can = hasApple[i];
        for (int j = 0; j != tree[i].size(); ++j) {
            int c = tree[i][j];
            dfs2(c, hasApple, tree, canGoIn);
            can |= canGoIn[c];
        }
        canGoIn[i] = can;
    }
};

int main(int argc, char const *argv[])
{
    int n = 7;
    vector<vector<int>> edges{{ 0, 1 }, { 0, 2 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 6 }};
    vector<bool> hasApple{false, false, true, false, true, true, false};
    cout << Solution().minTime(n, edges, hasApple) << endl;
    return 0;
}
