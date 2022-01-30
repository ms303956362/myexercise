#include "usual.h"

class Solution {
public:
    long long kMirror(int k, int n) {
        if (n <= k)
            return (1 + n) * n / 2;
        vector<vector<pair<string, long long>>> dp;
        // l == 1
        dp.push_back({make_pair("", 0)});
        dp.push_back({});
        long long ans = 0;
        for (long long i = 0; i < k; ++i) {
            dp[1].push_back(make_pair(to_string(i), i));
            ans += i;
        }
        long long mask = 1;
        long long cnt = k - 1;
        for (long long l = 2; cnt < n; ++l) {
            dp.push_back({});
            mask *= k;
            // 加前导0
            for (auto& [s, num] : dp[l - 2]) {
                dp[l].push_back(make_pair("0" + s + "0", num * k));
            }
            // 不加
            for (int i = 1; i < k; ++i) {
                for (const auto& [s, num] : dp[l - 2]) {
                    dp[l].push_back(make_pair(to_string(i) + s + to_string(i), i * mask + num * k + i));
                    if (check(i * mask + num * k + i)) {
                        // cout << i * mask + num * k + i << " " << to_string(i) + s + to_string(i) << endl;
                        ans += i * mask + num * k + i;
                        ++cnt;
                        if (cnt >= n)
                            break;
                    }
                }
                if (cnt >= n)
                    break;
            }
        }
        return ans;
    }

    inline bool check(long long num) {
        string s;
        while (num > 0) {
            s.push_back(num % 10 + '0');
            num /= 10;
        }
        string t(s.rbegin(), s.rend());
        return s == t;
    }
};

int main(int argc, char const *argv[])
{
    int k = 3, n = 7;
    cout << Solution().kMirror(k, n) << endl;
    return 0;
}
