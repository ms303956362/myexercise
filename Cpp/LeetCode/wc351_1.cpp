#include "usual.h"

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        auto first = [](int num) {
            int ret = 0;
            while (num > 0) {
                ret = num % 10;
                num /= 10;
            }
            return ret;
        };
        for (int i = 0; i < n; ++i) {
            int fi = first(nums[i]);
            for (int j = i + 1; j < n; ++j) {
                int fj = nums[j] % 10;
                if (__gcd(fi, fj) == 1) {
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
