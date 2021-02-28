#include "usual.h"

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> cnt(50, 0);
        for (int i = lowLimit; i <= highLimit; ++i) {
            int sum = 0, tmp = i;
            while (tmp > 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            ++cnt[sum];
        }
        int ans = 0;
        for (int i = 0; i != 50; ++i)
            ans = max(ans, cnt[i]);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
