#include "usual.h"

class Solution {
public:
    int countVowelSubstrings(string word) {
        int ans = 0, n = word.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(word.substr(i, j - i + 1)))
                    ++ans;
            }
        }
        return ans;
    }

    bool check(const string& s) {
        vector<int> cnt(26);
        for (const auto& c : s) {
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
                return false;
            ++cnt[c - 'a'];
        }
        return cnt['a' - 'a'] > 0 && cnt['e' - 'a'] > 0 && cnt['i' - 'a'] > 0 && cnt['o' - 'a'] > 0 && cnt['u' - 'a'] > 0;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
