#include "usual.h"

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        auto check = [](string s) {
            int n = s.size(), cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (s[i] == s[i + 1]) {
                    ++cnt;
                }
            }
            return cnt <= 1;
        };
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (check(s.substr(i, j - i))) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
