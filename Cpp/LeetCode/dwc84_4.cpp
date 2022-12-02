#include "usual.h"

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                long long cnt = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
                ans += cnt - 1;
                nums[i] /= cnt;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
