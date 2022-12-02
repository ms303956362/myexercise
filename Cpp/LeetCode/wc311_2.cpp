#include "usual.h"

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size(), curr = 1, ans = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1] + 1) {
                ++curr;
            } else {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
