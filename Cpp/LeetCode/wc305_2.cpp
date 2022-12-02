#include "usual.h"

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> is_res(n, false);
        for (const auto& u : restricted) {
            is_res[u] = true;
        }
        vector<bool> vst(n, false);
        int ans = 0, cnt = 0;
        function<void(int)> dfs = [&](int u) {
            ++cnt;
            for (const auto& v : g[u]) {
                if (!vst[v] && !is_res[v]) {
                    vst[v] = true;
                    dfs(v);
                }
            }
        };
        cnt = 0;
        vst[0] = true;
        dfs(0);
        ans = max(ans, cnt);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
