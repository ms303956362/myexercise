#include "usual.h"

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        multiset<pair<long long, int>> ms;
        long long total = 0;
        for (auto& num : nums) {
            if (num > 0) {
                total += (long long)num;
            } else {
                num = -num;
            }
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ms.emplace(0, -1);
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            auto [s, j] = *ms.begin();
            sum = s;
            ms.erase(ms.begin());
            for (int t = j + 1; t < n && t <= (j + k); ++t) {
                if (ms.size() < k) {
                    ms.emplace(s + nums[t], t);
                } else {
                    auto p = prev(ms.end());
                    if (p->first > s + nums[t]) {
                        ms.erase(p);
                        ms.emplace(s + nums[t], t);
                    } else {
                        break;
                    }
                }
            }
        }
        return total - sum;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
