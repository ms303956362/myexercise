#include "usual.h"

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        vector<int> dp(num + 1);
        auto rev = [](int num) {
            int ret = 0;
            while (num > 0) {
                ret = ret * 10 + num % 10;
                num /= 10;
            }
            return ret;
        };
        for (int i = 0; i <= num; ++i) {
            int sum = i + rev(i);
            if (sum <= num) {
                dp[sum] = true;
            }
        }
        return dp[num];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
