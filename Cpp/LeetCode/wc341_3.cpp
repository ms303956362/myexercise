#include "usual.h"

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        vector<vector<int>> tab{{2, 1, 0}, {0, 2, 1}, {1, 0, 2}};
        int ans = 0;
        if (word[0] == 'b') {
            ++ans;
        } else if (word[0] == 'c') {
            ans += 2;
        }
        for (int i = 1; i < n; ++i) {
            ans += tab[word[i] - 'a'][word[i - 1] - 'a'];
        }
        if (word[n - 1] == 'b') {
            ++ans;
        } else if (word[n - 1] == 'a') {
            ans += 2;
        }
        return ans;
    }
};
