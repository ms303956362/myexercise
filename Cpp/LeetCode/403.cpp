#include "usual.h"

class Solution {
    unordered_map<int, unordered_set<int>> unfeasible_set;

public:
    bool canCross(vector<int>& stones) {
        unfeasible_set.clear();
        return dfs(0, 1, stones.size(), stones);
        return true;
    }

    bool dfs(int i, int k, int n, vector<int>& stones) {
        cout << i << " ";
        if (k == 0 || unfeasible_set.count(i) && unfeasible_set[i].count(k)) {
            cout << " fail"<< endl;
            return false;
        }
        if (stones[n - 1] == stones[i] + k) {
            cout << " success"<< endl;
            return true;
        }
        int j = lower_bound(stones.begin() + i, stones.end(), stones[i] + k) - stones.begin();
        if (j >= n || stones[j] != stones[i] + k || (!dfs(j, k - 1, n, stones) && !dfs(j, k, n, stones) && !dfs(j, k + 1, n, stones))) {
            cout << " fail"<< endl;
            unfeasible_set[i].insert(k);
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};
    Solution().canCross(stones);
    return 0;
}
