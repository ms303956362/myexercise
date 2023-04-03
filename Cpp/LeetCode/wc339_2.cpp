#include "usual.h"

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> cnt;
        for (const auto& num : nums) {
            ++cnt[num];
        }
        vector<vector<int>> ans;
        for (const auto& [num, c] : cnt) {
            int l = ans.size();
            for (int k = 0; k < c - l; ++k) {
                ans.push_back(vector<int>{});
            }
            for (int k = 0; k < c; ++k) {
                ans[k].push_back(num);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
