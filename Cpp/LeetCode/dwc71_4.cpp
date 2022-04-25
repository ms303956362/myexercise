#include "usual.h"

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> sufmax(3 * n), premin(3 * n);
        long long s = 0;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (int i = 3 * n - 1; i >= 2 * n; --i) {
            s += nums[i];
            q.push(nums[i]);
        }
        sufmax[2 * n] = s;
        for (int i = 2 * n - 1; i >= n; --i) {
            if (nums[i] > q.top()) {
                s -= q.top();
                s += nums[i];
                q.pop();
                q.push(nums[i]);
            }
            sufmax[i] = s;
        }
        s = 0;
        priority_queue<long long> p;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            p.push(nums[i]);
        }
        premin[n - 1] = s;
        for (int i = n; i <= 2 * n; ++i) {
            if (nums[i] < p.top()) {
                s -= p.top();
                s += nums[i];
                p.pop();
                p.push(nums[i]);
            }
            premin[i] = s;
        }
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = n; i <= 2 * n; ++i) {
            ans = min(ans, premin[i - 1] - sufmax[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{3, 1, 2};
    Solution().minimumDifference(v);
    return 0;
}
