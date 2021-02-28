#include "usual.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = candiesCount.size();
        vector<long long> presum(n);
        presum[0] = candiesCount[0];
        for (int i = 1; i != n; ++i)
            presum[i] = presum[i - 1] + candiesCount[i];
        for (const auto &q : queries) {
            int l = upper_bound(presum.begin(), presum.end(), (long long)q[1]) - presum.begin();
            int h = upper_bound(presum.begin(), presum.end(), (long long)q[1] * (long long)q[2]) - presum.begin();
            ans.push_back((l <= q[0] && q[0] <= h));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{46,5,47,48,43,34,15,26,11,25,41,47,15,25,16,50,32,42,32,21,36,34,50,45,46,15,46,38,50,12,3,26,26,16,23,1,4,48,47,32,47,16,33,23,38,2,19,50,6,19,29,3,27,12,6,22,33,28,7,10,12,8,13,24,21,38,43,26,35,18,34,3,14,48,50,34,38,4,50,26,5,35,11,2,35,9,11,31,36,20,21,37,18,34,34,10,21,8,5};
    vector<vector<int>> q{{85, 54, 42}};
    Solution().canEat(a, q);
    return 0;
}
