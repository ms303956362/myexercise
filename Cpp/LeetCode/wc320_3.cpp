#include "usual.h"

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> g(n);
        for (const auto& r : roads) {
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        long long ans = 0;
        function<long long(int, int)> dfs = [&](int u, int f) {
            long long sum = 1;
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                long long cnt = dfs(v, u);
                ans += (cnt + seats - 1) / seats;
                sum += cnt;
            }
            return sum;
        };
        dfs(0, -1);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
