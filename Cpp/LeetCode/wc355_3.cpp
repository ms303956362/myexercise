#include "usual.h"

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        int n = usageLimits.size();
        sort(usageLimits.begin(), usageLimits.end());
        auto check = [&](int m) -> bool {
            vector<int> ul(usageLimits);
            int need = n, i = n - 1;
            for (int level = n; level >= 1; --level) {
                int last = 0;
                while (need > 0 && i >= 0) {
                    last = min(need, ul[i]);
                    need -= last;
                    ul[i] -= last;
                    if (ul[i] == 0) {
                        --i;
                    }
                }
                if (need > 0 && i < 0) {
                    return false;
                }
                need = level - 1 - min(level - 1 - last, ul[i] - last);
            }
        };
        int l = 1, h = n, ans = 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                l = m + 1;
                ans = l;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
