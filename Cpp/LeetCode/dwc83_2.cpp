#include "usual.h"

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0;
        long long ans = 0;
        while (i < n) {
            if (nums[i] != 0) {
                ++i;
                continue;
            }
            int j = i + 1;
            while (j < n && nums[j] == 0) {
                ++j;
            }
            long long l = j - i;
            ans += (1 + l) * l / 2;
            i = j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{2,10,2019};
    cout << Solution().zeroFilledSubarray(a) << endl;
    return 0;
}
