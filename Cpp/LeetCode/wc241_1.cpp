#include "usual.h"

class Solution {
    int ans;

public:
    int subsetXORSum(vector<int>& nums) {
        ans = 0;
        int n = nums.size();
        backtrack(0, n, 0, nums);
        return ans;
    }

    void backtrack(int i, int n, int sum, vector<int>& nums) {
        if (i == n) {
            ans += sum;
            return;
        }
        sum ^= nums[i];
        backtrack(i + 1, n, sum, nums);
        sum ^= nums[i];
        backtrack(i + 1, n, sum, nums);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
