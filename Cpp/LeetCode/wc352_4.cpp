#include "usual.h"

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(n + 5);
            ++cnt[nums[i]];
            int nb = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (cnt[nums[j]] == 0) {
                    if (cnt[nums[j] - 1] == 0 && cnt[nums[j] + 1] == 0) {
                        ++nb;
                    }
                    if (cnt[nums[j] - 1] > 0 && cnt[nums[j] + 1] > 0) {
                        --nb;
                    }
                }
                ans += nb;
                ++cnt[nums[j]];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
