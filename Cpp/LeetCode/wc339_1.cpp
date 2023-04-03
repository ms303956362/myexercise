#include "usual.h"

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int last0 = -1, first1 = n, cnt0 = 0, cnt1 = 0;
                for (int k = i; k <= j; ++k) {
                    if (s[k] == '0') {
                        last0 = k;
                        ++cnt0;
                    } else {
                        first1 = min(first1, k);
                        ++cnt1;
                    }
                }
                if (last0 < first1 && cnt0 == cnt1) {
                    ans = max(ans, j - i + 1);
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
