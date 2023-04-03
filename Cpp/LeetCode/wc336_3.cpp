#include "usual.h"

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> cnt;
        long long ans = 0;
        cnt[0] = 1;
        for (int s = 0, i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 30; ++j) {
                if (nums[i] & (1 << j)) {
                    s ^= (1 << j);
                }
            }
            ans += cnt[s];
            ++cnt[s];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
