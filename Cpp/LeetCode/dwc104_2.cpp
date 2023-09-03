#include "usual.h"

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }
        int m = nums.size(), n = nums[0].size();
        int ans = 0;
        for (int j = n - 1; j >= 0; --j) {
            int mx = 0;
            for (int i = 0; i < m; ++i) {
                mx = max(mx, nums[i][j]);
            }
            ans += mx;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
