#include "usual.h"

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        if (start == target) {
            return 0;
        }
        map<pair<int, int>, map<pair<int, int>, int>> sp;
        set<pair<int, int>> has;
        vector<pair<int, int>> points;
        points.emplace_back(start[0], start[1]);
        points.emplace_back(target[0], target[1]);
        has.emplace(start[0], start[1]);
        has.emplace(target[0], target[1]);
        for (const auto& r : specialRoads) {
            auto p1 = make_pair(r[0], r[1]), p2 = make_pair(r[2], r[3]);
            if (!has.count(p1)) {
                points.push_back(p1);
            }
            if (!has.count(p2)) {
                points.push_back(p2);
            }
            has.insert(p1);
            has.insert(p2);
            if (sp.count(p1) && sp[p1].count(p2)) {
                sp[p1][p2] = min(sp[p1][p2], r[4]);
            } else {
                sp[p1][p2] = r[4];
            }
        }
        int n = points.size();
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                if (sp.count(points[i]) && sp[points[i]].count(points[j])) {
                    g[i].emplace_back(j, min(abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second), sp[points[i]][points[j]]));
                } else {
                    g[i].emplace_back(j, abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second));
                }
            }
        }
        vector<int> dis(n, 0x3f3f3f3f);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, 0);
        dis[0] = 0;
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (d > dis[u]) {
                continue;
            }
            for (const auto& [v, c] : g[u]) {
                if (d + c < dis[v]) {
                    dis[v] = d + c;
                    q.emplace(d + c, v);
                }
            }
        }
        return dis[1];
    }
};
