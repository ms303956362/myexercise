#include "usual.h"

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int m = nums.size(), ans = INT_MIN;
        for (int p = 0, q = 0; p <= m; ++p) {
            if (p < m && nums[p] != 0)
                continue;
            int n = p;
            int first = -1, last = -1;
            int cnt = 0;
            for (int i = q; i != n; ++i) {
                if (nums[i] < 0) {
                    if (first == -1) {
                        first = i;
                    }
                    ++cnt;
                }
            }
            for (int i = n - 1; i >= q; --i) {
                if (nums[i] < 0) {
                    last = i;
                    break;
                }
            }
            if (cnt % 2 == 0)
                ans  = max(ans, n - q);
            else
                ans = max(ans, max(last - q, n - first - 1));
            q = p + 1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
