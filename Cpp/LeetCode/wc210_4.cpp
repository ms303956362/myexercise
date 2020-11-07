#include "usual.h"

class Solution {
    vector<int> ans;
    int** es;
    vector<vector<int>> tab;

public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        ans.resize(n - 1, 0);
        es.clear();
        tab.resize(n + 1, vector<int>(n + 1, 0));
        for (const auto& e : edges) {
            es.emplace_back(e);
        }
        bfs(n);
        vector<int> nodes;
        backtrack(0, n, nodes);
    }

    void backtrack(int i, int n, vector<int>& nodes) {
        if (i == n) {
            if (nodes.size() > 0) {
                unordered_set<int> s;
                int ecnt = 0;
                for (const auto& i : nodes) {
                    s.insert(i);
                }
                for (const auto& e : es) {
                    if (s.count(e[0]) && s.count(e[1])) {
                        ++ecnt;
                    }
                }
                if (ecnt >= nodes.size() - 1) {
                    int d = 0;
                    for (int i = 0; i != nodes.size(); ++i) {
                        for (int j = 0; j != nodes.size(); ++j) {
                            if (i == j)
                                continue;
                            d = max(d, tab[nodes[i]][nodes[j]]);
                        }
                    }
                    ++ans[d - 1];
                }
            }
            return;
        }
        nodes.push_back(i + 1);
        backtrack(i + 1, n, nodes);
        nodes.pop_back();
        backtrack(i + 1, n, nodes);
    }

    void bfs(int n) {
        vector<vector<int>> ed(n + 1, vector<int>());
        for (const auto& e : es) {
            ed[e[0]].push_back(e[1]);
            ed[e[1]].push_back(e[0]);
        }
        for (int i = 1; i <= n; ++i) {
            queue<int> q;
            vector<bool> vst(n + 1, false);
            q.push(i);
            vst[i] = true;
            int level = 0;
            while (!q.empty()) {
                int l = q.size();
                for (int k = 0; k != l; ++k) {
                    int j = q.front();
                    q.pop();
                    tab[i][j] = max(tab[i][j], level);
                    tab[j][i] = max(tab[j][i], level);
                    for (int v : ed[j]) {
                        if (!vst[v]) {
                            q.push(v);
                            vst[v] = true;
                        }
                    }
                }
                ++level;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n = 2;
    vector<vector<int>> es{{1, 2}};
    Solution().countSubgraphsForEachDiameter(n, es);
    return 0;
}
