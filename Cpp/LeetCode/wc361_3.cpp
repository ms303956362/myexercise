#include "usual.h"

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + ((nums[i] % modulo == k) ? 1 : 0);
        }
        long long ans = 0;
        unordered_map<int, long long> cnt;
        ++cnt[pre[n] % modulo];
        for (int i = n - 1; i >= 0; --i) {
            int r = (pre[i] % modulo - k + modulo) % modulo;
            ans += cnt[r];
            ++cnt[pre[i] % modulo];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
