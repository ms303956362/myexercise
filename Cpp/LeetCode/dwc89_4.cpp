#include "usual.h"

class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), sum = 0;
        for (const auto& num : nums) {
            sum += num;
        }
        vector<int> factors;
        for (int i = 1; i * i <= sum; ++i) {
            if (sum % i == 0) {
                factors.push_back(i);
                if (i != sum / i) {
                    factors.push_back(sum / i);
                }
            }
        }
        sort(factors.rbegin(), factors.rend());
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> ssum(n);
        function<void(int, int)> dfs = [&](int u, int f) {
            ssum[u] = nums[u];
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                dfs(v, u);
                ssum[u] += ssum[v];
            }
        };
        dfs(0, -1);
        function<void(int, int)> dfs1 = [&](int u, int f) {
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                // if (ssum[v] % )
            }
        };
        for (const auto& x : factors) {

        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
