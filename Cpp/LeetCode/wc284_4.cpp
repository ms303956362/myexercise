#include "usual.h"

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long long, int>>> g1(n), g0(n);
        for (const auto& e : edges) {
            g0[e[0]].emplace_back(e[1], e[2]);
            g1[e[1]].emplace_back(e[0], e[2]);
        }
        vector<long long> dis1(n, -1), dis2(n, -1), dis3(n, -1);
        dij(g0, src1, dis1);
        dij(g0, src2, dis2);
        dij(g1, dest, dis3);
        long long ans = -1;
        for (int u = 0; u < n; ++u) {
            if (dis1[u] == -1 || dis2[u] == -1 || dis3[u] == -1) {
                continue;
            }
            long long d = dis1[u] + dis2[u] + dis3[u];
            if (ans == -1 || d < ans) {
                ans = d;
            }
        }
        return ans;
    }

    void dij(vector<vector<pair<long long, int>>>& g, int src, vector<long long>& dis) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        dis[src] = 0;
        q.emplace(0, src);
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (d > dis[u]) {
                continue;
            }
            for (const auto& [v, w] : g[u]) {
                if (dis[v] == -1 || d + w < dis[v]) {
                    dis[v] = d + w;
                    q.emplace(d + w, v);
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n = 8;
    vector<vector<int>> e{{ 4, 7, 24 }, { 1, 3, 30 }, { 4, 0, 31 }, { 1, 2, 31 }, { 1, 5, 18 }, { 1, 6, 19 }, { 4, 6, 25 }, { 5, 6, 32 }, { 0, 6, 50 }};
    int s1 = 4, s2 = 1, d = 6;
    cout << Solution().minimumWeight(n, e, s1, s2, d) << endl;
    return 0;
}
