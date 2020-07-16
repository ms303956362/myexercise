#include "usual.h"

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> a;
        int MOD = 1e9 + 7;
        for (int i = 0; i != n; ++i) {
            int s = 0;
            for (int j = i; j != n; ++j) {
                s += nums[j];
                a.push_back(s);
            }
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + a[i]) % MOD;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
