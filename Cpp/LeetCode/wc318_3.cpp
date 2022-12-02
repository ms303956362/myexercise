#include "usual.h"

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        int n = costs.size(), i = 0, j = n - 1;
        while (i < candidates) {
            q.emplace(costs[i], i, 0);
            ++i;
        }
        while (j >= i && j >= n - candidates) {
            q.emplace(costs[j], j, 1);
            --j;
        }
        for (int t = 0; t < k; ++t) {
            auto [c, _, type] = q.top();
            q.pop();
            ans += (long long)c;
            if (type == 0) {
                if (i <= j) {
                    q.emplace(costs[i], i, 0);
                    ++i;
                }
            } else {
                if (j >= i) {
                    q.emplace(costs[j], j, 1);
                    --j;
                }
            }
        }
        return ans;
    }
};