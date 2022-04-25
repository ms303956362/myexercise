#include "usual.h"

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        if (pattern[0] == pattern[1]) {
            long long cnt = 0;
            for (const auto& c : text) {
                if (c == pattern[0]) {
                    ++cnt;
                }
            }
            return cnt * (cnt + 1) / 2;
        }
        long long ans = 0;
        int n = text.size();
        long long cnt0 = 0, cnt1 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (text[i] == pattern[1]) {
                ++cnt1;
            } else if (text[i] == pattern[0]) {
                ++cnt0;
                ans += cnt1;
            }
        }
        return ans + max(cnt0, cnt1);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
