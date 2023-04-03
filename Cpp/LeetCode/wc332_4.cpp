#include "usual.h"

class Solution {
public:
    int minimumScore(string s, string t) {
        auto check = [](const string& s, const string& t, vector<int>& pre) {
            int n = s.size(), m = t.size();
            pre[0] = 0;
            int i = 0, j = 0;
            while (j < m) {
                while (i < n && s[i] != t[j]) {
                    ++i;
                }
                if (i >= n) {
                    break;
                }
                pre[j + 1] = i + 1;
                ++i;
                ++j;
            }
        };
        int n = s.size(), m = t.size();
        vector<int> pre(m + 1, 0x3f3f3f3f), suf(m + 1, 0x3f3f3f3f);
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        check(s, t, suf);
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        check(s, t, pre);
        int ans = m;
        for (int i = 0; i <= m && pre[i] != 0x3f3f3f3f; ++i) {
            int j = upper_bound(suf.begin(), suf.end(), n - pre[i]) - suf.begin() - 1;
            ans = min(ans, m - i - j);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abacaba";
    string t = "bzaa";
    Solution().minimumScore(s, t);
    return 0;
}
