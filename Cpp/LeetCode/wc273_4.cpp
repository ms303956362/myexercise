#include "usual.h"

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        auto check = [&](int k)
        {
            unordered_map<int, int> cnt;
            for (int i = 0; i < n; ++i) {
                if (!cnt.count(nums[i]))
                    cnt[nums[i]] = 0;
                ++cnt[nums[i]];
            }
            int c = 0;
            for (int i = 0; i < n; ++i) {
                if (cnt[nums[i]] == 0)
                    continue;
                if (cnt[nums[i] + k] > 0) {
                    ++c;
                    --cnt[nums[i]];
                    --cnt[nums[i] + k];
                } else {
                    return false;
                }
            }
            if (c < n / 2) {
                return false;
            }
            return true;
        };
        for (int i = 1; i < n; ++i) {
            int k = nums[i] - nums[0];
            if (k == 0 || k % 2 != 0)
                continue;
            if (check(k)) {
                unordered_map<int, int> cnt;
                for (int i = 0; i < n; ++i) {
                    if (!cnt.count(nums[i]))
                        cnt[nums[i]] = 0;
                    ++cnt[nums[i]];
                }
                for (int i = 0; i < n; ++i) {
                    if (cnt[nums[i]] == 0)
                        continue;
                    if (cnt[nums[i] + k] > 0) {
                        ans.push_back(nums[i] + k / 2);
                        --cnt[nums[i]];
                        --cnt[nums[i] + k];
                    }
                }
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{2, 10, 6, 4, 8, 12};
    Solution().recoverArray(a);
    return 0;
}
