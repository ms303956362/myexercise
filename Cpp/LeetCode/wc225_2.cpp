#include "usual.h"

class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> cnta(128, 0), cntb(128, 0), prea(128, 0), preb(128, 0), posta(128, 0), postb(128, 0);
        for (const auto& c : a)
            ++cnta[c];
        for (const auto& c : b)
            ++cntb[c];
        int ans = INT_MAX, len = a.size() + b.size();
        for (char c = 'a'; c <= 'z'; ++c) {
            prea[c] = prea[c - 1] + cnta[c];
            preb[c] = preb[c - 1] + cntb[c];
        }
        for (char c = 'y'; c >= 'a'; --c) {
            posta[c] += posta[c + 1] + cntb[c + 1];
            postb[c] += postb[c + 1] + cnta[c + 1];
            ans = min({ans, len - cnta[c] - cntb[c], prea[c] + posta[c], preb[c] + postb[c]});
        }
        ans = min(ans, len - cnta['z'] - cntb['z']);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string a("a"), b("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
    Solution().minCharacters(a, b);
    return 0;
}
