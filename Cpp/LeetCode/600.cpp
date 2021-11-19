#include "usual.h"

class Solution {
public:
    int findIntegers(int n) {
        vector<unordered_set<int>> dp(17, unordered_set<int>());
        dp[0].insert(0);
        long long ans = 1, mask = 7, bit_mask = 1;
        for (int i = 1; i < 17; ++i) {
            for (const auto& num : dp[i - 1]) {
                if (!(num & 1) && !(num & 2) && (num | 1) <= n)
                    dp[i].insert(num | 1);
                for (int i = 0; i < 31; ++i) {
                    long long curr_num = ((bit_mask << (i + 1)) | num);
                    
                    if (!((mask << i) & num) && (curr_num <= n)) {
                        // cout << "true\t";
                        cout << curr_num << " ";
                        dp[i].insert(curr_num);
                    } else {
                        // cout << "false\t";
                    }
                }
            }
            cout << endl;
            // for (const auto& num : dp[i])
            //     cout << num << " ";
            // cout << endl;
            ans += dp[i].size();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().findIntegers(5);
    return 0;
}
