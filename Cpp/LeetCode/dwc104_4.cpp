#include "usual.h"

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0, mod = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long x = nums[i];
            int p2 = (x * x) % mod, p3 = (p2 * x) % mod;
            ans = (ans + p3 + (p2 * sum) % mod) % mod;
            sum = (((2 * sum) % mod) + x) % mod;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
