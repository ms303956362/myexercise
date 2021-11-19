#include "usual.h"

class Solution {
public:
    int maxProduct(string s) {
        int n = s.size(), ans = 0;
        string s1, s2;
        dfs(0, n, ans, s, s1, s2);
        return ans;
    }

    void dfs(int i, int n, int& ans, string& s, string& s1, string& s2) {
        if (i == n) {
            if (isPalindromic(s1) && isPalindromic(s2))
                ans = max(ans, (int)s1.size() * (int)s2.size());
            return;
        }
        dfs(i + 1, n, ans, s, s1, s2);
        s1.push_back(s[i]);
        dfs(i + 1, n, ans, s, s1, s2);
        s1.pop_back();
        s2.push_back(s[i]);
        dfs(i + 1, n, ans, s, s1, s2);
        s2.pop_back();
    }

    bool isPalindromic(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
