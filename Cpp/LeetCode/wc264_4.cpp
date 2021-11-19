#include "usual.h"

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue<int> q;
        vector<int> degree(n);
        vector<vector<int>> g(n);
        for (const auto& r : relations) {
            g[r[0] - 1].push_back(r[1] - 1);
            ++degree[r[1] - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0)
                q.push(i);
        }
        int ans = 0;
        vector<int> start(n, 0);
        while (!q.empty()) {
            int l = q.size();
            int max_month = 0;
            for (int i = 0; i < l; ++i) {
                int u = q.front();
                q.pop();
                for (const auto& v : g[u]) {
                    start[v] = max(start[v], start[u] + times[u]);
                    --degree[v];
                    if (degree[v] == 0)
                        q.push(v);
                }
                // max_month = max(max_month, time[u]);
                ans = max(ans, start[u] + times[u]);
            }
            // ans += max_month;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<vector<int>> a{{1, 3}, {2, 3}};
    vector<int> time{3, 2, 5};
    Solution().minimumTime(n, a, time);
    return 0;
}
