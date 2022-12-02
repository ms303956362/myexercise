#include "usual.h"

int cnt[26][26];
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        memset(cnt, 0, 26 * 26 * sizeof(int));
        unordered_map<string, unordered_set<char>> has;
        for (const auto &s : ideas) {
            string post = s.substr(1, s.size() - 1);
            has[post].insert(s[0]);
        }
        // for (char c = 'a'; c <= 'z'; ++c) {
        //     for (char d = 'a'; d <= 'z'; ++d) {
        //         for (const auto &s : ideas) {
        //             if (s[0] == c) {
        //                 string post = s.substr(1, s.size() - 1);
        //                 if (!has[post][d - 'a']) {
        //                     ++cnt[c - 'a'][d - 'a'];
        //                 }
        //             }
        //         }
        //     }
        // }
        for (const auto& [post, v] : has) {
            for (const auto& c : v) {
                for (char d = 'a'; d <= 'z'; ++d) {
                    if (!v.count(d)) {
                        ++cnt[c - 'a'][d - 'a'];
                    }
                }
            }
        }
        long long ans = 0;
        for (const auto& s : ideas) {
            string post = s.substr(1, s.size() - 1);
            for (char c = 'a'; c <= 'z'; ++c) {
                if (!has[post].count(c)) {
                    ans += cnt[c - 'a'][s[0] - 'a'];
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> v{"coffee", "donuts", "time", "toffee"};
    Solution().distinctNames(v);
    return 0;
}
