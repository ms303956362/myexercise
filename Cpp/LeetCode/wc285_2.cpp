#include "usual.h"

class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, n = directions.size();
        for (int i = 0; i < n; ) {
            if (directions[i] == 'L') {
                ++i;
                continue;
            }
            int j = i;
            while (j < n && directions[j] == 'R') {
                ++j;
            }
            int k = j;
            while (k < n && directions[k] == 'S') {
                ++k;
            }
            int l = k;
            while (l < n && directions[l] == 'L') {
                ++l;
            }
            if (k - j > 0) {
                ans += j - i + l - k;
            } else if (j - i > 0 && l - k > 0) {
                ans += j - i + l - k;
            }
            i = l;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("LLRR");
    Solution().countCollisions(s);
    return 0;
}
