#include "usual.h"

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        long long l = 1, h = 2e9;
        auto check = [&](long long m) -> bool {
            int i = 0, cnt = 0;
            while (i < n) {
                while (i < n && nums[i] > m) {
                    ++i;
                }
                if (i >= n) {
                    break;
                }
                int j = i + 1;
                while (j < n && nums[j] <= m) {
                    ++j;
                }
                cnt += (j - i + 1) / 2;
                i = j;
            }
            return cnt >= k;
        };
        long long ans = 0;
        while (l <= h) {
            long long m = (l + h) / 2;
            if (check(m)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
