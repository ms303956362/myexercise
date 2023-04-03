#include "usual.h"

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        for (long long i = 0; i < n; ++i) {
            long long cnt = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i] + 1) - 
            upper_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            ans += cnt;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
