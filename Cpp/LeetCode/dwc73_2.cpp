#include "usual.h"

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> maps;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int a = 0, num = nums[i];
            vector<int> v;
            if (num == 0) {
                v.push_back(mapping[0]);
            } else {
                while (num > 0)
                {
                    v.push_back(mapping[num % 10]);
                    num /= 10;
                }
            }
            reverse(v.begin(), v.end());
            for (const auto &c : v)
            {
                a = a * 10 + c;
            }
            maps.emplace_back(a, i);
        }
        sort(maps.begin(), maps.end());
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[maps[i].second]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, b{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution().sortJumbled(a, b);
    return 0;
}
