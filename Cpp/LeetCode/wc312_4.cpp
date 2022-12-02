#include "usual.h"

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        function<int(int)> find = [&](int u) {
            return p[u] == u ? u : (p[u] = find(p[u]));
        };
        auto merge = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                return;
            }
            p[pu] = pv;
        };
        map<int, vector<int>> nodes;
        for (int i = 0; i < n; ++i) {
            nodes[vals[i]].push_back(i);
        }
        int ans = 0;
        for (const auto& [val, vs] : nodes) {
            for (const auto& v : vs) {
                for (const auto& u : g[v]) {
                    if (vals[v] >= vals[u]) {
                        merge(u, v);
                    }
                }
            }
            unordered_map<int, int> cnt;
            for (const auto& v : vs) {
                ++cnt[find(v)];
            }
            for (const auto& [_, c] : cnt) {
                ans += c * (c + 1) / 2;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
