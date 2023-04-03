#include "usual.h"

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) {
            return 0;
        }
        int n = s.size(), i = 0, j = n - 1;
        vector<int> cnt(3);
        while (i < n) {
            ++cnt[s[i] - 'a'];
            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                break;
            }
            ++i;
        }
        if (i >= n) {
            return -1;
        }
        int ans = i + 1;
        while (j >= 0) {
            ++cnt[s[j] - 'a'];
            while (i >= 0 && cnt[s[i] - 'a'] > k) {
                --cnt[s[i] - 'a'];
                --i;
            }
            ans = min(ans, i + 1 + n - j);
            --j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
