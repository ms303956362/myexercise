#include "usual.h"

class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.size(), k = 0;
        while (k < n && expression[k] != '+') {
            ++k;
        }
        long long ans = 0x3f3f3f3f3f3f3f3f, i0 = 0, j0 = n - 1;
        for (int i = 0; i < k; ++i) {
            for (int j = k + 1; j < n; ++j) {
                long long p1 = (i == 0 ? 1 : stoll(expression.substr(0, i))), p2 = (j == n - 1 ? 1 : stoll(expression.substr(j + 1, n - j - 1)));
                long long num1 = stoll(expression.substr(i, k - i)), num2 = stoll(expression.substr(k + 1, j - k));
                long long res = p1 * (num1 + num2) * p2;
                if (res < ans) {
                    ans = res;
                    i0 = i;
                    j0 = j;
                }
            }
        }
        expression.insert(expression.begin() + i0, '(');
        expression.insert(expression.begin() + j0 + 2, ')');
        return expression;
    }
};

int main(int argc, char const *argv[])
{
    Solution().minimizeResult("247+38");
    return 0;
}
