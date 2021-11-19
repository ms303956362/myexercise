#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnt;
        sort(nums.begin(), nums.end());
        cnt[0] = 0;
        for (const auto& num : nums) {
            if (cnt.count(num))
                ++cnt[num];
            else
                cnt[num] = 1;
        }
        map<int, int> cnt1(cnt);
        for (auto p = next(cnt.begin()); p != cnt.end(); ++p) {
            --(p->second);
            p->second += prev(p)->second;
        }
        for (auto p = next(cnt1.begin()); p != cnt1.end(); ++p) {
            p->second += prev(p)->second;
        }
        int ans = INT_MAX;
        for (auto p = next(cnt.begin()); p != cnt.end(); ++p) {
            auto q = prev(cnt.upper_bound(p->first + n - 1));
            if (q != cnt.end())
                ans = min(ans, n - (cnt1[q->first] - cnt1[prev(p)->first]) + (cnt[q->first] - cnt[prev(p)->first]));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{4, 2, 5, 3};
    Solution().minOperations(a);
    return 0;
}
