#include "usual.h"

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        bool ans = false;
        int n = a.size();
        int i = 0, j = n - 1;
        for (i = 0, j = n - 1; i < j; ++i, --j) {
            if (a[i] != b[j]) {
                ans = (isPalindrome(i, j, a) || isPalindrome(i, j, b));
                break;
            }
        }
        if (i >= j)
            ans = true;
        if (ans)
            return ans;
        for (i = 0, j = n - 1; i < j; ++i, --j) {
            if (b[i] != a[j]) {
                ans = (isPalindrome(i, j, a) || isPalindrome(i, j, b));
                break;
            }
        }
        if (i >= j)
            ans = true;
        return ans;
    }

    bool isPalindrome(int b, int e, const string& s) {
        // [b, e]
        int i = b, j = e;
        for (i = b, j = e; i < j && s[i] == s[j]; ++i, --j) {
 
        }
        return i >= j;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
