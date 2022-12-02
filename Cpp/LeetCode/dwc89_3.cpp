#include "usual.h"

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](long long m) {
            vector<long long> a(nums.begin(), nums.end());
            for (int i = n - 1; i > 0; --i) {
                if (a[i] > m) {
                    long long diff = a[i] - m;
                    a[i] -= diff;
                    a[i - 1] += diff;
                }
            }
            return a[0] <= m;
        };
        long long l = 0, r = 1e9 + 7, ans = 0;
        while (l <= r) {
            long long m = (l + r) / 2;
            if (check(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
