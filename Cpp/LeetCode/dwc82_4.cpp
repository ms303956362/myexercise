#include "usual.h"

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + nums[i];
        }
        vector<int> l(n, -1), r(n, n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                l[i] = s.top();
            }
            s.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                r[i] = s.top();
            }
            s.push(i);
        }
        for (int i = 0; i < n; ++i) {
            if (pre[l[i] + 1] - pre[r[i]] > threshold && nums[i] > threshold / (r[i] - l[i] - 1)) {
                return r[i] - l[i] - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1,3,4,3,1};
    int a = 6;
    Solution().validSubarraySize(v, a);
    return 0;
}
