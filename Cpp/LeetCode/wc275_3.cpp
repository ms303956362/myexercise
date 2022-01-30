#include "usual.h"

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> s;
        for (const auto& w : startWords) {
            s.insert(trans(w));
        }
        int ans = 0;
        for (auto& w : targetWords) {
            vector<int> cnt(26);
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
            int num = trans(w);
            for (char c = 'a'; c <= 'z'; ++c) {
                if (cnt[c - 'a']) {
                    int t = (num & ~(1 << (c - 'a')));
                    if (s.count(t)) {
                        ++ans;
                        break;
                    }
                }
            }
        }
        return ans;
    }

    int trans(const string& s) {
        int num = 0;
        for (const auto& c : s) {
            num |= (1 << (c - 'a'));
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
