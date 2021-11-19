#include "usual.h"

class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0, n = word.size();
        for (long long i = 0; i < n; ++i) {
            char c = word[i];
            if (!(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'))
                ans += n * (n - 1) / 2 - i * (i - 1) / 2 - (n - i - 1) * (n - i - 2) / 2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
