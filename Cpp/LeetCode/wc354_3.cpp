#include "usual.h"

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (const auto& num : nums) {
            ++cnt[num];
        }
        int d = 0;
        for (const auto& [num, c] : cnt) {
            if (2 * c > n) {
                d = num;
                break;
            }
        }
        vector<int> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + (nums[i] == d);
        }
        int ans = -1;
        for (int i = n - 1; i > 0; --i) {
            if (2 * (pre[i] - pre[n]) > (n - i) && 2 * (pre[0] - pre[i]) > i) {
                ans = i - 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
