#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for (const auto& num : numsDivide) {
            g = __gcd(g, num);
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (const auto& num : nums) {
            if (g % num == 0) {
                break;
            }
            ++ans;
        }
        return ans >= nums.size() ? -1 : ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
