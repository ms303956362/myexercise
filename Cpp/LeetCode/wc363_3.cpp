#include <bitset>
#include "usual.h"


class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long ans = 0;
        auto check = [&](int i, long long c) {
            long long total = 0;
            for (int j = 0; j < n; ++j) {
                total += max(composition[i][j] * c - stock[j], 0LL) * (long long)cost[j];
            }
            return total <= budget;
        };
        for (int i = 0; i < k; ++i) {
            long long l = 0, h = 1e9, cnt = 0;
            while (l <= h) {
                int m = (l + h) / 2;
                if (check(i, m)) {
                    cnt = m;
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
