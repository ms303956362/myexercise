#include "usual.h"

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size(), i = 0, j = n - 1;
        while (i < j) {
            if (s[i] < s[j]) {
                s[j] = s[i];
            } else if (s[i] > s[j]) {
                s[i] = s[j];
            }
            ++i;
            --j;
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
