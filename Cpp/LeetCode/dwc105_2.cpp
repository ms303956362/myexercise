#include "usual.h"

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            for (int j = i + 1; j <= n; ++j) {
                if (st.count(s.substr(i, j - i))) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
