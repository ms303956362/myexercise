#include "usual.h"

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();
        map<int, long long> cnt;
        for (long long i = 0; i < n; ++i) {
            ans += i - cnt[nums[i] - i];
            ++cnt[nums[i] - i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
