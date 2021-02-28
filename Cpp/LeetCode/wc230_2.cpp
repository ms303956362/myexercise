#include "usual.h"

class Solution {
    vector<int> top;

public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        top.clear();
        int min_diff = INT_MAX, ans = INT_MAX, n = toppingCosts.size();
        backtrack(0, 0, n, toppingCosts);
        for (const auto& base : baseCosts) {
            for (const auto& t : top) {
                if (abs(base + t - target) < min_diff || (abs(base + t - target) == min_diff && base + t < ans)) {
                    ans = base + t;
                    min_diff = abs(base + t - target);
                    if (min_diff == 0)
                        break;
                }
            }
            if (min_diff == 0)
                break;
        }
        return ans;
    }

    void backtrack(int i, int cost, int n, vector<int>& costs) {
        if (i == n) {
            top.push_back(cost);
            return;
        }
        backtrack(i + 1, cost, n, costs);
        cost += costs[i];
        backtrack(i + 1, cost, n, costs);
        cost += costs[i];
        backtrack(i + 1, cost, n, costs);
    }
};