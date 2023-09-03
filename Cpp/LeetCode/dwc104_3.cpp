#include "usual.h"

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long orsum = 0;
        vector<long long> cnt(60);
        for (long long num : nums) {
            orsum |= num;
            for (long long i = 0; i < 60; ++i) {
                if (num & (1LL << i)) {
                    ++cnt[i];
                }
            }
        }
        long long ans = 0;
        for (long long num : nums) {
            long long res = orsum;
            for (long long i = 0; i < 60; ++i) {
                if ((num & (1LL << i)) && cnt[i] == 1) {
                    res &= ~(1LL << i);
                }
            }
            for (long long i = 0; i < k; ++i) {
                num <<= 1LL;
            }
            ans = max(ans, res | num);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
