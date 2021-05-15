#include "usual.h"

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int sum = 0;
        vector<int> ans;
        int max_num = (1 << maximumBit);
        for (const auto& num : nums) {
            sum ^= num;
            ans.push_back(max_num - 1 - sum);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
