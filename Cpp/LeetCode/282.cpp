#include "usual.h"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        long long n = num.size();
        vector<string> ans;
        string curr;
        backtrack(0, n, 0, 0, -1, "+", "", num, target, ans);
        return ans;
    }

    void backtrack(long long i, long long n, long long res, long long curr, long long prev, string op, string expr, const string& num, long long target, vector<string>& ans) {
        if (i == n) {
            // if (op == "+")
            //     res += curr;
            // else if (op == "-")
            //     res -= curr;
            // else
            //     res += prev * curr - prev;
            if (res == target)
                ans.push_back(expr);
            return;
        }
        curr = curr * 10 + num[i] - '0';
        if (i < n - 1)
            backtrack(i + 1, n, res, curr, prev, op, expr, num, target, ans);
        if (op == "+")
            res += curr;
        else if (op == "-")
            res -= curr;
        else
            res += prev * curr - prev;
        backtrack(i + 1, n, res, 0, curr, "+", (prev != -1 ? expr + op + to_string(curr) : to_string(curr)), num, target, ans);
        if (i < n - 1) {
            backtrack(i + 1, n, res, 0, curr, "-", (prev != -1 ? expr + op + to_string(curr) : to_string(curr)), num, target, ans);
            backtrack(i + 1, n, res, 0, curr, "*", (prev != -1 ? expr + op + to_string(curr) : to_string(curr)), num, target, ans);
        }
    }
};

int main() {
    Solution().addOperators("105", 5);
}