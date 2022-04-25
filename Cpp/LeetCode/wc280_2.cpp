#include "usual.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> cnt1, cnt2;
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {
            if (!cnt1.count(nums[i])) {
                cnt1[nums[i]] = 0;
            }
            ++cnt1[nums[i]];
        }
        for (int i = 1; i < n; i += 2) {
            if (!cnt2.count(nums[i])) {
                cnt2[nums[i]] = 0;
            }
            ++cnt2[nums[i]];
        }
        int max_cnt1 = 0, second_cnt1 = 0, max_num1 = 0;
        int max_cnt2 = 0, second_cnt2 = 0, max_num2 = 0;
        for (const auto& [num, c] : cnt1) {
            if (c > max_cnt1) {
                second_cnt1 = max_cnt1;
                max_cnt1 = c;
                max_num1 = num;
            } else if (c > second_cnt1) {
                second_cnt1 = c;
            }
        }
        for (const auto& [num, c] : cnt2) {
            if (c > max_cnt2) {
                second_cnt2 = max_cnt2;
                max_cnt2 = c;
                max_num2 = num;
            } else if (c > second_cnt2) {
                second_cnt2 = c;
            }
        }
        if (max_num1 == max_num2) {
            return n - max(max_cnt1 + second_cnt2, max_cnt2 + second_cnt1);
        }
        return n - max_cnt1 - max_cnt2;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
