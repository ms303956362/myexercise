#include "usual.h"

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        vector<long long> digits;
        long long tmp = n, sum = 0;
        while (tmp > 0) {
            sum += tmp % 10;
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
        if (sum <= target) {
            return 0;
        }
        int m = digits.size(), i = 0;
        vector<long long> xd;
        while (i < m && sum > target) {
            long long diff = (10 - digits[i]) % 10;
            sum -= digits[i] - 1;
            xd.push_back(diff);
            ++i;
            while (i < m && digits[i] == 9) {
                sum -= digits[i];
                digits[i] = 0;
                xd.push_back(0);
                ++i;
            }
            if (i == m) {
                digits.push_back(1);
            } else {
                ++digits[i];
            }
        }
        reverse(xd.begin(), xd.end());
        long long x = 0;
        m = xd.size();
        for (int i = 0; i < m; ++i) {
            x = x * 10 + xd[i];
        }
        return x;
    }
};

int main(int argc, char const *argv[])
{
    Solution().makeIntegerBeautiful(69992, 5);
    return 0;
}
