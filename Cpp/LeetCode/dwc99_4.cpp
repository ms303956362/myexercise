#include "usual.h"

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        multiset<pair<int, int>> st;
        for (const auto& e : guesses) {
            st.emplace(e[0], e[1]);
        }
        vector<int> cnt(n);
        function<void(int, int)> dfs = [&](int u, int f) {
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                if (st.count(make_pair(u, v))) {
                    ++cnt[0];
                }
                dfs(v, u);
            }
        };
        dfs(0, -1);
        function<void(int, int)> dfs2 = [&](int u, int f) {
            if (f != -1) {
                cnt[u] = cnt[f] - st.count(make_pair(f, u)) + st.count(make_pair(u, f));
            }
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                dfs2(v, u);
            }
        };
        dfs2(0, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] >= k) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
