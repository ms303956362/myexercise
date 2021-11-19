#include "usual.h"

class Solution {
public:
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string s;
        int ans = 0;
        while (ss >> s) {
            int n = s.size();
            int i = 0;
            bool hasc = false;
            for (i = 0; i < n; ++i) {
                if ('0' <= s[i] && s[i] <= '9')
                    break;
                else if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
                    if (i != n - 1)
                        break;
                } else if (s[i] == '-') {
                    if (!hasc) {
                        if (i > 0 && i < n - 1 && ('a' <= s[i - 1] && s[i - 1] <= 'z' && 'a' <= s[i + 1] && s[i + 1] <= 'z' ))
                            hasc = true;
                        else
                            break;
                    } else {
                        break;
                    }
                }
            }
            if (i == n)
                ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("cat and  dog");
    Solution().countValidWords(s);
    return 0;
}
