#include "usual.h"

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string t(words[i].rbegin(), words[i].rend());
            if (t == words[i])
                return t;
        }
        return "";
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
