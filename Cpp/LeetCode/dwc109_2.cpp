#include "usual.h"

class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string ans(s);
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> idx;
        vector<char> v;
        for (int i = 0; i < n; ++i) {
            if (!vowels.count(s[i])) {
                continue;
            } else {
                idx.push_back(i);
                v.push_back(s[i]);
            }
        }
        sort(v.begin(), v.end());
        int m = idx.size();
        for (int i = 0; i < m; ++i) {
            ans[idx[i]] = v[i];
        }
        return ans;
    }
};