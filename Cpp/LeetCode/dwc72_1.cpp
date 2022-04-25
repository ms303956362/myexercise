#include "usual.h"

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    if ((i * j) % k == 0) {
                        ++ans;
                    }
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
