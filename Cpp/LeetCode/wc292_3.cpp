#include "usual.h"

class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size(), mod = 1e9 + 7;
        vector<int> max_press{0, 0, 3, 3, 3, 3, 3, 4, 3, 4}, dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            int num = pressedKeys[i] - '0';
            for (int j = i; j <= min(n - 1, i + max_press[num] - 1) && pressedKeys[j] == pressedKeys[i]; ++j) {
                dp[i] = (dp[i] + dp[j + 1]) % mod;
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
