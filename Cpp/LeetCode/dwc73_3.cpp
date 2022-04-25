#include "usual.h"

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<unordered_set<int>> as(n);
        vector<int> in(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            ++in[e[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (const auto& v : g[u]) {
                as[v].insert(u);
                for (const auto& a : as[u]) {
                    as[v].insert(a);
                }
                --in[v];
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<vector<int>> ans;
        // 祖先升序排序
        for (auto &s : as)
        {
            vector<int> v(s.begin(), s.end());
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
