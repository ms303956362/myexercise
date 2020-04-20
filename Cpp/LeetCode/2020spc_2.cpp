#include "usual.h"

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> r(n, vector<int>());
        for (auto& v : relation) {
            r[v[0]].push_back(v[1]);
        }
        return helper(n, 0, r, k);
    }

    int helper(int n, int beg, vector<vector<int>>& r, int k) {
        if (k == 0) {
            if (beg == n-1)
                return 1;
            else
                return 0;
        }
        int sum = 0;
        for (auto& nbr : r[beg]) {
            sum += helper(n, nbr, r, k - 1);
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    // cout << Solution()
    return 0;
}
