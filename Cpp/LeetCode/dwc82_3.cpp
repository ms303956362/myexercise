#include "usual.h"

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = abs(nums1[i] - nums2[i]);
        }
        sort(a.begin(), a.end());
        long long l = 0, h = a.back();
        auto check = [&](int m) {
            long long cnt = 0;
            for (int i = n - 1; i >= 0 && a[i] > m; --i) {
                cnt += a[i] - m;
            }
            return cnt;
        };
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m) <= k1 + k2) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        int cnt = k1 + k2;
        for (int i = n - 1; i >= 0 && a[i] > l; --i) {
            cnt -= a[i] - l;
            a[i] = l;
        }
        for (int i = n - 1; i >= 0 && cnt > 0 && a[i] > 0; --i) {
            --a[i];
            --cnt;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i] * a[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{10,10,10,11,5}, b{1,0,6,6,1};
    int k1 = 11, k2 = 27;
    Solution().minSumSquareDiff(a, b, k1, k2);
    return 0;
}
