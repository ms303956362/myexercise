#include "usual.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0, i_max = n, i_min = n, end = n;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < minK || nums[i] > maxK) {
                end = i;
                i_max = n;
                i_min = n;
            }
            if (nums[i] == minK) {
                i_min = i;
            }
            if (nums[i] == maxK) {
                i_max = i;
            }
            ans += max(0LL, end - min(i_max, i_min));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
