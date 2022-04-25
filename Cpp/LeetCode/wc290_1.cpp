#include "usual.h"

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums[0].size(), m = nums.size();
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 1; j < m; ++j) {
                bool ok1 = false;
                for (const auto& num : nums[j]) {
                    if (num == nums[0][i]) {
                        ok1 = true;
                        break;
                    }
                }
                if (!ok1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.push_back(nums[0][i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
