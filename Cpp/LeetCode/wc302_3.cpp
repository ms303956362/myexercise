#include "usual.h"

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), l = nums[0].size();
        vector<int> ans;
        for (auto& num : nums) {
            reverse(num.begin(), num.end());
        }
        for (const auto& q : queries) {
            int k = q[0], trim = q[1];
            vector<pair<string, int>> tmp(n);
            for (int i = 0; i < n; ++i) {
                auto num = nums[i];
                while (num.size() > trim) {
                    num.pop_back();
                }
                reverse(num.begin(), num.end());
                tmp[i] = make_pair(num, i);
            }
            sort(tmp.begin(), tmp.end());
            ans.push_back(tmp[k - 1].second);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
