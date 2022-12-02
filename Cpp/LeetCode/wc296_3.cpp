#include "usual.h"

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> idx;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            idx[nums[i]] = i;
        }
        for (const auto& op : operations) {
            int i = idx[op[0]];
            idx.erase(op[0]);
            idx[op[1]] = i;
        }
        vector<int> ans(n);
        for (const auto& [num, i] : idx) {
            ans[i] = num;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
