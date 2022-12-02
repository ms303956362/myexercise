#include "usual.h"

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt(26), cntt(26);
        for (const auto& c : s) {
            ++cnt[c - 'a'];
        }
        for (const auto& c : target) {
            ++cntt[c - 'a'];
        }
        int ans = INT_MAX;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cntt[c - 'a'] != 0) {
                ans = min(ans, cnt[c - 'a'] / cntt[c - 'a']);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
