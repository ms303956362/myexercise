#include "usual.h"

long long pow(long long x, long long n, long long mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

class Solution {
public:
    int g(string s, int k) {
        int m = s.length(), memo[m][21][21];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
        function<int(int, int, int, bool, bool)> f = [&](int i, int c, int r, bool is_limit, bool is_num) -> int {
            if (i == m) {
                return is_num && c == 10 && r == 0; // is_num 为 true 表示得到了一个合法数字
            }
            if (!is_limit && is_num && memo[i][c][r] != -1) {
                return memo[i][c][r];
            }
            int res = 0;
            if (!is_num) { // 可以跳过当前数位
                res = f(i + 1, c, r, false, false);
            }
            int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            for (int d = 1 - is_num; d <= up; ++d) { // 枚举要填入的数字 d
                int rd = (d * pow(10, m - i - 1, k)) % k, r1 = ((r - rd) % k + k) % k;
                int c1 = (d % 2 ? (c - 1) : (c + 1));
                res = (res + f(i + 1, c1, r1, is_limit && d == up, true));
            }
            if (!is_limit && is_num) {
                memo[i][c][r] = res;
            }
            return res;
        };
        return f(0, 10, 0, true, false);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        auto check = [](int num, int k) {
            string s = to_string(num);
            int n = s.size();
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if ((s[i] - '0') % 2 == 0) {
                    ++cnt;
                } else {
                    --cnt;
                }
            }
            return num % k == 0 && cnt == 0;
        };
        string sl = to_string(low), sh = to_string(high);
        int nl = g(sl, k) - check(low, k), nh = g(sh, k);
        return nh - nl;
    }
};


int main(int argc, char const *argv[])
{
    int l = 132136, h = 926456463, k = 6;
    auto check = [](int num, int k) {
            string s = to_string(num);
            int n = s.size();
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if ((s[i] - '0') % 2 == 0) {
                    ++cnt;
                } else {
                    --cnt;
                }
            }
            return num % k == 0 && cnt == 0;
        };
    int ans1 = 0, ans2 = Solution().numberOfBeautifulIntegers(l, h, k);
    // for (int i = l; i <= h; ++i) {
    //     if (check(i, k)) {
    //         ++ans1;
    //     }
    // }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
