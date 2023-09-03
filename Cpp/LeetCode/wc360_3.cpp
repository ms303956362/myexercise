#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;
        for (const auto& num : nums) {
            sum += num;
        }
        if (sum < target) {
            return -1;
        }
        if (sum == target) {
            return 0;
        }
        int n = nums.size();
        vector<int> cntn(35), cntt(35);
        auto idx = [](int num) {
            int cnt = 0;
            while (num > 1) {
                ++cnt;
                num /= 2;
            }
            return cnt;
        };
        for (const auto& num : nums) {
            ++cntn[idx(num)];
        }
        for (int i = 0; i < 30; ++i) {
            if (target & (1 << i)) {
                ++cntt[i];
            }
        }
        for (int i = 0; i < 30; ++i) {
            
        }
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            if (cntn[i] == 0 && cntt[i] > 0) {
                // 1
                int j = 0;
                while (j < i && cntn[j] >= cntt[j] + 2) {
                    cntn[j] -= 2;
                    ++cntn[j + 1];
                    ++j;
                }
                if (cntn[i] >= cntt[i]) {
                    continue;
                }
                // 2
                j = i + 1;
                while (j < 30 && cntn[j] <= cntt[j]) {
                    ++j;
                }
                --cntn[j];
                --j;
                while (j >= i) {
                    ++ans;
                    ++cntn[j];
                    --j;
                }
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> a{128,8,8,2};
    int t = 4;
    Solution().minOperations(a, t);
    return 0;
}
