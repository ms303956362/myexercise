#include "usual.h"

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1, n = nums.size();
        auto check = [&](int i, int j) -> bool {
            int diff = 1;
            for (int k = i + 1; k <= j; ++k) {
                if (nums[k] - nums[k - 1] != diff) {
                    return false;
                }
                diff = -diff;
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(i, j)) {
                    ans = max(ans, j - i + 1);
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
