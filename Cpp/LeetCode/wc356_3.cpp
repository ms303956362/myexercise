#include "usual.h"

class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<vector<string>> perms{
            {a, b, c},
            {a, c, b},
            {b, a, c},
            {b, c, a},
            {c, a, b},
            {c, b, a},
        };
        auto check = [](string a, string b) {
            int n = min(a.size(), b.size());
            int la = a.size(), lb = b.size();
            while (n > 0) {
                if (a.substr(la - n, n) == b.substr(0, n)) {
                    break;
                }
                --n;
            }
            return n;
        };
        auto is_substring = [](string a, string b) {
            if (a.size() > b.size()) {
                return false;
            }
            int la = a.size(), lb = b.size();
            for (int i = 0; i <= lb - la; ++i) {
                if (a == b.substr(i, la)) {
                    return true;
                }
            }
            return false;
        };
        string ans(1000, 'z');
        for (const auto& perm : perms) {
            int l0 = perm[0].size(), l2 = perm[2].size();
            int n1 = check(perm[0], perm[1]), n2 = check(perm[1], perm[2]);
            string s = (is_substring(perm[0], perm[1]) ? "" : perm[0].substr(0, l0 - n1)) 
                        + perm[1] 
                        + (is_substring(perm[2], perm[1]) ? "" : perm[2].substr(n2, l2 - n2));
            if (s.size() < ans.size() || (s.size() == ans.size() && s < ans)) {
                ans = s;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string a = "b";
    string b = "a";
    string c = "aba";
    Solution().minimumString(a, b, c);
    return 0;
}
