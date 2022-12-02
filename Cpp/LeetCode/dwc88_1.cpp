#include "usual.h"

class Solution {
public:
    bool equalFrequency(string word) {
        auto check = [&](string w) {
            vector<int> cnt;
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
            int cc = -1;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) {
                    continue;
                }
                if (cc == -1) {
                    cc = cnt[i];
                } else if (cc != cnt[i]) {
                    return false;
                }
            }
            return true;
        };
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            string tmp(word);
            tmp.erase(tmp.begin() + i);
            if (check(tmp)) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
