#include "usual.h"

class Solution {
public:
    bool splitString(string s) {
        int n = s.size();
        vector<vector<string>> dp(n + 1);
        dp[n].push_back("");
        for (int i = n - 1; i >= 0; --i) {
            string num;
            for (int j = i; j < n; ++j) {
                if (num == "0")
                    num.pop_back();
                num.push_back(s[j]);
                for (const auto& firstnum : dp[j + 1]) {
                    if ((firstnum == "" || this->inc(firstnum) == num)) {
                        dp[i].push_back(num);
                        break;
                    }
                }
            }
        }
        if (dp[0].size() > 1)
            cout << dp[0][0] << " " << dp[0][1] << endl;
        return dp[0].size() > 1;
    }

    string inc(const string& s) {
        string ans;
        int c = 0, n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            ans.push_back((s[i] - '0' + c) % 10 + '0');
            c = (s[i] - '0' + c) / 10;
        }
        if (c)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
    // bool backtrack(int i, int n, const string& s, vector<int> nums) {
    //     if (i == n) {


    //     }
    // }
};

int main(int argc, char const *argv[])
{
    string s("10");
    cout << Solution().splitString(s) << endl;
    return 0;
}
