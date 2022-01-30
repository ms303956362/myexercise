#include "usual.h"

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int max_num = INT_MIN, min_num = INT_MAX;
            for (int j = i; j < n; ++j) {
                max_num = max(max_num, nums[j]);
                min_num = min(min_num, nums[j]);
                ans += (long long)max_num - (long long)min_num;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
