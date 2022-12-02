#include "usual.h"

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int g = nums[i];
            for (int j = i; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
