#include "usual.h"

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string right_min(n, 'a');
        right_min[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_min[i] = min(right_min[i], s[i]);
        }
        string t, ans;
        int i = 0;
        while (i < n) {
            while (i < n && (t.empty() || t.back() > right_min[i])) {
                t.push_back(s[i]);
                ++i;
            }
            ans.push_back(t.back());
            t.pop_back();
        }
        while (!t.empty()) {
            ans.push_back(t.back());
            t.pop_back();
        }
        return ans;
    }
};
