#include "usual.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        queue<pair<int, int>> q;
        int n = nums.size();
        q.push({0, 0});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            res.push_back(nums[i][j]);
            if (j == 0 && i + 1 < n)
                q.push({i + 1, 0});
            int ni = nums[i].size();
            if (j + 1 < ni)
                q.push({i, j + 1});
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
    Solution().findDiagonalOrder(v);
    return 0;
}
