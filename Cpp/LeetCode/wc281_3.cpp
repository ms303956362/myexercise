#include "usual.h"

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        priority_queue<pair<char, int>> q;
        for (int c = 'a'; c <= 'z'; ++c) {
            if (cnt[c - 'a'] > 0) {
                q.emplace(c, cnt[c - 'a']);
            }
        }
        string ans;
        while (!q.empty()) {
            auto [curr_ch, curr_cnt] = q.top();
            q.pop();
            while (!q.empty() && curr_cnt > 0) {
                if (curr_cnt > repeatLimit) {
                    ans += string(repeatLimit, curr_ch);
                    curr_cnt -= repeatLimit;
                    if (!q.empty()) {
                        auto [next_ch, next_cnt] = q.top();
                        q.pop();
                        ans.push_back(next_ch);
                        --next_cnt;
                        if (next_cnt > 0) {
                            q.emplace(next_ch, next_cnt);
                        }
                    }
                } else {
                    ans += string(curr_cnt, curr_ch);
                    curr_cnt = 0;
                }
            }
            if (ans.back() != curr_ch && curr_cnt > 0) {
                ans += string(min(repeatLimit, curr_cnt), curr_ch);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("cczazcc");
    int r = 3;
    Solution().repeatLimitedString(s, r);
    return 0;
}
