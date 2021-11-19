#include "usual.h"

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), cntl = 0, cntr = 0, max_len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                ++cntl;
            else if (s[i] == ')')
                ++cntr;
        }
        string curr;
        unordered_set<string> a;
        cout << cntl << " " << cntr << endl;
        backtrack(0, n, s, curr, a, 0, cntl, cntr, max_len);
        vector<string> ret;
        for (const auto& str : a) {
            if (str.size() == max_len)
                ret.push_back(str);
        }
        return ret;
    }

    void backtrack(int i, int n, const string& s, string& curr, unordered_set<string>& ans, int cnt, int cntl, int cntr, int& max_len) {
        cout << s.substr(i, n - i) << ": " << curr << " " << cnt << " " << cntl << " " << cntr << endl;
        if (i == n) {
            if (cnt == 0) {
                ans.insert(curr);
                max_len = max(max_len, (int)curr.size());
            }
            return;
        }
        if (s[i] == '(') {
            if (cnt < cntr) {
                curr.push_back('(');
                backtrack(i + 1, n, s, curr, ans, cnt + 1, cntl - 1, cntr, max_len);
                curr.pop_back();
            }
            backtrack(i + 1, n, s, curr, ans, cnt, cntl - 1, cntr, max_len);
        } else if (s[i] == ')') {
            if (cnt > 0) {
                curr.push_back(')');
                backtrack(i + 1, n, s, curr, ans, cnt - 1, cntl, cntr - 1, max_len);
                curr.pop_back();
            }
            if (cnt <= cntr) {
                backtrack(i + 1, n, s, curr, ans, cnt, cntl, cntr - 1, max_len);
            }
        } else {
            curr.push_back(s[i]);
            backtrack(i + 1, n, s, curr, ans, cnt, cntl, cntr, max_len);
            curr.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    string a("((i)");
    Solution().removeInvalidParentheses(a);
    return 0;
}
