#include "usual.h"

class Solution {
    using ll = long long;

public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        ll base = 1, next_base = 10;
        for (int i = 0; i < (intLength - 1) / 2; ++i) {
            base *= 10;
            next_base *= 10;
        }
        vector<ll> ans;
        for (const ll& q : queries) {
            if (base + q > next_base) {
                ans.push_back(-1);
                continue;
            }
            ll half = base + q - 1, tmp = half;
            vector<ll> digits;
            while (tmp > 0) {
                digits.push_back(tmp % 10);
                tmp /= 10;
            }
            int m = digits.size(), i = ((intLength % 2 == 0) ? 0 : 1);
            while (i < m) {
                half = half * 10 + digits[i];
                ++i;
            }
            ans.push_back(half);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> q{1, 2, 3, 4, 5, 90};
    int l = 3;
    Solution().kthPalindrome(q, l);
    return 0;
}
