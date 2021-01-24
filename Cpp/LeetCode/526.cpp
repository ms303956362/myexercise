#include "usual.h"

class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> candidates(n + 1, vector<int>());
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0)
                    candidates[i].push_back(j);
            }
            for (int j = i; j <= n; ++j) {
                if (j % i == 0)
                    candidates[i].push_back(j);
            }
        }
        vector<bool> has(n + 1, false);
        int ans = backtrack(1, n, candidates, has);
        return ans;
    }

    int backtrack(int i, int n, vector<vector<int>>& candidates, vector<bool>& has) {
        if (i == n + 1)
            return 1;
        int ans = 0, tmp;
        for (int j : candidates[i]) {
            if (has[j])
                continue;
            has[j] = true;
            ans += backtrack(i + 1, n, candidates, has);
            has[j] = false;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;
    Solution().countArrangement(n);
    return 0;
}
