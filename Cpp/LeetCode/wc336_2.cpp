#include "usual.h"

class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long sum = 0;
        sort(nums.rbegin(), nums.rend());
        int ans = 0;
        for (const auto& num : nums) {
            sum += num;
            if (sum <= 0) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
