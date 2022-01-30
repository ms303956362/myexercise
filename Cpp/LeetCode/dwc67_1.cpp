#include "usual.h"

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            v.emplace_back(nums[i], i);
        }
        sort(v.begin(), v.end());
        vector<pair<int, int>> a(v.begin() + n - k, v.end());
        sort(a.begin(), a.end(), [](const pair<int, int>& lp, const pair<int, int>& rp) {return lp.second > rp.second});
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(a[i].first);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
