#include "usual.h"

const int mod = 1e9 + 7;

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        num1 = dec(num1);
        int m1 = num1.size(), m2 = num2.size();
        vector<vector<int>> dp1(m1, vector<int>(max_sum + 1, -1)), dp2(m2, vector<int>(max_sum + 1, -1));
        int ans1 = 0, ans2 = 0;
        for (int sum = min_sum; sum <= max_sum; ++sum) {
            ans1 = (ans1 + f(0, sum, true, false, num1, dp1)) % mod;
        }
        for (int sum = min_sum; sum <= max_sum; ++sum) {
            ans2 = (ans2 + f(0, sum, true, false, num2, dp2)) % mod;
        }
        return ((ans2 - ans1) % mod + mod) % mod;
    }

    string dec(string num) {
        string ret = num;
        int m = num.size(), i = m - 1;
        while (num[i] == '0') {
            --i;
        }
        --num[i];
        for (int j = i + 1; j < m; ++j) {
            num[j] = '9';
        }
        return num[0] == '0' ? num.substr(1, m) : num;
    }

    int f(int i, int sum, bool is_limit, bool is_num, string& s, vector<vector<int>>& memo) {
        int m = s.size();
        if (i == m) {
            return is_num && sum == 0; // is_num 为 true 表示得到了一个合法数字
        }
        if (!is_limit && is_num && memo[i][sum] != -1) {
            return memo[i][sum];
        }
        int res = 0;
        if (!is_num) { // 可以跳过当前数位
            res = f(i + 1, sum, false, false, s, memo);
        }
        int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
        for (int d = 1 - is_num; d <= up; ++d) {// 枚举要填入的数字 d
            if (d <= sum) { // d <= sum
                res = (res + f(i + 1, sum - d, is_limit && d == up, true, s, memo)) % mod;
            }
        }
        if (!is_limit && is_num) {
            memo[i][sum] = res;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
