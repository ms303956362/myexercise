#include "usual.h"

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        long long n = parents.size();
        vector<vector<long long>> children(n);
        for (long long i = 1; i < n; ++i) {
            children[parents[i]].push_back(i);
        }
        vector<long long> nums(n, 1);
        dfs(0, children, nums);
        long long max_score = 1;
        vector<long long> scores(n);
        for (long long i = 0; i < n; ++i) {
            long long p = 1;
            if (i > 0)
                p *= nums[0] - nums[i];
            for (const auto& c : children[i]) {
                p *= nums[c];
            }
            scores[i] = p;
            max_score = max(max_score, p);
        }
        long long ans = 0;
        for (const auto& s : scores) {
            if (s == max_score)
                ++ans;
        }
        return ans;
    }

    long long dfs(long long i, vector<vector<long long>>& children, vector<long long>& nums) {
        if (children[i].size() == 0) {
            return 1;
        }
        long long num = 1;
        for (const auto& c : children[i]) {
            num += dfs(c, children, nums);
        }
        nums[i] = num;
        return num;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> p({-1, 2, 0, 2, 0});
    Solution().countHighestScoreNodes(p);
    return 0;
}
