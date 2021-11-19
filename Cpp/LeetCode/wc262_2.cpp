#include "usual.h"

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a.push_back(grid[i][j]);
            }
        }
        sort(a.begin(), a.end());
        vector<int> diff;
        n = a.size();
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if ((a[i] - a[i - 1]) % x != 0)
                return -1;
            diff.push_back((a[i] - a[i - 1]) / x);
            sum += a[i] - a[0];
        }
        int ans = sum;
        for (int i = 1; i < n; ++i) {
            sum += i * diff[i - 1] - (n - i) * diff[i - 1];
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
