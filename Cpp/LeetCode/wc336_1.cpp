#include "usual.h"

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto is_vowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (is_vowel(words[i][0]) && is_vowel(words[i].back())) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
