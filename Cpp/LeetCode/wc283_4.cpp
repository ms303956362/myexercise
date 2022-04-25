#include "usual.h"

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans3;
        bool ok = false;
        while (!ok) {
            int n = nums.size();
            vector<int> ans0, ans;
            ok = true;
            int last = nums[0];
            for (int i = 1; i < n; ++i) {
                int gcd = __gcd(nums[i], last);
                if (gcd > 1) {
                    ok = false;
                    last = (last / gcd) * (nums[i] / gcd) * gcd;
                } else {
                    ans0.push_back(last);
                    last = nums[i];
                }
            }
            ans0.push_back(last);
            if (ok) {
                ans3 = ans0;
                break;
            }
            ok = true;
            int m = ans0.size();
            last = ans0[m - 1];
            for (int i = m - 2; i >= 0; --i) {
                int gcd = __gcd(ans0[i], last);
                if (gcd > 1) {
                    ok = false;
                    last = (last / gcd) * (ans0[i] / gcd) * gcd;
                } else {
                    ans.push_back(last);
                    last = ans0[i];
                }
            }
            ans.push_back(last);
            reverse(ans.begin(), ans.end());
            if (ok) {
                ans3 = ans;
                break;
            }
            nums = ans;
        }
        return ans3;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{287,41,49,287,899,23,23,20677,5,825};
    Solution().replaceNonCoprimes(nums);
    return 0;
}
