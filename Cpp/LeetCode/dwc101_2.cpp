#include "usual.h"

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size(), m = chars.size();
        vector<int> scores(26);
        for (int i = 0; i < 26; ++i) {
            scores[i] = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            scores[chars[i] - 'a'] = vals[i];
        }
        int ans = 0, min_pre = 0, pre = 0;
        for (int i = n - 1; i >= 0; --i) {
            pre = pre + scores[s[i] - 'a'];
            min_pre = min(min_pre, pre);
            ans = max(ans, pre - min_pre);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
