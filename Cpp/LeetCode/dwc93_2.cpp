#include "usual.h"

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(vals[e[1]]);
            g[e[1]].push_back(vals[e[0]]);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sort(g[i].rbegin(), g[i].rend());
            int sum = vals[i], m = g[i].size();
            for (int j = 0; j < min(k, m); ++j) {
                sum += g[i][j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
