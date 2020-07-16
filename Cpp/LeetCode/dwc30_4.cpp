#include "usual.h"

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        vector<int> c;
        for (int i = 1; i * i <= n; ++i) {
            c.push_back(i * i);
        }
        int m = c.size();
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j != m && c[j] <= i; ++j) {
                if (!dp[i - c[j]]) {
                    dp[i] = true;
                    break;
                } 
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
