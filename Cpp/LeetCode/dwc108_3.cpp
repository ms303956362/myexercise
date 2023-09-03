#include "usual.h"

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        auto check_s = [](const auto& s) {
            int n = s.size();
            if (n == 0 || s[0] == '0') {
                return false;
            }
            long long num = 0;
            for (int i = 0; i < n; ++i) {
                num = num * 2 + (s[i] - '0');
            }
            while (num % 5 == 0) {
                num /= 5;
            }
            return num == 1;
        };
        auto check = [&check_s](vector<string>& v) {
            for (const auto& s : v) {
                if (!check_s(s)) {
                    return false;
                }
            }
            return true;
        };
        int ans = 0x3f3f3f3f;
        for (int t = 0; t < (1 << (n - 1)); ++t) {
            string num;
            vector<string> v;
            num.push_back(s[0]);
            for (int i = 0; i < n - 1; ++i) {
                if (t & (1 << i)) {
                    v.push_back(num);
                    num.clear();
                }
                num.push_back(s[i + 1]);
            }
            v.push_back(num);
            // for (const auto& num : v) {
            //     cout << num << " ";
            // }
            // cout << endl;
            if (check(v)) {
                ans = min(ans, (int)v.size());
            }
        }
        return ans >= 0x3f3f3f3f ? -1 : ans;
    }
};

class Solution2 {
public:
    int minimumBeautifulSubstrings(string s) {
        auto check_s = [](const auto& s) {
            int n = s.size();
            if (n == 0 || s[0] == '0') {
                return false;
            }
            long long num = 0;
            for (int i = 0; i < n; ++i) {
                num = num * 2 + (s[i] - '0');
            }
            while (num % 5 == 0) {
                num /= 5;
            }
            return num == 1;
        };
        int n = s.size();
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                continue;
            }
            for (int j = i; j < n; ++j) {
                if (check_s(s.substr(i, j - i + 1))) {
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }
        return dp[0] >= 0x3f3f3f3f ? -1 : dp[0];
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().minimumBeautifulSubstrings("110111110011111") << endl;
    return 0;
}
