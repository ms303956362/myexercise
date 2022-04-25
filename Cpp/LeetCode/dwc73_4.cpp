#include "usual.h"

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            int j = n - 1 - i, k = j;
            while (k > i) {
                if (s[k] == s[i]) {
                    break;
                }
                --k;
            }
            if (k == i) {
                if (k > n / 2) {
                    while (k > n / 2) {
                        swap(s[k], s[k - 1]);
                        ++ans;
                        --k;
                    }
                } else if (k < n / 2) {
                    while (k < n / 2) {
                        swap(s[k], s[k + 1]);
                        ++ans;
                        ++k;
                    }
                }
            } else {
                while (k < j) {
                    swap(s[k], s[k + 1]);
                    ++ans;
                    ++k;
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
