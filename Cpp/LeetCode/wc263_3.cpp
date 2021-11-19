#include "usual.h"

class Solution {
    int cnt;
    int max_res;

public:
    int countMaxOrSubsets(vector<int>& nums) {
        cnt = 0;
        max_res = INT_MIN;
        int n = nums.size();
        vector<int> curr;
        backtrack(0, n, curr, nums, false);
        backtrack(0, n, curr, nums, true);
        return cnt;
    }

    void backtrack(int i, int n, vector<int>& curr, vector<int>& nums, bool cnt) {
        if (i == n) {
            int res = 0;
            if (curr.empty())
                return;
            for (const auto& num : curr) {
                res |= num;
            }
            if (cnt) {
                if (res == max_res)
                    ++cnt;
            } else {
                max_res = max(max_res, res);
            }
            return;
        }
        curr.push_back(nums[i]);
        backtrack(i + 1, n, curr, nums, cnt);
        curr.pop_back();
        backtrack(i + 1, n, curr, nums, cnt);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
