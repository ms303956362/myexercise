#include "usual.h"

class Solution {
    const int mod = 1e9 + 7;

public:
    int g(string s) {
        int m = s.length(), memo[m][11];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
        function<int(int, int, bool, bool)> f = [&](int i, int last, bool is_limit, bool is_num) -> int {
            if (i == m)
                return is_num; // is_num 为 true 表示得到了一个合法数字
            if (!is_limit && is_num && memo[i][last] != -1)
                return memo[i][last];
            int res = 0;
            if (!is_num) // 可以跳过当前数位
                res = f(i + 1, last, false, false);
            int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
                if (!is_num || (abs(d - last) == 1)) // d 不在 mask 中
                    res = (res + f(i + 1, d, is_limit && d == up, true)) % mod;
            if (!is_limit && is_num)
                memo[i][last] = res;
            return res;
        };
        return f(0, -1, true, false);
    }

    int countSteppingNumbers(string low, string high) {
        auto check = [](string s) {
            int n = s.size();
            for (int i = 1; i < n; ++i) {
                int d0 = s[i] - '0', d1 = s[i - 1] - '0';
                if (abs(d0 - d1) != 1) {
                    return 0;
                }
            }
            return 1;
        };
        int nl = (g(low) - check(low) + mod) % mod, nh = g(high);
        return (nh - nl + mod) % mod;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
