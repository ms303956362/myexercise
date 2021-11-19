#include "usual.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<int> lens_s;
        unordered_set<string> ss(wordDict.begin(), wordDict.end());
        for (const auto& w : wordDict) {
            lens_s.insert(w.size());
        }
        for (int i = 1; i <= n; ++i) {
            for (const auto& l : lens_s) {
                if (i >= l) {
                    if (dp[i - l] && ss.count(s.substr(i - l, l))) {
                        dp[i] = true;
                        break;
                    }
                }
                if (dp[i])
                    break;
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
