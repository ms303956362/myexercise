#include "usual.h"

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<unordered_set<int>> cnt(200);
        for (const auto& num : nums) {
            cnt[__builtin_popcount(num)].insert(num);
        }
        long long ans = 0;
        for (int i = 0; i < 200; ++i) {
            for (int j = 0; j < 200; ++j) {
                if (i + j >= k) {
                    long long li = cnt[i].size(), lj = cnt[j].size();
                    ans += li * lj;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
