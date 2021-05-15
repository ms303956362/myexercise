#include "usual.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> cnts;
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                cnts.push_back({nums[i - 1], cnt});
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        cnts.push_back({nums[n - 1], cnt});
        int ans = cnts[0].second, m = cnts.size();
        for (int i = 1; i < m; ++i) {
            cnt = cnts[i].second;
            int res = k, inc = 1;
            for (int j = i - 1; j >= 0 && inc > 0; --j) {
                inc = min(res / (cnts[i].first - cnts[j].first), cnts[j].second);
                cnt += inc;
                res -= inc * (cnts[i].first - cnts[j].first);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
