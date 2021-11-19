#include "usual.h"

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, n = word.size();
        while (i < n && word[i] != ch) {
            ++i;
        }
        if (i < n)
            reverse(word.begin(), word.begin() + i + 1);
        return word;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
