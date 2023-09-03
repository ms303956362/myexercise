#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), min_len = n + 1, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            int g = nums[i], j = i;
            for (; j < n && g != 1; ++j) {
                g = __gcd(g, nums[j]);
            }
            if (g == 1) {
                min_len = min(min_len, j - i + 1);
            }
            if (nums[i] == 1) {
                ++cnt1;
            }
        }
        if (min_len > n) {
            return -1;
        }
        if (cnt1 == 0) {
            return min_len - 1 + n - 1;
        }
        return n - cnt1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
