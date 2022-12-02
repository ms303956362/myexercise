#include "usual.h"

class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();
        vector<int> idx(26, n);
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            if (idx[s[i] - 'a'] == n) {
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == s[i]) {
                        idx[s[i] - 'a'] = j;
                        break;
                    }
                }
            }
        }
        int min_idx = n;
        char min_c = 'a';
        for (char c = 'a'; c <= 'z'; ++c) {
            if (idx[c - 'a'] < min_idx) {
                min_idx = idx[c - 'a'];
                min_c = c;
            }
        }
        return min_c;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
