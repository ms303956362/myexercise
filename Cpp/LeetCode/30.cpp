#include "usual.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt_dict;
        for (const auto& word : words)
            ++cnt_dict[word];
        int n = s.size(), wl = words[0].size();
        vector<int> ans;
        for (int i = 0; i != wl; ++i) {
            int l = i, r = i + wl;
            unordered_map<string, int> cnt;
            while (r <= n) {
                string subs(s.begin() + r - wl, s.begin() + r);
                if (cnt_dict[subs] == 0) {
                    l = r;
                    cnt.clear();
                } else {
                    ++cnt[subs];
                    while (l < r && cnt[subs] > cnt_dict[subs]) {
                        --cnt[string(s.begin() + l, s.begin() + l + wl)];
                        l += wl;
                    }
                    if (r - l == wl * words.size())
                        ans.push_back(l);
                }
                r += wl;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("barfoothefoobarman");
    vector<string> words{"foo","bar"};
    Solution().findSubstring(s, words);
    return 0;
}
