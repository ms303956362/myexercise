#include "usual.h"

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n, vector<int>()), gr(n, vector<int>());
        vector<int> vst(n, 0);
        for (const auto& c : connections) {
            g[c[0]].push_back(c[1]);
            gr[c[1]].push_back(c[0]);
        }
        queue<int> q;
        q.push(0);
        int cnt = 0;
        vst[0] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (const auto u : g[v]) {
                if (!vst[u]) {
                    ++cnt;
                    q.push(u);
                    vst[u] = 1;
                }
            }
            for (const auto u : gr[v]) {
                if (!vst[u]) {
                    q.push(u);
                    vst[u] = 1;
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<vector<int>> c{{ 1, 0 }, { 2, 0 }};
    cout << Solution().minReorder(n, c);
    return 0;
}