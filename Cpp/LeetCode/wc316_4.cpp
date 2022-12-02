#include "usual.h"

using ll = long long;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<ll> nums_o, nums_e, target_o, target_e;
        for (const auto& num : nums) {
            if (num % 2 == 1) {
                nums_o.push_back(num);
            } else {
                nums_e.push_back(num);
            }
        }
        for (const auto& t :target) {
            if (t % 2 == 1) {
                target_o.push_back(t);
            } else {
                target_e.push_back(t);
            }
        }
        sort(nums_e.begin(), nums_e.end());
        sort(nums_o.begin(), nums_o.end());
        sort(target_e.begin(), target_e.end());
        sort(target_o.begin(), target_o.end());
        int me = nums_e.size(), mo = nums_o.size();
        ll ans = 0;
        for (int i = 0; i < me; ++i) {
            if (nums_e[i] >= target_e[i]) {
                ans += (nums_e[i] - target_e[i]) / 2;
            }
        }
        for (int i = 0; i < mo; ++i) {
            if (nums_o[i] >= target_o[i]) {
                ans += (nums_o[i] - target_o[i]) / 2;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
