#include "usual.h"

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        vector<long long> v(s.begin(), s.end());
        long long n = v.size(), last = 0;
        long long ans = 0, kk = k;
        for (int i = 0; i < n && kk > 0; ++i) {
            long long cnt = min(kk, (v[i] - last - 1));
            ans += cnt * (2 * last + 1 + cnt) / 2;
            kk -= cnt;
            last = v[i];
        }
        ans += kk * (2 * last + 1 + kk) / 2;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
