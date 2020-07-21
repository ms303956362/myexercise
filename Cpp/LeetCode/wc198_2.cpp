#include "usual.h"

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n, vector<int>());
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> cnt(128, 0);
        vector<int> ans(n, 0);
        vector<bool> vst(n, false);
        dfs(0, g, labels, vst, cnt, ans);
        return ans;
    }

    void dfs(int u, vector<vector<int>>& g, string& lb, vector<bool>& vst, vector<int>& cnt, vector<int>& ans) {
        vector<int> cntl(128, 0);
        vst[u] = true;
        cntl[lb[u]] = 1;
        for (int v : g[u]) {
            if (!vst[v])
                dfs(v, g, lb, vst, cntl, ans);
        }
        for (int i = 0; i != 128; ++i)
            cnt[i] += cntl[i];
        ans[u] = cntl[lb[u]];
    }
};

int main(int argc, char const *argv[])
{
    int n = 7;
    vector<vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 6 } };
    string labels = "abaedcd";
    Solution().countSubTrees(n, edges, labels);
    return 0;
}