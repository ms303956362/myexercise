#include "usual.h"

class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans;
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            vector<bool> exist(128, false);
            exist[s[i]] = true;
            for (int j = i + 1; j < n; ++j) {
                exist[s[j]] = true;
                bool ok = true;
                for (int k = i; k <= j; ++k) {
                    if ('a' <= s[k] && s[k] <= 'z' && !exist[s[k] - 'a' + 'A'] || 'A' <= s[k] && s[k] <= 'Z' && !exist[s[k] - 'A' + 'a']) {
                        ok = false;
                        break;
                    }
                }
                if (ok && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("YazaAay");
    Solution().longestNiceSubstring(s);
    return 0;
}
