#include "usual.h"

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> v{arr[i]};
            int cnt = 1;
            for (int j = i + k; j < n; j += k) {
                v.push_back(arr[j]);
                ++cnt;
            }
            ans += cnt - lengthOfLIS(v);
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> d(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            int j = upper_bound(d.begin(), d.end(), nums[i]) - d.begin();
            ans = max(ans, j + 1);
            if (d[j] > nums[i]) {
                d[j] = nums[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
