#include "usual.h"

class Solution {
public:
    int rampartDefensiveLine(vector<vector<int>>& rampart) {
        int n = rampart.size();
        int l = 0, h = 1e9, ans = 0;
        auto check = [&](int m) -> bool {
            int last = rampart[0][1];
            for (int i = 1; i < n; ++i) {
                if (rampart[i][0] - last >= m) {
                    last = rampart[i][1];
                } else {
                    last = rampart[i][1] + m - (rampart[i][0] - last);
                }
                if (i < n - 1 && last > rampart[i + 1][0]) {
                    return false;
                }
            }
            return true;
        };
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                ans = m;
                l = m + 1;
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
