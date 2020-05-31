#include "usual.h"

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pq, vector<vector<int>>& qs) {
        vector<vector<int>> g(n, vector<int>());
        vector<vector<bool>> pre(n, vector<bool>(n, false));
        vector<bool> res;
        vector<bool> vst(n, false);
        for (const auto& p : pq) {
            g[p[0]].push_back(p[1]);
        }
        for (int i = 0; i != n; ++i) {
            if (!vst[i])
                dfs(i, g, pre, vst);
        }
        for (const auto& q : qs) {
            res.push_back(pre[q[0]][q[1]]);
        }
        return res;
    }

    void dfs(int v, vector<vector<int>>& g, vector<vector<bool>>& pre, vector<bool>& vst) {
        int n = g.size();
        vst[v] = true;
        for (const auto& u : g[v]) {
            pre[v][u] = true;
            if (!vst[u]) {
                dfs(u, g, pre, vst);
            }
            for (int i = 0; i != n; ++i) {
                if (pre[u][i])
                    pre[v][i] = true;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v1{{ 1, 0 }}, v2{{ 0, 1 }, { 1, 0 }};
    Solution().checkIfPrerequisite(2, v1, v2);
    return 0;
}
