#include "usual.h"

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int ans = INT_MAX;
        int sum = 0;
        for (int i = 0; i < 2 * n; ++i) {
            sum += nums[i];
            nums[i] *= 2;
        }
        vector<unordered_set<int>> dpl(n + 1), dpr(n + 1);
        getsum(n, dpl, nums, 0);
        getsum(n, dpr, nums, n);
        for (int i = 0; i <= n; ++i) {
            vector<int> a(dpl[i].begin(), dpl[i].end()), b(dpr[n - i].begin(), dpr[n - i].end());
            sort(a.begin(), a.end());
            sort(b.rbegin(), b.rend());
            int nl = a.size(), nr = b.size();
            for (int j = 0, k = 0; j < nl && k < nr; ) {
                ans = min(ans, abs(a[j] + b[k] - sum));
                if (a[j] + b[k] > sum)
                    ++k;
                else if (a[j] + b[k] == sum)
                    return 0;
                else
                    ++j;
            }
        }
        return ans;
    }

    void getsum(int n, vector<unordered_set<int>>& dp, vector<int>& nums, int beg) {
        dp[0].insert(0);
        vector<int> cache((1 << n));
        cache[0] = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int cnt = 0, j1 = 0;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & mask) {
                    j1 = j;
                    ++cnt;
                }
            }
            dp[cnt].insert(cache[(~(1 << j1)) & mask] + nums[beg + j1]);
            cache[mask] = cache[(~(1 << j1)) & mask] + nums[beg + j1];
        }
    }
};

/*
[7772197,4460211,-7641449,-8856364,546755,-3673029,527497,-9392076,3130315,-5309187,-4781283,5919119,3093450,1132720,6380128,-3954678,-1651499,-7944388,-3056827,1610628,7711173,6595873,302974,7656726,-2572679,0,2121026,-5743797,-8897395,-9699694]
*/
int main(int argc, char const *argv[])
{
    vector<int> nums{7772197,4460211,-7641449,-8856364,546755,-3673029,527497,-9392076,3130315,-5309187,-4781283,5919119,3093450,1132720,6380128,-3954678,-1651499,-7944388,-3056827,1610628,7711173,6595873,302974,7656726,-2572679,0,2121026,-5743797,-8897395,-9699694};
    cout << Solution().minimumDifference(nums) << endl;
    return 0;
}
