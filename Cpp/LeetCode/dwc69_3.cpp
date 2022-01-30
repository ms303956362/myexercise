#include "usual.h"

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // if (words == vector<string>{"oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"})
        //     return 102;
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            if (!cnt.count(w))
                cnt[w] = 0;
            ++cnt[w];
        }
        int ans = 0;
        bool ok = false;
        for (const auto& [w, c] : cnt) {
            if (w[0] == w[1]) {
                if (c % 2 == 0) {
                    ans += c;
                } else {
                    ok = true;
                    ans += c - 1;
                }
            } else {
                string w2(w.rbegin(), w.rend());
                int num = min(c, cnt[w2]);
                ans += num;
            }
        }
        if (ok)
            ++ans;
        return ans * 2;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> a{"oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"};
    cout << Solution().longestPalindrome(a) << endl;
    return 0;
}
