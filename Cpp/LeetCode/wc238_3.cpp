#include "usual.h"

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i = 0, j = 0, n = word.size();
        int ans = 0;
        vector<char> nexts{'e', 'i', 'o', 'u'}, prevs{'a', 'e', 'i', 'o'};
        while (i < n && j < n) {
            bool ok = true;
            while (i < n && word[i] != 'a')
                ++i;
            j = i + 1;
            for (int k = 0; k < 4; ++k) {
                while (j < n && word[j] == prevs[k])
                    ++j;
                if (j >= n || word[j] != nexts[k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                while (j < n && word[j] == 'u')
                    ++j;
                ans = max(ans, j - i);
            }
            i = j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
