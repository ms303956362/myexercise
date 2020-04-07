#include "usual.h"

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int i1, int i2) { return i1 > i2; });
        vector<int> res;
        int sum = 0, curr = 0;
        for (auto& num : nums) {
            sum += num;
        }
        for (auto& num : nums) {
            curr += num;
            res.push_back(num);
            if (curr > sum - curr)
                return res;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{4,3,10,9,8};
    vector<int> res = Solution().minSubsequence(v);
    return 0;
}
