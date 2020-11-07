#include "usual.h"

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n - 1, 0);
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX)), g(n, vector<int>());
        for (int i = 0; i != n; ++i)
            dis[i][i] = 0;
        for (const auto& e : edges) {
            int i = e[0] - 1, j = e[1] - 1;
            g[i].push_back(j);
            g[j].push_back(i);
            dis[i][j] = dis[j][i] = 1;
        }
        for (int k = 0; k != n; ++k)
            for (int i = 0; i != n; ++i)
                for (int j = 0; j != n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
};