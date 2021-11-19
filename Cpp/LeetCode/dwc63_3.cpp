#include "usual.h"

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<int> d(n, -1);
        vector<bool> vst(n, false);
        q.push({0, 0});
        while (!q.empty()) {
            int dist = q.top()[0], u = q.top()[1];
            q.pop();
            if (vst[u])
                continue;
            vst[u] = true;
            d[u] = dist;
            for (const auto& v : g[u]) {
                if (!vst[v]) {
                    q.push({dist + 1, v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if ((2 * d[i]) % patience[i] == 0)
                ans = max(ans, 4 * d[i] - patience[i] + 1);
            else
                ans = max(ans, 2 * d[i] / patience[i] * patience[i] + 2 * d[i] + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
