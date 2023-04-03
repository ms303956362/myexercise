#include "usual.h"

using ll = long long;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll n = nums.size(), ans = 0;
        unordered_map<ll, ll> cnt;
        ll i = n - 1, j = n - 1, c = 0;
        while (i >= 0) {
            c += cnt[nums[i]];
            ++cnt[nums[i]];
            while (j > i && c >= k) {
                --cnt[nums[j]];
                c -= cnt[nums[j]];
                --j;
            }
            ans += n - j - 1;
            --i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
