#include "usual.h"

class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> nums;
        vector<int> a;
        backtrack(0, 7, 0, nums, a);
        sort(a.begin(), a.end());
        return *upper_bound(a.begin(), a.end(), n);
    }

    void backtrack(int i, int n, int sum, vector<int>& nums, vector<int>& a) {
        if (i == n) {
            permute(sum, nums, a);
            return;
        }
        if (sum + i <= 7) {
            nums.push_back(i);
            backtrack(i + 1, n, sum + i, nums, a);
            nums.pop_back();
        }
        backtrack(i + 1, n, sum, nums, a);
    }

    void permute(int n, vector<int>& nums, vector<int>& a) {
        vector<int> cnt(nums);
        int m = nums.size();
        dfs(0, n, m, 0, nums, cnt, a);
    }

    void dfs(int i, int n, int m, int num, vector<int>& nums, vector<int>& cnts, vector<int>& a) {
        if (i == n) {
            a.push_back(num);
            return;
        }
        for (int j = 0; j < m; ++j) {
            if (cnts[j] > 0) {
                --cnts[j];
                num = num * 10 + nums[j];
                dfs(i + 1, n, m, num, nums, cnts, a);
                num /= 10;
                ++cnts[j];
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n = 10;
    Solution().nextBeautifulNumber(n);
    return 0;
}
