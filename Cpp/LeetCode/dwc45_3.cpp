#include "usual.h"

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), i = 0, j = n - 1;
        while (i < j && s[i] == s[j]) {
            ++i;
            --j;
            while (i < n && (i == 0 || s[i] == s[i - 1]))
                ++i;
            while (j >= 0 && (j == n - 1 || s[j] == s[j + 1]))
                --j;
        }
        return max(0, j - i + 1);
    }
};

int main(int argc, char const *argv[])
{
    string s("cabaabac");
    Solution().minimumLength(s);
    return 0;
}
