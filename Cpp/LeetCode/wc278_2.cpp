#include "usual.h"

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> scores(n + 1), suffix(n + 1), pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        int max_score = 0;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + 1 - nums[i];
            scores[i] = pre[i] + suffix[i];
            max_score = max(max_score, scores[i]);
        }
        scores[n] = pre[n] + suffix[n];
        max_score = max(max_score, scores[n]);
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            if (scores[i] == max_score) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
