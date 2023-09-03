#include "usual.h"

int dij(int n, vector<vector<pair<int, int>>>& g, int source, int destination) {
    vector<int> dis(n, 0x3f3f3f3f);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.emplace(0, source, -1);
    dis[source] = 0;
    while (!q.empty()) {
        auto [d, u, w] = q.top();
        q.pop();
        if (d > dis[u]) {
            continue;
        }
        if (u == destination) {
            return d;
        }
        for (const auto& [v, c] : g[u]) {
            if (d + c < dis[v]) {
                dis[v] = d + c;
                q.emplace(d + c, v, u);
            }
        }
    }
    return 0x3f3f3f3f;
}

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> g(n);
        vector<vector<int>> a, ans;
        for (const auto& e : edges) {
            if (e[2] != -1) {
                g[e[0]].emplace_back(e[1], e[2]);
                g[e[1]].emplace_back(e[0], e[2]);
                ans.push_back(e);
            } else {
                a.push_back({e[0], e[1], 2000000000});
            }
        }
        int d = dij(n, g, source, destination);
        if (d < target) {
            return {};
        } else if (d == target) {
            for (auto& e : a) {
                ans.push_back({e[0], e[1], 2000000000});
            }
            return ans;
        } else {
            for (auto& e : a) {
                e[2] = 1;
                g[e[0]].emplace_back(e[1], 1);
                g[e[1]].emplace_back(e[0], 1);
                int d = dij(n, g, source, destination);
                if (d <= target) {
                    e[2] = target - d + 1;
                    for (const auto& e : a) {
                        ans.push_back(e);
                    }
                    return ans;
                }
            }
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
