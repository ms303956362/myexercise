#include "usual.h"

class Solution {
public:

    long long rev(long long num) {
        long long ret = 0;
        while (num > 0) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }

    int numberOfPairs(vector<int>& nums) {
        long long ans = 0, mod = 1e9 + 7;
        unordered_map<long long, long long> cnt;
        for (const auto& num : nums) {
            long long r = rev(num);
            ans = (ans + cnt[num - r]) % mod;
            ++cnt[num - r];
        }
        return ans % mod;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
