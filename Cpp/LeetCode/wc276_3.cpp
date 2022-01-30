#include "usual.h"

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(dp[i + 1], dp[min(n, i + questions[i][1])] + questions[i][0]);
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
