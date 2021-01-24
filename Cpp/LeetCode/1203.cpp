#include "usual.h"


class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, int> idx;
        vector<vector<int>> nodes;
        vector<int> parent(n);
        int cnt = 0;
        for (int i = 0; i != n; ++i) {
            if (group[i] == -1) {
                nodes.push_back({i});
                parent[i] = cnt;
                ++cnt;
            } else if (idx.count(group[i]) == 0) {
                nodes.push_back({i});
                idx[group[i]] = cnt;
                parent[i] = cnt;
                ++cnt;
            } else {
                int j = idx[group[i]];
                parent[i] = j;
                nodes[j].push_back(i);
            }
        }
        int k = nodes.size();
        vector<int> inDegree(k, 0);
        vector<vector<int>> graph(k, vector<int>());
        vector<unordered_map<int, int>> subInDegree(k);
        vector<unordered_map<int, vector<int>>> subgraph(k);
        for (int i = 0; i != k; ++i) {
            for (const auto& u : nodes[i]) {
                subInDegree[i][u] = 0;
                subgraph[i][u] = {};
            }
        }
        for (int i = 0; i != n; ++i) {
            const auto& edges = beforeItems[i];
            for (const auto& e : edges) {
                if (parent[i] == parent[e]) {
                    ++subInDegree[parent[i]][i];
                    subgraph[parent[i]][e].push_back(i);
                } else {
                    ++inDegree[parent[i]];
                    graph[parent[e]].push_back(parent[i]);
                }
            }
        }
        queue<int> q;
        for (int i = 0; i != k; ++i) {
            if (inDegree[i] == 0)
                q.push(i); 
        }
        vector<int> ans;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            queue<int> q1;
            for (const auto& [j, id] : subInDegree[i]) {
                if (id == 0)
                    q1.push(j);
            }
            while (!q1.empty()) {
                int i1 = q1.front();
                ans.push_back(i1);
                q1.pop();
                for (const auto& j1 :subgraph[i][i1]) {
                    if (subInDegree[i][j1] >= 1) {
                        if (subInDegree[i][j1] == 1)
                            q1.push(j1);
                        --subInDegree[i][j1];
                    }
                }
            }
            for (const auto& j : graph[i]) {
                if (inDegree[j] >= 1) {
                    if (inDegree[j] == 1) {
                        q.push(j);
                    }
                    --inDegree[j];
                }
            }
        }
        if (ans.size() < n)
            ans.clear();
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    int n = 8;
    int m = 2;
    vector<int> g{-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> b{{}, {6}, {5}, {6}, { 3, 6 }, {}, {}, {}};
    Solution().sortItems(n, m, g, b);
    return 0;
}
